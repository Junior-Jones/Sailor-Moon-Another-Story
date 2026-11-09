#include "sailor_moon_math.h"

enum { SM08_DIVIDEND = 0, SM08_QUOTIENT = 1, SM08_RESULT = 2 };

void sm08_math_init(Sm08Math *math) {
    if (math == NULL) return;
    math->words[SM08_DIVIDEND] = 0xFFFFu;
    math->words[SM08_QUOTIENT] = 0u;
    math->words[SM08_RESULT] = 0u;
    math->known[SM08_DIVIDEND] = 0xFFFFu;
    math->known[SM08_QUOTIENT] = 0xFFFFu;
    math->known[SM08_RESULT] = 0u;
    math->serial = 0u;
    math->serial_known = 0u;
    math->factor.value = 0xFFu;
    math->factor.known_mask = 0xFFu;
    math->mode = 0u;
    math->remaining = 0u;
}

Sm08Status sm08_math_write(Sm08Math *math, uint16_t reg, Sm08Value byte) {
    if (math == NULL) return SM08_ARGUMENT;
    if (reg == 0x4202u) {
        math->factor.value = byte.value;
        math->factor.known_mask = byte.known_mask;
        return SM08_OK;
    }
    if (reg == 0x4204u) {
        math->words[SM08_DIVIDEND] = (uint16_t)((math->words[SM08_DIVIDEND] & 0xFF00u) | byte.value);
        math->known[SM08_DIVIDEND] = (uint16_t)((math->known[SM08_DIVIDEND] & 0xFF00u) | byte.known_mask);
        return SM08_OK;
    }
    if (reg == 0x4205u) {
        math->words[SM08_DIVIDEND] = (uint16_t)((math->words[SM08_DIVIDEND] & 0x00FFu) | ((uint16_t)byte.value << 8u));
        math->known[SM08_DIVIDEND] = (uint16_t)((math->known[SM08_DIVIDEND] & 0x00FFu) | ((uint16_t)byte.known_mask << 8u));
        return SM08_OK;
    }
    if (reg == 0x4203u) {
        /* This latch effect still occurs when the arithmetic engine is busy. */
        math->words[SM08_RESULT] = 0u;
        math->known[SM08_RESULT] = 0xFFFFu;
        if (math->mode != 0u) return SM08_OK;
        math->words[SM08_QUOTIENT] = (uint16_t)(math->factor.value | ((uint16_t)byte.value << 8u));
        math->known[SM08_QUOTIENT] = (uint16_t)(math->factor.known_mask | ((uint16_t)byte.known_mask << 8u));
        math->serial = byte.value;
        math->serial_known = 0xFFFFFF00u | byte.known_mask;
        math->mode = 1u;
        math->remaining = 8u;
        return SM08_OK;
    }
    if (reg == 0x4206u) {
        math->words[SM08_RESULT] = math->words[SM08_DIVIDEND];
        math->known[SM08_RESULT] = math->known[SM08_DIVIDEND];
        if (math->mode != 0u) return SM08_OK;
        math->serial = (uint32_t)byte.value << 16u;
        math->serial_known = 0xFF00FFFFu | ((uint32_t)byte.known_mask << 16u);
        math->mode = 2u;
        math->remaining = 16u;
        return SM08_OK;
    }
    return SM08_REGISTER;
}

Sm08Status sm08_math_read(const Sm08Math *math, uint16_t reg, Sm08Drive *byte) {
    unsigned slot;
    unsigned shift;
    if (math == NULL || byte == NULL) return SM08_ARGUMENT;
    if (reg == 0x4214u || reg == 0x4215u) slot = SM08_QUOTIENT;
    else if (reg == 0x4216u || reg == 0x4217u) slot = SM08_RESULT;
    else return SM08_REGISTER;
    shift = (reg & 1u) << 3u;
    byte->value = (uint8_t)(math->words[slot] >> shift);
    byte->known_mask = (uint8_t)(math->known[slot] >> shift);
    byte->driven_mask = 0xFFu;
    return SM08_OK;
}

void sm08_math_tick(Sm08Math *math) {
    if (math == NULL) return;
    if (math->remaining == 0u) {
        math->mode = 0u;
        return;
    }
    if (math->mode == 1u) {
        uint16_t next_result = math->words[SM08_RESULT];
        uint16_t next_mask = math->known[SM08_RESULT];
        const int selected = (math->words[SM08_QUOTIENT] & 1u) != 0u;
        /* An exactly zero addend cannot expose an unknown selector. */
        if ((math->serial_known & 0xFFFFu) != 0xFFFFu ||
            (math->serial & 0xFFFFu) != 0u) {
            if ((math->known[SM08_QUOTIENT] & 1u) == 0u) next_mask = 0u;
            if (selected != 0) {
                next_result = (uint16_t)(next_result + (uint16_t)math->serial);
                if (next_mask != 0xFFFFu || (math->serial_known & 0xFFFFu) != 0xFFFFu)
                    next_mask = 0u;
            }
        }
        math->words[SM08_RESULT] = next_result;
        math->known[SM08_RESULT] = next_mask;
        math->words[SM08_QUOTIENT] = (uint16_t)(math->words[SM08_QUOTIENT] >> 1u);
        math->known[SM08_QUOTIENT] = (uint16_t)((math->known[SM08_QUOTIENT] >> 1u) | 0x8000u);
        math->serial = math->serial << 1u;
        math->serial_known = (math->serial_known << 1u) | 1u;
    } else if (math->mode == 2u) {
        uint32_t trial_min;
        uint32_t trial_max;
        uint32_t result_min;
        uint32_t result_max;
        int decision_known;
        int selected;
        math->serial = math->serial >> 1u;
        math->serial_known = (math->serial_known >> 1u) | 0x80000000u;
        /* Mask bounds prove a compare only when every represented value has
         * the same decision. No concrete completions are enumerated here. */
        trial_min = math->serial & math->serial_known;
        trial_max = trial_min | (0xFFFFFFFFu - math->serial_known);
        result_min = math->words[SM08_RESULT] & math->known[SM08_RESULT];
        result_max = result_min | (0xFFFFu - math->known[SM08_RESULT]);
        decision_known = result_min >= trial_max || trial_min >= result_max + 1u;
        selected = math->words[SM08_RESULT] >= math->serial;
        if (decision_known == 0) {
            /* With a known zero remainder, either branch still leaves zero. */
            if (math->known[SM08_RESULT] != 0xFFFFu || math->words[SM08_RESULT] != 0u)
                math->known[SM08_RESULT] = 0u;
        } else if (selected != 0 && (math->known[SM08_RESULT] != 0xFFFFu ||
                                     (math->serial_known & 0xFFFFu) != 0xFFFFu)) {
            math->known[SM08_RESULT] = 0u;
        }
        math->words[SM08_QUOTIENT] = (uint16_t)((math->words[SM08_QUOTIENT] << 1u) | (selected != 0 ? 1u : 0u));
        math->known[SM08_QUOTIENT] = (uint16_t)((math->known[SM08_QUOTIENT] << 1u) | (decision_known != 0 ? 1u : 0u));
        if (selected != 0) math->words[SM08_RESULT] = (uint16_t)(math->words[SM08_RESULT] - math->serial);
    }
    math->remaining = (uint8_t)(math->remaining - 1u);
}
