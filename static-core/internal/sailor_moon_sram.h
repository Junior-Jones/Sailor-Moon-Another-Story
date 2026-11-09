#ifndef SAILOR_MOON_SRAM_H
#define SAILOR_MOON_SRAM_H
#include "sailor_moon_memory.h"
enum { SM08_SRAM_HEADER_SIZE = 80u, SM08_SRAM_PAYLOAD_SIZE = 9216u,
       SM08_SRAM_FILE_SIZE = 9296u };
/* Portable battery-save data, not a machine snapshot. No host filesystem.
 * Disjoint caller buffers and a quiescent instance are required. Encoding
 * exports but does not acknowledge generation; decoding commits only after
 * every file/identity/integrity check succeeds and access has not begun. */
Sm08Status sm08_sram_encode(const Sm08Memory *, uint8_t *, size_t, uint64_t *);
Sm08Status sm08_sram_decode(Sm08Memory *, const uint8_t *, size_t);
#endif
