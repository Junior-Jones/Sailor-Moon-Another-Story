#include "sailor_moon_spc700_retired_init.h"

Sm08Status sm13_fail(Sm13State *s, Sm08Status status, uint16_t address) {
    Sm08Value sample = {0u, 0u};
    if (s == NULL || s->apu == NULL) return SM08_ARGUMENT;
    s->apu->phase = SM12_FAILED;
    if (s->apu->bus == NULL) return status;
    sample = s->apu->aram[address];
    return sm08_bus_fault(s->apu->bus, status, 13u, address, sample);
}

Sm08Status sm13_guard(Sm13State *s, uint16_t pc,
                      const uint8_t *expected, unsigned length) {
    unsigned i;
    if (s == NULL || s->apu == NULL || expected == NULL || length == 0u)
        return sm13_fail(s, SM08_ARGUMENT, pc);
    for (i = 0u; i < length; ++i) {
        uint16_t address = (uint16_t)(pc + i);
        Sm08Value value = s->apu->aram[address];
        if (value.known_mask != 0xFFu)
            return sm13_fail(s, SM08_UNKNOWN, address);
        if (value.value != expected[i])
            return sm13_fail(s, SM08_GUARD, address);
    }
    return SM08_OK;
}

Sm08Status sm13_known_guard(Sm13State *s, uint16_t address, unsigned length) {
    unsigned i;
    if (s == NULL || s->apu == NULL || length == 0u)
        return sm13_fail(s, SM08_ARGUMENT, address);
    for (i = 0u; i < length; ++i) {
        uint16_t current = (uint16_t)(address + i);
        if (s->apu->aram[current].known_mask != 0xFFu)
            return sm13_fail(s, SM08_UNKNOWN, current);
    }
    return SM08_OK;
}

Sm08Status sm13_read(Sm13State *s, uint16_t address, uint8_t *out) {
    Sm08Value value = {0u, 0u};
    Sm08Status status;
    if (s == NULL || s->apu == NULL || out == NULL)
        return sm13_fail(s, SM08_ARGUMENT, address);
    status = sm12_apu_smp_read(s->apu, address, &value);
    if (status != SM08_OK) return sm13_fail(s, status, address);
    ++s->apu->bus_events;
    if (value.known_mask != 0xFFu)
        return sm13_fail(s, SM08_UNKNOWN, address);
    *out = value.value;
    return SM08_OK;
}

Sm08Status sm13_dummy_read(Sm13State *s, uint16_t address) {
    Sm08Value ignored = {0u, 0u};
    Sm08Status status;
    if (s == NULL || s->apu == NULL)
        return sm13_fail(s, SM08_ARGUMENT, address);
    status = sm12_apu_smp_read(s->apu, address, &ignored);
    if (status == SM08_OK) ++s->apu->bus_events;
    return status == SM08_OK ? SM08_OK : sm13_fail(s, status, address);
}

/* Exact source lifetime, using the existing actual CALL shadow and epoch.
 * No initializer-liveness flag, synthetic stack token or new context exists. */
int sm13_retired_init_write_allowed(const Sm13State *s, uint16_t address, Sm08Value value) {
    return s != NULL && s->apu != NULL && s->active != 0u &&
        value.known_mask == 0xFFu && s->apu->phase == SM12_STATIC_RUNNING &&
        s->source_epoch == s->apu->upload_epoch &&
        s->return_depth == 1u && s->return_pc[0] == 0x038Au &&
        sm13_aot_write_allowed(s->active_pc, address) != 0;
}

Sm08Status sm13_write(Sm13State *s, uint16_t address, uint8_t value) {
    Sm08Value sample = {value, 0xFFu};
    Sm08Status status;
    if (s == NULL || s->apu == NULL)
        return sm13_fail(s, SM08_ARGUMENT, address);
    if (sm13_aot_protected(address) != 0 &&
        sm13_retired_init_write_allowed(s, address, sample) == 0)
        return sm13_fail(s, SM08_GUARD, address);
    status = sm12_apu_smp_write(s->apu, address, sample);
    if (status == SM08_OK) ++s->apu->bus_events;
    return status == SM08_OK ? SM08_OK : sm13_fail(s, status, address);
}

uint16_t sm13_dp(const Sm13State *s, uint8_t address) {
    return (uint16_t)(((s->psw & SM13_P) != 0u ? 0x100u : 0u) | address);
}

void sm13_nz8(Sm13State *s, uint8_t value) {
    s->psw = (uint8_t)((s->psw & 0x7Du) | (value & 0x80u) |
                       (value == 0u ? SM13_Z : 0u));
}

void sm13_nz16(Sm13State *s, uint16_t value) {
    s->psw = (uint8_t)((s->psw & 0x7Du) | ((value >> 8u) & 0x80u) |
                       (value == 0u ? SM13_Z : 0u));
}

void sm13_cmp8(Sm13State *s, uint8_t left, uint8_t right) {
    s->psw = (uint8_t)((s->psw & 0xFEu) | (left >= right ? SM13_C : 0u));
    sm13_nz8(s, (uint8_t)(left - right));
}

uint8_t sm13_adc8(Sm13State *s, uint8_t left, uint8_t right) {
    unsigned carry = s->psw & SM13_C;
    unsigned total = (unsigned)left + right + carry;
    uint8_t result = (uint8_t)total;
    s->psw = (uint8_t)((s->psw & 0xB6u) |
        (total > 0xFFu ? SM13_C : 0u) |
        (((unsigned)(left & 15u) + (right & 15u) + carry) > 15u ? SM13_H : 0u) |
        (((left ^ result) & (right ^ result) & 0x80u) != 0u ? SM13_V : 0u));
    sm13_nz8(s, result);
    return result;
}

uint8_t sm13_sbc8(Sm13State *s, uint8_t left, uint8_t right) {
    unsigned borrow = (s->psw & SM13_C) == 0u ? 1u : 0u;
    int total = (int)left - (int)right - (int)borrow;
    uint8_t result = (uint8_t)total;
    s->psw = (uint8_t)((s->psw & 0xB6u) |
        (total >= 0 ? SM13_C : 0u) |
        ((int)(left & 15u) - (int)(right & 15u) - (int)borrow >= 0 ? SM13_H : 0u) |
        (((left ^ right) & (left ^ result) & 0x80u) != 0u ? SM13_V : 0u));
    sm13_nz8(s, result);
    return result;
}

uint16_t sm13_addw(Sm13State *s, uint16_t left, uint16_t right) {
    uint32_t total = (uint32_t)left + right;
    uint16_t result = (uint16_t)total;
    s->psw = (uint8_t)((s->psw & 0xB6u) |
        (total > 0xFFFFu ? SM13_C : 0u) |
        (((uint32_t)(left & 0xFFFu) + (right & 0xFFFu)) > 0xFFFu ? SM13_H : 0u) |
        (((left ^ result) & (right ^ result) & 0x8000u) != 0u ? SM13_V : 0u));
    sm13_nz16(s, result);
    return result;
}

uint8_t sm13_asl8(Sm13State *s, uint8_t value) {
    uint8_t result = (uint8_t)(value << 1u);
    s->psw = (uint8_t)((s->psw & 0xFEu) | (value >> 7u));
    sm13_nz8(s, result);
    return result;
}

uint16_t sm13_subw(Sm13State *s, uint16_t left, uint16_t right) {
    uint16_t result = (uint16_t)(left - right);
    s->psw = (uint8_t)((s->psw & 0xB6u) |
        (left >= right ? SM13_C : 0u) |
        ((left & 0xFFFu) >= (right & 0xFFFu) ? SM13_H : 0u) |
        (((left ^ right) & (left ^ result) & 0x8000u) != 0u ? SM13_V : 0u));
    sm13_nz16(s, result);
    return result;
}

void sm13_div(Sm13State *s) {
    unsigned old_y = s->y;
    unsigned divisor = s->x;
    unsigned dividend = ((unsigned)s->y << 8u) | s->a;
    /* V describes the initial 8-bit quotient overflow, independently of the
     * divider's abnormal-result branch. C is preserved, including X == 0. */
    s->psw = (uint8_t)((s->psw & 0xB7u) |
        ((old_y & 15u) >= (divisor & 15u) ? SM13_H : 0u) |
        (old_y >= divisor ? SM13_V : 0u));
    if (old_y < divisor * 2u) {
        /* This condition implies divisor != 0. */
        s->a = (uint8_t)(dividend / divisor);
        s->y = (uint8_t)(dividend % divisor);
    } else {
        unsigned residual = dividend - divisor * 512u;
        unsigned complement = 256u - divisor;
        s->a = (uint8_t)(255u - residual / complement);
        s->y = (uint8_t)(divisor + residual % complement);
    }
    sm13_nz8(s, s->a);
}

uint8_t sm13_lsr8(Sm13State *s, uint8_t value) {
    uint8_t result = (uint8_t)(value >> 1u);
    s->psw = (uint8_t)((s->psw & 0xFEu) | (value & 1u));
    sm13_nz8(s, result);
    return result;
}

uint8_t sm13_rol8(Sm13State *s, uint8_t value) {
    uint8_t result = (uint8_t)((value << 1u) | (s->psw & SM13_C));
    s->psw = (uint8_t)((s->psw & 0xFEu) | (value >> 7u));
    sm13_nz8(s, result);
    return result;
}

uint8_t sm13_ror8(Sm13State *s, uint8_t value) {
    uint8_t result = (uint8_t)((value >> 1u) | ((s->psw & SM13_C) << 7u));
    s->psw = (uint8_t)((s->psw & 0xFEu) | (value & 1u));
    sm13_nz8(s, result);
    return result;
}
