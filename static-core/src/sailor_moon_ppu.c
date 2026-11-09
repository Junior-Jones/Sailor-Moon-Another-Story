#include "sailor_moon_ppu.h"
#include <string.h>

static int sm11_attached(const Sm11Ppu *p) {
    return p != NULL && p->bus != NULL && p->scheduler != NULL &&
           p->wrio != NULL && p->scheduler->bus == p->bus;
}

static Sm08Status sm11_fault(Sm11Ppu *p, Sm08Status status,
                             uint16_t reg, Sm08Value value) {
    if (!sm11_attached(p)) return SM08_ARGUMENT;
    return sm08_bus_fault(p->bus, status, 11u, reg, value);
}

static Sm08Status sm11_need(Sm11Ppu *p, uint16_t reg,
                            Sm08Value value, uint8_t mask) {
    if ((value.known_mask & mask) != mask)
        return sm11_fault(p, SM08_UNKNOWN, reg, value);
    return SM08_OK;
}

static Sm08Status sm11_address(Sm11Ppu *p, uint16_t reg,
                               Sm11Word address, uint16_t mask) {
    Sm08Value unknown = {0u, 0u};
    if ((address.known_mask & mask) != mask)
        return sm11_fault(p, SM08_UNKNOWN, reg, unknown);
    return SM08_OK;
}

static Sm08Status sm11_storage_window(Sm11Ppu *p, uint16_t reg, int palette) {
    Sm08Value unknown = {0u, 0u};
    if (p->forced_blank != 0u || p->scheduler->vblank != 0u) return SM08_OK;
    /* 09 supplies the beam position. The palette port also has the horizontal
     * blank/prerender window; this is not VRAM/OAM access permission. */
    if (palette && (p->scheduler->hblank != 0u ||
                    p->scheduler->scanline == 0u ||
                    sm09_scheduler_dot(p->scheduler) < 22u)) return SM08_OK;
    return sm11_fault(p, SM08_STORAGE, reg, unknown);
}

static Sm11Word sm11_latched_word(Sm08Value prior, Sm08Value next) {
    Sm11Word out;
    out.value = (uint16_t)((uint16_t)prior.value | ((uint16_t)next.value << 8u));
    out.known_mask = (uint16_t)((uint16_t)prior.known_mask |
                              ((uint16_t)next.known_mask << 8u));
    return out;
}

static void sm11_scroll(Sm11Ppu *p, unsigned bg, uint8_t vertical, Sm08Value data) {
    Sm11Word out;
    if (vertical != 0u) {
        out = sm11_latched_word(p->scroll_previous, data);
        p->scroll_y[bg] = out;
    } else {
        /* The low three bits come from this BG's old HOFS high bits, not
         * from the last horizontal write to some other background. */
        out.value = (uint16_t)((((uint16_t)data.value << 8u) |
                        (p->scroll_previous.value & 0xF8u) |
                        ((p->scroll_x[bg].value >> 8u) & 7u)));
        out.known_mask = (uint16_t)((((uint16_t)data.known_mask << 8u) |
                        (p->scroll_previous.known_mask & 0xF8u) |
                        ((p->scroll_x[bg].known_mask >> 8u) & 7u)));
        p->scroll_x[bg] = out;
    }
    p->scroll_previous = data;
}

static uint16_t sm11_vram_word(const Sm11Ppu *p) {
    uint16_t address = p->vram_address.value;
    unsigned shift = (p->registers[0x15u].value >> 2u) & 3u;
    if (shift != 0u) {
        unsigned bits = shift + 4u;
        uint16_t low = (uint16_t)((1u << bits) - 1u);
        uint16_t field = (uint16_t)((1u << (bits + 3u)) - 1u);
        address = (uint16_t)((address & (uint16_t)~field) |
                           ((address & low) << 3u) |
                           ((address >> bits) & 7u));
    }
    return (uint16_t)(address & 0x7FFFu);
}

static void sm11_prefetch(Sm11Ppu *p) {
    unsigned address;
    /* A partial VMADD/VMAIN write must not choose an arbitrary storage cell.
     * The internal buffer becomes unknown until its effective address is
     * determined; this performs no extra CPU or B-bus access. */
    if ((p->forced_blank == 0u && p->scheduler->vblank == 0u) ||
        (p->vram_address.known_mask & 0x7FFFu) != 0x7FFFu ||
        (p->registers[0x15u].known_mask & 0x0Cu) != 0x0Cu) {
        p->read_buffer[0] = (Sm08Value){0u, 0u};
        p->read_buffer[1] = (Sm08Value){0u, 0u};
        return;
    }
    address = (unsigned)sm11_vram_word(p) * 2u;
    p->read_buffer[0] = p->vram[address];
    p->read_buffer[1] = p->vram[address + 1u];
}

static void sm11_vram_next(Sm11Ppu *p) {
    unsigned mode = p->registers[0x15u].value & 3u;
    uint16_t increment = mode == 0u ? 1u : mode == 1u ? 32u : 128u;
    p->vram_address.value = (uint16_t)((p->vram_address.value + increment) & 0x7FFFu);
}

static void sm11_oam_reload(Sm11Ppu *p) {
    p->oam_address.value = (uint16_t)((p->oam_reload.value << 1u) & 0x03FFu);
    p->oam_address.known_mask = (uint16_t)(((p->oam_reload.known_mask << 1u) |
                                          1u) & 0x03FFu);
}

static unsigned sm11_oam_physical(uint16_t address) {
    return address < 512u ? address : 512u + (address & 31u);
}

Sm08Status sm11_ppu_power_on(Sm11Ppu *p, Sm08Bus *bus, Sm09Scheduler *scheduler,
                            const Sm08Value *wrio) {
    if (p == NULL || bus == NULL || scheduler == NULL || wrio == NULL ||
        scheduler->bus != bus || scheduler->advancing != 0u) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    memset(p, 0, sizeof(*p));
    p->bus = bus;
    p->scheduler = scheduler;
    p->wrio = wrio;
    /* Representatives in zeroed tagged records are not known zero storage.
     * Only the declared cold force-blank bit is forced here. Geometry remains
     * the selected09 cold geometry until an actual SETINI commit. */
    p->forced_blank = 1u;
    p->registers[0] = (Sm08Value){0x80u, 0x80u};
    p->obj_status = (Sm08Value){0u, 0xC0u};
    return SM08_OK;
}

Sm08Status sm11_ppu_reset(Sm11Ppu *p) {
    if (!sm11_attached(p)) return SM08_ARGUMENT;
    if (p->bus->fault.status != SM08_OK) return p->bus->fault.status;
    p->forced_blank = 1u;
    p->registers[0].value |= 0x80u;
    p->registers[0].known_mask |= 0x80u;
    p->counter_latched = 0u;
    p->counter_h_second = 0u;
    p->counter_v_second = 0u;
    return SM08_OK;
}

Sm08Status sm11_ppu_latch_counters(Sm11Ppu *p) {
    if (!sm11_attached(p)) return SM08_ARGUMENT;
    if (p->bus->fault.status != SM08_OK) return p->bus->fault.status;
    p->counter_h = sm09_scheduler_dot(p->scheduler);
    p->counter_v = p->scheduler->scanline;
    p->counter_latched = 1u;
    /* Only STAT78 resets the read selectors. A latch, including a real
     * WRIO/controller edge, does not reset either independent selector. */
    return SM08_OK;
}

Sm08Status sm11_ppu_obj_flags(Sm11Ppu *p, Sm08Value flags) {
    uint8_t sticky;
    if (!sm11_attached(p)) return SM08_ARGUMENT;
    if (p->bus->fault.status != SM08_OK) return p->bus->fault.status;
    sticky = p->obj_status.value & p->obj_status.known_mask & 0xC0u;
    p->obj_status.value = (uint8_t)((flags.value & 0xC0u) | sticky);
    p->obj_status.known_mask = (uint8_t)((flags.known_mask & 0xC0u) | sticky);
    return SM08_OK;
}

static Sm08Status sm11_write(void *context, uint16_t reg, Sm08Value data) {
    Sm11Ppu *p = context;
    unsigned index;
    unsigned address;
    uint16_t blank_line;
    Sm11Word word;
    if (!sm11_attached(p) || reg < 0x2100u || reg > 0x213Fu) return SM08_ARGUMENT;
    if (p->bus->fault.status != SM08_OK) return p->bus->fault.status;
    ++p->writes[reg - 0x2100u];
    if (reg <= 0x2133u) p->registers[reg - 0x2100u] = data;
    /* Register writes are not PPU1/PPU2 read-bus samples. */
    switch (reg) {
        case 0x2100u:
            if (sm11_need(p, reg, data, 0x80u) != SM08_OK) return p->bus->fault.status;
            blank_line = p->scheduler->overscan != 0u ? 240u : 225u;
            if (p->forced_blank != 0u && p->scheduler->scanline == blank_line)
                sm11_oam_reload(p);
            p->forced_blank = data.value >> 7u;
            p->brightness.value = data.value & 15u;
            p->brightness.known_mask = data.known_mask & 15u;
            break;
        case 0x2102u:
            p->oam_reload.value = (uint16_t)((p->oam_reload.value & 0x0100u) | data.value);
            p->oam_reload.known_mask = (uint16_t)((p->oam_reload.known_mask & 0x0100u) |
                                               data.known_mask);
            sm11_oam_reload(p);
            break;
        case 0x2103u:
            p->oam_reload.value = (uint16_t)((p->oam_reload.value & 0x00FFu) |
                                            ((uint16_t)(data.value & 1u) << 8u));
            p->oam_reload.known_mask = (uint16_t)((p->oam_reload.known_mask & 0x00FFu) |
                                            ((uint16_t)(data.known_mask & 1u) << 8u));
            sm11_oam_reload(p);
            break;
        case 0x2104u:
            if (sm11_storage_window(p, reg, 0) != SM08_OK ||
                sm11_address(p, reg, p->oam_address, 0x03FFu) != SM08_OK)
                return p->bus->fault.status;
            address = sm11_oam_physical(p->oam_address.value);
            if (p->oam_address.value < 512u && (address & 1u) == 0u) {
                p->oam_buffer = data;
            } else if (p->oam_address.value < 512u) {
                p->oam[address - 1u] = p->oam_buffer;
                p->oam[address] = data;
                p->storage_writes += 2u;
            } else {
                p->oam[address] = data;
                ++p->storage_writes;
            }
            p->oam_address.value = (uint16_t)((p->oam_address.value + 1u) & 0x03FFu);
            break;
        case 0x210Du: case 0x210Eu:
            word = sm11_latched_word(p->m7_previous, data);
            word.value &= 0x1FFFu;
            word.known_mask &= 0x1FFFu;
            p->m7_scroll[reg - 0x210Du] = word;
            p->m7_previous = data;
            sm11_scroll(p, 0u, (uint8_t)(reg == 0x210Eu), data);
            break;
        case 0x210Fu: case 0x2110u: case 0x2111u:
        case 0x2112u: case 0x2113u: case 0x2114u:
            sm11_scroll(p, (reg - 0x210Du) / 2u, (uint8_t)((reg & 1u) == 0u), data);
            break;
        case 0x2116u:
            p->vram_address.value = (uint16_t)((p->vram_address.value & 0x7F00u) | data.value);
            p->vram_address.known_mask = (uint16_t)((p->vram_address.known_mask & 0x7F00u) |
                                                  data.known_mask);
            sm11_prefetch(p);
            break;
        case 0x2117u:
            p->vram_address.value = (uint16_t)((p->vram_address.value & 0x00FFu) |
                                              ((uint16_t)(data.value & 0x7Fu) << 8u));
            p->vram_address.known_mask = (uint16_t)((p->vram_address.known_mask & 0x00FFu) |
                                              ((uint16_t)(data.known_mask & 0x7Fu) << 8u));
            sm11_prefetch(p);
            break;
        case 0x2118u: case 0x2119u:
            if (sm11_storage_window(p, reg, 0) != SM08_OK ||
                sm11_address(p, reg, p->vram_address, 0x7FFFu) != SM08_OK ||
                sm11_need(p, reg, p->registers[0x15u], 0x8Fu) != SM08_OK)
                return p->bus->fault.status;
            address = (unsigned)sm11_vram_word(p) * 2u + (reg & 1u);
            p->vram[address] = data;
            ++p->storage_writes;
            if ((unsigned)(reg == 0x2119u) == (p->registers[0x15u].value >> 7u))
                sm11_vram_next(p);
            break;
        case 0x211Bu: case 0x211Cu: case 0x211Du:
        case 0x211Eu: case 0x211Fu: case 0x2120u:
            index = reg - 0x211Bu;
            word = sm11_latched_word(p->m7_previous, data);
            if (index >= 4u) { word.value &= 0x1FFFu; word.known_mask &= 0x1FFFu; }
            p->matrix[index] = word;
            p->m7_previous = data;
            break;
        case 0x2121u:
            p->cgram_address = data;
            p->cgram_second = 0u;
            break;
        case 0x2122u:
            if (p->cgram_second == 0u) {
                p->cgram_buffer = data;
                p->cgram_second = 1u;
                break;
            }
            if (sm11_storage_window(p, reg, 1) != SM08_OK ||
                sm11_need(p, reg, p->cgram_address, 0xFFu) != SM08_OK)
                return p->bus->fault.status;
            address = (unsigned)p->cgram_address.value * 2u;
            p->cgram[address] = p->cgram_buffer;
            data.value &= 0x7Fu;
            data.known_mask |= 0x80u;
            p->cgram[address + 1u] = data;
            ++p->cgram_address.value;
            p->cgram_second = 0u;
            p->storage_writes += 2u;
            break;
        case 0x2132u:
            if (sm11_need(p, reg, data, 0xE0u) != SM08_OK) return p->bus->fault.status;
            for (index = 0u; index < 3u; ++index) {
                if ((data.value & (0x20u << index)) != 0u) {
                    uint16_t mask = (uint16_t)(31u << (index * 5u));
                    p->fixed_color.value = (uint16_t)((p->fixed_color.value & (uint16_t)~mask) |
                                                     ((data.value & 31u) << (index * 5u)));
                    p->fixed_color.known_mask = (uint16_t)((p->fixed_color.known_mask & (uint16_t)~mask) |
                                                     ((data.known_mask & 31u) << (index * 5u)));
                }
            }
            break;
        case 0x2133u:
            if (sm11_need(p, reg, data, 5u) != SM08_OK) return p->bus->fault.status;
            p->scheduler->interlace = data.value & 1u;
            p->scheduler->overscan = (data.value >> 2u) & 1u;
            break;
        default:
            /* Other writable registers retain their tagged raw state for14;
             * writes to2134..213F have no writable register-image effect. */
            break;
    }
    return SM08_OK;
}

static Sm08Status sm11_read(void *context, uint16_t reg, Sm08Drive *drive) {
    Sm11Ppu *p = context;
    Sm08Value data = {0u, 0u};
    uint8_t owner = 0u;
    uint8_t driven = 0xFFu;
    unsigned address;
    uint16_t count;
    int32_t product;
    if (!sm11_attached(p) || drive == NULL || reg < 0x2100u || reg > 0x213Fu)
        return SM08_ARGUMENT;
    if (p->bus->fault.status != SM08_OK) return p->bus->fault.status;
    ++p->reads[reg - 0x2100u];
    switch (reg) {
        case 0x2134u: case 0x2135u: case 0x2136u:
            product = (int32_t)(int16_t)p->matrix[0].value *
                      (int32_t)(int8_t)(p->matrix[1].value >> 8u);
            data.value = (uint8_t)((uint32_t)product >> ((reg - 0x2134u) * 8u));
            data.known_mask = p->matrix[0].known_mask == 0xFFFFu &&
                              (p->matrix[1].known_mask & 0xFF00u) == 0xFF00u ? 0xFFu : 0u;
            owner = 1u;
            break;
        case 0x2137u:
            if (sm11_need(p, 0x4201u, *p->wrio, 0x80u) != SM08_OK)
                return p->bus->fault.status;
            if ((p->wrio->value & 0x80u) != 0u) {
                if (sm11_ppu_latch_counters(p) != SM08_OK) return p->bus->fault.status;
            }
            driven = 0u;
            break;
        case 0x2138u:
            if (sm11_storage_window(p, reg, 0) != SM08_OK ||
                sm11_address(p, reg, p->oam_address, 0x03FFu) != SM08_OK)
                return p->bus->fault.status;
            address = sm11_oam_physical(p->oam_address.value);
            data = p->oam[address];
            p->oam_address.value = (uint16_t)((p->oam_address.value + 1u) & 0x03FFu);
            ++p->storage_reads;
            owner = 1u;
            break;
        case 0x2139u: case 0x213Au:
            if (sm11_storage_window(p, reg, 0) != SM08_OK ||
                sm11_address(p, reg, p->vram_address, 0x7FFFu) != SM08_OK ||
                sm11_need(p, reg, p->registers[0x15u], 0x8Fu) != SM08_OK)
                return p->bus->fault.status;
            data = p->read_buffer[reg - 0x2139u];
            if ((unsigned)(reg == 0x213Au) == (p->registers[0x15u].value >> 7u)) {
                sm11_prefetch(p);
                sm11_vram_next(p);
            }
            ++p->storage_reads;
            owner = 1u;
            break;
        case 0x213Bu:
            if (sm11_storage_window(p, reg, 1) != SM08_OK ||
                sm11_need(p, reg, p->cgram_address, 0xFFu) != SM08_OK)
                return p->bus->fault.status;
            address = (unsigned)p->cgram_address.value * 2u + p->cgram_second;
            data = p->cgram[address];
            if (p->cgram_second != 0u) {
                data.value = (uint8_t)((data.value & 0x7Fu) | (p->ppu2_mdr.value & 0x80u));
                data.known_mask = (uint8_t)((data.known_mask & 0x7Fu) | (p->ppu2_mdr.known_mask & 0x80u));
                ++p->cgram_address.value;
            }
            p->cgram_second ^= 1u;
            ++p->storage_reads;
            owner = 2u;
            break;
        case 0x213Cu: case 0x213Du:
            if (reg == 0x213Cu) {
                count = p->counter_latched != 0u ? p->counter_h : sm09_scheduler_dot(p->scheduler);
                if (p->counter_h_second == 0u) data = (Sm08Value){(uint8_t)count, 0xFFu};
                else data = (Sm08Value){(uint8_t)(((count >> 8u) & 1u) | (p->ppu2_mdr.value & 0xFEu)),
                                        (uint8_t)(1u | (p->ppu2_mdr.known_mask & 0xFEu))};
                p->counter_h_second ^= 1u;
            } else {
                count = p->counter_latched != 0u ? p->counter_v : p->scheduler->scanline;
                if (p->counter_v_second == 0u) data = (Sm08Value){(uint8_t)count, 0xFFu};
                else data = (Sm08Value){(uint8_t)(((count >> 8u) & 1u) | (p->ppu2_mdr.value & 0xFEu)),
                                        (uint8_t)(1u | (p->ppu2_mdr.known_mask & 0xFEu))};
                p->counter_v_second ^= 1u;
            }
            owner = 2u;
            break;
        case 0x213Eu:
            data.value = (uint8_t)(SM11_PPU1_VERSION | (p->obj_status.value & 0xC0u) |
                                   (p->ppu1_mdr.value & 0x10u));
            data.known_mask = (uint8_t)(0x2Fu | (p->obj_status.known_mask & 0xC0u) |
                                        (p->ppu1_mdr.known_mask & 0x10u));
            owner = 1u;
            break;
        case 0x213Fu:
            if (sm11_need(p, 0x4201u, *p->wrio, 0x80u) != SM08_OK)
                return p->bus->fault.status;
            data.value = (uint8_t)(SM11_PPU2_VERSION | (p->ppu2_mdr.value & 0x20u) |
                                   (p->counter_latched << 6u) | (p->scheduler->field << 7u));
            data.known_mask = (uint8_t)(0xDFu | (p->ppu2_mdr.known_mask & 0x20u));
            if ((p->wrio->value & 0x80u) != 0u) p->counter_latched = 0u;
            p->counter_h_second = 0u;
            p->counter_v_second = 0u;
            owner = 2u;
            break;
        default:
            address = reg & 15u;
            if (reg < 0x2130u && ((address >= 4u && address <= 6u) ||
                                   (address >= 8u && address <= 10u))) {
                data = p->ppu1_mdr;
                owner = 1u;
            } else driven = 0u;
            break;
    }
    if (owner == 1u) p->ppu1_mdr = data;
    if (owner == 2u) p->ppu2_mdr = data;
    drive->value = data.value;
    drive->known_mask = data.known_mask;
    drive->driven_mask = driven;
    return SM08_OK;
}

Sm08Device sm11_ppu_device(Sm11Ppu *p) {
    Sm08Device port = {p, sm11_read, sm11_write};
    return port;
}

Sm08Status sm11_ppu_raster_event(Sm11Ppu *p, Sm08Bus *bus,
                                const Sm09Scheduler *scheduler, Sm09RasterEvent event) {
    if (!sm11_attached(p) || bus != p->bus || scheduler != p->scheduler) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (event == SM09_RASTER_VBLANK_BEGIN && p->forced_blank == 0u) sm11_oam_reload(p);
    if (event == SM09_RASTER_VBLANK_END) p->obj_status = (Sm08Value){0u, 0xC0u};
    if (event == SM09_RASTER_LINE_BEGIN && scheduler->scanline != 0u &&
        scheduler->vblank == 0u && p->forced_blank == 0u) {
        /* A missing14 OBJ evaluation is not a fabricated no-overflow result.
         * Known sticky ones survive;14 may publish its actual cumulative flags. */
        p->obj_status.known_mask &= p->obj_status.value;
    }
    return SM08_OK;
}

static Sm08Status sm11_forward_smp(void *context, Sm08Bus *bus, uint64_t target) {
    Sm11Ppu *p = context;
    if (!sm11_attached(p) || bus != p->bus) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    return p->downstream.smp_sync(p->downstream.context, bus, target);
}

static Sm08Status sm11_forward_raster(void *context, Sm08Bus *bus,
                                     const Sm09Scheduler *scheduler, Sm09RasterEvent event) {
    Sm11Ppu *p = context;
    Sm08Status status = sm11_ppu_raster_event(p, bus, scheduler, event);
    if (status != SM08_OK) return status;
    status = p->downstream.raster_event(p->downstream.context, bus, scheduler, event);
    return bus->fault.status != SM08_OK ? bus->fault.status : status;
}

static Sm08Status sm11_forward_boundary(void *context, Sm08Bus *bus,
                                       const Sm09Scheduler *scheduler, uint8_t kind,
                                       uint32_t address, uint8_t clocks) {
    Sm11Ppu *p = context;
    if (!sm11_attached(p) || bus != p->bus || scheduler != p->scheduler) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    return p->downstream.cpu_boundary(p->downstream.context, bus, scheduler, kind, address, clocks);
}

Sm08Status sm11_ppu_bind(Sm11Ppu *p) {
    if (!sm11_attached(p) || p->bound != 0u ||
        p->scheduler->advancing != 0u || p->scheduler->master_clock != 0u ||
        p->bus->ports.ppu.read != NULL || p->bus->ports.ppu.write != NULL ||
        p->bus->ports.dma.read != NULL || p->bus->ports.dma.write != NULL ||
        p->scheduler->receivers.smp_sync == NULL ||
        p->scheduler->receivers.raster_event == NULL ||
        p->scheduler->receivers.cpu_boundary == NULL ||
        p->scheduler->receivers.context == p) return SM08_ARGUMENT;
    if (p->bus->fault.status != SM08_OK) return p->bus->fault.status;
    p->downstream = p->scheduler->receivers;
    p->bus->ports.ppu = sm11_ppu_device(p);
    p->scheduler->receivers.context = p;
    p->scheduler->receivers.smp_sync = sm11_forward_smp;
    p->scheduler->receivers.raster_event = sm11_forward_raster;
    p->scheduler->receivers.cpu_boundary = sm11_forward_boundary;
    p->bound = 1u;
    return SM08_OK;
}
