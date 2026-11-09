#ifndef SAILOR_MOON_TIMING_PLAN_H
#define SAILOR_MOON_TIMING_PLAN_H
#include <stddef.h>
#include <stdint.h>

/* Offline source-owned recipes; exact-key selection is not opcode decoding. */
typedef enum Sm09TimingKind {
    SM09_TIMING_FETCH, SM09_TIMING_READ, SM09_TIMING_WRITE, SM09_TIMING_INTERNAL
} Sm09TimingKind;
typedef enum Sm09TimingCondition {
    SM09_TIMING_ALWAYS, SM09_TIMING_DIRECT_LOW_NONZERO,
    SM09_TIMING_BRANCH_TAKEN, SM09_TIMING_BRANCH_TAKEN_AND_PAGE_CROSSED,
    SM09_TIMING_INDEX_PAGE_CROSSED
} Sm09TimingCondition;
typedef enum Sm09TimingRole {
    SM09_TIMING_INSTRUCTION, SM09_TIMING_STACK, SM09_TIMING_CALL,
    SM09_TIMING_POINTER_INDEX, SM09_TIMING_RETURN, SM09_TIMING_STACK_PREPARE,
    SM09_TIMING_RETURN_INCREMENT, SM09_TIMING_DIRECT_PAGE, SM09_TIMING_POINTER,
    SM09_TIMING_BLOCK_SOURCE, SM09_TIMING_BLOCK_DESTINATION,
    SM09_TIMING_BLOCK_INDEX, SM09_TIMING_BLOCK_COUNT, SM09_TIMING_STATUS_WIDTH,
    SM09_TIMING_BRANCH, SM09_TIMING_BRANCH_PAGE, SM09_TIMING_BRANCH_LONG,
    SM09_TIMING_STACK_INCREMENT, SM09_TIMING_IMPLIED, SM09_TIMING_ACCUMULATOR_SWAP,
    SM09_TIMING_DIRECT_INDEX, SM09_TIMING_STACK_RELATIVE, SM09_TIMING_INDEX_ADD,
    SM09_TIMING_PAYLOAD, SM09_TIMING_MODIFY,
    SM09_TIMING_STACK_STATUS, SM09_TIMING_VECTOR
} Sm09TimingRole;
enum { SM09_TIMING_INDEX_NONE, SM09_TIMING_INDEX_X, SM09_TIMING_INDEX_Y };
enum { SM09_TIMING_PAGE_NONE, SM09_TIMING_PAGE_OPERAND, SM09_TIMING_PAGE_POINTER };
enum { SM09_TIMING_ENTRY_I, SM09_TIMING_RTI_STACK_P, SM09_TIMING_SOFTWARE_BREAK };

typedef struct Sm09TimingEvent {
    uint8_t kind, role, index, condition;
} Sm09TimingEvent;
typedef struct Sm09TimingPlan {
    uint32_t first_event;
    uint8_t event_count, fetch_count, initial_fetch_count, deferred_operand_count;
    uint8_t branch_mask, branch_set, index_register, page_base_source;
    uint8_t irq_status_policy;
} Sm09TimingPlan;
typedef struct Sm09TimingBinding {
    uint32_t context_key, plan_index;
} Sm09TimingBinding;

extern const Sm09TimingEvent sm09_timing_events[];
extern const Sm09TimingPlan sm09_timing_plans[];
extern const Sm09TimingBinding sm09_timing_bindings[];
extern const uint32_t sm09_timing_bank_first[257];
extern const size_t sm09_timing_event_count, sm09_timing_plan_count, sm09_timing_binding_count;

/* NULL for an absent exact key. The09 clock copies the entry CPU/descriptor.
 * RAM deferred read8 callbacks consume FETCH indexes1/2, never extra data reads.
 * Other late instruction fetches drain at their declared event positions.
 * RTI STACK_STATUS/index0 is its actual first pull; software BRK's already
 * emitted frame/vector sequence is not a second hardware interrupt entry.
 * Index conditions use captured entry index and actual fetched/pointer-low
 * samples. Actual07 callbacks remain the payload/stack address authority. */
const Sm09TimingPlan *sm09_timing_plan_lookup(uint32_t context_key);
#endif
