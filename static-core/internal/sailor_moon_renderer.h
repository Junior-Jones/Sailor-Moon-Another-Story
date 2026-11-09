#ifndef SAILOR_MOON_RENDERER_H
#define SAILOR_MOON_RENDERER_H
#include "sailor_moon_ppu.h"

enum { SM14_WIDTH = 256u, SM14_HEIGHT = 224u,
       SM14_PIXELS = SM14_WIDTH * SM14_HEIGHT,
       SM14_KNOWN_BYTES = (SM14_PIXELS + 7u) / 8u };

typedef enum Sm14Dependency {
    SM14_DEP_NONE, SM14_DEP_REGISTER, SM14_DEP_VRAM, SM14_DEP_CGRAM,
    SM14_DEP_OAM, SM14_DEP_SCROLL, SM14_DEP_MATRIX, SM14_DEP_GEOMETRY
} Sm14Dependency;

typedef struct Sm14Failure {
    Sm08Status status;
    Sm14Dependency dependency;
    uint32_t address;
    uint16_t mask, value, known_mask, x, y;
    uint8_t layer;
} Sm14Failure;

typedef struct Sm14Object {
    uint16_t x;
    uint8_t index, size, row, tile_mask;
} Sm14Object;

typedef struct Sm14Renderer {
    Sm11Ppu *ppu;
    Sm08Bus *bus;
    Sm09Scheduler *scheduler;
    Sm09Receivers downstream;
    uint16_t work[SM14_PIXELS], published[SM14_PIXELS];
    uint8_t work_known[SM14_KNOWN_BYTES], published_known[SM14_KNOWN_BYTES];
    uint16_t width, height, published_width, published_height;
    uint64_t sequence;
    uint8_t bound, ready, field_published;
    uint16_t x, y;
    uint8_t layer;
    Sm14Failure failure, object_failure;
    Sm14Object objects[32];
    uint8_t object_count, objects_valid, objects_prepared;
    uint16_t object_line;
    Sm08Value object_flags;
} Sm14Renderer;

/* Declared following-line HBLANK sampling of the sole11 tagged state.
 * Output is core BGR555, 256x224; no scaling, renderer clock or PPU bus access.
 * Modes1/7 and normal SETINI00/OBJ-size0 are the source-qualified class.
 * Unsupported or demanded unknown state is a typed fault, never a fallback. */
Sm08Status sm14_renderer_power_on(Sm14Renderer *, Sm11Ppu *);
Sm08Status sm14_renderer_bind(Sm14Renderer *);
Sm08Status sm14_renderer_raster_event(Sm14Renderer *, Sm08Bus *,
                                     const Sm09Scheduler *, Sm09RasterEvent);
/* Author/owner APIs use the same pixel and scanline path as raster sampling.
 * y is output row0..223, corresponding to actual visible scanline y+1.
 * pixel invalidates no published frame; render_line records work knownness. */
Sm08Status sm14_renderer_pixel(Sm14Renderer *, uint16_t x, uint16_t y, uint16_t *color);
Sm08Status sm14_renderer_render_line(Sm14Renderer *, uint16_t y);
/* Observational copy; all capacities validated before any output mutation. */
int sm14_renderer_copy_frame(const Sm14Renderer *, uint16_t *pixels,
                             uint32_t pixel_capacity, uint8_t *known_map,
                             uint32_t known_capacity, uint16_t *width,
                             uint16_t *height, uint64_t *sequence);
#endif
