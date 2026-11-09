#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_family_038(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x06F03DBAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07B9u;
    if (sm_scpu_context_key(cpu) != 0x06F03DCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03DCAu: {
    static const uint8_t source_bytes[] = {0xE6u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    value = (uint8_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,address,value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07BBu;
    if (sm_scpu_context_key(cpu) != 0x06F03DDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03DDAu: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x07BEu;
    if (sm_scpu_context_key(cpu) != 0x06F03DF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03DF2u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE07BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x07BBu;
        cycles = 3u;
    } else {
        cpu->pc = 0x07C0u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F03DDAu && sm_scpu_context_key(cpu) != 0x06F03E02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F03E02u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00A62u && sm_scpu_context_key(cpu) != 0x06F00AF2u && sm_scpu_context_key(cpu) != 0x06F00B82u && sm_scpu_context_key(cpu) != 0x06F00BEAu && sm_scpu_context_key(cpu) != 0x06F00F8Au && sm_scpu_context_key(cpu) != 0x06F01042u && sm_scpu_context_key(cpu) != 0x06F0127Au && sm_scpu_context_key(cpu) != 0x06F01332u && sm_scpu_context_key(cpu) != 0x06F01402u && sm_scpu_context_key(cpu) != 0x06F0158Au && sm_scpu_context_key(cpu) != 0x06F01BA2u && sm_scpu_context_key(cpu) != 0x06F025EAu && sm_scpu_context_key(cpu) != 0x06F02652u && sm_scpu_context_key(cpu) != 0x06F026BAu && sm_scpu_context_key(cpu) != 0x06F026FAu && sm_scpu_context_key(cpu) != 0x06F0274Au && sm_scpu_context_key(cpu) != 0x06F0287Au && sm_scpu_context_key(cpu) != 0x06F02F1Au && sm_scpu_context_key(cpu) != 0x06F02FDAu && sm_scpu_context_key(cpu) != 0x06F03192u && sm_scpu_context_key(cpu) != 0x06F033D2u && sm_scpu_context_key(cpu) != 0x06F0345Au && sm_scpu_context_key(cpu) != 0x06F034EAu && sm_scpu_context_key(cpu) != 0x06F0356Au && sm_scpu_context_key(cpu) != 0x06F0368Au && sm_scpu_context_key(cpu) != 0x06F0370Au && sm_scpu_context_key(cpu) != 0x06F0378Au && sm_scpu_context_key(cpu) != 0x06F0386Au && sm_scpu_context_key(cpu) != 0x06F039D2u && sm_scpu_context_key(cpu) != 0x06F03A52u && sm_scpu_context_key(cpu) != 0x06F03B82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
