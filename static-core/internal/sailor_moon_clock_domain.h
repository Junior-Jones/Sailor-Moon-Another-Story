#ifndef SAILOR_MOON_CLOCK_DOMAIN_H
#define SAILOR_MOON_CLOCK_DOMAIN_H
#include <stdint.h>

/* Explicit functional profile, not physically phase-locked oscillators. */
enum {
    SM09_MASTER_NUMERATOR = 236250000u,
    SM09_MASTER_DENOMINATOR = 11u,
    SM09_SMP_NUMERATOR = 5632u,
    SM09_SMP_DENOMINATOR = 118125u,
    SM09_NORMAL_LINE = 1364u,
    SM09_SHORT_LINE = 1360u,
    SM09_FIELD_LINES = 262u
};
typedef struct Sm09SmpJoin {
    uint64_t target_cycles;
    uint32_t remainder;
} Sm09SmpJoin;
typedef struct Sm09TimingProfile {
    uint32_t master_numerator, master_denominator;
    uint32_t smp_numerator, smp_denominator;
    uint16_t normal_line, short_line, field_lines;
} Sm09TimingProfile;
const Sm09TimingProfile *sm09_timing_profile(void);
void sm09_smp_cold(Sm09SmpJoin *);
int sm09_smp_advance(Sm09SmpJoin *, uint32_t);
#endif
