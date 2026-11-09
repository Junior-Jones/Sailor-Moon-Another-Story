#include "../internal/sailor_moon_dma.h"
#include <string.h>

static int sm10_bound(const Sm10Dma *d) {
    return d != NULL && d->bus != NULL && d->scheduler != NULL &&
        d->scheduler->bus == d->bus;
}

static Sm08Status sm10_fault(Sm10Dma *d, Sm08Status status,
                             uint32_t address, Sm08Value sample) {
    return sm08_bus_fault(d->bus, status, 10u, address, sample);
}

static uint16_t sm10_word(const Sm10Channel *c, unsigned lane) {
    return (uint16_t)(c->registers[lane].value |
        ((uint16_t)c->registers[lane + 1u].value << 8u));
}

static void sm10_set_word(Sm10Channel *c, unsigned lane, uint16_t value) {
    c->registers[lane].value = (uint8_t)value;
    c->registers[lane + 1u].value = (uint8_t)(value >> 8u);
    c->registers[lane].known_mask = 0xFFu;
    c->registers[lane + 1u].known_mask = 0xFFu;
}

static Sm08Status sm10_require(Sm10Dma *d, unsigned index,
                               unsigned lane, uint8_t bits) {
    const Sm08Value v = d->channel[index].registers[lane];
    if ((v.known_mask & bits) == bits) return SM08_OK;
    return sm10_fault(d, SM08_UNKNOWN, 0x4300u + index * 16u + lane, v);
}

static Sm08Status sm10_require_word(Sm10Dma *d, unsigned index, unsigned lane) {
    Sm08Status status = sm10_require(d, index, lane, 0xFFu);
    return status == SM08_OK ? sm10_require(d, index, lane + 1u, 0xFFu) : status;
}

/* Fixed hardware patterns, not a runtime opcode or target table decoder. */
static uint8_t sm10_offset(uint8_t control, unsigned ordinal) {
    switch (control & 7u) {
        case 1u: case 5u: return (uint8_t)(ordinal & 1u);
        case 3u: case 7u: return (uint8_t)((ordinal >> 1u) & 1u);
        case 4u: return (uint8_t)(ordinal & 3u);
        default: return 0u;
    }
}

static unsigned sm10_length(uint8_t control) {
    switch (control & 7u) {
        case 0u: return 1u;
        case 1u: case 2u: case 6u: return 2u;
        default: return 4u;
    }
}

static int sm10_restricted(uint32_t address) {
    const uint16_t low = (uint16_t)address;
    return ((address >> 16u) & 0x40u) == 0u &&
        ((low >= 0x2100u && low <= 0x21FFu) || low == 0x420Bu ||
         low == 0x420Cu || (low >= 0x4300u && low <= 0x437Fu));
}

/* One09 elapsed transfer receiver: no CPU cycle or arithmetic pulse here. */
static Sm08Status sm10_advance(Sm10Dma *d, uint32_t clocks) {
    return sm09_scheduler_transfer_advance(d->scheduler, clocks);
}

static Sm08Status sm10_read_half(Sm10Dma *d, uint32_t address,
                                 int on_a, Sm08Value *out) {
    Sm08Status status = sm10_advance(d, 4u);
    if (status != SM08_OK) return status;
    if (on_a && sm10_restricted(address)) { *out = d->bus->mdr; return SM08_OK; }
    return sm08_bus_sample(d->bus, address, out);
}

static Sm08Status sm10_write_half(Sm10Dma *d, uint32_t address,
                                  int on_a, Sm08Value value) {
    Sm08Status status = sm10_advance(d, 4u);
    if (status != SM08_OK) return status;
    if (!on_a || !sm10_restricted(address)) status = sm08_bus_commit(d->bus, address, value);
    if (status == SM08_OK) d->bus->mdr = value;
    return status;
}

static Sm08Status sm10_byte(Sm10Dma *d, uint32_t a, uint16_t b, uint8_t reverse) {
    Sm08Region mapped;
    Sm08Status status;
    Sm08Value value;
    int conflict;
    if (!sm08_decode(a, &mapped)) return SM08_ARGUMENT;
    conflict = b == 0x2180u && mapped.kind == SM08_WRAM;
    if (conflict && !reverse) status = sm10_advance(d, 8u);
    else if (conflict) {
        /* The documented WRAM-port conflict driver is a known FF; this is
         * not an unknown payload/table/absent-device replacement. */
        value.value = 0xFFu; value.known_mask = 0xFFu;
        status = sm10_advance(d, 4u);
        if (status == SM08_OK) status = sm10_write_half(d, a, 1, value);
    } else {
        status = sm10_read_half(d, reverse ? b : a, !reverse, &value);
        if (status == SM08_OK) status = sm10_write_half(d, reverse ? a : b, reverse, value);
    }
    if (status == SM08_OK) ++d->completed_bytes;
    return status;
}

/* A table bus sample is always made, even when the current line count means
 * its byte is discarded. Advancing the cursor/consuming bits is separate. */
static Sm08Status sm10_table(Sm10Dma *d, unsigned index, Sm08Value *out) {
    Sm10Channel *c = &d->channel[index];
    Sm08Status status = sm10_require(d, index, 4u, 0xFFu);
    if (status == SM08_OK) status = sm10_require_word(d, index, 8u);
    if (status != SM08_OK) return status;
    status = sm10_read_half(d, ((uint32_t)c->registers[4].value << 16u) |
        sm10_word(c, 8u), 1, out);
    return status == SM08_OK ? sm10_advance(d, 4u) : status;
}

static void sm10_table_next(Sm10Channel *c) {
    sm10_set_word(c, 8u, (uint16_t)(sm10_word(c, 8u) + 1u));
}

static Sm08Status sm10_indirect(Sm10Dma *d, unsigned index, int high_only) {
    Sm10Channel *c = &d->channel[index];
    Sm08Value sampled;
    Sm08Status status = sm10_table(d, index, &sampled);
    if (status != SM08_OK) return status;
    sm10_table_next(c);
    if (high_only) {
        c->registers[5].value = 0u; c->registers[5].known_mask = 0xFFu;
        c->registers[6] = sampled;
        return SM08_OK;
    }
    c->registers[5] = sampled;
    status = sm10_table(d, index, &sampled);
    if (status != SM08_OK) return status;
    sm10_table_next(c); c->registers[6] = sampled;
    return SM08_OK;
}

static Sm08Status sm10_hdma_init(Sm10Dma *d, uint8_t mask) {
    unsigned index;
    for (index = 0u; index < 8u; ++index) {
        d->channel[index].finished = 0u;
        d->channel[index].transfer_line = 0u;
    }
    /* The field-init event still resets hidden flags with HDMA disabled.
     * It does not reload A2A/NLTR/registers or spend transfer clocks. */
    if (mask == 0u) return SM08_OK;
    for (index = 0u; index < 8u; ++index) {
        Sm10Channel *c = &d->channel[index];
        Sm08Status status;
        Sm08Value header;
        c->transfer_line = 1u;
        if ((mask & (1u << index)) == 0u) continue;
        d->active_channel = (uint8_t)(0x80u | index);
        c->manual_active = 0u;
        status = sm10_require_word(d, index, 2u);
        if (status != SM08_OK) return status;
        sm10_set_word(c, 8u, sm10_word(c, 2u));
        status = sm10_table(d, index, &header);
        if (status != SM08_OK) return status;
        sm10_table_next(c); c->registers[10] = header;
        status = sm10_require(d, index, 10u, 0xFFu);
        if (status == SM08_OK) status = sm10_require(d, index, 0u, 0x40u);
        if (status != SM08_OK) return status;
        c->finished = header.value == 0u;
        if (c->registers[0].value & 0x40u) {
            status = sm10_indirect(d, index, c->finished);
            if (status != SM08_OK) return status;
        }
    }
    return SM08_OK;
}

static int sm10_last(const Sm10Dma *d, unsigned current, uint8_t mask) {
    unsigned index;
    for (index = current + 1u; index < 8u; ++index)
        if ((mask & (1u << index)) && !d->channel[index].finished) return 0;
    return 1;
}

static Sm08Status sm10_hdma_line(Sm10Dma *d, uint8_t mask) {
    unsigned index;
    for (index = 0u; index < 8u; ++index) {
        Sm10Channel *c = &d->channel[index];
        Sm08Status status;
        uint8_t control;
        unsigned ordinal;
        if (!(mask & (1u << index)) || c->finished) continue;
        c->manual_active = 0u;
        if (!c->transfer_line) continue;
        d->active_channel = (uint8_t)(0x80u | index);
        status = sm10_require(d, index, 0u, 0xC7u);
        if (status == SM08_OK) status = sm10_require(d, index, 1u, 0xFFu);
        if (status != SM08_OK) return status;
        control = c->registers[0].value;
        for (ordinal = 0u; ordinal < sm10_length(control); ++ordinal) {
            const unsigned pointer = control & 0x40u ? 5u : 8u;
            const unsigned bank = control & 0x40u ? 7u : 4u;
            const uint16_t target = (uint16_t)(0x2100u |
                (uint8_t)(c->registers[1].value + sm10_offset(control, ordinal)));
            uint32_t address;
            status = sm10_require_word(d, index, pointer);
            if (status == SM08_OK) status = sm10_require(d, index, bank, 0xFFu);
            if (status != SM08_OK) return status;
            address = ((uint32_t)c->registers[bank].value << 16u) | sm10_word(c, pointer);
            status = sm10_byte(d, address, target, control & 0x80u);
            if (status != SM08_OK) return status;
            sm10_set_word(c, pointer, (uint16_t)(sm10_word(c, pointer) + 1u));
        }
    }
    for (index = 0u; index < 8u; ++index) {
        Sm10Channel *c = &d->channel[index];
        Sm08Value next;
        Sm08Status status;
        if (!(mask & (1u << index)) || c->finished) continue;
        d->active_channel = (uint8_t)(0x80u | index);
        status = sm10_require(d, index, 10u, 0xFFu);
        if (status != SM08_OK) return status;
        --c->registers[10].value;
        c->transfer_line = (uint8_t)((c->registers[10].value >> 7u) & 1u);
        status = sm10_table(d, index, &next);
        if (status != SM08_OK) return status;
        if (c->registers[10].value & 0x7Fu) continue;
        sm10_table_next(c); c->registers[10] = next;
        status = sm10_require(d, index, 10u, 0xFFu);
        if (status == SM08_OK) status = sm10_require(d, index, 0u, 0x40u);
        if (status != SM08_OK) return status;
        c->finished = next.value == 0u; c->transfer_line = 1u;
        if (c->registers[0].value & 0x40u) {
            status = sm10_indirect(d, index, next.value == 0u && sm10_last(d, index, mask));
            if (status != SM08_OK) return status;
        }
    }
    return SM08_OK;
}

static Sm08Status sm10_pending_hdma(Sm10Dma *d) {
    const uint8_t active = d->active_channel;
    Sm08Status status;
    if (d->start_delay) { --d->start_delay; return SM08_OK; }
    if (d->line_pending) {
        d->line_pending = 0u;
        if (!d->hdma_enable) return SM08_OK;
        status = sm10_advance(d, 8u);
        if (status == SM08_OK) status = sm10_hdma_line(d, d->hdma_enable);
    } else if (d->init_pending) {
        d->init_pending = 0u;
        if (!d->hdma_enable) return sm10_hdma_init(d, 0u);
        status = sm10_advance(d, 8u);
        if (status == SM08_OK) status = sm10_hdma_init(d, d->hdma_enable);
    } else return SM08_OK;
    if (status == SM08_OK) d->active_channel = active;
    return status;
}

static Sm08Status sm10_manual(Sm10Dma *d, uint8_t mask) {
    unsigned index;
    Sm08Status status = sm10_pending_hdma(d);
    if (status != SM08_OK) return status;
    for (index = 0u; index < 8u; ++index) {
        Sm10Channel *c = &d->channel[index];
        unsigned ordinal = 0u;
        if (!(mask & (1u << index)) || !c->manual_active) continue;
        d->active_channel = (uint8_t)index;
        status = sm10_advance(d, 8u);
        if (status == SM08_OK) status = sm10_pending_hdma(d);
        if (status != SM08_OK) return status;
        if (!c->manual_active) continue;
        status = sm10_require(d, index, 0u, 0x8Fu);
        if (status == SM08_OK && !(c->registers[0].value & 8u))
            status = sm10_require(d, index, 0u, 0x10u);
        if (status == SM08_OK) status = sm10_require(d, index, 1u, 0xFFu);
        if (status == SM08_OK) status = sm10_require_word(d, index, 2u);
        if (status == SM08_OK) status = sm10_require(d, index, 4u, 0xFFu);
        if (status == SM08_OK) status = sm10_require_word(d, index, 5u);
        if (status != SM08_OK) return status;
        do {
            const uint8_t control = c->registers[0].value;
            const uint32_t a = ((uint32_t)c->registers[4].value << 16u) | sm10_word(c, 2u);
            const uint16_t b = (uint16_t)(0x2100u |
                (uint8_t)(c->registers[1].value + sm10_offset(control, ordinal)));
            status = sm10_byte(d, a, b, control & 0x80u);
            if (status != SM08_OK) return status;
            if (!(control & 8u)) sm10_set_word(c, 2u,
                (uint16_t)(sm10_word(c, 2u) + (control & 0x10u ? 0xFFFFu : 1u)));
            sm10_set_word(c, 5u, (uint16_t)(sm10_word(c, 5u) - 1u));
            ++ordinal;
            /* Completed byte/counters precede same-channel HDMA reuse or
             * cancellation. Failures retain already committed08/09 effects. */
            status = sm10_pending_hdma(d);
            if (status != SM08_OK) return status;
        } while (c->manual_active && sm10_word(c, 5u) != 0u);
        c->manual_active = 0u;
    }
    return SM08_OK;
}

static Sm08Status sm10_register_read(void *context, uint16_t reg, Sm08Drive *out) {
    Sm10Dma *d = context;
    unsigned lane;
    if (!sm10_bound(d) || out == NULL) return SM08_ARGUMENT;
    if (d->bus->fault.status != SM08_OK) return d->bus->fault.status;
    out->value = 0u; out->known_mask = 0u; out->driven_mask = 0u;
    if (reg == 0x420Bu || reg == 0x420Cu) return SM08_OK;
    if (reg < 0x4300u || reg > 0x437Fu) return SM08_REGISTER;
    lane = reg & 15u;
    if (lane == 15u) lane = 11u;
    if (lane < 12u) {
        const Sm08Value v = d->channel[(reg >> 4u) & 7u].registers[lane];
        out->value = v.value; out->known_mask = v.known_mask; out->driven_mask = 0xFFu;
    }
    return SM08_OK;
}

static Sm08Status sm10_register_write(void *context, uint16_t reg, Sm08Value value) {
    Sm10Dma *d = context;
    unsigned lane, index;
    if (!sm10_bound(d)) return SM08_ARGUMENT;
    if (d->bus->fault.status != SM08_OK) return d->bus->fault.status;
    if (reg == 0x420Bu || reg == 0x420Cu) {
        if (value.known_mask != 0xFFu) return sm10_fault(d, SM08_UNKNOWN, reg, value);
        if (reg == 0x420Cu) d->hdma_enable = value.value;
        else if (value.value) {
            d->manual_pending |= value.value; d->start_delay = 1u;
            for (index = 0u; index < 8u; ++index)
                if (value.value & (1u << index)) d->channel[index].manual_active = 1u;
        }
        return SM08_OK;
    }
    if (reg < 0x4300u || reg > 0x437Fu) return SM08_REGISTER;
    lane = reg & 15u;
    if (lane == 15u) lane = 11u;
    if (lane < 12u) d->channel[(reg >> 4u) & 7u].registers[lane] = value;
    return SM08_OK;
}

static Sm08Status sm10_smp(void *context, Sm08Bus *bus, uint64_t target) {
    Sm10Dma *d = context;
    if (!sm10_bound(d) || bus != d->bus) return SM08_ARGUMENT;
    return d->downstream.smp_sync(d->downstream.context, bus, target);
}

static Sm08Status sm10_raster(void *context, Sm08Bus *bus,
                             const Sm09Scheduler *scheduler, Sm09RasterEvent event) {
    Sm10Dma *d = context;
    if (!sm10_bound(d) || bus != d->bus || scheduler != d->scheduler) return SM08_ARGUMENT;
    if (event == SM09_RASTER_HDMA_INIT_REQUEST) { d->init_pending = 1u; d->start_delay = 1u; }
    else if (event == SM09_RASTER_HDMA_LINE_REQUEST && d->hdma_enable) {
        d->line_pending = 1u; d->start_delay = 1u;
    }
    return d->downstream.raster_event(d->downstream.context, bus, scheduler, event);
}

static Sm08Status sm10_boundary(void *context, Sm08Bus *bus,
                               const Sm09Scheduler *scheduler, uint8_t kind,
                               uint32_t address, uint8_t clocks) {
    Sm10Dma *d = context;
    Sm08Status status;
    uint64_t pause;
    uint8_t mask, event, delay;
    const Sm08Value unknown = {0u, 0u};
    (void)kind;
    if (!sm10_bound(d) || bus != d->bus || scheduler != d->scheduler) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (d->servicing || !scheduler->advancing || !scheduler->transfer_boundary ||
        (clocks != 6u && clocks != 8u && clocks != 12u))
        return sm10_fault(d, SM08_CLOCK_ABSENT, address, unknown);
    if (d->start_delay) { --d->start_delay; return SM08_OK; }
    mask = d->hdma_enable;
    if (d->line_pending) { d->line_pending = 0u; event = 1u; }
    else if (d->init_pending) { d->init_pending = 0u; event = 2u; }
    else if (d->manual_pending) { mask = d->manual_pending; d->manual_pending = 0u; event = 0u; }
    else return SM08_OK;
    if (event != 0u && !mask) return event == 2u ? sm10_hdma_init(d, 0u) : SM08_OK;
    d->servicing = 1u; pause = scheduler->master_clock;
    status = sm09_scheduler_dma_alignment(scheduler, 0u, &delay);
    if (status == SM08_OK) status = sm10_advance(d, delay);
    if (status == SM08_OK) status = sm10_advance(d, 8u);
    if (status == SM08_OK) status = event == 0u ? sm10_manual(d, mask) :
        event == 1u ? sm10_hdma_line(d, mask) : sm10_hdma_init(d, mask);
    if (status == SM08_OK) status = sm09_scheduler_dma_resume_delay(scheduler, pause, clocks, &delay);
    if (status == SM08_OK) status = sm10_advance(d, delay);
    d->servicing = 0u;
    if (status == SM08_OK) d->active_channel = 0xFFu;
    return status;
}

Sm08Status sm10_dma_bind(Sm10Dma *d, Sm08Bus *bus, Sm09Scheduler *scheduler) {
    Sm09Receivers previous;
    unsigned index, lane;
    if (d == NULL || bus == NULL || scheduler == NULL || scheduler->bus != bus ||
        bus->fault.status != SM08_OK || scheduler->advancing || scheduler->master_clock ||
        scheduler->smp_started || scheduler->receivers.context == d ||
        scheduler->receivers.smp_sync == NULL || scheduler->receivers.raster_event == NULL ||
        bus->ports.dma.read != NULL || bus->ports.dma.write != NULL) return SM08_ARGUMENT;
    previous = scheduler->receivers; previous.cpu_boundary = NULL;
    memset(d, 0, sizeof(*d)); d->bus = bus; d->scheduler = scheduler; d->downstream = previous;
    d->active_channel = 0xFFu;
    for (index = 0u; index < 8u; ++index)
        for (lane = 0u; lane < 12u; ++lane) {
            d->channel[index].registers[lane].value = 0xFFu;
            d->channel[index].registers[lane].known_mask = 0xFFu;
        }
    bus->ports.dma.context = d; bus->ports.dma.read = sm10_register_read;
    bus->ports.dma.write = sm10_register_write;
    scheduler->receivers.context = d; scheduler->receivers.smp_sync = sm10_smp;
    scheduler->receivers.raster_event = sm10_raster; scheduler->receivers.cpu_boundary = sm10_boundary;
    return SM08_OK;
}

Sm08Status sm10_dma_reset(Sm10Dma *d) {
    unsigned index;
    if (!sm10_bound(d) || d->servicing) return SM08_ARGUMENT;
    d->manual_pending = 0u; d->hdma_enable = 0u; d->line_pending = 0u; d->init_pending = 0u;
    d->start_delay = 0u; d->active_channel = 0xFFu;
    for (index = 0u; index < 8u; ++index) d->channel[index].manual_active = 0u;
    return SM08_OK;
}
