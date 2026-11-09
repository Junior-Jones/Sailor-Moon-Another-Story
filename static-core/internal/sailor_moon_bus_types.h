#ifndef SAILOR_MOON_BUS_TYPES_H
#define SAILOR_MOON_BUS_TYPES_H
#include <stddef.h>
#include <stdint.h>

/* 01C's pinned cartridge profile. No foreign cartridge settings. */
enum { SM08_ROM_SIZE = 0x400000u, SM08_WRAM_SIZE = 0x20000u,
       SM08_SRAM_SIZE = 0x2000u };

typedef enum Sm08Status {
    SM08_OK = 0, SM08_ARGUMENT, SM08_BAD_ROM, SM08_UNKNOWN,
    SM08_GUARD, SM08_STORAGE, SM08_LATE_SRAM_LOAD, SM08_SRAM_OVERFLOW,
    SM08_BAD_SAVE, SM08_PPU_ABSENT, SM08_APUIO_ABSENT,
    SM08_DMA_ABSENT, SM08_INPUT_ABSENT, SM08_CLOCK_ABSENT,
    SM08_IO_ABSENT, SM08_REGISTER
} Sm08Status;

typedef enum Sm08Kind {
    SM08_OPEN_EXTERNAL, SM08_ROM, SM08_WRAM, SM08_SRAM,
    SM08_PPU, SM08_APUIO, SM08_WRAM_PORT, SM08_CPU_IO,
    SM08_SCHEDULER_IO, SM08_DMA_IO, SM08_INPUT_IO, SM08_OPEN_INTERNAL
} Sm08Kind;

typedef struct Sm08Region {
    Sm08Kind kind;
    unsigned owner;
    uint32_t offset;
    uint8_t internal_io;
} Sm08Region;

/* Raw representatives carry no authority in bits not marked known. */
typedef struct Sm08Value { uint8_t value, known_mask; } Sm08Value;
typedef struct Sm08Drive { uint8_t value, driven_mask, known_mask; } Sm08Drive;
/* Memory uses one knownness bit per byte, packed in storage/transport. */
typedef struct Sm08Cell { uint8_t value, known; } Sm08Cell;

/* Pure placement/speed classification: neither function performs an access. */
int sm08_decode(uint32_t address, Sm08Region *region);
int sm08_access_period(uint32_t address, uint8_t memsel, uint8_t *clocks);
#endif
