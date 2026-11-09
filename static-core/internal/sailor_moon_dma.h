#ifndef SAILOR_MOON_DMA_H
#define SAILOR_MOON_DMA_H
#include "sailor_moon_scheduler.h"

/* Architectural register lanes0..B, with F aliasing B. Data and knowledge
 * travel together; only bits actually consumed by an operation must be known. */
typedef struct Sm10Channel {
    Sm08Value registers[12];
    uint8_t manual_active, finished, transfer_line;
} Sm10Channel;

typedef struct Sm10Dma {
    Sm08Bus *bus;
    Sm09Scheduler *scheduler;
    Sm09Receivers downstream;
    Sm10Channel channel[8];
    uint64_t completed_bytes;
    uint8_t manual_pending, hdma_enable, line_pending, init_pending;
    uint8_t start_delay, servicing, active_channel;
} Sm10Dma;

/* Cold assembly after09 construction at master0, before CPU release. Retains
 * mandatory SMP/raster receivers. The previous CPU-boundary callback is
 * replaced, never delegated; this is the sole transfer boundary owner. */
Sm08Status sm10_dma_bind(Sm10Dma *, Sm08Bus *, Sm09Scheduler *);
/* Warm reset cancels requests/activity, retaining register bytes/knownness,
 * hidden cursor state and the existing09 absolute clock/alignment phase. */
Sm08Status sm10_dma_reset(Sm10Dma *);
#endif
