#include "sailor_moon_machine.h"

static int sm09_valid_cpu(const SmScpuState *cpu) {
    if (cpu == NULL || cpu->e > 1u || cpu->stopped > 1u) return 0;
    if (cpu->e != 0u && ((cpu->p & (SM_P_M | SM_P_X)) != (SM_P_M | SM_P_X) ||
                         (cpu->s & 0xFF00u) != 0x0100u)) return 0;
    if ((cpu->p & SM_P_X) != 0u && ((cpu->x | cpu->y) & 0xFF00u) != 0u) return 0;
    return 1;
}

static int sm09_bound(const Sm09Machine *m) {
    return m != NULL && m->storage != NULL && m->scheduler != NULL &&
           m->clock != NULL && m->cpu != NULL;
}

static Sm08Status sm09_stop(Sm09Machine *m, Sm08Status status, const char *reason) {
    const Sm08Value unknown = {0u, 0u};
    sm08_bus_fault(&m->storage->bus, status, 9u, sm_scpu_address(m->cpu), unknown);
    sm_scpu_stop(m->cpu, NULL, reason);
    return m->storage->bus.fault.status;
}

Sm08Status sm09_machine_construct(Sm09Machine *m, Sm08Machine *storage,
    Sm09Scheduler *scheduler, Sm09Clock *clock, SmScpuState *cpu,
    const uint8_t *rom, size_t size, Sm08Ports ports, Sm08Pins pins,
    Sm09Receivers receivers) {
    Sm08Status status;
    if (m == NULL || storage == NULL || scheduler == NULL || clock == NULL ||
        !sm09_valid_cpu(cpu) || rom == NULL || receivers.smp_sync == NULL ||
        receivers.raster_event == NULL || receivers.cpu_boundary == NULL) return SM08_ARGUMENT;
    status = sm08_machine_power_on(storage, rom, size, ports, pins);
    if (status != SM08_OK) return status;
    status = sm09_scheduler_cold(scheduler, &storage->bus, receivers);
    if (status != SM08_OK) return status;
    status = sm09_clock_bind(clock, &storage->bus, &storage->io,
                             sm09_scheduler_timeline(scheduler));
    if (status != SM08_OK) return status;
    status = sm09_machine_bind(m, storage, scheduler, clock, cpu);
    if (status != SM08_OK) return status;
    return sm09_machine_cpu_reset_assert(m);
}

Sm08Status sm09_machine_bind(Sm09Machine *m, Sm08Machine *storage,
    Sm09Scheduler *scheduler, Sm09Clock *clock, SmScpuState *cpu) {
    Sm09TimelinePort timeline;
    if (m == NULL || storage == NULL || scheduler == NULL || clock == NULL ||
        !sm09_valid_cpu(cpu) || scheduler->bus != &storage->bus ||
        clock->bus != &storage->bus || clock->math != &storage->io.math ||
        storage->io.bus != &storage->bus || clock->active != 0u ||
        clock->reset_vector_phase != 0u || clock->reset_cpu != NULL ||
        scheduler->advancing != 0u || scheduler->poll_valid != 0u) return SM08_ARGUMENT;
    timeline = sm09_scheduler_timeline(scheduler);
    if (clock->timeline.context != timeline.context ||
        clock->timeline.start_cycle != timeline.start_cycle ||
        clock->timeline.advance != timeline.advance ||
        clock->timeline.interrupt_poll != timeline.interrupt_poll) return SM08_ARGUMENT;
    m->storage = storage;
    m->scheduler = scheduler;
    m->clock = clock;
    m->cpu = cpu;
    m->reset_phase = SM09_RESET_NONE;
    m->reset_assert_clock = 0u;
    m->reset_release_clock = 0u;
    storage->bus.ports.clock = sm09_clock_port(clock);
    storage->bus.ports.scheduler = sm09_scheduler_register_port(scheduler);
    return SM08_OK;
}

static Sm08Status sm09_entry_cycle(Sm09Machine *m, Sm09MachineCycle kind,
                                   uint32_t address, uint8_t *byte) {
    Sm08Status status;
    if (m->cpu->completed_cycles == UINT64_MAX)
        return sm09_stop(m, SM08_CLOCK_ABSENT, "CPU_CYCLE_COUNTER_OVERFLOW");
    status = sm09_clock_machine_cycle(m->clock, kind, address, byte);
    m->cpu->completed_cycles += m->clock->machine_cycle_completed;
    if (status != SM08_OK) return sm09_stop(m, status, "INTERRUPT_ENTRY_CYCLE_FAILED");
    return SM08_OK;
}

static Sm08Status sm09_entry_push(Sm09Machine *m, uint8_t byte) {
    Sm08Status status = sm09_entry_cycle(m, SM09_MACHINE_WRITE, m->cpu->s, &byte);
    if (status != SM08_OK) return status;
    m->cpu->s = m->cpu->e != 0u ?
        (uint16_t)(0x0100u | ((m->cpu->s - 1u) & 0xFFu)) : (uint16_t)(m->cpu->s - 1u);
    return SM08_OK;
}

Sm08Status sm09_machine_interrupt_entry(Sm09Machine *m, uint8_t interrupt) {
    Sm08Status status;
    SmScpuState *cpu;
    uint16_t vector;
    uint8_t byte = 0u, low = 0u, high = 0u;
    if (!sm09_bound(m) || (interrupt != 1u && interrupt != 2u)) return SM08_ARGUMENT;
    if (m->storage->bus.fault.status != SM08_OK) return m->storage->bus.fault.status;
    if (m->reset_phase != SM09_RESET_NONE) return SM08_ARGUMENT;
    cpu = m->cpu;
    if (cpu->stopped != 0u || cpu->failure_reason != NULL || m->clock->active != 0u ||
        m->scheduler->poll_valid != 0u || m->storage->bus.instruction_open != 0u)
        return sm09_stop(m, SM08_CLOCK_ABSENT, "INVALID_HARDWARE_ENTRY_BOUNDARY");
    status = sm09_entry_cycle(m, SM09_MACHINE_FETCH_DISCARD, sm_scpu_address(cpu), &byte);
    if (status != SM08_OK) return status;
    status = sm09_entry_cycle(m, SM09_MACHINE_INTERNAL, sm_scpu_address(cpu), &byte);
    if (status != SM08_OK) return status;
    if (cpu->e == 0u) {
        status = sm09_entry_push(m, cpu->pbr);
        if (status != SM08_OK) return status;
    }
    status = sm09_entry_push(m, (uint8_t)(cpu->pc >> 8u));
    if (status != SM08_OK) return status;
    status = sm09_entry_push(m, (uint8_t)cpu->pc);
    if (status != SM08_OK) return status;
    byte = cpu->e != 0u ? (uint8_t)(cpu->p & (uint8_t)~0x10u) : cpu->p;
    status = sm09_entry_push(m, byte);
    if (status != SM08_OK) return status;
    cpu->p = (uint8_t)((cpu->p | SM_P_I) & (uint8_t)~SM_P_D);
    cpu->pbr = 0u;
    vector = cpu->e != 0u ? (interrupt == 1u ? 0xFFFAu : 0xFFFEu) :
                           (interrupt == 1u ? 0xFFEAu : 0xFFEEu);
    status = sm09_entry_cycle(m, SM09_MACHINE_READ, vector, &low);
    if (status != SM08_OK) return status;
    status = sm09_entry_cycle(m, SM09_MACHINE_READ, (uint32_t)vector + 1u, &high);
    if (status != SM08_OK) return status;
    cpu->pc = (uint16_t)(low | ((uint16_t)high << 8u));
    if (sm09_timing_plan_lookup(sm_scpu_context_key(cpu)) == NULL)
        return sm09_stop(m, SM08_CLOCK_ABSENT, "UNADMITTED_INTERRUPT_CONTEXT");
    return SM08_OK;
}

Sm08Status sm09_machine_retire(Sm09Machine *m) {
    Sm08Status status;
    uint8_t interrupt = 0u;
    if (!sm09_bound(m) || m->reset_phase != SM09_RESET_NONE) return SM08_ARGUMENT;
    if (m->storage->bus.fault.status != SM08_OK) return m->storage->bus.fault.status;
    if (m->cpu->stopped != 0u || m->cpu->failure_reason != NULL || m->clock->active != 0u ||
        m->storage->bus.instruction_open != 0u)
        return sm09_stop(m, SM08_CLOCK_ABSENT, "FAILED_INSTRUCTION_CANNOT_RETIRE");
    /* Existing02/07 BRK source bodies have already emitted their signature,
     * frame and vector. Consume that explicit source policy, not an ordinary
     * poll or a second hardware entry. Asynchronous pending state is retained;
     * this functional source contract does not prove physical NMI hijacking. */
    if (m->clock->plan != NULL &&
        m->clock->plan->irq_status_policy == SM09_TIMING_SOFTWARE_BREAK) {
        if (m->scheduler->poll_valid != 0u)
            return sm09_stop(m, SM08_CLOCK_ABSENT, "SOFTWARE_ENTRY_HAS_FOREIGN_POLL");
        return SM08_OK;
    }
    status = sm09_scheduler_take_interrupt(m->scheduler, &interrupt);
    if (status != SM08_OK) return sm09_stop(m, status, "MISSING_RETIREMENT_POLL");
    if (interrupt == 0u) return SM08_OK;
    return sm09_machine_interrupt_entry(m, interrupt);
}

SmScpuExecResult sm09_machine_step(Sm09Machine *m) {
    SmScpuBus view;
    SmScpuExecResult result;
    if (!sm09_bound(m) || m->reset_phase != SM09_RESET_NONE) return SM_SCPU_STOPPED;
    if (m->cpu->stopped != 0u || m->cpu->failure_reason != NULL ||
        m->storage->bus.fault.status != SM08_OK) return SM_SCPU_STOPPED;
    if (m->clock->active != 0u || m->scheduler->poll_valid != 0u ||
        m->storage->bus.instruction_open != 0u) {
        sm09_stop(m, SM08_CLOCK_ABSENT, "UNRETIRED_INSTRUCTION");
        return SM_SCPU_STOPPED;
    }
    view = sm08_bus_cpu_view(&m->storage->bus);
    result = sm_scpu_step(m->cpu, &view);
    if (result != SM_SCPU_EXECUTED) return result;
    if (sm09_machine_retire(m) != SM08_OK) return SM_SCPU_STOPPED;
    return SM_SCPU_EXECUTED;
}

Sm08Status sm09_machine_cpu_reset_assert(Sm09Machine *m) {
    Sm08Status status;
    SmScpuState *cpu;
    if (!sm09_bound(m) || m->scheduler->advancing != 0u ||
        m->reset_phase == SM09_RESET_RELEASING) return SM08_ARGUMENT;
    if (m->reset_phase == SM09_RESET_HELD) return m->storage->bus.fault.status;
    if ((m->clock->active != 0u || m->scheduler->poll_valid != 0u ||
         m->storage->bus.instruction_open != 0u) && m->cpu->failure_reason == NULL &&
        m->cpu->stopped == 0u && m->storage->bus.fault.status == SM08_OK) return SM08_ARGUMENT;
    m->reset_phase = SM09_RESET_HELD;
    m->reset_assert_clock = m->scheduler->master_clock;
    m->reset_release_clock = 0u;
    /* The source body has returned at a fault cut, so09 can abort its callback
     * plumbing. Neither a RAM installer epoch nor a frame token is invented. */
    m->clock->active = 0u;
    m->clock->reset_vector_phase = 0u;
    m->clock->reset_cpu = NULL;
    m->storage->bus.instruction_open = 0u;
    m->storage->bus.active_cpu = NULL;
    status = sm08_machine_reset_latches(m->storage);
    if (status == SM08_OK) status = sm09_scheduler_reset_cpu_latches(m->scheduler);
    if (status != SM08_OK) {
        m->reset_phase = SM09_RESET_FAILED;
        return sm09_stop(m, status, "CPU_RESET_ASSERTION_FAILED");
    }
    cpu = m->cpu;
    cpu->e = 1u;
    cpu->p = (uint8_t)((cpu->p | SM_P_I | SM_P_M | SM_P_X) & (uint8_t)~SM_P_D);
    cpu->d = 0u;
    cpu->dbr = 0u;
    cpu->pbr = 0u;
    cpu->x &= 0xFFu;
    cpu->y &= 0xFFu;
    cpu->s = (uint16_t)(0x0100u | (cpu->s & 0xFFu));
    cpu->stopped = 0u;
    cpu->failure_reason = NULL;
    cpu->failure_address = 0u;
    cpu->failure_context = 0u;
    return SM08_OK;
}

Sm08Status sm09_machine_cpu_reset_hold(Sm09Machine *m, uint32_t clocks) {
    Sm08Status status;
    if (!sm09_bound(m) || m->reset_phase != SM09_RESET_HELD) return SM08_ARGUMENT;
    if (m->storage->bus.fault.status != SM08_OK) return m->storage->bus.fault.status;
    status = sm09_scheduler_advance_wall(m->scheduler, clocks);
    if (status != SM08_OK) {
        m->reset_phase = SM09_RESET_FAILED;
        return sm09_stop(m, status, "RESET_HOLD_DOMAIN_FAILED");
    }
    return SM08_OK;
}

Sm08Status sm09_machine_cpu_reset_release(Sm09Machine *m) {
    Sm08Status status;
    uint16_t vector = 0u;
    if (!sm09_bound(m) || m->reset_phase != SM09_RESET_HELD ||
        m->scheduler->advancing != 0u) return SM08_ARGUMENT;
    if (m->storage->bus.fault.status != SM08_OK) return m->storage->bus.fault.status;
    status = sm09_scheduler_reset_cpu_latches(m->scheduler);
    if (status != SM08_OK) {
        m->reset_phase = SM09_RESET_FAILED;
        return sm09_stop(m, status, "RESET_RELEASE_LATCH_FAILED");
    }
    m->reset_phase = SM09_RESET_RELEASING;
    m->reset_release_clock = m->scheduler->master_clock;
    status = sm09_clock_reset_vector_begin(m->clock, m->cpu);
    if (status == SM08_OK) status = sm08_bus_reset_vector(&m->storage->bus, &vector);
    if (status == SM08_OK) {
        m->cpu->pc = vector;
        if (sm09_timing_plan_lookup(sm_scpu_context_key(m->cpu)) == NULL) status = SM08_GUARD;
    }
    if (status == SM08_OK)
        status = sm09_scheduler_advance_wall(m->scheduler, SM09_RESET_RELEASE_MASTER_CLOCKS);
    if (status != SM08_OK) {
        m->reset_phase = SM09_RESET_FAILED;
        return sm09_stop(m, status, "RESET_RELEASE_FAILED");
    }
    m->reset_phase = SM09_RESET_NONE;
    return SM08_OK;
}

static Sm08Status sm09_device_reset(Sm09Machine *m, Sm09DeviceResetPort port,
                                    Sm09DeviceResetPhase phase, uint32_t hold) {
    const uint64_t before = m->scheduler->master_clock;
    const Sm09SmpJoin smp_before = m->scheduler->smp;
    const Sm08Fault prior = m->storage->bus.fault;
    Sm08Status status;
    m->scheduler->advancing = 1u;
    status = port.apply(port.context, &m->storage->bus, m->scheduler, phase, hold);
    m->scheduler->advancing = 0u;
    if (m->scheduler->master_clock != before ||
        m->scheduler->smp.target_cycles != smp_before.target_cycles ||
        m->scheduler->smp.remainder != smp_before.remainder) {
        m->reset_phase = SM09_RESET_FAILED;
        return sm09_stop(m, SM08_CLOCK_ABSENT, "DEVICE_RESET_ADVANCED_TIME");
    }
    if (phase == SM09_DEVICE_RESET_PREFLIGHT) {
        if (m->storage->bus.fault.status != prior.status ||
            m->storage->bus.fault.owner != prior.owner ||
            m->storage->bus.fault.address != prior.address ||
            m->storage->bus.fault.sample.value != prior.sample.value ||
            m->storage->bus.fault.sample.known_mask != prior.sample.known_mask) {
            m->storage->bus.fault = prior;
            m->reset_phase = SM09_RESET_FAILED;
            return sm09_stop(m, SM08_CLOCK_ABSENT, "RESET_PREFLIGHT_MUTATED_FAULT");
        }
        return status;
    }
    if (status == SM08_OK) status = m->storage->bus.fault.status;
    if (status != SM08_OK) {
        m->reset_phase = SM09_RESET_FAILED;
        return sm09_stop(m, status, "DEVICE_RESET_RECEIVER_FAILED");
    }
    return SM08_OK;
}

Sm08Status sm09_machine_reset_with_devices(Sm09Machine *m, Sm09DeviceResetPort port,
                                           uint32_t hold) {
    Sm08Status status;
    if (!sm09_bound(m) || m->scheduler->advancing != 0u ||
        m->reset_phase == SM09_RESET_RELEASING) return SM08_ARGUMENT;
    if (port.apply == NULL) return SM08_REGISTER;
    if ((m->clock->active != 0u || m->scheduler->poll_valid != 0u ||
         m->storage->bus.instruction_open != 0u) && m->cpu->failure_reason == NULL &&
        m->cpu->stopped == 0u && m->storage->bus.fault.status == SM08_OK) return SM08_ARGUMENT;
    status = sm09_device_reset(m, port, SM09_DEVICE_RESET_PREFLIGHT, hold);
    if (status != SM08_OK) return status;
    status = sm09_machine_cpu_reset_assert(m);
    if (status != SM08_OK) return status;
    status = sm09_device_reset(m, port, SM09_DEVICE_RESET_ASSERT, hold);
    if (status != SM08_OK) return status;
    status = sm09_machine_cpu_reset_hold(m, hold);
    if (status != SM08_OK) return status;
    status = sm09_device_reset(m, port, SM09_DEVICE_RESET_RELEASE, hold);
    if (status != SM08_OK) return status;
    return sm09_machine_cpu_reset_release(m);
}

