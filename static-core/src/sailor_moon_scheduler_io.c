#include "sailor_moon_scheduler.h"

void sm09_scheduler_update_nmi_line(Sm09Scheduler *s) {
    uint8_t next = (uint8_t)(s->nmi_flag != 0u && (s->nmitimen & 0x80u) != 0u);
    if (next != 0u && s->nmi_line == 0u) s->nmi_edge_latched = 1u;
    s->nmi_line = next;
}

Sm08Status sm09_scheduler_irq_match(const Sm09Scheduler *s, uint8_t *match) {
    uint8_t mode;
    if (s == NULL || match == NULL) return SM08_ARGUMENT;
    mode = (uint8_t)((s->nmitimen >> 4u) & 3u);
    *match = 0u;
    if (mode == 0u) return SM08_OK;
    if ((mode & 2u) != 0u) {
        if (s->vtime_known != 0x1FFu) return SM08_UNKNOWN;
        if (s->irq_vcounter != s->vtime) return SM08_OK;
    }
    if ((mode & 1u) != 0u) {
        if (s->htime_known != 0x1FFu) return SM08_UNKNOWN;
        if (s->irq_hcounter != s->htime) return SM08_OK;
    }
    *match = 1u;
    return SM08_OK;
}

static Sm08Status sm09_compare(Sm09Scheduler *s) {
    uint8_t match;
    Sm08Status status = sm09_scheduler_irq_match(s, &match);
    if (status != SM08_OK) return status;
    if (s->irq_level == 0u && match != 0u)
        s->irq_wait_ticks = (uint8_t)((s->nmitimen & 0x10u) != 0u && s->hclock == 6u ? 3u : 2u);
    s->irq_level = match;
    return SM08_OK;
}

Sm08Status sm09_scheduler_irq_tick(Sm09Scheduler *s) {
    Sm08Status status;
    if (s == NULL || s->bus == NULL) return SM08_ARGUMENT;
    if ((s->hclock & 3u) != 2u ||
        (s->irq_phase_valid != 0u && s->irq_phase_clock == s->master_clock)) return SM08_OK;
    s->irq_phase_valid = 1u; s->irq_phase_clock = s->master_clock;
    if (s->irq_wait_ticks != 0u) {
        --s->irq_wait_ticks;
        if (s->irq_wait_ticks == 1u) {
            s->irq_flag = 1u; s->irq_flag_known = 1u; s->irq_assert_clock = s->master_clock;
        } else if (s->irq_wait_ticks == 0u) {
            s->irq_line = s->irq_flag;
            if (s->irq_line != 0u) {
                status = s->receivers.raster_event(s->receivers.context, s->bus, s, SM09_RASTER_IRQ_ASSERT);
                if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
                if (status != SM08_OK) return status;
            }
        }
    }
    if (s->hclock > 10u) s->irq_hcounter = (uint16_t)((s->irq_hcounter + 1u) & 0x1FFu);
    else if (s->hclock == 10u) s->irq_hcounter = 0u;
    else if (s->hclock == 6u) {
        s->irq_hcounter = 0u;
        if (s->scanline != 0u) s->irq_vcounter = (uint16_t)((s->irq_vcounter + 1u) & 0x1FFu);
    } else {
        s->irq_hcounter = (uint16_t)((s->irq_hcounter + 1u) & 0x1FFu);
        if (s->scanline == 0u) s->irq_vcounter = 0u;
    }
    return sm09_compare(s);
}

static Sm08Status sm09_register_read(void *context, uint16_t reg, Sm08Drive *out) {
    Sm09Scheduler *s = context;
    if (s == NULL || s->bus == NULL || out == NULL) return SM08_ARGUMENT;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    out->value = 0u; out->driven_mask = 0u; out->known_mask = 0u;
    switch (reg) {
        case 0x4210u:
            out->value = (uint8_t)((s->nmi_flag != 0u ? 0x80u : 0u) | 2u);
            out->driven_mask = 0x8Fu; out->known_mask = 0x8Fu;
            if (s->scanline != (s->overscan != 0u ? 240u : 225u) || s->hclock >= 6u) {
                s->nmi_flag = 0u; sm09_scheduler_update_nmi_line(s);
            }
            return SM08_OK;
        case 0x4211u:
            out->value = (uint8_t)(s->irq_flag_known != 0u && s->irq_flag != 0u ? 0x80u : 0u);
            out->driven_mask = 0x80u; out->known_mask = s->irq_flag_known != 0u ? 0x80u : 0u;
            if (s->irq_wait_ticks == 0u) {
                s->irq_flag = 0u; s->irq_flag_known = 1u; s->irq_line = 0u;
            }
            return SM08_OK;
        case 0x4212u:
            out->value = (uint8_t)((s->vblank != 0u ? 0x80u : 0u) |
                (s->hblank != 0u ? 0x40u : 0u) | (s->autojoy_busy != 0u ? 1u : 0u));
            out->driven_mask = 0xC1u; out->known_mask = 0xC1u;
            return SM08_OK;
        case 0x4200u: case 0x4207u: case 0x4208u: case 0x4209u: case 0x420Au: return SM08_OK;
        default: return SM08_REGISTER;
    }
}

static Sm08Status sm09_register_write(void *context, uint16_t reg, Sm08Value value) {
    Sm09Scheduler *s = context;
    uint8_t mask, previous;
    if (s == NULL || s->bus == NULL) return SM08_ARGUMENT;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    if (reg >= 0x4210u && reg <= 0x4212u) return SM08_OK;
    if (reg != 0x4200u && (reg < 0x4207u || reg > 0x420Au)) return SM08_REGISTER;
    mask = reg == 0x4200u ? 0xB1u : (reg == 0x4208u || reg == 0x420Au ? 1u : 0xFFu);
    if ((value.known_mask & mask) != mask) return SM08_UNKNOWN;
    switch (reg) {
        case 0x4200u:
            previous = s->nmitimen;
            s->nmitimen = value.value & 0xB1u;
            if ((s->nmitimen & 0x30u) == 0u) {
                s->irq_flag = 0u; s->irq_flag_known = 1u; s->irq_line = 0u;
                s->irq_level = 0u; s->irq_wait_ticks = 0u;
            }
            if ((previous & 0x80u) == 0u || (s->nmitimen & 0x80u) == 0u)
                sm09_scheduler_update_nmi_line(s);
            break;
        case 0x4207u:
            s->htime = (uint16_t)((s->htime & 0x100u) | value.value); s->htime_known |= 0xFFu; break;
        case 0x4208u:
            s->htime = (uint16_t)((s->htime & 0xFFu) | ((uint16_t)(value.value & 1u) << 8u));
            s->htime_known |= 0x100u; break;
        case 0x4209u:
            s->vtime = (uint16_t)((s->vtime & 0x100u) | value.value); s->vtime_known |= 0xFFu; break;
        case 0x420Au:
            s->vtime = (uint16_t)((s->vtime & 0xFFu) | ((uint16_t)(value.value & 1u) << 8u));
            s->vtime_known |= 0x100u; break;
        default: return SM08_REGISTER;
    }
    return sm09_compare(s);
}

Sm08Device sm09_scheduler_register_port(Sm09Scheduler *s) {
    Sm08Device device = {s, sm09_register_read, sm09_register_write};
    return device;
}

Sm08Status sm09_scheduler_take_interrupt(Sm09Scheduler *s, uint8_t *interrupt) {
    if (s == NULL || s->bus == NULL || interrupt == NULL) return SM08_ARGUMENT;
    if (s->bus->fault.status != SM08_OK) return s->bus->fault.status;
    if (s->poll_valid == 0u) return SM08_CLOCK_ABSENT;
    *interrupt = s->polled_interrupt;
    if (*interrupt == 1u) s->nmi_pending = 0u;
    s->poll_valid = 0u; s->polled_interrupt = 0u;
    return SM08_OK;
}
