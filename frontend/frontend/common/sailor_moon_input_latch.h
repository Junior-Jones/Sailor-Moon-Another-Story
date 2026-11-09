#ifndef SAILOR_MOON_INPUT_LATCH_H
#define SAILOR_MOON_INPUT_LATCH_H

#include <stdint.h>

typedef struct SailorMoonInputLatch {
    uint16_t held;
    uint16_t pending_press;
} SailorMoonInputLatch;

void sailor_moon_input_latch_reset(SailorMoonInputLatch *latch);
void sailor_moon_input_latch_press(SailorMoonInputLatch *latch, uint16_t mask,
                           uint16_t unsampled_opposite_mask, int repeated);
void sailor_moon_input_latch_release(SailorMoonInputLatch *latch, uint16_t mask);
uint16_t sailor_moon_input_latch_sample(const SailorMoonInputLatch *latch);
void sailor_moon_input_latch_consume(SailorMoonInputLatch *latch, uint16_t sampled_mask);

#endif
