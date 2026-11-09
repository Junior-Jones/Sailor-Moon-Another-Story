#include "sailor_moon_bus_types.h"

/* Own01 single-ROM HiROM contract: 22 connected ROM address bits and
 * one8KiB SRAM page. Placement is not physical PCB identification. */
int sm08_decode(uint32_t address, Sm08Region *region) {
    uint32_t bank, low;
    Sm08Region found = {SM08_OPEN_EXTERNAL, 8u, 0u, 0u};
    if (region == 0 || address > 0xFFFFFFu) return 0;
    bank = address >> 16;
    low = address & 0xFFFFu;
    found.offset = low;
    if ((bank & 0xFEu) == 0x7Eu) {
        found.kind = SM08_WRAM;
        found.offset = address - 0x7E0000u;
    } else if ((bank & 0x40u) != 0u || low >= 0x8000u) {
        found.kind = SM08_ROM;
        found.offset = address & 0x3FFFFFu;
    } else if (low < 0x2000u) {
        found.kind = SM08_WRAM;
    } else if ((bank & 0x20u) != 0u && low >= 0x6000u) {
        found.kind = SM08_SRAM;
        found.offset = low & 0x1FFFu;
    } else if (low >= 0x2100u && low <= 0x213Fu) {
        found.kind = SM08_PPU; found.owner = 11u;
    } else if (low >= 0x2140u && low <= 0x217Fu) {
        found.kind = SM08_APUIO; found.owner = 12u;
        found.offset = 0x2140u | (low & 3u);
    } else if (low >= 0x2180u && low <= 0x2183u) {
        found.kind = SM08_WRAM_PORT;
    } else if (low >= 0x4000u && low <= 0x43FFu) {
        found.kind = SM08_OPEN_INTERNAL; found.internal_io = 1u;
        if (low == 0x4016u || low == 0x4017u || (low >= 0x4218u && low <= 0x421Fu)) {
            found.kind = SM08_INPUT_IO; found.owner = 15u;
        } else if (low == 0x4201u || (low >= 0x4202u && low <= 0x4206u) ||
                   low == 0x420Du || low == 0x4213u || (low >= 0x4214u && low <= 0x4217u)) {
            found.kind = SM08_CPU_IO;
        } else if (low == 0x4200u || (low >= 0x4207u && low <= 0x420Au) ||
                   (low >= 0x4210u && low <= 0x4212u)) {
            found.kind = SM08_SCHEDULER_IO; found.owner = 9u;
        } else if (low == 0x420Bu || low == 0x420Cu || (low >= 0x4300u && low <= 0x437Fu)) {
            found.kind = SM08_DMA_IO; found.owner = 10u;
        }
    }
    *region = found;
    return 1;
}

int sm08_access_period(uint32_t address, uint8_t memsel, uint8_t *clocks) {
    uint32_t bank, low;
    uint8_t period = 8u;
    if (clocks == 0 || address > 0xFFFFFFu || memsel > 1u) return 0;
    bank = address >> 16;
    low = address & 0xFFFFu;
    if ((bank & 0x40u) == 0u) {
        if ((low >= 0x2000u && low < 0x4000u) || (low >= 0x4200u && low < 0x6000u)) period = 6u;
        else if (low >= 0x4000u && low < 0x4200u) period = 12u;
        else if (bank >= 0x80u && low >= 0x8000u && memsel != 0u) period = 6u;
    } else if (bank >= 0xC0u && memsel != 0u) period = 6u;
    *clocks = period;
    return 1;
}
