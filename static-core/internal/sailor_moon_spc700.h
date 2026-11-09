#ifndef SAILOR_MOON_SPC700_H
#define SAILOR_MOON_SPC700_H
#include "sailor_moon_apu13.h"

enum {
    SM13_C = 0x01u, SM13_Z = 0x02u, SM13_I = 0x04u,
    SM13_H = 0x08u, SM13_B = 0x10u, SM13_P = 0x20u,
    SM13_V = 0x40u, SM13_N = 0x80u
};

/* Known-only architectural registers. Required unknown inputs stop before
 * consumption; dummy reads may discard unknown values. Transaction latches
 * survive between actual SMP cycle events, not just instruction completion. */
typedef struct Sm13State {
    Sm12Apu *apu;
    uint16_t pc, active_pc, next_pc, address, pointer, word;
    uint8_t a, x, y, sp, psw;
    uint8_t active, cycle_index, cycles_remaining, total_cycles, branch_taken;
    uint8_t latch_low, latch_high, latch_data, operand0, operand1;
    uint16_t return_pc[256], return_depth;
    uint32_t source_epoch;
    uint8_t entry_prefetch_consumed;
} Sm13State;

Sm08Status sm13_fail(Sm13State *, Sm08Status, uint16_t);
/* Observational guards do not perform a FETCH, advance time or acknowledge a
 * port. Each generated event performs its own explicit transaction. */
Sm08Status sm13_guard(Sm13State *, uint16_t, const uint8_t *, unsigned);
Sm08Status sm13_known_guard(Sm13State *, uint16_t, unsigned);
Sm08Status sm13_read(Sm13State *, uint16_t, uint8_t *);
Sm08Status sm13_dummy_read(Sm13State *, uint16_t);
Sm08Status sm13_write(Sm13State *, uint16_t, uint8_t);
uint16_t sm13_dp(const Sm13State *, uint8_t);
void sm13_nz8(Sm13State *, uint8_t);
void sm13_nz16(Sm13State *, uint16_t);
void sm13_cmp8(Sm13State *, uint8_t, uint8_t);
uint8_t sm13_adc8(Sm13State *, uint8_t, uint8_t);
uint8_t sm13_sbc8(Sm13State *, uint8_t, uint8_t);
uint16_t sm13_addw(Sm13State *, uint16_t, uint16_t);
uint16_t sm13_subw(Sm13State *, uint16_t, uint16_t);
void sm13_div(Sm13State *);
uint8_t sm13_asl8(Sm13State *, uint8_t);
uint8_t sm13_lsr8(Sm13State *, uint8_t);
uint8_t sm13_rol8(Sm13State *, uint8_t);
uint8_t sm13_ror8(Sm13State *, uint8_t);

/* Exact-PC generated authority. No opcode decoder or fallback is linked. */
Sm08Status sm13_aot_begin(Sm13State *);
Sm08Status sm13_aot_event(Sm13State *);
Sm08Status sm13_aot_complete(Sm13State *);
int sm13_aot_protected(uint16_t);
int sm13_aot_write_allowed(uint16_t writer_pc, uint16_t address);
#endif
