#include "../internal/sailor_moon_scpu.h"

uint32_t sm_scpu_context_key(const SmScpuState *cpu) {
    return ((uint32_t)cpu->pbr << 19) | ((uint32_t)cpu->pc << 3)
        | ((uint32_t)(cpu->e != 0) << 2)
        | ((uint32_t)((cpu->p & SM_P_M) != 0) << 1)
        | (uint32_t)((cpu->p & SM_P_X) != 0);
}
uint32_t sm_scpu_address(const SmScpuState *cpu) {
    return ((uint32_t)cpu->pbr << 16) | cpu->pc;
}
SmScpuExecResult sm_scpu_stop(SmScpuState *cpu, const SmScpuBus *bus, const char *reason) {
    (void)bus;
    cpu->stopped=1;
    cpu->failure_reason=reason;
    cpu->failure_address=sm_scpu_address(cpu);
    cpu->failure_context=sm_scpu_context_key(cpu);
    return SM_SCPU_STOPPED;
}
SmScpuExecResult sm_scpu_guard_code(SmScpuState *cpu, const SmScpuBus *bus,
    uint32_t address, const uint8_t *bytes, size_t count) {
    SmStaticFetch fetch;
    if (!sm_static_fetch_descriptor(cpu,address,count,&fetch))
        return sm_scpu_stop(cpu,bus,"UNREGISTERED_EXECUTABLE_FETCH");
    if (!bus || !bus->guard_code || !bus->guard_code(bus->opaque,cpu,&fetch,bytes))
        return sm_scpu_stop(cpu,bus,"SOURCE_EPOCH_CODE_OR_FRAME_GUARD_FAILED");
    return SM_SCPU_EXECUTED;
}
SmScpuExecResult sm_scpu_read8(SmScpuState *cpu, const SmScpuBus *bus,
    uint32_t address, uint8_t *value) {
    if (!bus || !bus->read8 || !bus->read8(bus->opaque,address & 0xFFFFFFu,value))
        return sm_scpu_stop(cpu,bus,"UNKNOWN_OR_FAILED_CONSUMED_READ");
    return SM_SCPU_EXECUTED;
}
SmScpuExecResult sm_scpu_write8(SmScpuState *cpu, const SmScpuBus *bus,
    uint32_t address, uint8_t value) {
    if (!bus || !bus->write8 || !bus->write8(bus->opaque,address & 0xFFFFFFu,value))
        return sm_scpu_stop(cpu,bus,"FAILED_BUS_WRITE");
    return SM_SCPU_EXECUTED;
}
SmScpuExecResult sm_scpu_pull8(SmScpuState *cpu, const SmScpuBus *bus, uint8_t *value) {
    cpu->s = cpu->e ? (uint16_t)(0x100u | ((cpu->s+1u) & 255u)) : (uint16_t)(cpu->s+1u);
    return sm_scpu_read8(cpu,bus,cpu->s,value);
}
SmScpuExecResult sm_scpu_expect_next(SmScpuState *cpu, uint32_t key) {
    if (sm_scpu_context_key(cpu) != key)
        return sm_scpu_stop(cpu,0,"UNPROVED_SUCCESSOR_CONTEXT");
    return SM_SCPU_EXECUTED;
}
SmScpuExecResult sm_scpu_finish(SmScpuState *cpu, const SmScpuBus *bus, uint32_t cycles) {
    if (!bus || !bus->finish_instruction || !bus->finish_instruction(bus->opaque,cpu,cycles))
        return sm_scpu_stop(cpu,bus,"UNPROVED_INSTRUCTION_COMPLETION");
    cpu->completed_cycles += cycles;
    return SM_SCPU_EXECUTED;
}
