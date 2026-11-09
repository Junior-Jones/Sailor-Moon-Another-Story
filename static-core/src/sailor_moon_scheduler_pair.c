#include "sailor_moon_scheduler.h"
#include <string.h>

Sm08Status sm09_scheduler_fault(Sm09Scheduler *s, Sm08Status status, unsigned owner) {
    Sm08Value sample = {0u, 0u};
    if (s == NULL || s->bus == NULL) return SM08_ARGUMENT;
    return sm08_bus_fault(s->bus, status, owner, 0u, sample);
}

uint16_t sm09_scheduler_line_clocks(const Sm09Scheduler *s) {
    if (s == NULL) return 0u;
    return s->interlace == 0u && s->field != 0u && s->scanline == 240u ?
        SM09_SHORT_LINE : SM09_NORMAL_LINE;
}

uint16_t sm09_scheduler_dot(const Sm09Scheduler *s) {
    uint16_t h;
    if (s == NULL) return 0u;
    h = s->hclock;
    if (sm09_scheduler_line_clocks(s) == SM09_SHORT_LINE) return (uint16_t)(h / 4u);
    if (h < 1292u) return (uint16_t)(h / 4u);
    if (h < 1298u) return 323u;
    if (h < 1310u) return (uint16_t)((h - 2u) / 4u);
    if (h < 1316u) return 327u;
    return (uint16_t)((h - 4u) / 4u);
}

static uint16_t sm09_refresh_at(const Sm09Scheduler *s) {
    uint8_t distance = (uint8_t)((10u - ((s->master_clock - s->hclock) & 7u)) & 7u);
    return (uint16_t)(distance > 4u ? 528u + distance : 536u + distance);
}

static Sm08Status sm09_emit(Sm09Scheduler *s, Sm09RasterEvent event) {
    Sm08Status status = s->receivers.raster_event(s->receivers.context, s->bus, s, event);
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    return status == SM08_OK ? status : sm09_scheduler_fault(s, status, 9u);
}

/* Every event is marked before its receiver: a failure never retries elapsed
 * clocks or earlier partial effects. IRQ comparison follows raster effects. */
static Sm08Status sm09_due(Sm09Scheduler *s) {
    unsigned event;
    Sm08Status status;
    const uint16_t hclock = s->hclock;
    /* Own switch-derived candidate set: every possible raster boundary,
     * including all eight refresh/HDMA-init origin residues. This skips only
     * an impossible scan; every guest clock still reaches the same owners. */
    if (!(hclock == 0u || hclock == 2u || hclock == 4u || hclock == 6u ||
          (hclock >= 12u && hclock <= 19u) ||
          (hclock >= 533u && hclock <= 540u) ||
          (hclock >= 573u && hclock <= 580u) ||
          hclock == 1096u || hclock == 1104u)) goto peripheral_ticks;
    for (event = 0u; event <= SM09_RASTER_HDMA_LINE_REQUEST; ++event) {
        uint16_t at = 0u;
        uint16_t bit = (uint16_t)(1u << event);
        uint16_t blank = s->overscan != 0u ? 240u : 225u;
        uint8_t applies = 1u;
        if ((s->processed_events & bit) != 0u) continue;
        switch ((Sm09RasterEvent)event) {
            case SM09_RASTER_LINE_BEGIN: break;
            case SM09_RASTER_FIELD_TOGGLE: at = 4u; applies = s->scanline == 0u; break;
            case SM09_RASTER_HBLANK_BEGIN: at = 1096u; break;
            case SM09_RASTER_HBLANK_END: at = 4u; break;
            case SM09_RASTER_VBLANK_BEGIN: applies = s->scanline == blank; break;
            case SM09_RASTER_VBLANK_END: applies = s->scanline == 0u; break;
            case SM09_RASTER_NMI_FLAG_SET: at = 2u; applies = s->scanline == blank; break;
            case SM09_RASTER_NMI_FLAG_CLEAR: at = 2u; applies = s->scanline == 0u; break;
            case SM09_RASTER_NMI_ASSERT: at = 6u; applies = s->scanline == blank; break;
            case SM09_RASTER_REFRESH_BEGIN: at = sm09_refresh_at(s); break;
            case SM09_RASTER_REFRESH_END: at = (uint16_t)(sm09_refresh_at(s) + 40u); break;
            case SM09_RASTER_IRQ_ASSERT: applies = 0u; break;
            case SM09_RASTER_HDMA_INIT_REQUEST:
                at = (uint16_t)(12u + ((s->master_clock - s->hclock) & 7u));
                applies = s->scanline == 0u; break;
            case SM09_RASTER_HDMA_LINE_REQUEST: at = 1104u; applies = s->scanline < blank; break;
        }
        if (applies == 0u || s->hclock != at) continue;
        s->processed_events |= bit;
        switch ((Sm09RasterEvent)event) {
            case SM09_RASTER_FIELD_TOGGLE: s->field ^= 1u; break;
            case SM09_RASTER_HBLANK_BEGIN: s->hblank = 1u; break;
            case SM09_RASTER_HBLANK_END: s->hblank = 0u; break;
            case SM09_RASTER_VBLANK_BEGIN: s->vblank = 1u; break;
            case SM09_RASTER_VBLANK_END: s->vblank = 0u; s->autojoy_field_claimed = 0u; break;
            case SM09_RASTER_NMI_FLAG_SET: s->nmi_flag = 1u; break;
            case SM09_RASTER_NMI_FLAG_CLEAR:
                s->nmi_flag = 0u; sm09_scheduler_update_nmi_line(s); break;
            case SM09_RASTER_NMI_ASSERT:
                if ((s->nmitimen & 0x80u) != 0u && s->nmi_line == 0u) {
                    s->nmi_line = 1u; s->nmi_edge_latched = 1u;
                }
                break;
            case SM09_RASTER_REFRESH_BEGIN: s->refreshing = 1u; break;
            case SM09_RASTER_REFRESH_END: s->refreshing = 0u; break;
            default: break;
        }
        status = sm09_emit(s, (Sm09RasterEvent)event);
        if (status != SM08_OK) return status;
    }
peripheral_ticks:
    /* The following are the exact immediate-OK predicates in the existing
     * owners. Read them after raster callbacks, preserving same-time changes.
     * Active overdue autojoy still calls its owner and retains its fault. */
    if ((s->hclock & 3u) == 2u &&
        (s->irq_phase_valid == 0u || s->irq_phase_clock != s->master_clock)) {
        status = sm09_scheduler_irq_tick(s);
        if (status != SM08_OK) return sm09_scheduler_fault(s, status, 9u);
    }
    if ((s->autojoy_active != 0u && s->master_clock >= s->autojoy_next_clock) ||
        (s->autojoy_active == 0u && s->autojoy_field_claimed == 0u &&
         s->scanline == (s->overscan != 0u ? 240u : 225u) &&
         s->hclock >= 2u && s->hclock <= 254u &&
         ((s->master_clock - s->autojoy_phase_origin) & 255u) == 126u))
        return sm09_scheduler_autojoy_tick(s);
    return SM08_OK;
}

/* Combine only when the first boundary cannot expose any owner effect.
 * The own join stores whole cycles plus a remainder. Its derived half-phase
 * remainder is checked too, so no independent half transition is deferred. */
static unsigned sm09_wall_span(const Sm09Scheduler *s, uint32_t remaining) {
    uint32_t half_remainder;
    uint16_t first_hclock;
    uint64_t first_master;
    if (remaining < 2u || (s->hclock & 1u) != 0u ||
        ((s->master_clock - s->hclock) & 1u) != 0u ||
        (s->autojoy_phase_origin & 1u) != 0u ||
        s->master_clock < s->hclock ||
        s->master_clock > UINT64_MAX - 2u ||
        s->completed_fields == UINT64_MAX ||
        s->smp.target_cycles == UINT64_MAX ||
        s->smp.remainder >= SM09_SMP_DENOMINATOR ||
        s->hclock >= sm09_scheduler_line_clocks(s)) return 1u;
    first_hclock = (uint16_t)(s->hclock + 1u);
    first_master = s->master_clock + 1u;
    /* Conservatively retain every possible first-clock raster candidate,
     * including odd refresh/HDMA-origin residues, even if not applicable on
     * this particular line. Line rollover must also use the original path. */
    if (first_hclock >= sm09_scheduler_line_clocks(s) ||
        first_hclock == 0u || first_hclock == 2u || first_hclock == 4u || first_hclock == 6u ||
        (first_hclock >= 12u && first_hclock <= 19u) ||
        (first_hclock >= 533u && first_hclock <= 540u) ||
        (first_hclock >= 573u && first_hclock <= 580u) ||
        first_hclock == 1096u || first_hclock == 1104u ||
        (first_hclock & 3u) == 2u ||
        (s->autojoy_active != 0u && s->autojoy_next_clock <= first_master) ||
        (s->autojoy_active == 0u && s->autojoy_field_claimed == 0u &&
         s->scanline == (s->overscan != 0u ? 240u : 225u) &&
         first_hclock >= 2u && first_hclock <= 254u &&
         ((first_master - s->autojoy_phase_origin) & 255u) == 126u)) return 1u;
    /* floor(2*(C+r/D)) = 2*C+floor(2*r/D). Therefore the phase
     * residual is (2*r)%D. D and 2*N are the existing own profile constants,
     * not an imported oscillator or a new retained scheduler field. */
    half_remainder = 2u * s->smp.remainder;
    if (half_remainder >= SM09_SMP_DENOMINATOR) half_remainder -= SM09_SMP_DENOMINATOR;
    if (half_remainder + 2u * SM09_SMP_NUMERATOR >= SM09_SMP_DENOMINATOR) return 1u;
    return 2u;
}

/* One original clock, or an inert-first pair. Independent progress is still
 * delivered before ordered raster/IRQ/autojoy and the caller's bus effect. */
static Sm08Status sm09_master_span(Sm09Scheduler *s, unsigned clocks) {
    Sm09SmpJoin next = s->smp;
    Sm08Status status;
    uint16_t length = sm09_scheduler_line_clocks(s);
    uint16_t lines;
    if (s->master_clock > UINT64_MAX - clocks || sm09_smp_advance(&next, clocks) == 0)
        return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
    s->master_clock += clocks;
    s->hclock = (uint16_t)(s->hclock + clocks);
    if (s->hclock == length) {
        s->previous_line_clocks = length;
        s->hclock = 0u; s->processed_events = 0u; ++s->scanline;
        lines = (uint16_t)(SM09_FIELD_LINES + (s->interlace != 0u && s->field == 0u ? 1u : 0u));
        if (s->scanline == lines) {
            if (s->completed_fields == UINT64_MAX)
                return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
            s->scanline = 0u; ++s->completed_fields;
        }
    }
    if (next.target_cycles != s->smp.target_cycles) {
        s->smp = next;
        status = s->receivers.smp_sync(s->receivers.context, s->bus, next.target_cycles);
        if (status != SM08_OK) return sm09_scheduler_fault(s, status, 12u);
    } else s->smp = next;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    return sm09_due(s);
}

static Sm08Status sm09_prepare(Sm09Scheduler *s) {
    Sm08Status status;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    if (s->advancing != 0u) return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
    s->advancing = 1u;
    if (s->smp_started == 0u) {
        status = s->receivers.smp_sync(s->receivers.context, s->bus, s->smp.target_cycles);
        if (status != SM08_OK) return sm09_scheduler_fault(s, status, 12u);
        if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
        s->smp_started = 1u;
    }
    return sm09_due(s);
}

static Sm08Status sm09_drain_refresh(Sm09Scheduler *s) {
    Sm08Status status;
    while (s->refreshing != 0u) {
        status = sm09_master_span(s, sm09_wall_span(s, 2u));
        if (status != SM08_OK) return status;
    }
    return SM08_OK;
}

Sm08Status sm09_scheduler_advance_wall(Sm09Scheduler *s, uint32_t clocks) {
    Sm08Status status;
    uint32_t elapsed;
    if (s == NULL || s->bus == NULL) return SM08_ARGUMENT;
    if (s->advancing != 0u) return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
    status = sm09_prepare(s);
    for (elapsed = 0u; elapsed < clocks && status == SM08_OK;) {
        unsigned span = sm09_wall_span(s, clocks - elapsed);
        status = sm09_master_span(s, span);
        elapsed += span;
    }
    s->advancing = 0u;
    return status;
}

static Sm08Status sm09_advance_cpu(void *context, Sm08Bus *bus, uint8_t clocks) {
    Sm09Scheduler *s = context;
    Sm08Status status;
    unsigned elapsed;
    if (s == NULL || bus == NULL || s->bus != bus) return SM08_ARGUMENT;
    if (s->advancing != 0u) return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
    status = sm09_prepare(s);
    for (elapsed = 0u; elapsed < clocks && status == SM08_OK;) {
        status = sm09_drain_refresh(s);
        if (status == SM08_OK) {
            unsigned span = sm09_wall_span(s, (uint32_t)clocks - elapsed);
            status = sm09_master_span(s, span);
            elapsed += span;
        }
    }
    if (status == SM08_OK) status = sm09_drain_refresh(s);
    s->advancing = 0u;
    return status;
}

static Sm08Status sm09_start_cycle(void *context, Sm08Bus *bus, uint8_t kind,
                                  uint32_t address, uint8_t clocks) {
    Sm09Scheduler *s = context;
    Sm08Status status = sm09_advance_cpu(context, bus, 0u);
    if (status != SM08_OK) return status;
    s->advancing = 1u; s->transfer_boundary = 1u;
    status = s->receivers.cpu_boundary(s->receivers.context, bus, s, kind, address, clocks);
    s->transfer_boundary = 0u; s->advancing = 0u;
    if (status != SM08_OK) return sm09_scheduler_fault(s, status, 10u);
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (s->nmi_edge_latched != 0u) { s->nmi_pending = 1u; s->nmi_edge_latched = 0u; }
    return SM08_OK;
}

Sm08Status sm09_scheduler_transfer_advance(Sm09Scheduler *s, uint32_t clocks) {
    Sm08Status status = SM08_OK;
    uint32_t elapsed;
    if (s == NULL || s->bus == NULL) return SM08_ARGUMENT;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    if (s->advancing == 0u || s->transfer_boundary == 0u || s->transfer_advancing != 0u)
        return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
    s->transfer_advancing = 1u;
    for (elapsed = 0u; elapsed < clocks && status == SM08_OK;) {
        status = sm09_drain_refresh(s);
        if (status == SM08_OK) {
            unsigned span = sm09_wall_span(s, (uint32_t)clocks - elapsed);
            status = sm09_master_span(s, span);
            elapsed += span;
        }
    }
    if (status == SM08_OK) status = sm09_drain_refresh(s);
    s->transfer_advancing = 0u;
    return status;
}

static Sm08Status sm09_interrupt_poll(void *context, Sm08Bus *bus, uint8_t status, uint32_t key) {
    Sm09Scheduler *s = context;
    if (s == NULL || bus == NULL || s->bus != bus) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (s->poll_valid != 0u) return sm09_scheduler_fault(s, SM08_CLOCK_ABSENT, 9u);
    s->polled_interrupt = s->nmi_pending != 0u ? 1u :
        ((s->irq_line != 0u || s->external_irq != 0u) && (status & SM_P_I) == 0u ? 2u : 0u);
    s->poll_context_key = key; s->poll_valid = 1u;
    return SM08_OK;
}

Sm09TimelinePort sm09_scheduler_timeline(Sm09Scheduler *s) {
    Sm09TimelinePort port = {s, sm09_start_cycle, sm09_advance_cpu, sm09_interrupt_poll};
    return port;
}

Sm08Status sm09_scheduler_cold(Sm09Scheduler *s, Sm08Bus *bus, Sm09Receivers receivers) {
    if (s == NULL || bus == NULL || receivers.smp_sync == NULL ||
        receivers.raster_event == NULL || receivers.cpu_boundary == NULL) return SM08_ARGUMENT;
    memset(s, 0, sizeof(*s));
    s->bus = bus; s->receivers = receivers; s->hblank = 1u;
    s->previous_line_clocks = SM09_NORMAL_LINE;
    /* Timer hardware initialization; warm CPU reset preserves these words. */
    s->htime = 0x1FFu; s->vtime = 0x1FFu;
    s->htime_known = 0x1FFu; s->vtime_known = 0x1FFu; s->irq_flag_known = 1u;
    sm09_smp_cold(&s->smp);
    return SM08_OK;
}

Sm08Status sm09_scheduler_reset_cpu_latches(Sm09Scheduler *s) {
    Sm08Status status;
    if (s == NULL || s->bus == NULL) return SM08_ARGUMENT;
    status = sm09_scheduler_autojoy_abort(s);
    if (status != SM08_OK) return status;
    s->nmitimen = 0u; s->nmi_flag = 0u; s->nmi_line = 0u;
    s->nmi_edge_latched = 0u; s->nmi_pending = 0u;
    s->irq_flag = 0u; s->irq_flag_known = 1u; s->irq_line = 0u;
    s->irq_level = 0u; s->irq_wait_ticks = 0u;
    s->autojoy_busy = 0u; s->poll_valid = 0u; s->polled_interrupt = 0u;
    return SM08_OK;
}
