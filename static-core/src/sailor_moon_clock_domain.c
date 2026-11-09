#include "sailor_moon_clock_domain.h"
#include <stddef.h>

_Static_assert((uint64_t)SM09_MASTER_NUMERATOR * SM09_SMP_NUMERATOR ==
               (uint64_t)1024000u * SM09_MASTER_DENOMINATOR * SM09_SMP_DENOMINATOR,
               "SMP ratio must agree with the selected rational profile");

const Sm09TimingProfile *sm09_timing_profile(void) {
    static const Sm09TimingProfile profile = {
        SM09_MASTER_NUMERATOR, SM09_MASTER_DENOMINATOR,
        SM09_SMP_NUMERATOR, SM09_SMP_DENOMINATOR,
        SM09_NORMAL_LINE, SM09_SHORT_LINE, SM09_FIELD_LINES
    };
    return &profile;
}

void sm09_smp_cold(Sm09SmpJoin *join) {
    if (join != NULL) {
        join->target_cycles = 0u;
        join->remainder = 0u;
    }
}

int sm09_smp_advance(Sm09SmpJoin *join, uint32_t elapsed) {
    uint64_t numerator, increment;
    if (join == NULL || join->remainder >= SM09_SMP_DENOMINATOR) return 0;
    numerator = (uint64_t)elapsed * SM09_SMP_NUMERATOR + join->remainder;
    increment = numerator / SM09_SMP_DENOMINATOR;
    if (increment > UINT64_MAX - join->target_cycles) return 0;
    join->target_cycles += increment;
    join->remainder = (uint32_t)(numerator % SM09_SMP_DENOMINATOR);
    return 1;
}
