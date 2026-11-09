#ifndef SAILOR_MOON_CLOCK_PORT_H
#define SAILOR_MOON_CLOCK_PORT_H

#include "sailor_moon_cpu_io.h"
#include "sailor_moon_timing_plan.h"

/* Receivers of the ONE09 timeline. start_cycle resolves boundary stalls and
 * rendezvous before this CPU cycle; advance places crossed events. Neither
 * callback may manufacture an08 value. Clock-port math pulses belong only to
 * actual CPU cycles, never wall/refresh/transfer advances. */
typedef struct Sm09TimelinePort {
    void *context;
    Sm08Status (*start_cycle)(void *, Sm08Bus *, uint8_t kind,
                              uint32_t address, uint8_t clocks);
    Sm08Status (*advance)(void *, Sm08Bus *, uint8_t clocks);
    Sm08Status (*interrupt_poll)(void *, Sm08Bus *, uint8_t status,
                                 uint32_t context_key);
} Sm09TimelinePort;

typedef struct Sm09Clock {
    Sm08Bus *bus;
    Sm08Math *math;
    Sm09TimelinePort timeline;
    SmScpuState entry;
    SmStaticFetch fetch;
    const Sm09TimingPlan *plan;
    uint32_t context_key, cycles;
    uint8_t expected[4], operands[4];
    uint8_t fetched_mask, pointer_low, pointer_low_valid;
    uint8_t cursor, active, irq_status, irq_status_valid, interrupt_polled;
    uint8_t reset_vector_phase;
    SmScpuState *reset_cpu;
    uint8_t machine_cycle_completed;
} Sm09Clock;

/* Source-normal binding, not power-on, reset, source admission or an epoch/
 * saved-frame history constructor. The caller supplies the existing06 normal
 * activation/frame contract before dispatch; no CPU/context/originalS token
 * or foreign per-address knownness exception is introduced. */
Sm08Status sm09_clock_bind(Sm09Clock *, Sm08Bus *, Sm08Io *, Sm09TimelinePort);
Sm08Clock sm09_clock_port(Sm09Clock *);

typedef enum Sm09MachineCycle {
    SM09_MACHINE_INTERNAL, SM09_MACHINE_FETCH_DISCARD,
    SM09_MACHINE_READ_DISCARD, SM09_MACHINE_READ, SM09_MACHINE_WRITE
} Sm09MachineCycle;

/* Reset/interrupt/wake use this same timed primitive without an instruction
 * plan or instruction poll. Ignored reads retain raw bus effects but never
 * turn unknown data into a CPU execution value. */
Sm08Status sm09_clock_machine_cycle(Sm09Clock *, Sm09MachineCycle,
                                   uint32_t address, uint8_t *byte);
/* Untimed mapped vector sampling followed by root's ONE186-wall interval. */
Sm08Status sm09_clock_reset_vector_begin(Sm09Clock *, SmScpuState *);

#endif
