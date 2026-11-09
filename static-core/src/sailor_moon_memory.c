#include "sailor_moon_memory.h"
#include "sailor_moon_identity.h"
#include <string.h>

static uint8_t sm08_bit(const uint8_t *bits, uint32_t offset) {
    return (uint8_t)((bits[offset >> 3u] >> (offset & 7u)) & 1u);
}
static void sm08_put_bit(uint8_t *bits, uint32_t offset, uint8_t known) {
    uint8_t select = (uint8_t)(1u << (offset & 7u));
    bits[offset >> 3u] = (uint8_t)((bits[offset >> 3u] & (0xFFu ^ select)) | (known != 0u ? select : 0u));
}
Sm08Status sm08_memory_power_on(Sm08Memory *m, const uint8_t *rom, size_t size) {
    if (m == 0 || rom == 0) return SM08_ARGUMENT;
    if (size != SM08_ROM_SIZE || sm08_rom_matches(rom, size) == 0) return SM08_BAD_ROM;
    /* Validate identity before the first instance mutation. */
    memset(m, 0, sizeof(*m));
    m->rom = rom; m->rom_size = size;
    /* Own project fresh-cartridge contract, not universal battery-RAM truth. */
    memset(m->sram.values, 0xFF, sizeof(m->sram.values));
    memset(m->sram.known, 0xFF, sizeof(m->sram.known));
    return SM08_OK;
}
Sm08Status sm08_memory_reset(Sm08Memory *m) {
    if (m == 0) return SM08_ARGUMENT;
    if (m->rom == 0 || m->rom_size != SM08_ROM_SIZE) return SM08_BAD_ROM;
    return SM08_OK;
}
Sm08Status sm08_memory_peek(const Sm08Memory *m, uint32_t address, Sm08Cell *cell) {
    Sm08Region r;
    Sm08Cell answer;
    if (m == 0 || cell == 0 || sm08_decode(address, &r) == 0) return SM08_ARGUMENT;
    if (m->rom == 0 || m->rom_size != SM08_ROM_SIZE) return SM08_BAD_ROM;
    if (r.kind == SM08_ROM) {
        if (r.offset >= m->rom_size) return SM08_BAD_ROM;
        answer.value = m->rom[r.offset]; answer.known = 1u;
    } else if (r.kind == SM08_WRAM) {
        answer.value = m->wram[r.offset]; answer.known = sm08_bit(m->wram_known, r.offset);
    } else if (r.kind == SM08_SRAM) {
        answer.value = m->sram.values[r.offset]; answer.known = sm08_bit(m->sram.known, r.offset);
    } else return SM08_STORAGE;
    *cell = answer;
    return SM08_OK;
}
Sm08Status sm08_memory_read(Sm08Memory *m, uint32_t address, Sm08Cell *cell) {
    Sm08Status result = sm08_memory_peek(m, address, cell);
    if (result == SM08_OK) m->access_started = 1u;
    return result;
}
Sm08Status sm08_memory_write(Sm08Memory *m, uint32_t address, Sm08Cell cell) {
    Sm08Region r;
    if (m == 0 || cell.known > 1u || sm08_decode(address, &r) == 0) return SM08_ARGUMENT;
    if (m->rom == 0 || m->rom_size != SM08_ROM_SIZE) return SM08_BAD_ROM;
    if (r.kind == SM08_SRAM) {
        uint8_t was_known = sm08_bit(m->sram.known, r.offset);
        int changes = was_known != cell.known || (cell.known != 0u && m->sram.values[r.offset] != cell.value);
        if (changes != 0 && m->sram_generation == UINT64_MAX) return SM08_SRAM_OVERFLOW;
        m->sram.values[r.offset] = cell.value;
        sm08_put_bit(m->sram.known, r.offset, cell.known);
        if (changes != 0) { m->sram_generation = m->sram_generation + 1u; m->sram_dirty = 1u; }
    } else if (r.kind == SM08_WRAM) {
        m->wram[r.offset] = cell.value;
        sm08_put_bit(m->wram_known, r.offset, cell.known);
    } else if (r.kind != SM08_ROM) return SM08_STORAGE;
    /* A ROM write drives the bus but does not mutate its immutable storage. */
    m->access_started = 1u;
    return SM08_OK;
}
Sm08Status sm08_memory_load_sram(Sm08Memory *m, const Sm08SramImage *image) {
    if (m == 0 || image == 0) return SM08_ARGUMENT;
    if (m->rom == 0 || m->rom_size != SM08_ROM_SIZE) return SM08_BAD_ROM;
    if (m->access_started != 0u) return SM08_LATE_SRAM_LOAD;
    memmove(&m->sram, image, sizeof(m->sram));
    m->sram_generation = 0u; m->sram_dirty = 0u;
    return SM08_OK;
}
Sm08Status sm08_memory_export_sram(const Sm08Memory *m, Sm08SramImage *image, uint64_t *generation) {
    if (m == 0 || image == 0 || generation == 0) return SM08_ARGUMENT;
    if (m->rom == 0 || m->rom_size != SM08_ROM_SIZE) return SM08_BAD_ROM;
    memmove(image, &m->sram, sizeof(*image));
    *generation = m->sram_generation;
    return SM08_OK;
}
int sm08_memory_ack_sram(Sm08Memory *m, uint64_t generation) {
    if (m == 0 || m->rom == 0 || m->rom_size != SM08_ROM_SIZE || generation != m->sram_generation) return 0;
    m->sram_dirty = 0u;
    return 1;
}
