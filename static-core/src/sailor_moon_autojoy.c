#include "sailor_moon_scheduler.h"

Sm08Status sm09_scheduler_autojoy_bind(Sm09Scheduler *s, Sm09AutoJoyPort port) {
    if (s == NULL || s->bus == NULL || s->advancing != 0u || s->autojoy_active != 0u ||
        port.phase == NULL || port.abort == NULL) return SM08_ARGUMENT;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    s->autojoy = port;
    return SM08_OK;
}

Sm08Status sm09_scheduler_autojoy_abort(Sm09Scheduler *s) {
    Sm08Status status;
    if (s == NULL || s->bus == NULL) return SM08_ARGUMENT;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    if (s->autojoy_active == 0u) return SM08_OK;
    if (s->autojoy_effects != 0u) {
        if (s->autojoy.abort == NULL) return sm09_scheduler_fault(s, SM08_INPUT_ABSENT, 15u);
        status = s->autojoy.abort(s->autojoy.context, s->bus, s->master_clock);
        if (status != SM08_OK) return sm09_scheduler_fault(s, status, 15u);
        if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    }
    s->autojoy_active = 0u; s->autojoy_busy = 0u; s->autojoy_effects = 0u;
    return SM08_OK;
}

/* Selected phase0 is the latch opportunity, phase1 samples busy/enable,
 * phase2 releases latch,3..33 serial control,34 completes.15 owns pin data.
 * Global latch residue126 makes the first cold busy window H298, matching
 * the own profile; later windows preserve this256-clock phase. */
Sm08Status sm09_scheduler_autojoy_tick(Sm09Scheduler *s) {
    uint8_t step, enabled;
    Sm08Status status;
    if (s == NULL || s->bus == NULL) return SM08_ARGUMENT;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    if (s->autojoy_active == 0u) {
        if (s->autojoy_field_claimed != 0u || s->scanline != (s->overscan != 0u ? 240u : 225u) ||
            s->hclock < 2u || s->hclock > 254u ||
            ((s->master_clock - s->autojoy_phase_origin) & 255u) != 126u) return SM08_OK;
        if (s->master_clock > UINT64_MAX - 4352u)
            return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
        s->autojoy_field_claimed = 1u; s->autojoy_active = 1u;
        s->autojoy_start_clock = s->master_clock; s->autojoy_next_clock = s->master_clock;
        s->autojoy_step = 0u; s->autojoy_effects = 0u;
    }
    if (s->master_clock < s->autojoy_next_clock) return SM08_OK;
    if (s->master_clock != s->autojoy_next_clock)
        return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
    enabled = s->nmitimen & 1u;
    step = s->autojoy_step;
    if (step != 0u && enabled == 0u) return sm09_scheduler_autojoy_abort(s);
    s->autojoy_last_clock = s->master_clock;
    if (step == 1u) s->autojoy_busy = 1u;
    if (enabled != 0u || s->autojoy_effects != 0u) {
        if (s->autojoy.phase == NULL || s->autojoy.abort == NULL)
            return sm09_scheduler_fault(s, SM08_INPUT_ABSENT, 15u);
        s->autojoy_effects = 1u;
        status = s->autojoy.phase(s->autojoy.context, s->bus, s->master_clock, step, enabled);
        if (status != SM08_OK) return sm09_scheduler_fault(s, status, 15u);
        if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    }
    if (step == 34u) {
        s->autojoy_active = 0u; s->autojoy_busy = 0u; s->autojoy_effects = 0u;
    } else {
        s->autojoy_step = (uint8_t)(step + 1u);
        s->autojoy_next_clock += 128u;
    }
    return SM08_OK;
}
