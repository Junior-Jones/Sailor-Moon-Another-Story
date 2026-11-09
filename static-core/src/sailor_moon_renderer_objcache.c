#include "sailor_moon_renderer.h"
#include <string.h>

/* A candidate contains an index, not eagerly resolved palette data. */
typedef struct Sm14Pixel {
    uint16_t palette;
    uint8_t present, layer, direct, color;
} Sm14Pixel;

/* UW-style render-row lifetime: retain raw plane bytes only for the current
 * synchronous line.  Knownness is still tested lazily for the selected bit,
 * so an unused unknown column cannot create or suppress a fault. */
typedef struct Sm14TileRowCache {
    uint32_t address;
    uint8_t valid, bpp;
    Sm08Value plane[8];
} Sm14TileRowCache;

typedef struct Sm14BgPixelCache {
    uint8_t priority_valid, priority, candidate_valid;
    Sm14Pixel pixel;
} Sm14BgPixelCache;

typedef struct Sm14BgLineCache {
    uint16_t sx, sy;
    uint8_t valid, mosaic_enabled, mosaic_size, sc;
    uint8_t chr_valid, chr;
} Sm14BgLineCache;

/* Host-local memo for one pixel in an immutable raster render call.
 * Successful source reads only; no saved/guest state, no eager palette read.
 * Each new pixel resets it; main/subscreen priority probes share the result. */
typedef struct Sm14ObjPixelCache {
    uint8_t valid, present, index, color, priority, palette_valid;
    uint8_t line_stage, line_display, line_brightness, line_mode, line_cg;
    uint8_t enabled_valid[2], enabled_value[2];
    uint8_t cgram_valid[32];
    uint16_t cgram_value[256];
    Sm14Pixel pixel;
    Sm14TileRowCache bg_row[4];
    Sm14BgPixelCache bg_pixel[4];
    Sm14BgLineCache bg_line[4];
} Sm14ObjPixelCache;

/* Labels shared by every candidate in the primary-derived total order. */
enum { SM14_B3L, SM14_O0, SM14_B3H, SM14_O1, SM14_B2L,
       SM14_B1L, SM14_O2, SM14_B2H, SM14_B1H, SM14_O3, SM14_M7 };
static const uint8_t sm14_order_normal[10] = {
    SM14_B3L, SM14_O0, SM14_B3H, SM14_O1, SM14_B2L,
    SM14_B1L, SM14_O2, SM14_B2H, SM14_B1H, SM14_O3
};
static const uint8_t sm14_order_bg3[10] = {
    SM14_B3L, SM14_O0, SM14_O1, SM14_B2L, SM14_B1L,
    SM14_O2, SM14_B2H, SM14_B1H, SM14_O3, SM14_B3H
};
static const uint8_t sm14_order_m7[5] = {
    SM14_O0, SM14_M7, SM14_O1, SM14_O2, SM14_O3
};

static int sm14_attached(const Sm14Renderer *r) {
    return r != NULL && r->ppu != NULL && r->bus != NULL &&
           r->scheduler != NULL && r->ppu->bus == r->bus &&
           r->ppu->scheduler == r->scheduler && r->scheduler->bus == r->bus;
}

static Sm08Status sm14_fail(Sm14Renderer *r, Sm08Status status, Sm14Dependency dep,
                            uint32_t address, uint16_t mask,
                            uint16_t value, uint16_t known) {
    Sm08Value byte = {(uint8_t)value, (uint8_t)known};
    if (r->failure.status == SM08_OK) {
        r->failure.status = status; r->failure.dependency = dep;
        r->failure.address = address; r->failure.mask = mask;
        r->failure.value = value; r->failure.known_mask = known;
        r->failure.x = r->x; r->failure.y = r->y; r->failure.layer = r->layer;
    }
    return sm08_bus_fault(r->bus, status, 14u, (uint16_t)address, byte);
}

static Sm08Status sm14_byte(Sm14Renderer *r, Sm08Value v, unsigned mask,
                            Sm14Dependency dep, uint32_t address, unsigned *out) {
    if ((v.known_mask & mask) != mask)
        return sm14_fail(r, SM08_UNKNOWN, dep, address, (uint16_t)mask, v.value, v.known_mask);
    *out = v.value & mask;
    return SM08_OK;
}

static Sm08Status sm14_reg(Sm14Renderer *r, unsigned reg, unsigned mask, unsigned *out) {
    return sm14_byte(r, r->ppu->registers[reg], mask, SM14_DEP_REGISTER, 0x2100u + reg, out);
}

static Sm08Status sm14_word(Sm14Renderer *r, Sm11Word v, unsigned mask,
                            Sm14Dependency dep, unsigned address, unsigned *out) {
    if ((v.known_mask & mask) != mask)
        return sm14_fail(r, SM08_UNKNOWN, dep, address, (uint16_t)mask, v.value, v.known_mask);
    *out = v.value & mask;
    return SM08_OK;
}

static Sm08Status sm14_vram(Sm14Renderer *r, unsigned address, unsigned mask, unsigned *out) {
    address &= 0xffffu;
    return sm14_byte(r, r->ppu->vram[address], mask, SM14_DEP_VRAM, address, out);
}

static Sm08Status sm14_oam(Sm14Renderer *r, unsigned address, unsigned mask, unsigned *out) {
    return sm14_byte(r, r->ppu->oam[address], mask, SM14_DEP_OAM, address, out);
}

static Sm08Status sm14_palette(Sm14Renderer *r, unsigned index, uint16_t *out) {
    unsigned lo = 0u, hi = 0u;
    Sm08Status s;
    index = (index & 255u) * 2u;
    s = sm14_byte(r, r->ppu->cgram[index], 255u, SM14_DEP_CGRAM, index, &lo);
    if (s != SM08_OK) return s;
    s = sm14_byte(r, r->ppu->cgram[index + 1u], 127u, SM14_DEP_CGRAM, index + 1u, &hi);
    if (s != SM08_OK) return s;
    *out = (uint16_t)(lo | (hi << 8u));
    return SM08_OK;
}

/* Only enabled windows consume position/inversion/logic bits. */
static Sm08Status sm14_window(Sm14Renderer *r, unsigned layer, unsigned x, unsigned *inside) {
    unsigned selection = 0u, enable1 = 0u, enable2 = 0u, v = 0u;
    unsigned a = 0u, b = 0u, left = 0u, right = 0u, logic = 0u;
    unsigned reg = 0x23u + layer / 2u, shift = (layer & 1u) * 4u;
    Sm08Status s = sm14_reg(r, reg, 0x0au << shift, &selection);
    if (s != SM08_OK) return s;
    enable1 = (selection >> (shift + 1u)) & 1u;
    enable2 = (selection >> (shift + 3u)) & 1u;
    *inside = 0u;
    if (!enable1 && !enable2) return SM08_OK;
    if (enable1) {
        s = sm14_reg(r, reg, 1u << shift, &v); if (s != SM08_OK) return s;
        s = sm14_reg(r, 0x26u, 255u, &left); if (s != SM08_OK) return s;
        s = sm14_reg(r, 0x27u, 255u, &right); if (s != SM08_OK) return s;
        a = ((x >= left && x <= right) ? 1u : 0u) ^ ((v >> shift) & 1u);
    }
    if (enable2) {
        s = sm14_reg(r, reg, 4u << shift, &v); if (s != SM08_OK) return s;
        s = sm14_reg(r, 0x28u, 255u, &left); if (s != SM08_OK) return s;
        s = sm14_reg(r, 0x29u, 255u, &right); if (s != SM08_OK) return s;
        b = ((x >= left && x <= right) ? 1u : 0u) ^ ((v >> (shift + 2u)) & 1u);
    }
    if (!enable1) { *inside = b; return SM08_OK; }
    if (!enable2) { *inside = a; return SM08_OK; }
    reg = layer < 4u ? 0x2au : 0x2bu;
    shift = (layer < 4u ? layer : layer - 4u) * 2u;
    s = sm14_reg(r, reg, 3u << shift, &logic); if (s != SM08_OK) return s;
    logic = (logic >> shift) & 3u;
    if (logic == 0u) *inside = a | b;
    else if (logic == 1u) *inside = a & b;
    else if (logic == 2u) *inside = a ^ b;
    else *inside = (a ^ b) ^ 1u;
    return SM08_OK;
}

static Sm08Status sm14_enabled(Sm14Renderer *r, unsigned layer, unsigned sub,
                               unsigned x, unsigned *enabled) {
    unsigned v = 0u, window = 0u;
    Sm08Status s = sm14_reg(r, sub ? 0x2du : 0x2cu, 1u << layer, &v);
    if (s != SM08_OK) return s;
    *enabled = 0u;
    if (!v) return SM08_OK;
    s = sm14_reg(r, sub ? 0x2fu : 0x2eu, 1u << layer, &v);
    if (s != SM08_OK) return s;
    if (v) {
        s = sm14_window(r, layer, x, &window); if (s != SM08_OK) return s;
        if (window) return SM08_OK;
    }
    *enabled = 1u;
    return SM08_OK;
}

static Sm08Status sm14_enabled_cached(Sm14Renderer *r, unsigned layer, unsigned sub,
                                      unsigned x, unsigned *enabled,
                                      Sm14ObjPixelCache *cache) {
    uint8_t bit = (uint8_t)(1u << layer);
    Sm08Status s;
    if (cache->enabled_valid[sub] & bit) {
        *enabled = (cache->enabled_value[sub] & bit) != 0u;
        return SM08_OK;
    }
    s = sm14_enabled(r, layer, sub, x, enabled);
    if (s != SM08_OK) return s;
    cache->enabled_valid[sub] |= bit;
    if (*enabled) cache->enabled_value[sub] |= bit;
    else cache->enabled_value[sub] &= (uint8_t)~bit;
    return SM08_OK;
}

static Sm08Status sm14_mosaic(Sm14Renderer *r, unsigned layer, unsigned *x, unsigned *y) {
    unsigned v = 0u, size = 0u;
    Sm08Status s = sm14_reg(r, 6u, 1u << layer, &v);
    if (s != SM08_OK || !v) return s;
    s = sm14_reg(r, 6u, 0xf0u, &v); if (s != SM08_OK) return s;
    size = (v >> 4u) + 1u;
    *x -= *x % size;
    /* Visible line1 is the first line of the declared field mosaic block. */
    *y = ((*y - 1u) / size) * size + 1u;
    return SM08_OK;
}

static Sm08Status sm14_planes(Sm14Renderer *r, unsigned address, unsigned bpp,
                              unsigned x, unsigned y, unsigned *color,
                              Sm14TileRowCache *cache) {
    unsigned p = 0u, value = 0u, bit = 1u << (7u - x);
    Sm08Status s;
    uint32_t row = (address + y * 2u) & 0xffffu;
    *color = 0u;
    if (cache != NULL && (!cache->valid || cache->address != row || cache->bpp != bpp)) {
        cache->valid = 0u;
        for (p = 0u; p < bpp; ++p)
            cache->plane[p] = r->ppu->vram[(row + (p / 2u) * 16u + (p & 1u)) & 0xffffu];
        cache->address = row;
        cache->bpp = (uint8_t)bpp;
        cache->valid = 1u;
    }
    for (p = 0u; p < bpp; ++p) {
        uint32_t plane_address = (row + (p / 2u) * 16u + (p & 1u)) & 0xffffu;
        if (cache != NULL)
            s = sm14_byte(r, cache->plane[p], bit, SM14_DEP_VRAM, plane_address, &value);
        else
            s = sm14_vram(r, plane_address, bit, &value);
        if (s != SM08_OK) return s;
        if (value) *color |= 1u << p;
    }
    return SM08_OK;
}

static Sm08Status sm14_bg(Sm14Renderer *r, unsigned layer, unsigned priority,
                          unsigned x, unsigned y, Sm14Pixel *pixel,
                          Sm14TileRowCache *row_cache,
                          Sm14BgPixelCache *pixel_cache,
                          Sm14BgLineCache *line_cache) {
    unsigned sx = 0u, sy = 0u, sc = 0u, chr = 0u, lo = 0u, hi = 0u;
    unsigned tx = 0u, ty = 0u, address = 0u, entry = 0u, color = 0u;
    unsigned bpp = layer == 2u ? 2u : 4u;
    Sm08Status s;
    pixel->present = 0u;
    if (pixel_cache->priority_valid) {
        if (pixel_cache->priority != priority) return SM08_OK;
        if (pixel_cache->candidate_valid) {
            *pixel = pixel_cache->pixel;
            return SM08_OK;
        }
    }
    if (!line_cache->valid) {
        unsigned mosaic = 0u;
        s = sm14_reg(r, 6u, 1u << layer, &mosaic); if (s != SM08_OK) return s;
        line_cache->mosaic_enabled = mosaic != 0u;
        line_cache->mosaic_size = 1u;
        if (mosaic) {
            s = sm14_reg(r, 6u, 0xf0u, &mosaic); if (s != SM08_OK) return s;
            line_cache->mosaic_size = (uint8_t)((mosaic >> 4u) + 1u);
        }
        s = sm14_word(r, r->ppu->scroll_x[layer], 0x3ffu, SM14_DEP_SCROLL,
                      0x210du + layer * 2u, &sx); if (s != SM08_OK) return s;
        s = sm14_word(r, r->ppu->scroll_y[layer], 0x3ffu, SM14_DEP_SCROLL,
                      0x210eu + layer * 2u, &sy); if (s != SM08_OK) return s;
        s = sm14_reg(r, 5u, 0x10u << layer, &chr); if (s != SM08_OK) return s;
        if (chr) return sm14_fail(r, SM08_REGISTER, SM14_DEP_REGISTER, 0x2105u,
                                  (uint16_t)(0x10u << layer), (uint16_t)chr,
                                  (uint16_t)(0x10u << layer));
        s = sm14_reg(r, 7u + layer, 0xfcu, &sc); if (s != SM08_OK) return s;
        line_cache->sx = (uint16_t)sx; line_cache->sy = (uint16_t)sy;
        line_cache->sc = (uint8_t)sc; line_cache->valid = 1u;
    }
    if (line_cache->mosaic_enabled) {
        unsigned size = line_cache->mosaic_size;
        x -= x % size;
        y = ((y - 1u) / size) * size + 1u;
    }
    sx = line_cache->sx; sy = line_cache->sy; sc = line_cache->sc;
    x = (x + sx) & 1023u; y = (y + sy) & 1023u;
    tx = x >> 3u; ty = y >> 3u;
    if (tx & 32u) {
        s = sm14_reg(r, 7u + layer, 1u, &chr); if (s != SM08_OK) return s;
        sc |= chr;
    }
    if (ty & 32u) {
        s = sm14_reg(r, 7u + layer, 2u, &chr); if (s != SM08_OK) return s;
        sc |= chr;
        if (chr) {
            s = sm14_reg(r, 7u + layer, 1u, &chr); if (s != SM08_OK) return s;
            sc |= chr;
        }
    }
    address = ((sc & 0xfcu) << 9u) + ((ty & 31u) * 32u + (tx & 31u)) * 2u;
    if ((sc & 1u) && (tx & 32u)) address += 0x800u;
    if ((sc & 2u) && (ty & 32u)) address += (sc & 1u) ? 0x1000u : 0x800u;
    /* A known losing priority can reject early. Unknown priority does not
     * matter until the tile's selected pixel is nontransparent. */
    if ((r->ppu->vram[(address + 1u) & 0xffffu].known_mask & 0x20u) &&
        (((r->ppu->vram[(address + 1u) & 0xffffu].value & 0x20u) ? 1u : 0u) != priority)) {
        pixel_cache->priority_valid = 1u;
        pixel_cache->priority = (uint8_t)(priority ^ 1u);
        return SM08_OK;
    }
    s = sm14_vram(r, address, 255u, &lo); if (s != SM08_OK) return s;
    s = sm14_vram(r, address + 1u, 0xc3u, &hi); if (s != SM08_OK) return s;
    entry = lo | (hi << 8u);
    x &= 7u; y &= 7u;
    if (entry & 0x4000u) x = 7u - x;
    if (entry & 0x8000u) y = 7u - y;
    if (!line_cache->chr_valid) {
        s = sm14_reg(r, layer < 2u ? 0x0bu : 0x0cu,
                     layer == 1u ? 0xf0u : 0x0fu, &chr); if (s != SM08_OK) return s;
        if (layer == 1u) chr >>= 4u;
        line_cache->chr = (uint8_t)chr; line_cache->chr_valid = 1u;
    } else chr = line_cache->chr;
    s = sm14_planes(r, (chr << 13u) + (entry & 1023u) * bpp * 8u,
                    bpp, x, y, &color, row_cache);
    if (s != SM08_OK) return s;
    if (!color) {
        pixel_cache->priority_valid = 1u;
        pixel_cache->priority = (uint8_t)priority;
        pixel_cache->candidate_valid = 1u;
        pixel_cache->pixel = *pixel;
        return SM08_OK;
    }
    s = sm14_vram(r, address + 1u, 0x20u, &hi); if (s != SM08_OK) return s;
    if ((hi ? 1u : 0u) != priority) return SM08_OK;
    s = sm14_vram(r, address + 1u, 0x1cu, &hi); if (s != SM08_OK) return s;
    pixel->present = 1u; pixel->layer = (uint8_t)layer;
    pixel->palette = (uint16_t)(((hi >> 2u) & 7u) * (1u << bpp) + color);
    pixel->direct = 0u; pixel->color = (uint8_t)color;
    pixel_cache->priority_valid = 1u;
    pixel_cache->priority = (uint8_t)priority;
    pixel_cache->candidate_valid = 1u;
    pixel_cache->pixel = *pixel;
    return SM08_OK;
}

static int32_t sm14_signed13(unsigned value) {
    return (value & 0x1000u) ? (int32_t)value - 8192 : (int32_t)value;
}

static int32_t sm14_clip10(int32_t value) {
    unsigned bits = (unsigned)value & 0x3fffu;
    return (bits & 0x2000u) ? (int32_t)(bits & 1023u) - 1024 : (int32_t)(bits & 1023u);
}

static int32_t sm14_floor256(int32_t value) {
    return value >= 0 ? value / 256 : -((255 - value) / 256);
}

static Sm08Status sm14_mode7(Sm14Renderer *r, unsigned x, unsigned y, Sm14Pixel *pixel) {
    unsigned values[8] = {0u}, i = 0u, sel = 0u, tile = 0u, color = 0u, direct = 0u;
    int32_t a, b, c, d, cx, cy, dx, dy, px, py, ox, oy;
    Sm08Status s;
    pixel->present = 0u;
    s = sm14_reg(r, 0x1au, 0xc3u, &sel); if (s != SM08_OK) return s;
    if (sel != 0u && sel != 0x80u)
        return sm14_fail(r, SM08_REGISTER, SM14_DEP_REGISTER, 0x211au, 0xc3u, (uint16_t)sel, 0xc3u);
    s = sm14_mosaic(r, 0u, &x, &y); if (s != SM08_OK) return s;
    for (i = 0u; i < 6u; ++i) {
        s = sm14_word(r, r->ppu->matrix[i], i < 4u ? 0xffffu : 0x1fffu,
                      SM14_DEP_MATRIX, 0x211bu + i, &values[i]);
        if (s != SM08_OK) return s;
    }
    for (i = 0u; i < 2u; ++i) {
        s = sm14_word(r, r->ppu->m7_scroll[i], 0x1fffu, SM14_DEP_SCROLL, 0x210du + i, &values[6u + i]);
        if (s != SM08_OK) return s;
    }
    a = (int16_t)values[0]; b = (int16_t)values[1];
    c = (int16_t)values[2]; d = (int16_t)values[3];
    cx = sm14_signed13(values[4]); cy = sm14_signed13(values[5]);
    dx = sm14_clip10(sm14_signed13(values[6]) - cx);
    dy = sm14_clip10(sm14_signed13(values[7]) - cy);
    ox = (a * dx & ~63) + (b * dy & ~63) + (b * (int32_t)y & ~63) + cx * 256;
    oy = (c * dx & ~63) + (d * dy & ~63) + (d * (int32_t)y & ~63) + cy * 256;
    px = sm14_floor256(ox + a * (int32_t)x);
    py = sm14_floor256(oy + c * (int32_t)x);
    if (sel == 0x80u && (px < 0 || px > 1023 || py < 0 || py > 1023)) return SM08_OK;
    x = (unsigned)px & 1023u; y = (unsigned)py & 1023u;
    s = sm14_vram(r, (((y >> 3u) * 128u) + (x >> 3u)) * 2u, 255u, &tile);
    if (s != SM08_OK) return s;
    s = sm14_vram(r, (tile * 64u + (y & 7u) * 8u + (x & 7u)) * 2u + 1u, 255u, &color);
    if (s != SM08_OK || !color) return s;
    s = sm14_reg(r, 0x30u, 1u, &direct); if (s != SM08_OK) return s;
    pixel->present = 1u; pixel->layer = 0u; pixel->palette = (uint16_t)color;
    pixel->direct = (uint8_t)(direct != 0u); pixel->color = (uint8_t)color;
    return SM08_OK;
}

/* Geometry/status sampling is distinct from pixel payload and palette reads.
 * Unknown geometry leaves status unknown; it faults only if a pixel demands
 * an OBJ candidate. A known sticky overflow is never undone by uncertainty. */
static void sm14_object_unknown(Sm14Renderer *r, unsigned address, unsigned mask) {
    Sm08Value v = r->ppu->oam[address];
    r->objects_valid = 0u;
    if (r->object_failure.status == SM08_OK) {
        r->object_failure.status = SM08_UNKNOWN; r->object_failure.dependency = SM14_DEP_OAM;
        r->object_failure.address = address; r->object_failure.mask = (uint16_t)mask;
        r->object_failure.value = v.value; r->object_failure.known_mask = v.known_mask;
    }
}

static void sm14_objects(Sm14Renderer *r, unsigned y) {
    unsigned n = 0u, high = 0u, shift = 0u, size = 0u, x = 0u, row = 0u, count = 0u;
    unsigned slivers = 0u, col = 0u, flags = 0u;
    int j;
    Sm08Value v;
    r->object_count = 0u; r->objects_valid = 1u;
    r->objects_prepared = 1u; r->object_line = (uint16_t)y;
    memset(&r->object_failure, 0, sizeof(r->object_failure));
    /* Unsupported/unknown OBJ control does not manufacture status zeros or
     * fault a pixel whose selected BG never demands an OBJ contribution. */
    v = r->ppu->registers[1];
    if ((v.known_mask & 0xe0u) != 0xe0u || (v.value & 0xe0u) != 0u) {
        r->objects_valid = 0u;
        r->object_failure.status = (v.known_mask & 0xe0u) != 0xe0u ? SM08_UNKNOWN : SM08_REGISTER;
        r->object_failure.dependency = SM14_DEP_REGISTER; r->object_failure.address = 0x2101u;
        r->object_failure.mask = 0xe0u; r->object_failure.value = v.value;
        r->object_failure.known_mask = v.known_mask;
        r->object_flags = (Sm08Value){0u, 0u};
        return;
    }
    v = r->ppu->registers[3];
    if ((v.known_mask & 0x80u) != 0x80u || (v.value & 0x80u) != 0u) {
        r->objects_valid = 0u;
        r->object_failure.status = (v.known_mask & 0x80u) != 0x80u ? SM08_UNKNOWN : SM08_REGISTER;
        r->object_failure.dependency = SM14_DEP_REGISTER; r->object_failure.address = 0x2103u;
        r->object_failure.mask = 0x80u; r->object_failure.value = v.value;
        r->object_failure.known_mask = v.known_mask;
        r->object_flags = (Sm08Value){0u, 0u};
        return;
    }
    for (n = 0u; n < 128u; ++n) {
        v = r->ppu->oam[n * 4u + 1u];
        if (v.known_mask != 255u) { sm14_object_unknown(r, n * 4u + 1u, 255u); continue; }
        row = (y - v.value) & 255u;
        if (row >= 16u) continue;
        shift = (n & 3u) * 2u; high = 512u + n / 4u;
        v = r->ppu->oam[high];
        if ((v.known_mask & (3u << shift)) != (3u << shift)) {
            sm14_object_unknown(r, high, 3u << shift); continue;
        }
        size = (v.value & (2u << shift)) ? 16u : 8u;
        if (row >= size) continue;
        high = (v.value >> shift) & 1u;
        v = r->ppu->oam[n * 4u];
        if (v.known_mask != 255u) { sm14_object_unknown(r, n * 4u, 255u); continue; }
        x = v.value | (high << 8u);
        if (x > 256u && x + size <= 512u) continue;
        if (++count > 32u) { flags |= 0x40u; break; }
        r->objects[r->object_count].index = (uint8_t)n;
        r->objects[r->object_count].x = (uint16_t)x;
        r->objects[r->object_count].size = (uint8_t)size;
        r->objects[r->object_count].row = (uint8_t)row;
        r->objects[r->object_count].tile_mask = 0u;
        ++r->object_count;
    }
    for (j = (int)r->object_count - 1; j >= 0; --j) {
        for (col = 0u; col < r->objects[j].size / 8u; ++col) {
            x = (r->objects[j].x + col * 8u) & 511u;
            /* Slivers at505..511 cross the9-bit wrap onto screen pixels.
             * X256 retains its special fetch/budget behavior without pixels. */
            if (r->objects[j].x != 256u && x >= 256u && x + 7u < 512u) continue;
            if (++slivers > 34u) { flags |= 0x80u; break; }
            r->objects[j].tile_mask |= (uint8_t)(1u << col);
        }
        if (slivers > 34u) break;
    }
    r->object_flags.value = (uint8_t)flags;
    r->object_flags.known_mask = r->objects_valid ? 0xc0u : (uint8_t)flags;
}

static Sm08Status sm14_obj(Sm14Renderer *r, unsigned wanted, unsigned x, Sm14Pixel *pixel, Sm14ObjPixelCache *cache) {
    unsigned n = 0u, dx = 0u, col = 0u, attr = 0u, name = 0u, base = 0u;
    unsigned tile = 0u, row = 0u, px = 0u, color = 0u, priority = 0u;
    Sm14Object object;
    Sm08Status s;
    pixel->present = 0u;
    if (!r->objects_valid)
        return sm14_fail(r, r->object_failure.status, r->object_failure.dependency, r->object_failure.address,
                         r->object_failure.mask, r->object_failure.value, r->object_failure.known_mask);
    if (cache->valid) {
        if (!cache->present || cache->priority != wanted) return SM08_OK;
        if (!cache->palette_valid) {
            s = sm14_oam(r, cache->index * 4u + 3u, 0x0eu, &attr);
            if (s != SM08_OK) return s;
            cache->pixel.present = 1u; cache->pixel.layer = 4u;
            cache->pixel.palette = (uint16_t)(128u + ((attr >> 1u) & 7u) * 16u + cache->color);
            cache->pixel.direct = 0u; cache->pixel.color = cache->color;
            cache->palette_valid = 1u;
        }
        *pixel = cache->pixel;
        return SM08_OK;
    }
    for (n = 0u; n < r->object_count; ++n) {
        object = r->objects[n];
        dx = (x - object.x) & 511u;
        if (dx >= object.size) continue;
        col = dx / 8u;
        if (!(object.tile_mask & (1u << col))) continue;
        s = sm14_oam(r, object.index * 4u + 3u, 0xc1u, &attr); if (s != SM08_OK) return s;
        s = sm14_oam(r, object.index * 4u + 2u, 255u, &name); if (s != SM08_OK) return s;
        s = sm14_reg(r, 1u, 7u, &base); if (s != SM08_OK) return s;
        row = object.row; px = dx;
        if (attr & 0x80u) row = object.size - 1u - row;
        if (attr & 0x40u) px = object.size - 1u - px;
        tile = (((name >> 4u) + row / 8u) & 15u) * 16u + ((name + px / 8u) & 15u);
        base <<= 14u;
        if (attr & 1u) {
            unsigned offset = 0u;
            s = sm14_reg(r, 1u, 0x18u, &offset); if (s != SM08_OK) return s;
            if (offset) return sm14_fail(r, SM08_REGISTER, SM14_DEP_REGISTER, 0x2101u, 0x18u, (uint16_t)offset, 0x18u);
            base += 0x2000u;
        }
        s = sm14_planes(r, base + tile * 32u, 4u, px & 7u, row & 7u, &color, NULL);
        if (s != SM08_OK) return s;
        if (!color) continue;
        /* First opaque object wins internal OAM ordering, whatever priority. */
        s = sm14_oam(r, object.index * 4u + 3u, 0x30u, &priority); if (s != SM08_OK) return s;
        priority = (priority >> 4u) & 3u;
        /* This is the first opaque object in unchanged OAM order. A losing
         * priority must not consume palette bits, now or on a cache hit. */
        cache->valid = 1u; cache->present = 1u;
        cache->index = object.index; cache->color = (uint8_t)color;
        cache->priority = (uint8_t)priority;
        if (priority != wanted) return SM08_OK;
        s = sm14_oam(r, object.index * 4u + 3u, 0x0eu, &attr); if (s != SM08_OK) return s;
        pixel->present = 1u; pixel->layer = 4u;
        pixel->palette = (uint16_t)(128u + ((attr >> 1u) & 7u) * 16u + color);
        pixel->direct = 0u; pixel->color = (uint8_t)color;
        cache->pixel = *pixel; cache->palette_valid = 1u;
        return SM08_OK;
    }
    cache->valid = 1u; cache->present = 0u;
    return SM08_OK;
}

static Sm08Status sm14_select(Sm14Renderer *r, unsigned mode, unsigned bg3high,
                              unsigned x, unsigned y, unsigned sub, Sm14Pixel *pixel, Sm14ObjPixelCache *cache) {
    unsigned n = mode == 7u ? 5u : 10u, label = 0u, layer = 0u, priority = 0u, enabled = 0u;
    const uint8_t *order = mode == 7u ? sm14_order_m7 : (bg3high ? sm14_order_bg3 : sm14_order_normal);
    Sm08Status s;
    memset(pixel, 0, sizeof(*pixel)); pixel->layer = 5u;
    if (mode == 0u) {
        /* Mode0 has four backgrounds. The fixed lowres OBJ/backdrop path
         * needs no BG decoder only when every BG is effectively disabled
         * on this requested screen at this x (including BG4/window masks).
         * This does not admit unknown modes or intrinsically-hires modes. */
        for (layer = 0u; layer < 4u; ++layer) {
            r->layer = (uint8_t)layer;
            s = sm14_enabled_cached(r, layer, sub, x, &enabled, cache);
            if (s != SM08_OK) return s;
            if (enabled)
                return sm14_fail(r, SM08_REGISTER, SM14_DEP_REGISTER,
                                0x2105u, 7u, 0u, 7u);
        }
        r->layer = 4u;
        s = sm14_enabled_cached(r, 4u, sub, x, &enabled, cache); if (s != SM08_OK) return s;
        if (enabled) {
            for (priority = 4u; priority != 0u; --priority) {
                s = sm14_obj(r, priority - 1u, x, pixel, cache);
                if (s != SM08_OK || pixel->present) return s;
            }
        }
        pixel->layer = 5u; pixel->palette = 0u;
        return SM08_OK;
    }
    if (mode == 1u) {
        if (r->ppu->registers[5].known_mask & 8u) bg3high = (r->ppu->registers[5].value >> 3u) & 1u;
        else {
            s = sm14_enabled_cached(r, 2u, sub, x, &enabled, cache); if (s != SM08_OK) return s;
            if (enabled) {
                s = sm14_reg(r, 5u, 8u, &priority); if (s != SM08_OK) return s;
                bg3high = priority != 0u;
            } else bg3high = 0u;
        }
        order = bg3high ? sm14_order_bg3 : sm14_order_normal;
    }
    while (n != 0u) {
        label = order[--n];
        if (label == SM14_O0 || label == SM14_O1 || label == SM14_O2 || label == SM14_O3) {
            layer = 4u;
            priority = label == SM14_O0 ? 0u : label == SM14_O1 ? 1u : label == SM14_O2 ? 2u : 3u;
        } else if (label == SM14_M7) { layer = 0u; priority = 0u; }
        else {
            layer = (label == SM14_B3L || label == SM14_B3H) ? 2u :
                    (label == SM14_B2L || label == SM14_B2H) ? 1u : 0u;
            priority = label == SM14_B1H || label == SM14_B2H || label == SM14_B3H;
        }
        r->layer = (uint8_t)layer;
        s = sm14_enabled_cached(r, layer, sub, x, &enabled, cache); if (s != SM08_OK) return s;
        if (!enabled) continue;
        if (layer == 4u) s = sm14_obj(r, priority, x, pixel, cache);
        else if (mode == 7u) s = sm14_mode7(r, x, y + 1u, pixel);
        else s = sm14_bg(r, layer, priority, x, y + 1u, pixel,
                         &cache->bg_row[layer], &cache->bg_pixel[layer],
                         &cache->bg_line[layer]);
        if (s != SM08_OK || pixel->present) return s;
    }
    pixel->layer = 5u; pixel->palette = 0u;
    return SM08_OK;
}

static Sm08Status sm14_color(Sm14Renderer *r, Sm14Pixel pixel, uint16_t *color,
                            Sm14ObjPixelCache *cache) {
    unsigned value = pixel.color;
    if (!pixel.direct) {
        unsigned index = pixel.palette & 255u;
        uint8_t bit = (uint8_t)(1u << (index & 7u));
        Sm08Status s;
        if (cache->cgram_valid[index >> 3u] & bit) {
            *color = cache->cgram_value[index];
            return SM08_OK;
        }
        s = sm14_palette(r, index, color);
        if (s != SM08_OK) return s;
        cache->cgram_value[index] = *color;
        cache->cgram_valid[index >> 3u] |= bit;
        return SM08_OK;
    }
    *color = (uint16_t)(((value & 7u) << 2u) | ((value & 0x38u) << 4u) | ((value & 0xc0u) << 7u));
    return SM08_OK;
}

/* CGWSEL clip/prevent modes: never/outside/inside/always. */
static Sm08Status sm14_color_window(Sm14Renderer *r, unsigned mode, unsigned x, unsigned *apply) {
    unsigned inside = 0u;
    Sm08Status s;
    *apply = 0u;
    if (!mode) return SM08_OK;
    if (mode == 3u) { *apply = 1u; return SM08_OK; }
    s = sm14_window(r, 5u, x, &inside); if (s != SM08_OK) return s;
    *apply = mode == 1u ? !inside : inside;
    return SM08_OK;
}

static uint16_t sm14_blend(uint16_t a, uint16_t b, unsigned subtract, unsigned half) {
    unsigned shift = 0u, out = 0u;
    int value;
    for (shift = 0u; shift < 15u; shift += 5u) {
        value = (int)((a >> shift) & 31u);
        if (subtract) value -= (int)((b >> shift) & 31u);
        else value += (int)((b >> shift) & 31u);
        if (value < 0) value = 0;
        if (half) value /= 2;
        if (value > 31) value = 31;
        out |= (unsigned)value << shift;
    }
    return (uint16_t)out;
}

static Sm08Status sm14_pixel_cached(Sm14Renderer *r, uint16_t x, uint16_t y, uint16_t *out, Sm14ObjPixelCache *cache) {
    unsigned display = 0u, mode = 0u, geometry = 0u, v = 0u, cg = 0u;
    unsigned clip = 0u, prevent = 0u, math = 0u, half = 0u, subtract = 0u;
    unsigned sub = 0u, brightness = 0u, shift = 0u;
    uint16_t color = 0u, second = 0u;
    Sm14Pixel main_pixel, sub_pixel;
    Sm08Status s;
    if (!sm14_attached(r) || out == NULL || x >= SM14_WIDTH || y >= SM14_HEIGHT) return SM08_ARGUMENT;
    if (r->bus->fault.status != SM08_OK) return r->bus->fault.status;
    cache->valid = 0u; cache->palette_valid = 0u;
    memset(cache->bg_pixel, 0, sizeof(cache->bg_pixel));
    cache->enabled_valid[0] = 0u; cache->enabled_valid[1] = 0u;
    cache->enabled_value[0] = 0u; cache->enabled_value[1] = 0u;
    r->x = x; r->y = y; r->layer = 5u;
    if (cache->line_stage < 1u) {
        s = sm14_reg(r, 0u, 0x80u, &display); if (s != SM08_OK) return s;
        cache->line_display = (uint8_t)display;
        cache->line_stage = 1u;
    } else display = cache->line_display;
    if (display) { *out = 0u; return SM08_OK; }
    if (cache->line_stage < 2u) {
        s = sm14_reg(r, 0u, 15u, &brightness); if (s != SM08_OK) return s;
        cache->line_brightness = (uint8_t)brightness;
        cache->line_stage = 2u;
    } else brightness = cache->line_brightness;
    if (!brightness) { *out = 0u; return SM08_OK; }
    if (cache->line_stage < 3u) {
        s = sm14_reg(r, 0x33u, 0x4fu, &geometry); if (s != SM08_OK) return s;
        if (geometry != 0u) return sm14_fail(r, SM08_REGISTER, SM14_DEP_GEOMETRY, 0x2133u, 0x4fu, (uint16_t)geometry, 0x4fu);
        s = sm14_reg(r, 5u, 7u, &mode); if (s != SM08_OK) return s;
        if (mode != 0u && mode != 1u && mode != 7u)
            return sm14_fail(r, SM08_REGISTER, SM14_DEP_REGISTER, 0x2105u, 7u, (uint16_t)mode, 7u);
        mode &= 7u;
        s = sm14_reg(r, 0x30u, 0xf0u, &cg); if (s != SM08_OK) return s;
        cache->line_mode = (uint8_t)mode;
        cache->line_cg = (uint8_t)cg;
        cache->line_stage = 3u;
    } else {
        mode = cache->line_mode;
        cg = cache->line_cg;
    }
    s = sm14_color_window(r, (cg >> 6u) & 3u, x, &clip); if (s != SM08_OK) return s;
    s = sm14_color_window(r, (cg >> 4u) & 3u, x, &prevent); if (s != SM08_OK) return s;
    if (clip && prevent) { *out = 0u; return SM08_OK; }
    if (!r->objects_prepared || r->object_line != y) sm14_objects(r, y);
    s = sm14_select(r, mode, 0u, x, y, 0u, &main_pixel, cache); if (s != SM08_OK) return s;
    if (!clip) { s = sm14_color(r, main_pixel, &color, cache); if (s != SM08_OK) return s; }
    if (!prevent) {
        if (main_pixel.layer != 4u || main_pixel.palette >= 192u) {
            s = sm14_reg(r, 0x31u, 1u << main_pixel.layer, &math); if (s != SM08_OK) return s;
        }
        if (math) {
            s = sm14_reg(r, 0x30u, 2u, &sub); if (s != SM08_OK) return s;
            s = sm14_reg(r, 0x31u, 0xc0u, &v); if (s != SM08_OK) return s;
            half = !clip && (v & 0x40u); subtract = v & 0x80u;
            if (sub) {
                s = sm14_select(r, mode, 0u, x, y, 1u, &sub_pixel, cache); if (s != SM08_OK) return s;
                if (sub_pixel.present) { s = sm14_color(r, sub_pixel, &second, cache); if (s != SM08_OK) return s; }
                else {
                    half = 0u;
                    s = sm14_word(r, r->ppu->fixed_color, 0x7fffu, SM14_DEP_REGISTER, 0x2132u, &v);
                    if (s != SM08_OK) return s;
                    second = (uint16_t)v;
                }
            } else {
                s = sm14_word(r, r->ppu->fixed_color, 0x7fffu, SM14_DEP_REGISTER, 0x2132u, &v);
                if (s != SM08_OK) return s;
                second = (uint16_t)v;
            }
            color = sm14_blend(color, second, subtract, half);
        }
    }
    *out = 0u;
    for (shift = 0u; shift < 15u; shift += 5u)
        *out |= (uint16_t)((((color >> shift) & 31u) * brightness / 15u) << shift);
    return SM08_OK;
}

Sm08Status sm14_renderer_pixel(Sm14Renderer *r, uint16_t x, uint16_t y, uint16_t *out) {
    Sm14ObjPixelCache cache = {0};
    return sm14_pixel_cached(r, x, y, out, &cache);
}

Sm08Status sm14_renderer_render_line(Sm14Renderer *r, uint16_t y) {
    Sm14ObjPixelCache cache = {0};
    unsigned x = 0u, index = 0u, blank = 0u;
    uint16_t color = 0u;
    Sm08Status s;
    if (!sm14_attached(r) || y >= SM14_HEIGHT) return SM08_ARGUMENT;
    if (r->bus->fault.status != SM08_OK) return r->bus->fault.status;
    r->x = 0u; r->y = y; r->layer = 4u; r->objects_prepared = 0u;
    s = sm14_reg(r, 0u, 0x80u, &blank); if (s != SM08_OK) return s;
    if (!blank) {
        sm14_objects(r, y);
        s = sm11_ppu_obj_flags(r->ppu, r->object_flags); if (s != SM08_OK) return s;
    }
    for (x = 0u; x < SM14_WIDTH; ++x) {
        s = sm14_pixel_cached(r, (uint16_t)x, y, &color, &cache); if (s != SM08_OK) return s;
        index = (unsigned)y * SM14_WIDTH + x;
        r->work[index] = color;
        r->work_known[index >> 3u] |= (uint8_t)(1u << (index & 7u));
    }
    return SM08_OK;
}

Sm08Status sm14_renderer_power_on(Sm14Renderer *r, Sm11Ppu *ppu) {
    if (r == NULL || ppu == NULL || ppu->bus == NULL || ppu->scheduler == NULL ||
        ppu->scheduler->bus != ppu->bus) return SM08_ARGUMENT;
    if (ppu->bus->fault.status != SM08_OK) return ppu->bus->fault.status;
    memset(r, 0, sizeof(*r));
    r->ppu = ppu; r->bus = ppu->bus; r->scheduler = ppu->scheduler;
    r->width = SM14_WIDTH; r->height = SM14_HEIGHT;
    return SM08_OK;
}

Sm08Status sm14_renderer_raster_event(Sm14Renderer *r, Sm08Bus *bus,
                                     const Sm09Scheduler *scheduler, Sm09RasterEvent event) {
    if (!sm14_attached(r) || bus != r->bus || scheduler != r->scheduler) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (event == SM09_RASTER_LINE_BEGIN && scheduler->scanline == 0u) {
        memset(r->work_known, 0, sizeof(r->work_known));
        r->field_published = 0u; r->objects_prepared = 0u;
    }
    if (event == SM09_RASTER_HBLANK_BEGIN && scheduler->scanline > 0u && scheduler->scanline <= SM14_HEIGHT)
        return sm14_renderer_render_line(r, (uint16_t)(scheduler->scanline - 1u));
    if (event == SM09_RASTER_VBLANK_BEGIN && !r->field_published) {
        if (r->sequence == UINT64_MAX)
            return sm14_fail(r, SM08_GUARD, SM14_DEP_GEOMETRY, 0u, 0u, 0u, 0u);
        memcpy(r->published, r->work, sizeof(r->published));
        memcpy(r->published_known, r->work_known, sizeof(r->published_known));
        r->published_width = r->width; r->published_height = r->height;
        ++r->sequence; r->ready = 1u; r->field_published = 1u;
    }
    return SM08_OK;
}

static Sm08Status sm14_forward_smp(void *context, Sm08Bus *bus, uint64_t target) {
    Sm14Renderer *r = context;
    if (!sm14_attached(r) || bus != r->bus) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    return r->downstream.smp_sync(r->downstream.context, bus, target);
}

static Sm08Status sm14_forward_raster(void *context, Sm08Bus *bus,
                                     const Sm09Scheduler *scheduler, Sm09RasterEvent event) {
    Sm14Renderer *r = context;
    Sm08Status s;
    if (!sm14_attached(r) || bus != r->bus || scheduler != r->scheduler) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    s = r->downstream.raster_event(r->downstream.context, bus, scheduler, event);
    if (s != SM08_OK || bus->fault.status != SM08_OK) return bus->fault.status != SM08_OK ? bus->fault.status : s;
    return sm14_renderer_raster_event(r, bus, scheduler, event);
}

static Sm08Status sm14_forward_boundary(void *context, Sm08Bus *bus,
                                       const Sm09Scheduler *scheduler, uint8_t kind,
                                       uint32_t address, uint8_t clocks) {
    Sm14Renderer *r = context;
    if (!sm14_attached(r) || bus != r->bus || scheduler != r->scheduler) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    return r->downstream.cpu_boundary(r->downstream.context, bus, scheduler, kind, address, clocks);
}

Sm08Status sm14_renderer_bind(Sm14Renderer *r) {
    if (!sm14_attached(r) || r->bound || !r->ppu->bound || r->scheduler->advancing ||
        r->scheduler->master_clock != 0u || r->scheduler->receivers.context == r ||
        r->scheduler->receivers.smp_sync == NULL || r->scheduler->receivers.raster_event == NULL ||
        r->scheduler->receivers.cpu_boundary == NULL) return SM08_ARGUMENT;
    if (r->bus->fault.status != SM08_OK) return r->bus->fault.status;
    r->downstream = r->scheduler->receivers;
    r->scheduler->receivers.context = r;
    r->scheduler->receivers.smp_sync = sm14_forward_smp;
    r->scheduler->receivers.raster_event = sm14_forward_raster;
    r->scheduler->receivers.cpu_boundary = sm14_forward_boundary;
    r->bound = 1u;
    return SM08_OK;
}

int sm14_renderer_copy_frame(const Sm14Renderer *r, uint16_t *pixels,
                             uint32_t pixel_capacity, uint8_t *known_map,
                             uint32_t known_capacity, uint16_t *width,
                             uint16_t *height, uint64_t *sequence) {
    if (!sm14_attached(r) || !r->ready || pixels == NULL || known_map == NULL ||
        width == NULL || height == NULL || sequence == NULL ||
        pixel_capacity < SM14_PIXELS || known_capacity < SM14_KNOWN_BYTES) return 0;
    memcpy(pixels, r->published, sizeof(r->published));
    memcpy(known_map, r->published_known, sizeof(r->published_known));
    *width = r->published_width; *height = r->published_height; *sequence = r->sequence;
    return 1;
}
