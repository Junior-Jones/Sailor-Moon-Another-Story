#ifndef SAILOR_MOON_MACHINE_H
#define SAILOR_MOON_MACHINE_H
#include "sailor_moon_scheduler.h"

typedef enum Sm09ResetPhase {
    SM09_RESET_NONE, SM09_RESET_HELD, SM09_RESET_RELEASING, SM09_RESET_FAILED
} Sm09ResetPhase;
enum { SM09_RESET_RELEASE_MASTER_CLOCKS = 186u };

/* A binding of existing owners at stable addresses, never a copied machine. */
typedef struct Sm09Machine {
    Sm08Machine *storage;
    Sm09Scheduler *scheduler;
    Sm09Clock *clock;
    SmScpuState *cpu;
    Sm09ResetPhase reset_phase;
    uint64_t reset_assert_clock, reset_release_clock;
} Sm09Machine;

typedef enum Sm09DeviceResetPhase {
    SM09_DEVICE_RESET_PREFLIGHT, SM09_DEVICE_RESET_ASSERT, SM09_DEVICE_RESET_RELEASE
} Sm09DeviceResetPhase;
typedef struct Sm09DeviceResetPort {
    void *context;
    /* Static assembled10/11/12/15/16 receiver. PREFLIGHT is observational;
     * ASSERT/RELEASE apply its qualified scope/hold policy. No dispatch or
     * time advancement here. Oscillator phase and processor startup differ. */
    Sm08Status (*apply)(void *, Sm08Bus *, const Sm09Scheduler *,
                        Sm09DeviceResetPhase, uint32_t hold_master_clocks);
} Sm09DeviceResetPort;

/* Cold construction preserves caller-supplied unforced CPU registers and
 * uses08's strict unknown storage contract. Required receiver/argument checks
 * and ROM validation precede mutation. Leaves CPU reset HELD, not dispatchable.
 * This is not SRAM reload, saved-state admission, or warm reset. */
Sm08Status sm09_machine_construct(Sm09Machine *, Sm08Machine *, Sm09Scheduler *,
                                  Sm09Clock *, SmScpuState *, const uint8_t *, size_t,
                                  Sm08Ports, Sm08Pins, Sm09Receivers);
/* Low-level conditional source-contract composition; not arbitrary restore. */
Sm08Status sm09_machine_bind(Sm09Machine *, Sm08Machine *, Sm09Scheduler *,
                             Sm09Clock *, SmScpuState *);
SmScpuExecResult sm09_machine_step(Sm09Machine *);
Sm08Status sm09_machine_retire(Sm09Machine *);
Sm08Status sm09_machine_interrupt_entry(Sm09Machine *, uint8_t interrupt);
Sm08Status sm09_machine_cpu_reset_assert(Sm09Machine *);
Sm08Status sm09_machine_cpu_reset_hold(Sm09Machine *, uint32_t master_clocks);
/* Untimed mapped vector then ONE functional186-clock shared wall advance.
 * No physical reset microcycle or SMP architectural startup claim. */
Sm08Status sm09_machine_cpu_reset_release(Sm09Machine *);
Sm08Status sm09_machine_reset_with_devices(Sm09Machine *, Sm09DeviceResetPort,
                                           uint32_t hold_master_clocks);
/* Source set contains no WAI/STP. stopped remains the07 fault stop, not a
 * fabricated waiting state. No dormant opcode or CPU ABI field is admitted. */
#endif

