#ifndef SAILOR_MOON_SCPU_H
#define SAILOR_MOON_SCPU_H
#include <stddef.h>
#include <stdint.h>

enum { SM_P_C=1, SM_P_Z=2, SM_P_I=4, SM_P_D=8,
       SM_P_X=16, SM_P_M=32, SM_P_V=64, SM_P_N=128 };
typedef enum SmScpuExecResult {
    SM_SCPU_EXECUTED=0, SM_SCPU_NOT_MINE=1, SM_SCPU_STOPPED=2
} SmScpuExecResult;
/* Caller supplies a valid physical CPU state. This declares no reset values. */
typedef struct SmScpuState {
    uint16_t a, x, y, s, d, pc;
    uint8_t pbr, dbr, p, e, stopped;
    uint64_t completed_cycles;
    const char *failure_reason;
    uint32_t failure_address, failure_context;
} SmScpuState;
typedef struct SmStaticFetch {
    uint32_t guard_address;
    size_t guard_count;
    uint32_t fetch_address;
    size_t fetch_count;
    uint8_t executable_epoch, immutable_byte_mask;
    uint32_t deferred_operand_address;
    size_t deferred_operand_count;
} SmStaticFetch;
/* All callbacks return nonzero on success. Unknown consumed bytes fail closed.
 * guard_code validates activation/epoch and the specific immediate RTS frame
 * contract from06, not only four coincidentally matching bytes. It receives a
 * normalized shape; it must mask immutable positions and never zero/freeze the
 * mutable banks. Deferred read8 slots are actual instruction operand fetches.
 * A receiver retaining a descriptor must copy its value before returning.
 * Partial bus effects are preserved; no rollback or causal timing is implied.
 */
typedef struct SmScpuBus {
    void *opaque;
    int (*guard_code)(void *, const SmScpuState *, const SmStaticFetch *, const uint8_t *);
    int (*read8)(void *, uint32_t, uint8_t *);
    int (*write8)(void *, uint32_t, uint8_t);
    int (*finish_instruction)(void *, const SmScpuState *, uint32_t);
} SmScpuBus;
uint32_t sm_scpu_context_key(const SmScpuState *);
uint32_t sm_scpu_address(const SmScpuState *);
SmScpuExecResult sm_scpu_stop(SmScpuState *, const SmScpuBus *, const char *);
SmScpuExecResult sm_scpu_guard_code(SmScpuState *, const SmScpuBus *, uint32_t, const uint8_t *, size_t);
SmScpuExecResult sm_scpu_read8(SmScpuState *, const SmScpuBus *, uint32_t, uint8_t *);
SmScpuExecResult sm_scpu_write8(SmScpuState *, const SmScpuBus *, uint32_t, uint8_t);
SmScpuExecResult sm_scpu_pull8(SmScpuState *, const SmScpuBus *, uint8_t *);
SmScpuExecResult sm_scpu_expect_next(SmScpuState *, uint32_t);
SmScpuExecResult sm_scpu_finish(SmScpuState *, const SmScpuBus *, uint32_t);
SmScpuExecResult sm_scpu_step(SmScpuState *, const SmScpuBus *);
int sm_static_fetch_descriptor(const SmScpuState *, uint32_t, size_t, SmStaticFetch *);
#endif
