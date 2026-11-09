#include "../internal/sailor_moon_clock_port.h"
#include <string.h>

static Sm08Status sm09_fail(Sm09Clock *clock, Sm08Status status, uint32_t address) {
    const Sm08Value unknown = {0u, 0u};
    if (clock == NULL || clock->bus == NULL) return SM08_ARGUMENT;
    return sm08_bus_fault(clock->bus, status, 9u, address, unknown);
}

static uint32_t sm09_fetch_address(const Sm09Clock *clock, uint8_t index) {
    return (clock->fetch.fetch_address & 0xFF0000u) |
        ((clock->fetch.fetch_address + index) & 0xFFFFu);
}

static int sm09_live_operand(const Sm09Clock *clock, const Sm09TimingEvent *event) {
    uint32_t address;
    if (event->kind != SM09_TIMING_FETCH || clock->fetch.deferred_operand_count == 0u)
        return 0;
    address = sm09_fetch_address(clock, event->index);
    return address >= clock->fetch.deferred_operand_address &&
        address - clock->fetch.deferred_operand_address < clock->fetch.deferred_operand_count;
}

/* Only captured entry contributors and actual sampled bytes choose a phase.
 * A missing contributor is unresolved, not a zero/no-penalty substitute. */
static int sm09_enabled(const Sm09Clock *clock, uint8_t condition) {
    const Sm09TimingPlan *plan = clock->plan;
    int taken, displacement;
    uint16_t next, target, base, index;
    taken = plan->branch_mask == 0u ||
        (((clock->entry.p & plan->branch_mask) != 0u) == (plan->branch_set != 0u));
    switch (condition) {
        case SM09_TIMING_ALWAYS: return 1;
        case SM09_TIMING_DIRECT_LOW_NONZERO: return (clock->entry.d & 0xFFu) != 0u;
        case SM09_TIMING_BRANCH_TAKEN: return taken;
        case SM09_TIMING_BRANCH_TAKEN_AND_PAGE_CROSSED:
            if (!taken || clock->entry.e == 0u) return 0;
            if ((clock->fetched_mask & 2u) == 0u) return -1;
            displacement = clock->operands[1] < 128u ? (int)clock->operands[1] :
                (int)clock->operands[1] - 256;
            next = (uint16_t)(clock->entry.pc + clock->fetch.fetch_count);
            target = (uint16_t)((int)next + displacement);
            return (next & 0xFF00u) != (target & 0xFF00u);
        case SM09_TIMING_INDEX_PAGE_CROSSED:
            if (plan->page_base_source == SM09_TIMING_PAGE_OPERAND) {
                if ((clock->fetched_mask & 2u) == 0u) return -1;
                base = clock->operands[1];
            } else if (plan->page_base_source == SM09_TIMING_PAGE_POINTER) {
                if (!clock->pointer_low_valid) return -1;
                base = clock->pointer_low;
            } else return -1;
            if (plan->index_register == SM09_TIMING_INDEX_X) index = clock->entry.x;
            else if (plan->index_register == SM09_TIMING_INDEX_Y) index = clock->entry.y;
            else return -1;
            return (uint32_t)base + index > 255u;
        default: return -1;
    }
}

static Sm08Status sm09_advance(Sm09Clock *clock, uint8_t amount) {
    Sm08Status status;
    if (clock->timeline.advance == NULL) return sm09_fail(clock, SM08_CLOCK_ABSENT, 0u);
    status = clock->timeline.advance(clock->timeline.context, clock->bus, amount);
    if (status != SM08_OK) return sm09_fail(clock, status, sm_scpu_address(&clock->entry));
    return clock->bus->fault.status;
}

static int sm09_last_enabled(const Sm09Clock *clock) {
    uint8_t index;
    for (index = (uint8_t)(clock->cursor + 1u); index < clock->plan->event_count; ++index) {
        const Sm09TimingEvent *event = &sm09_timing_events[clock->plan->first_event + index];
        /* Unknown future conditions cannot establish an early last cycle. */
        if (sm09_enabled(clock, event->condition) != 0) return 0;
    }
    return 1;
}

/* Read/internal bytes are output-only. Capture a write before any receiver
 * can act. An elapsed write cycle stays completed even if commit then fails. */
static Sm08Status sm09_cycle(Sm09Clock *clock, uint8_t kind, uint32_t address,
                              uint8_t *byte, uint8_t require_value) {
    Sm08Status status;
    Sm08Value sampled;
    Sm08Value written = {0u, 0xFFu};
    uint8_t clocks = 6u;
    if (clock == NULL || clock->bus == NULL || clock->math == NULL || byte == NULL)
        return SM08_ARGUMENT;
    if (clock->bus->fault.status != SM08_OK) return clock->bus->fault.status;
    if (kind > SM09_TIMING_INTERNAL) return sm09_fail(clock, SM08_ARGUMENT, address);
    if (kind == SM09_TIMING_WRITE) written.value = *byte;
    if (kind != SM09_TIMING_INTERNAL &&
        !sm08_access_period(address, clock->bus->memsel, &clocks))
        return sm09_fail(clock, SM08_ARGUMENT, address);
    if (clocks < 4u || clock->timeline.start_cycle == NULL ||
        clock->timeline.advance == NULL || clock->timeline.interrupt_poll == NULL)
        return sm09_fail(clock, SM08_CLOCK_ABSENT, address);
    status = clock->timeline.start_cycle(clock->timeline.context, clock->bus, kind, address, clocks);
    if (status != SM08_OK) return sm09_fail(clock, status, address);
    if (clock->bus->fault.status != SM08_OK) return clock->bus->fault.status;
    if (clock->active && clock->plan->irq_status_policy != SM09_TIMING_SOFTWARE_BREAK &&
        sm09_last_enabled(clock)) {
        if (clock->interrupt_polled || !clock->irq_status_valid)
            return sm09_fail(clock, SM08_CLOCK_ABSENT, address);
        status = clock->timeline.interrupt_poll(clock->timeline.context, clock->bus,
            clock->irq_status, clock->context_key);
        if (status != SM08_OK) return sm09_fail(clock, status, address);
        if (clock->bus->fault.status != SM08_OK) return clock->bus->fault.status;
        clock->interrupt_polled = 1u;
    }
    if (kind == SM09_TIMING_FETCH || kind == SM09_TIMING_READ) {
        status = sm09_advance(clock, (uint8_t)(clocks - 4u));
        if (status != SM08_OK) return status;
        sm08_math_tick(clock->math);
        status = sm08_bus_sample(clock->bus, address, &sampled);
        if (status != SM08_OK) return sm09_fail(clock, status, address);
        status = sm09_advance(clock, 4u);
        if (status != SM08_OK) return status;
        ++clock->cycles;
        if (require_value) return sm08_bus_known(clock->bus, address, sampled, byte);
        *byte = 0u; /* Ignored read: real effects, no invented execution value. */
        return SM08_OK;
    }
    status = sm09_advance(clock, clocks);
    if (status != SM08_OK) return status;
    sm08_math_tick(clock->math);
    ++clock->cycles;
    if (kind == SM09_TIMING_WRITE) {
        status = sm08_bus_commit(clock->bus, address, written);
        if (status != SM08_OK) return sm09_fail(clock, status, address);
    }
    return clock->bus->fault.status;
}

Sm08Status sm09_clock_machine_cycle(Sm09Clock *clock, Sm09MachineCycle kind,
                                    uint32_t address, uint8_t *byte) {
    uint8_t event_kind, require_value = 1u;
    Sm08Status status;
    if (clock != NULL) clock->machine_cycle_completed = 0u;
    if (clock == NULL || clock->bus == NULL || byte == NULL) return SM08_ARGUMENT;
    if (clock->bus->fault.status != SM08_OK) return clock->bus->fault.status;
    if (clock->active || clock->reset_vector_phase)
        return sm09_fail(clock, SM08_CLOCK_ABSENT, address);
    switch (kind) {
        case SM09_MACHINE_INTERNAL: event_kind = SM09_TIMING_INTERNAL; break;
        case SM09_MACHINE_FETCH_DISCARD: event_kind = SM09_TIMING_FETCH; require_value = 0u; break;
        case SM09_MACHINE_READ_DISCARD: event_kind = SM09_TIMING_READ; require_value = 0u; break;
        case SM09_MACHINE_READ: event_kind = SM09_TIMING_READ; break;
        case SM09_MACHINE_WRITE: event_kind = SM09_TIMING_WRITE; break;
        default: return SM08_ARGUMENT;
    }
    clock->cycles = 0u;
    status = sm09_cycle(clock, event_kind, address, byte, require_value);
    clock->machine_cycle_completed = clock->cycles != 0u;
    return status;
}

static Sm08Status sm09_fetch(Sm09Clock *clock, const Sm09TimingEvent *event, uint8_t *out) {
    uint32_t address = sm09_fetch_address(clock, event->index);
    uint16_t lane = (uint16_t)(address - clock->fetch.guard_address);
    Sm08Status status;
    if (event->index >= clock->fetch.fetch_count || lane >= clock->fetch.guard_count)
        return sm09_fail(clock, SM08_GUARD, address);
    status = sm09_cycle(clock, SM09_TIMING_FETCH, address, out, 1u);
    if (status != SM08_OK) return status;
    if ((clock->fetch.immutable_byte_mask & (1u << lane)) &&
        *out != clock->expected[lane]) return sm09_fail(clock, SM08_GUARD, address);
    clock->operands[event->index] = *out;
    clock->fetched_mask |= (uint8_t)(1u << event->index);
    ++clock->cursor;
    return SM08_OK;
}

static Sm08Status sm09_drain(Sm09Clock *clock) {
    while (clock->cursor < clock->plan->event_count) {
        const Sm09TimingEvent *event = &sm09_timing_events[clock->plan->first_event + clock->cursor];
        uint8_t byte = 0u;
        Sm08Status status;
        int use = sm09_enabled(clock, event->condition);
        if (use < 0) return sm09_fail(clock, SM08_CLOCK_ABSENT, sm_scpu_address(&clock->entry));
        if (!use) { ++clock->cursor; continue; }
        if (event->kind == SM09_TIMING_READ || event->kind == SM09_TIMING_WRITE ||
            sm09_live_operand(clock, event)) return SM08_OK;
        if (event->kind == SM09_TIMING_FETCH) status = sm09_fetch(clock, event, &byte);
        else if (event->kind == SM09_TIMING_INTERNAL) {
            status = sm09_cycle(clock, SM09_TIMING_INTERNAL, sm_scpu_address(&clock->entry), &byte, 1u);
            if (status == SM08_OK) ++clock->cursor;
        } else return sm09_fail(clock, SM08_CLOCK_ABSENT, sm_scpu_address(&clock->entry));
        if (status != SM08_OK) return status;
    }
    return SM08_OK;
}

static Sm08Status sm09_begin(void *context, Sm08Bus *bus, const SmScpuState *cpu,
                              const SmStaticFetch *fetch, const uint8_t *expected) {
    Sm09Clock *clock = context;
    const Sm09TimingPlan *plan;
    if (clock == NULL || bus == NULL || clock->bus != bus || cpu == NULL ||
        fetch == NULL || expected == NULL) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    /* The private bus guard receives the descriptor produced by
       sm_scpu_guard_code and calls this owner directly.  Do not repeat the
       same generated registry search for a third time. */
    if (clock->active || clock->reset_vector_phase || fetch->guard_count == 0u ||
        fetch->guard_count > 4u)
        return sm09_fail(clock, SM08_GUARD, sm_scpu_address(cpu));
    plan = sm09_timing_plan_lookup(sm_scpu_context_key(cpu));
    if (plan == NULL || plan->fetch_count == 0u || plan->fetch_count > 4u ||
        plan->fetch_count != fetch->fetch_count ||
        plan->deferred_operand_count != fetch->deferred_operand_count ||
        (size_t)plan->first_event + plan->event_count > sm09_timing_event_count ||
        plan->irq_status_policy > SM09_TIMING_SOFTWARE_BREAK)
        return sm09_fail(clock, SM08_CLOCK_ABSENT, sm_scpu_address(cpu));
    clock->entry = *cpu;
    clock->fetch = *fetch;
    clock->plan = plan;
    clock->context_key = sm_scpu_context_key(cpu);
    memcpy(clock->expected, expected, fetch->guard_count);
    memset(clock->operands, 0, sizeof(clock->operands));
    clock->fetched_mask = 0u;
    clock->pointer_low_valid = 0u;
    clock->cycles = 0u;
    clock->cursor = 0u;
    clock->irq_status = cpu->p;
    clock->irq_status_valid = plan->irq_status_policy != SM09_TIMING_RTI_STACK_P;
    clock->interrupt_polled = 0u;
    clock->active = 1u;
    return sm09_drain(clock);
}

static Sm08Status sm09_access(void *context, Sm08Bus *bus, const SmScpuState *cpu,
                               uint32_t address, uint8_t kind, uint8_t *byte) {
    Sm09Clock *clock = context;
    const Sm09TimingEvent *event;
    Sm08Status status;
    if (clock == NULL || bus == NULL || clock->bus != bus || cpu == NULL || byte == NULL)
        return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (!clock->active) return sm09_fail(clock, SM08_CLOCK_ABSENT, address);
    status = sm09_drain(clock);
    if (status != SM08_OK) return status;
    if (clock->cursor >= clock->plan->event_count)
        return sm09_fail(clock, SM08_CLOCK_ABSENT, address);
    event = &sm09_timing_events[clock->plan->first_event + clock->cursor];
    if (sm09_live_operand(clock, event)) {
        if (kind != SM09_TIMING_READ || address != sm09_fetch_address(clock, event->index))
            return sm09_fail(clock, SM08_CLOCK_ABSENT, address);
        return sm09_fetch(clock, event, byte);
    }
    if (event->kind != kind) return sm09_fail(clock, SM08_CLOCK_ABSENT, address);
    status = sm09_cycle(clock, kind, address, byte, 1u);
    if (status != SM08_OK) return status;
    if (kind == SM09_TIMING_READ && event->role == SM09_TIMING_POINTER && event->index == 0u) {
        clock->pointer_low = *byte;
        clock->pointer_low_valid = 1u;
    }
    if (kind == SM09_TIMING_READ && event->role == SM09_TIMING_STACK_STATUS && event->index == 0u &&
        clock->plan->irq_status_policy == SM09_TIMING_RTI_STACK_P) {
        clock->irq_status = *byte;
        clock->irq_status_valid = 1u;
    }
    ++clock->cursor;
    return SM08_OK;
}

static Sm08Status sm09_read(void *context, Sm08Bus *bus, const SmScpuState *cpu,
                             uint32_t address, uint8_t *byte) {
    return sm09_access(context, bus, cpu, address, SM09_TIMING_READ, byte);
}
static Sm08Status sm09_write(void *context, Sm08Bus *bus, const SmScpuState *cpu,
                              uint32_t address, uint8_t byte) {
    return sm09_access(context, bus, cpu, address, SM09_TIMING_WRITE, &byte);
}

static Sm08Status sm09_finish(void *context, Sm08Bus *bus, const SmScpuState *cpu,
                               uint32_t declared_cycles) {
    Sm09Clock *clock = context;
    Sm08Status status;
    if (clock == NULL || bus == NULL || clock->bus != bus || cpu == NULL) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (!clock->active) return sm09_fail(clock, SM08_CLOCK_ABSENT, sm_scpu_address(cpu));
    status = sm09_drain(clock);
    if (status != SM08_OK) return status;
    if (clock->cursor != clock->plan->event_count || clock->cycles != declared_cycles ||
        clock->fetched_mask != (uint8_t)((1u << clock->plan->fetch_count) - 1u) ||
        (clock->plan->irq_status_policy != SM09_TIMING_SOFTWARE_BREAK && !clock->interrupt_polled) ||
        (clock->plan->irq_status_policy == SM09_TIMING_SOFTWARE_BREAK && clock->interrupt_polled) ||
        UINT64_MAX - cpu->completed_cycles < declared_cycles)
        return sm09_fail(clock, SM08_CLOCK_ABSENT, sm_scpu_address(cpu));
    clock->active = 0u;
    return SM08_OK;
}

Sm08Status sm09_clock_bind(Sm09Clock *clock, Sm08Bus *bus, Sm08Io *io,
                            Sm09TimelinePort timeline) {
    Sm08Device device;
    if (clock == NULL || bus == NULL || io == NULL || io->bus != bus ||
        timeline.start_cycle == NULL || timeline.advance == NULL || timeline.interrupt_poll == NULL)
        return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    device = sm08_io_device(io);
    if (bus->ports.cpu_io.context != io || bus->ports.cpu_io.read != device.read ||
        bus->ports.cpu_io.write != device.write) return SM08_ARGUMENT;
    memset(clock, 0, sizeof(*clock));
    clock->bus = bus;
    clock->math = &io->math;
    clock->timeline = timeline;
    return SM08_OK;
}

Sm08Status sm09_clock_reset_vector_begin(Sm09Clock *clock, SmScpuState *cpu) {
    if (clock == NULL || clock->bus == NULL || cpu == NULL) return SM08_ARGUMENT;
    if (clock->bus->fault.status != SM08_OK) return clock->bus->fault.status;
    if (clock->active || clock->reset_vector_phase)
        return sm09_fail(clock, SM08_CLOCK_ABSENT, 0xFFFCu);
    clock->reset_cpu = cpu;
    clock->reset_vector_phase = 1u;
    return SM08_OK;
}

static Sm08Status sm09_reset_read(void *context, Sm08Bus *bus, uint32_t address, uint8_t *byte) {
    Sm09Clock *clock = context;
    Sm08Value sampled;
    Sm08Status status;
    if (clock == NULL || bus == NULL || clock->bus != bus || byte == NULL) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (clock->reset_cpu == NULL ||
        (clock->reset_vector_phase == 1u ? address != 0xFFFCu :
         clock->reset_vector_phase == 2u ? address != 0xFFFDu : 1))
        return sm09_fail(clock, SM08_CLOCK_ABSENT, address);
    status = sm08_bus_sample(bus, address, &sampled);
    if (status == SM08_OK) status = sm08_bus_known(bus, address, sampled, byte);
    if (status != SM08_OK) return status;
    if (clock->reset_vector_phase == 1u) clock->reset_vector_phase = 2u;
    else { clock->reset_vector_phase = 0u; clock->reset_cpu = NULL; }
    return SM08_OK;
}

Sm08Clock sm09_clock_port(Sm09Clock *clock) {
    Sm08Clock port = {clock, sm09_begin, sm09_read, sm09_write, sm09_finish, sm09_reset_read};
    return port;
}
