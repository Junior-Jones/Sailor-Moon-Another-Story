#ifndef SAILOR_MOON_PPU_H
#define SAILOR_MOON_PPU_H
#include "sailor_moon_scheduler.h"

enum { SM11_VRAM_BYTES = 65536u, SM11_CGRAM_BYTES = 512u,
       SM11_OAM_BYTES = 544u, SM11_PPU1_VERSION = 1u, SM11_PPU2_VERSION = 3u };

typedef struct Sm11Word { uint16_t value, known_mask; } Sm11Word;

/* State only. 14 consumes these tagged values and the same09 raster stream;
 * no framebuffer, pixel producer, alternate clock or memory bypass lives here.
 * VRAM storage is bytes, VMADD is a 15-bit word address. CGADD counts colors.
 * OAM cursor is a logical byte address; its high table mirrors 32 bytes.
 * Scroll retains the full latch word (including HOFS feedback bit10);14
 * consumes its effective low10 bits, not a prematurely truncated latch. */
typedef struct Sm11Ppu {
    Sm08Bus *bus;
    Sm09Scheduler *scheduler;
    const Sm08Value *wrio;
    Sm09Receivers downstream;
    Sm08Value registers[64];
    Sm08Value vram[SM11_VRAM_BYTES], cgram[SM11_CGRAM_BYTES], oam[SM11_OAM_BYTES];
    Sm11Word scroll_x[4], scroll_y[4], matrix[6], m7_scroll[2], fixed_color;
    Sm11Word vram_address, oam_reload, oam_address;
    Sm08Value cgram_address, read_buffer[2], oam_buffer, cgram_buffer;
    Sm08Value scroll_previous, m7_previous;
    Sm08Value ppu1_mdr, ppu2_mdr, brightness, obj_status;
    uint16_t counter_h, counter_v;
    uint8_t forced_blank, cgram_second, counter_latched, counter_h_second, counter_v_second;
    uint8_t bound;
    uint64_t reads[64], writes[64], storage_reads, storage_writes;
} Sm11Ppu;

/* Own explicit functional cold policy: unknown video RAM/control values;
 * forced blank known, no fabricated zero-storage profile. Same-bus scheduler
 * attachment and WRIO bit7 receiver are required before publication. */
Sm08Status sm11_ppu_power_on(Sm11Ppu *, Sm08Bus *, Sm09Scheduler *, const Sm08Value *wrio);
/* Hardware reset preserves video registers/storage/geometry and actual09 time.
 * Force blank and reset counter-read sequencing; caller/09 owns access abort. */
Sm08Status sm11_ppu_reset(Sm11Ppu *);
Sm08Device sm11_ppu_device(Sm11Ppu *);
/* Bind before10DMA. Preserve all three actual scheduler receiver contexts. */
Sm08Status sm11_ppu_bind(Sm11Ppu *);
Sm08Status sm11_ppu_raster_event(Sm11Ppu *, Sm08Bus *, const Sm09Scheduler *, Sm09RasterEvent);
/* Typed producer seams:14 reports sticky OBJ overflow,15/WRIO pin wiring
 * requests an actual external counter latch. Neither seam creates pixels,
 * guessed input, raster advancement or a second register owner. */
Sm08Status sm11_ppu_obj_flags(Sm11Ppu *, Sm08Value flags);
Sm08Status sm11_ppu_latch_counters(Sm11Ppu *);
#endif
