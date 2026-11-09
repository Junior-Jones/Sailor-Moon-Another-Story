#ifndef SAILOR_MOON_MEMORY_H
#define SAILOR_MOON_MEMORY_H
#include "sailor_moon_bus_types.h"
typedef struct Sm08SramImage {
    uint8_t values[SM08_SRAM_SIZE];
    uint8_t known[SM08_SRAM_SIZE / 8u];
} Sm08SramImage;
typedef struct Sm08Memory {
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[SM08_WRAM_SIZE];
    uint8_t wram_known[SM08_WRAM_SIZE / 8u];
    Sm08SramImage sram;
    uint64_t sram_generation;
    uint8_t sram_dirty, access_started;
} Sm08Memory;
/* Call at a quiescent boundary. ROM stays immutable and disjoint from receiver.
 * Other input/output buffers are disjoint from receiver except exact image self
 * copy handled by memmove. This component owns no bus/MDR/clock/device effect. */
Sm08Status sm08_memory_power_on(Sm08Memory *, const uint8_t *, size_t);
Sm08Status sm08_memory_reset(Sm08Memory *);
Sm08Status sm08_memory_peek(const Sm08Memory *, uint32_t, Sm08Cell *);
Sm08Status sm08_memory_read(Sm08Memory *, uint32_t, Sm08Cell *);
Sm08Status sm08_memory_write(Sm08Memory *, uint32_t, Sm08Cell);
Sm08Status sm08_memory_load_sram(Sm08Memory *, const Sm08SramImage *);
Sm08Status sm08_memory_export_sram(const Sm08Memory *, Sm08SramImage *, uint64_t *);
int sm08_memory_ack_sram(Sm08Memory *, uint64_t);
#endif
