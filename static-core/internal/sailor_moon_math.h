#ifndef SAILOR_MOON_MATH_H
#define SAILOR_MOON_MATH_H

#include "sailor_moon_bus_types.h"

/* The three word latches are dividend, quotient, and product/remainder.
 * Their raw representatives have authority only under the matching masks. */
typedef struct Sm08Math {
    uint16_t words[3];
    uint16_t known[3];
    uint32_t serial;
    uint32_t serial_known;
    Sm08Value factor;
    uint8_t mode;
    uint8_t remaining;
} Sm08Math;

void sm08_math_init(Sm08Math *math);
Sm08Status sm08_math_write(Sm08Math *math, uint16_t reg, Sm08Value byte);
Sm08Status sm08_math_read(const Sm08Math *math, uint16_t reg, Sm08Drive *byte);

/* One arithmetic pulse, with no elapsed-time owner. The09 clock supplies it
 * before a cycle's bus sample/commit. Calculation takes8/16 pulses; its final
 * result is visible while the trigger remains inhibited. The following tick
 * releases that inhibit without performing another arithmetic step. Reset
 * preserves this state; it must not call init or invent completion. */
void sm08_math_tick(Sm08Math *math);

#endif
