#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_tranche_074_123(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x04042D30u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x8085A6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85A8u;
    if (sm_scpu_context_key(cpu) != 0x04042D42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04042D42u: {
    static const uint8_t source_bytes[] = {0xADu, 0x50u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x8085A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1950u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85ABu;
    if (sm_scpu_context_key(cpu) != 0x04042D5Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04042D5Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8085ABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85AEu;
    if (sm_scpu_context_key(cpu) != 0x04042D72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04042D72u: {
    static const uint8_t source_bytes[] = {0xADu, 0x51u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x8085AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1951u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85B1u;
    if (sm_scpu_context_key(cpu) != 0x04042D8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04042D8Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8085B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85B4u;
    if (sm_scpu_context_key(cpu) != 0x04042DA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04042DA2u: {
    static const uint8_t source_bytes[] = {0xADu, 0x52u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x8085B4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1952u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85B7u;
    if (sm_scpu_context_key(cpu) != 0x04042DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04042DBAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x20u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8085B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2120u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85BAu;
    if (sm_scpu_context_key(cpu) != 0x04042DD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04042DD2u: {
    static const uint8_t source_bytes[] = {0xADu, 0x53u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x8085BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1953u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85BDu;
    if (sm_scpu_context_key(cpu) != 0x04042DEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04042DEAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x20u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8085BDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2120u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85C0u;
    if (sm_scpu_context_key(cpu) != 0x04042E02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04042E02u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8085C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04041582u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04042E08u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8085C1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85C3u;
    if (sm_scpu_context_key(cpu) != 0x04042E18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04042E18u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8085C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85C6u;
    if (sm_scpu_context_key(cpu) != 0x04042E30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04042E30u: {
    static const uint8_t source_bytes[] = {0xA5u, 0xC4u};
    if (sm_scpu_guard_code(cpu,bus,0x8085C6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC4u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85C8u;
    if (sm_scpu_context_key(cpu) != 0x04042E40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04042E40u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x8085C8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x85C9u;
    if (sm_scpu_context_key(cpu) != 0x04042E48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04042E48u: {
    static const uint8_t source_bytes[] = {0x69u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8085C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0001u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x85CCu;
    if (sm_scpu_context_key(cpu) != 0x04042E60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04042E60u: {
    static const uint8_t source_bytes[] = {0x85u, 0xC4u};
    if (sm_scpu_guard_code(cpu,bus,0x8085CCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC4u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85CEu;
    if (sm_scpu_context_key(cpu) != 0x04042E70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04042E70u: {
    static const uint8_t source_bytes[] = {0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x8085CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = cpu->y;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85CFu;
    if (sm_scpu_context_key(cpu) != 0x04042E78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04042E78u: {
    static const uint8_t source_bytes[] = {0x65u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0x8085CFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0xC6u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x85D1u;
    if (sm_scpu_context_key(cpu) != 0x04042E88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04042E88u: {
    static const uint8_t source_bytes[] = {0x85u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0x8085D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC6u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85D3u;
    if (sm_scpu_context_key(cpu) != 0x04042E98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04042E98u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8085D3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04041E48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04043AC0u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808758u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x875Au;
    if (sm_scpu_context_key(cpu) != 0x04043AD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04043AD2u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x02u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80875Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2102u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x875Du;
    if (sm_scpu_context_key(cpu) != 0x04043AEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043AEAu: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x03u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80875Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2103u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8760u;
    if (sm_scpu_context_key(cpu) != 0x04043B02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B02u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x00u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808760u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4300u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8763u;
    if (sm_scpu_context_key(cpu) != 0x04043B1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B1Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x808763u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8765u;
    if (sm_scpu_context_key(cpu) != 0x04043B2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043B2Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808765u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4301u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8768u;
    if (sm_scpu_context_key(cpu) != 0x04043B42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B42u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808768u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x876Au;
    if (sm_scpu_context_key(cpu) != 0x04043B52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043B52u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80876Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4302u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x876Du;
    if (sm_scpu_context_key(cpu) != 0x04043B6Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B6Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x80876Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x876Fu;
    if (sm_scpu_context_key(cpu) != 0x04043B7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043B7Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80876Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4303u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8772u;
    if (sm_scpu_context_key(cpu) != 0x04043B92u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B92u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808772u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8774u;
    if (sm_scpu_context_key(cpu) != 0x04043BA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043BA2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x04u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808774u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4304u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8777u;
    if (sm_scpu_context_key(cpu) != 0x04043BBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043BBAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808777u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8779u;
    if (sm_scpu_context_key(cpu) != 0x04043BCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043BCAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808779u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4305u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x877Cu;
    if (sm_scpu_context_key(cpu) != 0x04043BE2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043BE2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x80877Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x877Eu;
    if (sm_scpu_context_key(cpu) != 0x04043BF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043BF2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80877Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4306u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8781u;
    if (sm_scpu_context_key(cpu) != 0x04043C0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043C0Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x84u};
    if (sm_scpu_guard_code(cpu,bus,0x808781u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x84u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8783u;
    if (sm_scpu_context_key(cpu) != 0x04043C1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043C1Au: {
    static const uint8_t source_bytes[] = {0xF0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x808783u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x878Cu;
        cycles = 3u;
    } else {
        cpu->pc = 0x8785u;
    }
    if (sm_scpu_context_key(cpu) != 0x04043C2Au && sm_scpu_context_key(cpu) != 0x04043C62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x04043C2Au: {
    static const uint8_t source_bytes[] = {0x64u, 0x84u};
    if (sm_scpu_guard_code(cpu,bus,0x808785u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x84u);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8787u;
    if (sm_scpu_context_key(cpu) != 0x04043C3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043C3Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x808787u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8789u;
    if (sm_scpu_context_key(cpu) != 0x04043C4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043C4Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808789u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x878Cu;
    if (sm_scpu_context_key(cpu) != 0x04043C62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043C62u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x40u};
    if (sm_scpu_guard_code(cpu,bus,0x80878Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x40u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x878Eu;
    if (sm_scpu_context_key(cpu) != 0x04043C72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043C72u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x00u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80878Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2100u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8791u;
    if (sm_scpu_context_key(cpu) != 0x04043C8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043C8Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808791u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x42u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8793u;
    if (sm_scpu_context_key(cpu) != 0x04043C9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043C9Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808793u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2105u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8796u;
    if (sm_scpu_context_key(cpu) != 0x04043CB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043CB2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808796u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x43u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8798u;
    if (sm_scpu_context_key(cpu) != 0x04043CC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043CC2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808798u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2106u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x879Bu;
    if (sm_scpu_context_key(cpu) != 0x04043CDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043CDAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x44u};
    if (sm_scpu_guard_code(cpu,bus,0x80879Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x44u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x879Du;
    if (sm_scpu_context_key(cpu) != 0x04043CEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043CEAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x07u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80879Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2107u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87A0u;
    if (sm_scpu_context_key(cpu) != 0x04043D02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043D02u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x45u};
    if (sm_scpu_guard_code(cpu,bus,0x8087A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x45u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87A2u;
    if (sm_scpu_context_key(cpu) != 0x04043D12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043D12u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x08u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2108u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87A5u;
    if (sm_scpu_context_key(cpu) != 0x04043D2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043D2Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x46u};
    if (sm_scpu_guard_code(cpu,bus,0x8087A5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x46u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87A7u;
    if (sm_scpu_context_key(cpu) != 0x04043D3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043D3Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x09u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2109u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87AAu;
    if (sm_scpu_context_key(cpu) != 0x04043D52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043D52u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x47u};
    if (sm_scpu_guard_code(cpu,bus,0x8087AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x47u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87ACu;
    if (sm_scpu_context_key(cpu) != 0x04043D62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043D62u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87AFu;
    if (sm_scpu_context_key(cpu) != 0x04043D7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043D7Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x48u};
    if (sm_scpu_guard_code(cpu,bus,0x8087AFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x48u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87B1u;
    if (sm_scpu_context_key(cpu) != 0x04043D8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043D8Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87B4u;
    if (sm_scpu_context_key(cpu) != 0x04043DA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043DA2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x49u};
    if (sm_scpu_guard_code(cpu,bus,0x8087B4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x49u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87B6u;
    if (sm_scpu_context_key(cpu) != 0x04043DB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043DB2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087B6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87B9u;
    if (sm_scpu_context_key(cpu) != 0x04043DCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043DCAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x8087B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Au);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87BBu;
    if (sm_scpu_context_key(cpu) != 0x04043DDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043DDAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87BEu;
    if (sm_scpu_context_key(cpu) != 0x04043DF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043DF2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x8087BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Bu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87C0u;
    if (sm_scpu_context_key(cpu) != 0x04043E02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043E02u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87C3u;
    if (sm_scpu_context_key(cpu) != 0x04043E1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043E1Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Cu};
    if (sm_scpu_guard_code(cpu,bus,0x8087C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Cu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87C5u;
    if (sm_scpu_context_key(cpu) != 0x04043E2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043E2Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87C8u;
    if (sm_scpu_context_key(cpu) != 0x04043E42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043E42u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Du};
    if (sm_scpu_guard_code(cpu,bus,0x8087C8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Du);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87CAu;
    if (sm_scpu_context_key(cpu) != 0x04043E52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043E52u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087CAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87CDu;
    if (sm_scpu_context_key(cpu) != 0x04043E6Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043E6Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Eu};
    if (sm_scpu_guard_code(cpu,bus,0x8087CDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Eu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87CFu;
    if (sm_scpu_context_key(cpu) != 0x04043E7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043E7Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087CFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2101u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87D2u;
    if (sm_scpu_context_key(cpu) != 0x04043E92u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043E92u: {
    static const uint8_t source_bytes[] = {0xADu, 0x58u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0058u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87D5u;
    if (sm_scpu_context_key(cpu) != 0x04043EAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043EAAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x26u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087D5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2126u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87D8u;
    if (sm_scpu_context_key(cpu) != 0x04043EC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043EC2u: {
    static const uint8_t source_bytes[] = {0xADu, 0x59u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0059u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87DBu;
    if (sm_scpu_context_key(cpu) != 0x04043EDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043EDAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x27u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2127u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87DEu;
    if (sm_scpu_context_key(cpu) != 0x04043EF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043EF2u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Au, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x005Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87E1u;
    if (sm_scpu_context_key(cpu) != 0x04043F0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F0Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x28u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2128u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87E4u;
    if (sm_scpu_context_key(cpu) != 0x04043F22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F22u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Bu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087E4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x005Bu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87E7u;
    if (sm_scpu_context_key(cpu) != 0x04043F3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F3Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x29u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087E7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2129u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87EAu;
    if (sm_scpu_context_key(cpu) != 0x04043F52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F52u: {
    static const uint8_t source_bytes[] = {0xADu, 0x53u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0053u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87EDu;
    if (sm_scpu_context_key(cpu) != 0x04043F6Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F6Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x25u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087EDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2125u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87F0u;
    if (sm_scpu_context_key(cpu) != 0x04043F82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F82u: {
    static const uint8_t source_bytes[] = {0xADu, 0x51u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0051u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87F3u;
    if (sm_scpu_context_key(cpu) != 0x04043F9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F9Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x23u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2123u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87F6u;
    if (sm_scpu_context_key(cpu) != 0x04043FB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043FB2u: {
    static const uint8_t source_bytes[] = {0xADu, 0x52u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0052u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87F9u;
    if (sm_scpu_context_key(cpu) != 0x04043FCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043FCAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x24u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2124u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87FCu;
    if (sm_scpu_context_key(cpu) != 0x04043FE2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043FE2u: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087FCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x004Fu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87FFu;
    if (sm_scpu_context_key(cpu) != 0x04043FFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043FFAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087FFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8802u;
    if (sm_scpu_context_key(cpu) != 0x04044012u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044012u: {
    static const uint8_t source_bytes[] = {0xADu, 0x50u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808802u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0050u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8805u;
    if (sm_scpu_context_key(cpu) != 0x0404402Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404402Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808805u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8808u;
    if (sm_scpu_context_key(cpu) != 0x04044042u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044042u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x55u};
    if (sm_scpu_guard_code(cpu,bus,0x808808u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x55u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x880Au;
    if (sm_scpu_context_key(cpu) != 0x04044052u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04044052u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x30u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80880Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2130u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x880Du;
    if (sm_scpu_context_key(cpu) != 0x0404406Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404406Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x56u};
    if (sm_scpu_guard_code(cpu,bus,0x80880Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x56u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x880Fu;
    if (sm_scpu_context_key(cpu) != 0x0404407Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404407Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x31u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80880Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2131u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8812u;
    if (sm_scpu_context_key(cpu) != 0x04044092u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044092u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x57u};
    if (sm_scpu_guard_code(cpu,bus,0x808812u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x57u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8814u;
    if (sm_scpu_context_key(cpu) != 0x040440A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040440A2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x32u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808814u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2132u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8817u;
    if (sm_scpu_context_key(cpu) != 0x040440BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040440BAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x71u};
    if (sm_scpu_guard_code(cpu,bus,0x808817u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x71u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8819u;
    if (sm_scpu_context_key(cpu) != 0x040440CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040440CAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808819u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x881Cu;
    if (sm_scpu_context_key(cpu) != 0x040440E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040440E2u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80881Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04040C52u && sm_scpu_context_key(cpu) != 0x0404169Au && sm_scpu_context_key(cpu) != 0x040418B2u && sm_scpu_context_key(cpu) != 0x04041C32u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045B48u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B69u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B6Bu;
    if (sm_scpu_context_key(cpu) != 0x04045B5Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045B5Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x00u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B6Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A00u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B6Eu;
    if (sm_scpu_context_key(cpu) != 0x04045B72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045B72u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B6Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B71u;
    if (sm_scpu_context_key(cpu) != 0x04045B8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045B8Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x01u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B71u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A01u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B74u;
    if (sm_scpu_context_key(cpu) != 0x04045BA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045BA2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B74u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B77u;
    if (sm_scpu_context_key(cpu) != 0x04045BBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045BBAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x02u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B77u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A02u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B7Au;
    if (sm_scpu_context_key(cpu) != 0x04045BD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045BD2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B7Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B7Du;
    if (sm_scpu_context_key(cpu) != 0x04045BEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045BEAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x03u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B7Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A03u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B80u;
    if (sm_scpu_context_key(cpu) != 0x04045C02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C02u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B80u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B83u;
    if (sm_scpu_context_key(cpu) != 0x04045C1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C1Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x06u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B83u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A06u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B86u;
    if (sm_scpu_context_key(cpu) != 0x04045C32u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C32u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x10u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B86u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2110u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B89u;
    if (sm_scpu_context_key(cpu) != 0x04045C4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C4Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x07u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B89u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A07u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B8Cu;
    if (sm_scpu_context_key(cpu) != 0x04045C62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C62u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x10u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B8Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2110u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B8Fu;
    if (sm_scpu_context_key(cpu) != 0x04045C7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C7Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x04u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B8Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A04u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B92u;
    if (sm_scpu_context_key(cpu) != 0x04045C92u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C92u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B92u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B95u;
    if (sm_scpu_context_key(cpu) != 0x04045CAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045CAAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x05u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B95u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A05u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B98u;
    if (sm_scpu_context_key(cpu) != 0x04045CC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045CC2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B98u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B9Bu;
    if (sm_scpu_context_key(cpu) != 0x04045CDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045CDAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Au, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B9Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B9Eu;
    if (sm_scpu_context_key(cpu) != 0x04045CF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045CF2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x12u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B9Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2112u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BA1u;
    if (sm_scpu_context_key(cpu) != 0x04045D0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D0Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Bu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BA1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Bu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BA4u;
    if (sm_scpu_context_key(cpu) != 0x04045D22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D22u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x12u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BA4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2112u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BA7u;
    if (sm_scpu_context_key(cpu) != 0x04045D3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D3Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x08u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BA7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A08u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BAAu;
    if (sm_scpu_context_key(cpu) != 0x04045D52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D52u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x11u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BAAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2111u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BADu;
    if (sm_scpu_context_key(cpu) != 0x04045D6Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D6Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x09u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A09u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BB0u;
    if (sm_scpu_context_key(cpu) != 0x04045D82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D82u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x11u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BB0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2111u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BB3u;
    if (sm_scpu_context_key(cpu) != 0x04045D9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D9Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Eu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BB3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BB6u;
    if (sm_scpu_context_key(cpu) != 0x04045DB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045DB2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x14u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BB6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2114u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BB9u;
    if (sm_scpu_context_key(cpu) != 0x04045DCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045DCAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Fu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BB9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Fu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BBCu;
    if (sm_scpu_context_key(cpu) != 0x04045DE2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045DE2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x14u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BBCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2114u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BBFu;
    if (sm_scpu_context_key(cpu) != 0x04045DFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045DFAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Cu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BBFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Cu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BC2u;
    if (sm_scpu_context_key(cpu) != 0x04045E12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045E12u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x13u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BC2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2113u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BC5u;
    if (sm_scpu_context_key(cpu) != 0x04045E2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045E2Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Du, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BC5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Du;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BC8u;
    if (sm_scpu_context_key(cpu) != 0x04045E42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045E42u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x13u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BC8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2113u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BCBu;
    if (sm_scpu_context_key(cpu) != 0x04045E5Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045E5Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808BCBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040407EAu && sm_scpu_context_key(cpu) != 0x04040D3Au && sm_scpu_context_key(cpu) != 0x040412EAu && sm_scpu_context_key(cpu) != 0x04041412u && sm_scpu_context_key(cpu) != 0x04041552u && sm_scpu_context_key(cpu) != 0x0404192Au && sm_scpu_context_key(cpu) != 0x04041B2Au && sm_scpu_context_key(cpu) != 0x04041CAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040787D8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80F0FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xF0FDu;
    if (sm_scpu_context_key(cpu) != 0x040787E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040787E8u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F0FDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF0FEu;
    if (sm_scpu_context_key(cpu) != 0x040787F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040787F0u: {
    static const uint8_t source_bytes[] = {0x65u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F0FEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x18u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF100u;
    if (sm_scpu_context_key(cpu) != 0x04078800u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04078800u: {
    static const uint8_t source_bytes[] = {0x85u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x80F100u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF102u;
    if (sm_scpu_context_key(cpu) != 0x04078810u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04078810u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F102u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF104u;
    if (sm_scpu_context_key(cpu) != 0x04078820u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04078820u: {
    static const uint8_t source_bytes[] = {0x85u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x80F104u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x12u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF106u;
    if (sm_scpu_context_key(cpu) != 0x04078830u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04078830u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F106u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04078168u && sm_scpu_context_key(cpu) != 0x04078230u && sm_scpu_context_key(cpu) != 0x040782F8u && sm_scpu_context_key(cpu) != 0x040783C0u && sm_scpu_context_key(cpu) != 0x04078488u && sm_scpu_context_key(cpu) != 0x04078550u && sm_scpu_context_key(cpu) != 0x04078618u && sm_scpu_context_key(cpu) != 0x040786E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04079098u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80F213u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xF215u;
    if (sm_scpu_context_key(cpu) != 0x040790A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040790A8u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F215u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF216u;
    if (sm_scpu_context_key(cpu) != 0x040790B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040790B0u: {
    static const uint8_t source_bytes[] = {0x65u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F216u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x18u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF218u;
    if (sm_scpu_context_key(cpu) != 0x040790C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040790C0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x80F218u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF21Au;
    if (sm_scpu_context_key(cpu) != 0x040790D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040790D0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F21Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040788C0u && sm_scpu_context_key(cpu) != 0x04078988u && sm_scpu_context_key(cpu) != 0x04078A50u && sm_scpu_context_key(cpu) != 0x04078B18u && sm_scpu_context_key(cpu) != 0x04078BE0u && sm_scpu_context_key(cpu) != 0x04078CA8u && sm_scpu_context_key(cpu) != 0x04078D70u && sm_scpu_context_key(cpu) != 0x04078E38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0415DC40u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB88u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB8Au;
    if (sm_scpu_context_key(cpu) != 0x0415DC50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415DC50u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB8Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0415DB78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0415E630u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82BCC6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBCC8u;
    if (sm_scpu_context_key(cpu) != 0x0415E640u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415E640u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82BCC8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0415E568u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0415F4B0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82BE96u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBE98u;
    if (sm_scpu_context_key(cpu) != 0x0415F4C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415F4C0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82BE98u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBE9Bu;
    if (sm_scpu_context_key(cpu) != 0x0415F4D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415F4D8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x90u};
    if (sm_scpu_guard_code(cpu,bus,0x82BE9Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x90u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBE9Du;
    if (sm_scpu_context_key(cpu) != 0x0415F4E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0415F4E8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82BE9Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBEA0u;
    if (sm_scpu_context_key(cpu) != 0x0415F500u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415F500u: {
    static const uint8_t source_bytes[] = {0x85u, 0x8Eu};
    if (sm_scpu_guard_code(cpu,bus,0x82BEA0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x8Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBEA2u;
    if (sm_scpu_context_key(cpu) != 0x0415F510u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0415F510u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x82BEA2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBEA5u;
    if (sm_scpu_context_key(cpu) != 0x0415F528u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415F528u: {
    static const uint8_t source_bytes[] = {0x85u, 0x94u};
    if (sm_scpu_guard_code(cpu,bus,0x82BEA5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x94u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBEA7u;
    if (sm_scpu_context_key(cpu) != 0x0415F538u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0415F538u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x82BEA7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBEA9u;
    if (sm_scpu_context_key(cpu) != 0x0415F54Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415F54Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x82BEA9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBEABu;
    if (sm_scpu_context_key(cpu) != 0x0415F55Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0415F55Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Bu};
    if (sm_scpu_guard_code(cpu,bus,0x82BEABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBEADu;
    if (sm_scpu_context_key(cpu) != 0x0415F56Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0415F56Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x82BEADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C0u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBEAFu;
    if (sm_scpu_context_key(cpu) != 0x0415F57Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0415F57Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x82BEAFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBEB1u;
    if (sm_scpu_context_key(cpu) != 0x0415F58Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0415F58Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82BEB1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0415E00Au && sm_scpu_context_key(cpu) != 0x0415E5FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041C5EF8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x838BDFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8BE1u;
    if (sm_scpu_context_key(cpu) != 0x041C5F08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C5F08u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xF6u, 0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x838BE1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x8BF6u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BE4u;
    if (sm_scpu_context_key(cpu) != 0x041C5F20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C5F20u: {
    static const uint8_t source_bytes[] = {0x85u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x838BE4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BE6u;
    if (sm_scpu_context_key(cpu) != 0x041C5F30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C5F30u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x06u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x838BE6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0006u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BE9u;
    if (sm_scpu_context_key(cpu) != 0x041C5F48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C5F48u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x838BE9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BEBu;
    if (sm_scpu_context_key(cpu) != 0x041C5F58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C5F58u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x2Cu, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x838BEBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x5E2Cu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BEEu;
    if (sm_scpu_context_key(cpu) != 0x041C5F70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C5F70u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Cu};
    if (sm_scpu_guard_code(cpu,bus,0x838BEEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BF0u;
    if (sm_scpu_context_key(cpu) != 0x041C5F80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C5F80u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x838BF0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BF3u;
    if (sm_scpu_context_key(cpu) != 0x041C5F98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C5F98u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Eu};
    if (sm_scpu_guard_code(cpu,bus,0x838BF3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BF5u;
    if (sm_scpu_context_key(cpu) != 0x041C5FA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C5FA8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x838BF5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041C5DF8u && sm_scpu_context_key(cpu) != 0x041C5EC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041CFB00u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x839F60u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x9F62u;
    if (sm_scpu_context_key(cpu) != 0x041CFB10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CFB10u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x77u, 0x9Fu};
    if (sm_scpu_guard_code(cpu,bus,0x839F62u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x9F77u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9F65u;
    if (sm_scpu_context_key(cpu) != 0x041CFB28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CFB28u: {
    static const uint8_t source_bytes[] = {0x85u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x839F65u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9F67u;
    if (sm_scpu_context_key(cpu) != 0x041CFB38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CFB38u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x15u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839F67u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0015u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9F6Au;
    if (sm_scpu_context_key(cpu) != 0x041CFB50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CFB50u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839F6Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9F6Cu;
    if (sm_scpu_context_key(cpu) != 0x041CFB60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CFB60u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x2Cu, 0x66u};
    if (sm_scpu_guard_code(cpu,bus,0x839F6Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x662Cu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9F6Fu;
    if (sm_scpu_context_key(cpu) != 0x041CFB78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CFB78u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Cu};
    if (sm_scpu_guard_code(cpu,bus,0x839F6Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9F71u;
    if (sm_scpu_context_key(cpu) != 0x041CFB88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CFB88u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839F71u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9F74u;
    if (sm_scpu_context_key(cpu) != 0x041CFBA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CFBA0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Eu};
    if (sm_scpu_guard_code(cpu,bus,0x839F74u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9F76u;
    if (sm_scpu_context_key(cpu) != 0x041CFBB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CFBB0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x839F76u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041CF358u && sm_scpu_context_key(cpu) != 0x041CF428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041D0A58u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x83A14Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xA14Du;
    if (sm_scpu_context_key(cpu) != 0x041D0A68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041D0A68u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x4Cu, 0xD3u};
    if (sm_scpu_guard_code(cpu,bus,0x83A14Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xD34Cu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xA150u;
    if (sm_scpu_context_key(cpu) != 0x041D0A80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041D0A80u: {
    static const uint8_t source_bytes[] = {0x85u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x83A150u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xA152u;
    if (sm_scpu_context_key(cpu) != 0x041D0A90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041D0A90u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x87u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83A152u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0087u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xA155u;
    if (sm_scpu_context_key(cpu) != 0x041D0AA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041D0AA8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x83A155u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x12u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xA157u;
    if (sm_scpu_context_key(cpu) != 0x041D0AB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041D0AB8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83A157u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041CDCE0u && sm_scpu_context_key(cpu) != 0x041CDD60u && sm_scpu_context_key(cpu) != 0x041CDDE0u && sm_scpu_context_key(cpu) != 0x041D0878u && sm_scpu_context_key(cpu) != 0x041D08F8u && sm_scpu_context_key(cpu) != 0x041D0978u && sm_scpu_context_key(cpu) != 0x041F7B50u && sm_scpu_context_key(cpu) != 0x041F7BD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041E45A8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x83C8B5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC8B7u;
    if (sm_scpu_context_key(cpu) != 0x041E45B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E45B8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xCCu, 0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x83C8B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xC8CCu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC8BAu;
    if (sm_scpu_context_key(cpu) != 0x041E45D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E45D0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x83C8BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC8BCu;
    if (sm_scpu_context_key(cpu) != 0x041E45E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E45E0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x15u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83C8BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0015u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC8BFu;
    if (sm_scpu_context_key(cpu) != 0x041E45F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E45F8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83C8BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC8C1u;
    if (sm_scpu_context_key(cpu) != 0x041E4608u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E4608u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x10u, 0x96u};
    if (sm_scpu_guard_code(cpu,bus,0x83C8C1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x9610u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC8C4u;
    if (sm_scpu_context_key(cpu) != 0x041E4620u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E4620u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Cu};
    if (sm_scpu_guard_code(cpu,bus,0x83C8C4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC8C6u;
    if (sm_scpu_context_key(cpu) != 0x041E4630u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E4630u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83C8C6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC8C9u;
    if (sm_scpu_context_key(cpu) != 0x041E4648u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E4648u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Eu};
    if (sm_scpu_guard_code(cpu,bus,0x83C8C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC8CBu;
    if (sm_scpu_context_key(cpu) != 0x041E4658u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E4658u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83C8CBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041E44A8u && sm_scpu_context_key(cpu) != 0x041E4578u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041E9EA8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3D5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xD3D7u;
    if (sm_scpu_context_key(cpu) != 0x041E9EB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E9EB8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3D7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD3DAu;
    if (sm_scpu_context_key(cpu) != 0x041E9ED0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E9ED0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x90u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x90u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD3DCu;
    if (sm_scpu_context_key(cpu) != 0x041E9EE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E9EE0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3DCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD3DFu;
    if (sm_scpu_context_key(cpu) != 0x041E9EF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E9EF8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x8Eu};
    if (sm_scpu_guard_code(cpu,bus,0x83D3DFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x8Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD3E1u;
    if (sm_scpu_context_key(cpu) != 0x041E9F08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E9F08u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x83D3E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD3E4u;
    if (sm_scpu_context_key(cpu) != 0x041E9F20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E9F20u: {
    static const uint8_t source_bytes[] = {0x85u, 0x94u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3E4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x94u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD3E6u;
    if (sm_scpu_context_key(cpu) != 0x041E9F30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E9F30u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3E6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xD3E8u;
    if (sm_scpu_context_key(cpu) != 0x041E9F42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041E9F42u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD3EAu;
    if (sm_scpu_context_key(cpu) != 0x041E9F52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041E9F52u: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Bu};
    if (sm_scpu_guard_code(cpu,bus,0x83D3EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD3ECu;
    if (sm_scpu_context_key(cpu) != 0x041E9F62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E9F62u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C0u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD3EEu;
    if (sm_scpu_context_key(cpu) != 0x041E9F72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041E9F72u: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x83D3EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD3F0u;
    if (sm_scpu_context_key(cpu) != 0x041E9F82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041E9F82u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83D3F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041E99CAu && sm_scpu_context_key(cpu) != 0x041E9CAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041EC068u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x83D80Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xD80Fu;
    if (sm_scpu_context_key(cpu) != 0x041EC078u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041EC078u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x06u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83D80Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0006u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD812u;
    if (sm_scpu_context_key(cpu) != 0x041EC090u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041EC090u: {
    static const uint8_t source_bytes[] = {0x85u, 0x90u};
    if (sm_scpu_guard_code(cpu,bus,0x83D812u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x90u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD814u;
    if (sm_scpu_context_key(cpu) != 0x041EC0A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041EC0A0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83D814u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD817u;
    if (sm_scpu_context_key(cpu) != 0x041EC0B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041EC0B8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x8Eu};
    if (sm_scpu_guard_code(cpu,bus,0x83D817u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x8Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD819u;
    if (sm_scpu_context_key(cpu) != 0x041EC0C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041EC0C8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x83D819u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD81Cu;
    if (sm_scpu_context_key(cpu) != 0x041EC0E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041EC0E0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x94u};
    if (sm_scpu_guard_code(cpu,bus,0x83D81Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x94u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD81Eu;
    if (sm_scpu_context_key(cpu) != 0x041EC0F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041EC0F0u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x83D81Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xD820u;
    if (sm_scpu_context_key(cpu) != 0x041EC102u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041EC102u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x83D820u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD822u;
    if (sm_scpu_context_key(cpu) != 0x041EC112u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041EC112u: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Bu};
    if (sm_scpu_guard_code(cpu,bus,0x83D822u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD824u;
    if (sm_scpu_context_key(cpu) != 0x041EC122u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041EC122u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x83D824u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C0u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xD826u;
    if (sm_scpu_context_key(cpu) != 0x041EC132u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041EC132u: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x83D826u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xD828u;
    if (sm_scpu_context_key(cpu) != 0x041EC142u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041EC142u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83D828u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041EAF1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04240EB0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8481D6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x81D8u;
    if (sm_scpu_context_key(cpu) != 0x04240EC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04240EC0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8481D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04242210u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x848442u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8444u;
    if (sm_scpu_context_key(cpu) != 0x04242220u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04242220u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x848444u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04242BD0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84857Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x857Cu;
    if (sm_scpu_context_key(cpu) != 0x04242BE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04242BE0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84857Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04245500u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x848AA0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8AA2u;
    if (sm_scpu_context_key(cpu) != 0x04245510u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04245510u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x848AA2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04260FA0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84C1F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC1F6u;
    if (sm_scpu_context_key(cpu) != 0x04260FB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04260FB0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84C1F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04268020u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84D004u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xD006u;
    if (sm_scpu_context_key(cpu) != 0x04268030u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04268030u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84D006u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0426B910u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84D722u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xD724u;
    if (sm_scpu_context_key(cpu) != 0x0426B920u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0426B920u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84D724u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0426DB00u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84DB60u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xDB62u;
    if (sm_scpu_context_key(cpu) != 0x0426DB10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0426DB10u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84DB62u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0426DCE0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84DB9Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xDB9Eu;
    if (sm_scpu_context_key(cpu) != 0x0426DCF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0426DCF0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84DB9Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0426E280u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84DC50u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xDC52u;
    if (sm_scpu_context_key(cpu) != 0x0426E290u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0426E290u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84DC52u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0426F140u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84DE28u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xDE2Au;
    if (sm_scpu_context_key(cpu) != 0x0426F150u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0426F150u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84DE2Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x042707B8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84E0F7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xE0F9u;
    if (sm_scpu_context_key(cpu) != 0x042707C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x042707C8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84E0F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x042715C8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84E2B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xE2BBu;
    if (sm_scpu_context_key(cpu) != 0x042715D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x042715D8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84E2BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x042715E0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84E2BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xE2BEu;
    if (sm_scpu_context_key(cpu) != 0x042715F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x042715F0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84E2BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x042715F8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x84E2BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xE2C1u;
    if (sm_scpu_context_key(cpu) != 0x04271608u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04271608u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84E2C1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043DEB78u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD6Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBD71u;
    if (sm_scpu_context_key(cpu) != 0x043DEB8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043DEB8Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x44u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD71u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0044u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD73u;
    if (sm_scpu_context_key(cpu) != 0x043DEB9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DEB9Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x50u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD73u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4350u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD76u;
    if (sm_scpu_context_key(cpu) != 0x043DEBB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043DEBB2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x26u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD76u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0026u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD78u;
    if (sm_scpu_context_key(cpu) != 0x043DEBC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DEBC2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x51u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD78u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4351u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD7Bu;
    if (sm_scpu_context_key(cpu) != 0x043DEBDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043DEBDAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0xA2u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD7Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00A2u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD7Du;
    if (sm_scpu_context_key(cpu) != 0x043DEBEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DEBEAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD7Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4352u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD80u;
    if (sm_scpu_context_key(cpu) != 0x043DEC02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043DEC02u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xC3u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD80u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C3u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD82u;
    if (sm_scpu_context_key(cpu) != 0x043DEC12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DEC12u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x53u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD82u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4353u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD85u;
    if (sm_scpu_context_key(cpu) != 0x043DEC2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043DEC2Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x87u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD85u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0087u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD87u;
    if (sm_scpu_context_key(cpu) != 0x043DEC3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DEC3Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x54u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD87u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4354u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD8Au;
    if (sm_scpu_context_key(cpu) != 0x043DEC52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043DEC52u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x87u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD8Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0087u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD8Cu;
    if (sm_scpu_context_key(cpu) != 0x043DEC62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DEC62u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x57u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD8Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4357u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD8Fu;
    if (sm_scpu_context_key(cpu) != 0x043DEC7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043DEC7Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x6Fu};
    if (sm_scpu_guard_code(cpu,bus,0x87BD8Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD91u;
    if (sm_scpu_context_key(cpu) != 0x043DEC8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043DEC8Au: {
    static const uint8_t source_bytes[] = {0x09u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD91u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    uint16_t result = (cpu->a | value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD93u;
    if (sm_scpu_context_key(cpu) != 0x043DEC9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DEC9Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x6Fu};
    if (sm_scpu_guard_code(cpu,bus,0x87BD93u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD95u;
    if (sm_scpu_context_key(cpu) != 0x043DECAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043DECAAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0xA0u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD95u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00A0u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD97u;
    if (sm_scpu_context_key(cpu) != 0x043DECBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DECBAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x51u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD97u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0051u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD9Au;
    if (sm_scpu_context_key(cpu) != 0x043DECD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043DECD2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD9Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0005u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD9Cu;
    if (sm_scpu_context_key(cpu) != 0x043DECE2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043DECE2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x4Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD9Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x004Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD9Fu;
    if (sm_scpu_context_key(cpu) != 0x043DECFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043DECFAu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD9Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043D7322u && sm_scpu_context_key(cpu) != 0x043DF242u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E1AC8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x87C359u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC35Bu;
    if (sm_scpu_context_key(cpu) != 0x043E1ADAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E1ADAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87C35Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC35Du;
    if (sm_scpu_context_key(cpu) != 0x043E1AEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1AEAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x60u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C35Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4360u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC360u;
    if (sm_scpu_context_key(cpu) != 0x043E1B02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1B02u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x2Cu};
    if (sm_scpu_guard_code(cpu,bus,0x87C360u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x002Cu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC362u;
    if (sm_scpu_context_key(cpu) != 0x043E1B12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1B12u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x61u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C362u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4361u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC365u;
    if (sm_scpu_context_key(cpu) != 0x043E1B2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1B2Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Bu};
    if (sm_scpu_guard_code(cpu,bus,0x87C365u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Bu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC367u;
    if (sm_scpu_context_key(cpu) != 0x043E1B3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1B3Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x62u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C367u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4362u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC36Au;
    if (sm_scpu_context_key(cpu) != 0x043E1B52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1B52u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xC3u};
    if (sm_scpu_guard_code(cpu,bus,0x87C36Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C3u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC36Cu;
    if (sm_scpu_context_key(cpu) != 0x043E1B62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1B62u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x63u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C36Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4363u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC36Fu;
    if (sm_scpu_context_key(cpu) != 0x043E1B7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1B7Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x87u};
    if (sm_scpu_guard_code(cpu,bus,0x87C36Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0087u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC371u;
    if (sm_scpu_context_key(cpu) != 0x043E1B8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1B8Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x64u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C371u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4364u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC374u;
    if (sm_scpu_context_key(cpu) != 0x043E1BA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1BA2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87C374u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC376u;
    if (sm_scpu_context_key(cpu) != 0x043E1BB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1BB2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x70u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C376u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4370u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC379u;
    if (sm_scpu_context_key(cpu) != 0x043E1BCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1BCAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0x87C379u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0005u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC37Bu;
    if (sm_scpu_context_key(cpu) != 0x043E1BDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1BDAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x71u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C37Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4371u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC37Eu;
    if (sm_scpu_context_key(cpu) != 0x043E1BF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1BF2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x94u};
    if (sm_scpu_guard_code(cpu,bus,0x87C37Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0094u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC380u;
    if (sm_scpu_context_key(cpu) != 0x043E1C02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1C02u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x72u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C380u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4372u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC383u;
    if (sm_scpu_context_key(cpu) != 0x043E1C1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1C1Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0xC3u};
    if (sm_scpu_guard_code(cpu,bus,0x87C383u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C3u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC385u;
    if (sm_scpu_context_key(cpu) != 0x043E1C2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1C2Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x73u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C385u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4373u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC388u;
    if (sm_scpu_context_key(cpu) != 0x043E1C42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1C42u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x87u};
    if (sm_scpu_guard_code(cpu,bus,0x87C388u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0087u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC38Au;
    if (sm_scpu_context_key(cpu) != 0x043E1C52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1C52u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x74u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x87C38Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4374u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC38Du;
    if (sm_scpu_context_key(cpu) != 0x043E1C6Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E1C6Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x6Fu};
    if (sm_scpu_guard_code(cpu,bus,0x87C38Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC38Fu;
    if (sm_scpu_context_key(cpu) != 0x043E1C7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E1C7Au: {
    static const uint8_t source_bytes[] = {0x09u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x87C38Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C0u;
    uint16_t result = (cpu->a | value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC391u;
    if (sm_scpu_context_key(cpu) != 0x043E1C8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E1C8Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x6Fu};
    if (sm_scpu_guard_code(cpu,bus,0x87C391u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC393u;
    if (sm_scpu_context_key(cpu) != 0x043E1C9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E1C9Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C393u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043D7962u && sm_scpu_context_key(cpu) != 0x043D82EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00020u: {
    static const uint8_t source_bytes[] = {0x4Cu, 0x3Du, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0004u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x003Du;
    if (sm_scpu_context_key(cpu) != 0x06F001E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00023u: {
    static const uint8_t source_bytes[] = {0x4Cu, 0x3Du, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0004u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x003Du;
    if (sm_scpu_context_key(cpu) != 0x06F001EBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F001E8u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE003Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x003Eu;
    if (sm_scpu_context_key(cpu) != 0x06F001F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F001EBu: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE003Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x003Eu;
    if (sm_scpu_context_key(cpu) != 0x06F001F3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F001F0u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE003Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x003Fu;
    if (sm_scpu_context_key(cpu) != 0x06F001F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F001F3u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE003Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x003Fu;
    if (sm_scpu_context_key(cpu) != 0x06F001FBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F001F8u: {
    static const uint8_t source_bytes[] = {0x0Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE003Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->d >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->d >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0040u;
    if (sm_scpu_context_key(cpu) != 0x06F00200u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F001FBu: {
    static const uint8_t source_bytes[] = {0x0Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE003Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->d >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->d >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0040u;
    if (sm_scpu_context_key(cpu) != 0x06F00203u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00200u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0040u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0042u;
    if (sm_scpu_context_key(cpu) != 0x06F00210u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00203u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0040u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0042u;
    if (sm_scpu_context_key(cpu) != 0x06F00210u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00210u: {
    static const uint8_t source_bytes[] = {0x5Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0042u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0043u;
    if (sm_scpu_context_key(cpu) != 0x06F00218u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00218u: {
    static const uint8_t source_bytes[] = {0xDAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0043u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0044u;
    if (sm_scpu_context_key(cpu) != 0x06F00220u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00220u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0044u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0045u;
    if (sm_scpu_context_key(cpu) != 0x06F00228u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00228u: {
    static const uint8_t source_bytes[] = {0xF4u, 0x80u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0045u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(0x8080u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(0x8080u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0048u;
    if (sm_scpu_context_key(cpu) != 0x06F00240u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F00240u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0048u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0049u;
    if (sm_scpu_context_key(cpu) != 0x06F00248u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00248u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0049u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x004Au;
    if (sm_scpu_context_key(cpu) != 0x06F00250u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00250u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE004Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x004Bu;
    if (sm_scpu_context_key(cpu) != 0x06F00258u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00258u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE004Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x004Eu;
    if (sm_scpu_context_key(cpu) != 0x06F00270u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00270u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE004Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x004Fu;
    if (sm_scpu_context_key(cpu) != 0x06F00278u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00278u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE004Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0050u;
    if (sm_scpu_context_key(cpu) != 0x06F00280u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00280u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0050u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0700u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0053u;
    if (sm_scpu_context_key(cpu) != 0x06F00298u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00298u: {
    static const uint8_t source_bytes[] = {0x5Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0053u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->d = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->d & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->d == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0054u;
    if (sm_scpu_context_key(cpu) != 0x06F002A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F002A0u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0054u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0055u;
    if (sm_scpu_context_key(cpu) != 0x06F002A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F002A8u: {
    static const uint8_t source_bytes[] = {0xE0u, 0x24u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0055u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0024u;
    uint16_t left = cpu->x;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0058u;
    if (sm_scpu_context_key(cpu) != 0x06F002C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F002C0u: {
    static const uint8_t source_bytes[] = {0xB0u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0058u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) != 0u) {
        cpu->pc = 0x0062u;
        cycles = 3u;
    } else {
        cpu->pc = 0x005Au;
    }
    if (sm_scpu_context_key(cpu) != 0x06F002D0u && sm_scpu_context_key(cpu) != 0x06F00310u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F002D0u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE005Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x005Cu;
    if (sm_scpu_context_key(cpu) != 0x06F002E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F002E2u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE005Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x005Du;
    if (sm_scpu_context_key(cpu) != 0x06F002EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F002EAu: {
    static const uint8_t source_bytes[] = {0xFCu, 0x69u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE005Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u || cpu->x == 0x0006u || cpu->x == 0x0008u || cpu->x == 0x000Au || cpu->x == 0x000Cu || cpu->x == 0x000Eu || cpu->x == 0x0010u || cpu->x == 0x0012u || cpu->x == 0x0014u || cpu->x == 0x0016u || cpu->x == 0x0018u || cpu->x == 0x001Au || cpu->x == 0x001Cu || cpu->x == 0x001Eu || cpu->x == 0x0020u || cpu->x == 0x0022u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0x005Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x0069u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0x008Du) || (cpu->x == 0x0002u && target == 0x0198u) || (cpu->x == 0x0004u && target == 0x01A8u) || (cpu->x == 0x0006u && target == 0x01B8u) || (cpu->x == 0x0008u && target == 0x01CAu) || (cpu->x == 0x000Au && target == 0x0201u) || (cpu->x == 0x000Cu && target == 0x0211u) || (cpu->x == 0x000Eu && target == 0x037Eu) || (cpu->x == 0x0010u && target == 0x03A1u) || (cpu->x == 0x0012u && target == 0x03A2u) || (cpu->x == 0x0014u && target == 0x0437u) || (cpu->x == 0x0016u && target == 0x043Cu) || (cpu->x == 0x0018u && target == 0x0443u) || (cpu->x == 0x001Au && target == 0x045Au) || (cpu->x == 0x001Cu && target == 0x0470u) || (cpu->x == 0x001Eu && target == 0x0486u) || (cpu->x == 0x0020u && target == 0x0495u) || (cpu->x == 0x0022u && target == 0x04A4u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x06F0046Au && sm_scpu_context_key(cpu) != 0x06F00CC2u && sm_scpu_context_key(cpu) != 0x06F00D42u && sm_scpu_context_key(cpu) != 0x06F00DC2u && sm_scpu_context_key(cpu) != 0x06F00E52u && sm_scpu_context_key(cpu) != 0x06F0100Au && sm_scpu_context_key(cpu) != 0x06F0108Au && sm_scpu_context_key(cpu) != 0x06F01BF2u && sm_scpu_context_key(cpu) != 0x06F01D0Au && sm_scpu_context_key(cpu) != 0x06F01D12u && sm_scpu_context_key(cpu) != 0x06F021BAu && sm_scpu_context_key(cpu) != 0x06F021E2u && sm_scpu_context_key(cpu) != 0x06F0221Au && sm_scpu_context_key(cpu) != 0x06F022D2u && sm_scpu_context_key(cpu) != 0x06F02382u && sm_scpu_context_key(cpu) != 0x06F02432u && sm_scpu_context_key(cpu) != 0x06F024AAu && sm_scpu_context_key(cpu) != 0x06F02522u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x06F00300u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0060u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0062u;
    if (sm_scpu_context_key(cpu) != 0x06F00310u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00302u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0060u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0062u;
    if (sm_scpu_context_key(cpu) != 0x06F00310u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00310u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0062u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0063u;
    if (sm_scpu_context_key(cpu) != 0x06F00318u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F00318u: {
    static const uint8_t source_bytes[] = {0xFAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0063u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0064u;
    if (sm_scpu_context_key(cpu) != 0x06F00320u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F00320u: {
    static const uint8_t source_bytes[] = {0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0064u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0065u;
    if (sm_scpu_context_key(cpu) != 0x06F00328u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F00328u: {
    static const uint8_t source_bytes[] = {0x2Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0065u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->d = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0066u;
    if (sm_scpu_context_key(cpu) != 0x06F00330u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F00330u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0066u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0067u;
    if (sm_scpu_context_key(cpu) != 0x06F00338u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00338u: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0067u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = low;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0068u;
    if (sm_scpu_context_key(cpu) != 0x06F00340u && sm_scpu_context_key(cpu) != 0x06F00343u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00340u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0068u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04040368u && sm_scpu_context_key(cpu) != 0x04042F80u && sm_scpu_context_key(cpu) != 0x040430B8u && sm_scpu_context_key(cpu) != 0x04076A90u && sm_scpu_context_key(cpu) != 0x04076C08u && sm_scpu_context_key(cpu) != 0x04076D90u && sm_scpu_context_key(cpu) != 0x040C38A8u && sm_scpu_context_key(cpu) != 0x042403A8u && sm_scpu_context_key(cpu) != 0x04240D70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00343u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0068u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x0404045Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00CC2u: {
    static const uint8_t source_bytes[] = {0xC5u, 0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0198u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x019Au;
    if (sm_scpu_context_key(cpu) != 0x06F00CD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00CD2u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x0Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE019Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x01A7u;
        cycles = 3u;
    } else {
        cpu->pc = 0x019Cu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F00CE2u && sm_scpu_context_key(cpu) != 0x06F00D3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F00CE2u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE019Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x019Eu;
    if (sm_scpu_context_key(cpu) != 0x06F00CF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00CF2u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB1u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE019Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01A0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04B1u;
    if (sm_scpu_context_key(cpu) != 0x06F0258Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00D0Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xF8u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01A1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01A3u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04F8u;
    if (sm_scpu_context_key(cpu) != 0x06F027C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00D22u: {
    static const uint8_t source_bytes[] = {0x20u, 0xE6u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01A6u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04E6u;
    if (sm_scpu_context_key(cpu) != 0x06F02732u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00D3Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00D42u: {
    static const uint8_t source_bytes[] = {0xC5u, 0x1Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Bu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x01AAu;
    if (sm_scpu_context_key(cpu) != 0x06F00D52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00D52u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x0Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x01B7u;
        cycles = 3u;
    } else {
        cpu->pc = 0x01ACu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F00D62u && sm_scpu_context_key(cpu) != 0x06F00DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F00D62u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x01AEu;
    if (sm_scpu_context_key(cpu) != 0x06F00D72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00D72u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB1u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01B0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04B1u;
    if (sm_scpu_context_key(cpu) != 0x06F0258Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00D8Au: {
    static const uint8_t source_bytes[] = {0x20u, 0x21u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01B3u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0521u;
    if (sm_scpu_context_key(cpu) != 0x06F0290Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00DA2u: {
    static const uint8_t source_bytes[] = {0x20u, 0xE6u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01B4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01B6u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04E6u;
    if (sm_scpu_context_key(cpu) != 0x06F02732u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00DBAu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00DC2u: {
    static const uint8_t source_bytes[] = {0xC5u, 0x1Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01B8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x01BAu;
    if (sm_scpu_context_key(cpu) != 0x06F00DD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00DD2u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE01BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x01C9u;
        cycles = 3u;
    } else {
        cpu->pc = 0x01BCu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F00DE2u && sm_scpu_context_key(cpu) != 0x06F00E4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F00DE2u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB1u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01BEu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04B1u;
    if (sm_scpu_context_key(cpu) != 0x06F0258Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00DFAu: {
    static const uint8_t source_bytes[] = {0x20u, 0x33u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01C1u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0533u;
    if (sm_scpu_context_key(cpu) != 0x06F0299Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00E12u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01C2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01C4u;
    if (sm_scpu_context_key(cpu) != 0x06F00E22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00E22u: {
    static const uint8_t source_bytes[] = {0x04u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01C4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t modified = (uint8_t)(value | (cpu->a & 0xFFu));
    if (sm_scpu_write8(cpu,bus,address,modified) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & value & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01C6u;
    if (sm_scpu_context_key(cpu) != 0x06F00E32u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00E32u: {
    static const uint8_t source_bytes[] = {0x20u, 0xE6u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01C6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01C8u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04E6u;
    if (sm_scpu_context_key(cpu) != 0x06F02732u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00E4Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00E52u: {
    static const uint8_t source_bytes[] = {0xC5u, 0x1Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01CAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Bu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x01CCu;
    if (sm_scpu_context_key(cpu) != 0x06F00E62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00E62u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE01CCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x01D8u;
        cycles = 3u;
    } else {
        cpu->pc = 0x01CEu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F00E72u && sm_scpu_context_key(cpu) != 0x06F00EC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F00E72u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x01D0u;
    if (sm_scpu_context_key(cpu) != 0x06F00E82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00E82u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB1u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01D0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01D2u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04B1u;
    if (sm_scpu_context_key(cpu) != 0x06F0258Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00E9Au: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01D3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x01D4u;
    if (sm_scpu_context_key(cpu) != 0x06F00EA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00EA2u: {
    static const uint8_t source_bytes[] = {0x20u, 0x21u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01D6u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0521u;
    if (sm_scpu_context_key(cpu) != 0x06F0290Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00EBAu: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01D7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01D8u;
    if (sm_scpu_context_key(cpu) != 0x06F00EC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00EC2u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01D9u;
    if (sm_scpu_context_key(cpu) != 0x06F00ECAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00ECAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01D9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01DBu;
    if (sm_scpu_context_key(cpu) != 0x06F00EDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00EDAu: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01DCu;
    if (sm_scpu_context_key(cpu) != 0x06F00EE2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00EE2u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01DCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01DDu;
    if (sm_scpu_context_key(cpu) != 0x06F00EEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00EEAu: {
    static const uint8_t source_bytes[] = {0xBFu, 0xB0u, 0x29u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE29B0u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01E1u;
    if (sm_scpu_context_key(cpu) != 0x06F00F0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F00F0Au: {
    static const uint8_t source_bytes[] = {0xC5u, 0x1Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x01E3u;
    if (sm_scpu_context_key(cpu) != 0x06F00F1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00F1Au: {
    static const uint8_t source_bytes[] = {0xF0u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x01EBu;
        cycles = 3u;
    } else {
        cpu->pc = 0x01E5u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F00F2Au && sm_scpu_context_key(cpu) != 0x06F00F5Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F00F2Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xB1u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01E5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01E7u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04B1u;
    if (sm_scpu_context_key(cpu) != 0x06F0258Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00F42u: {
    static const uint8_t source_bytes[] = {0x20u, 0x33u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01EAu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0533u;
    if (sm_scpu_context_key(cpu) != 0x06F0299Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00F5Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xB1u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01EDu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04B1u;
    if (sm_scpu_context_key(cpu) != 0x06F0258Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00F72u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01F0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00F8Au: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01F1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x01F4u;
    if (sm_scpu_context_key(cpu) != 0x06F00FA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00FA2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01F6u;
    if (sm_scpu_context_key(cpu) != 0x06F00FB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00FB2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x01F9u;
    if (sm_scpu_context_key(cpu) != 0x06F00FCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00FCAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01FBu;
    if (sm_scpu_context_key(cpu) != 0x06F00FDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00FDAu: {
    static const uint8_t source_bytes[] = {0x04u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE01FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t modified = (uint8_t)(value | (cpu->a & 0xFFu));
    if (sm_scpu_write8(cpu,bus,address,modified) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & value & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x01FDu;
    if (sm_scpu_context_key(cpu) != 0x06F00FEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00FEAu: {
    static const uint8_t source_bytes[] = {0x20u, 0xE6u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE01FDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x01FFu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04E6u;
    if (sm_scpu_context_key(cpu) != 0x06F02732u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01002u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0200u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0108Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0211u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0213u;
    if (sm_scpu_context_key(cpu) != 0x06F0109Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0109Au: {
    static const uint8_t source_bytes[] = {0x89u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0213u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & 0xC0u & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0215u;
    if (sm_scpu_context_key(cpu) != 0x06F010AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F010AAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0215u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x021Eu;
        cycles = 3u;
    } else {
        cpu->pc = 0x0217u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F010BAu && sm_scpu_context_key(cpu) != 0x06F010F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F010BAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0217u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0219u;
    if (sm_scpu_context_key(cpu) != 0x06F010CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F010CAu: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0219u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x021Cu;
    if (sm_scpu_context_key(cpu) != 0x06F010E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F010E2u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE021Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x0221u;
        cycles = 3u;
    } else {
        cpu->pc = 0x021Eu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F010F2u && sm_scpu_context_key(cpu) != 0x06F0110Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F010F2u: {
    static const uint8_t source_bytes[] = {0x82u, 0x5Cu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0xDE021Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x037Du;
    if (sm_scpu_context_key(cpu) != 0x06F01BEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0110Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x40u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0221u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0040u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0223u;
    if (sm_scpu_context_key(cpu) != 0x06F0111Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0111Au: {
    static const uint8_t source_bytes[] = {0x04u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0223u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t modified = (uint8_t)(value | (cpu->a & 0xFFu));
    if (sm_scpu_write8(cpu,bus,address,modified) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & value & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0225u;
    if (sm_scpu_context_key(cpu) != 0x06F0112Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0112Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0225u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0227u;
    if (sm_scpu_context_key(cpu) != 0x06F0113Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0113Au: {
    static const uint8_t source_bytes[] = {0x89u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0227u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & 0x10u & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0229u;
    if (sm_scpu_context_key(cpu) != 0x06F0114Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0114Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0229u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x023Du;
        cycles = 3u;
    } else {
        cpu->pc = 0x022Bu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0115Au && sm_scpu_context_key(cpu) != 0x06F011EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0115Au: {
    static const uint8_t source_bytes[] = {0x89u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE022Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & 0x08u & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x022Du;
    if (sm_scpu_context_key(cpu) != 0x06F0116Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0116Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0x17u};
    if (sm_scpu_guard_code(cpu,bus,0xDE022Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0246u;
        cycles = 3u;
    } else {
        cpu->pc = 0x022Fu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0117Au && sm_scpu_context_key(cpu) != 0x06F01232u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0117Au: {
    static const uint8_t source_bytes[] = {0x89u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE022Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & 0x04u & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0231u;
    if (sm_scpu_context_key(cpu) != 0x06F0118Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0118Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0231u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0239u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0233u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0119Au && sm_scpu_context_key(cpu) != 0x06F011CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0119Au: {
    static const uint8_t source_bytes[] = {0x89u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0233u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & 0x20u & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0235u;
    if (sm_scpu_context_key(cpu) != 0x06F011AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F011AAu: {
    static const uint8_t source_bytes[] = {0xF0u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0235u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x023Du;
        cycles = 3u;
    } else {
        cpu->pc = 0x0237u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F011BAu && sm_scpu_context_key(cpu) != 0x06F011EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F011BAu: {
    static const uint8_t source_bytes[] = {0x80u, 0x3Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0237u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0275u;
    if (sm_scpu_context_key(cpu) != 0x06F013AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F011CAu: {
    static const uint8_t source_bytes[] = {0x89u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0239u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & 0x20u & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x023Bu;
    if (sm_scpu_context_key(cpu) != 0x06F011DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F011DAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE023Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0240u;
        cycles = 3u;
    } else {
        cpu->pc = 0x023Du;
    }
    if (sm_scpu_context_key(cpu) != 0x06F011EAu && sm_scpu_context_key(cpu) != 0x06F01202u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F011EAu: {
    static const uint8_t source_bytes[] = {0x82u, 0xF6u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE023Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0336u;
    if (sm_scpu_context_key(cpu) != 0x06F019B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01202u: {
    static const uint8_t source_bytes[] = {0x29u, 0xDBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0240u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00DBu;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0242u;
    if (sm_scpu_context_key(cpu) != 0x06F01212u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01212u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0242u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0244u;
    if (sm_scpu_context_key(cpu) != 0x06F01222u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01222u: {
    static const uint8_t source_bytes[] = {0x80u, 0x37u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0244u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x027Du;
    if (sm_scpu_context_key(cpu) != 0x06F013EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01232u: {
    static const uint8_t source_bytes[] = {0x29u, 0xF3u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0246u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00F3u;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0248u;
    if (sm_scpu_context_key(cpu) != 0x06F01242u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01242u: {
    static const uint8_t source_bytes[] = {0x09u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0248u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    uint16_t result = (cpu->a | value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x024Au;
    if (sm_scpu_context_key(cpu) != 0x06F01252u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01252u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE024Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x024Cu;
    if (sm_scpu_context_key(cpu) != 0x06F01262u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01262u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE024Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x024Eu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0127Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x29u};
    if (sm_scpu_guard_code(cpu,bus,0xDE024Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x29u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0251u;
    if (sm_scpu_context_key(cpu) != 0x06F0128Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0128Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0251u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0254u;
    if (sm_scpu_context_key(cpu) != 0x06F012A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F012A2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0254u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x21u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0256u;
    if (sm_scpu_context_key(cpu) != 0x06F012B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F012B2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0256u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0259u;
    if (sm_scpu_context_key(cpu) != 0x06F012CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F012CAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0259u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x025Bu;
    if (sm_scpu_context_key(cpu) != 0x06F012DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F012DAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE025Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x025Eu;
    if (sm_scpu_context_key(cpu) != 0x06F012F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F012F2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE025Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Cu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0260u;
    if (sm_scpu_context_key(cpu) != 0x06F01302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01302u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0260u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0263u;
    if (sm_scpu_context_key(cpu) != 0x06F0131Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0131Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0263u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0265u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01332u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x2Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0266u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x2Bu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0268u;
    if (sm_scpu_context_key(cpu) != 0x06F01342u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01342u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0268u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x026Bu;
    if (sm_scpu_context_key(cpu) != 0x06F0135Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0135Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x2Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE026Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x2Au);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x026Du;
    if (sm_scpu_context_key(cpu) != 0x06F0136Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0136Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE026Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0270u;
    if (sm_scpu_context_key(cpu) != 0x06F01382u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01382u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0270u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Cu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0272u;
    if (sm_scpu_context_key(cpu) != 0x06F01392u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01392u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0272u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0275u;
    if (sm_scpu_context_key(cpu) != 0x06F013AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F013AAu: {
    static const uint8_t source_bytes[] = {0xA6u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0275u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0277u;
    if (sm_scpu_context_key(cpu) != 0x06F013BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F013BAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0277u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0288u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0279u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F013CAu && sm_scpu_context_key(cpu) != 0x06F01442u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F013CAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0279u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x027Bu;
    if (sm_scpu_context_key(cpu) != 0x06F013DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F013DAu: {
    static const uint8_t source_bytes[] = {0x14u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE027Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint8_t modified = (uint8_t)(value & ~(cpu->a & 0xFFu));
    if (sm_scpu_write8(cpu,bus,address,modified) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & value & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x027Du;
    if (sm_scpu_context_key(cpu) != 0x06F013EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F013EAu: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE027Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x027Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01402u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x93u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0280u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0093u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0282u;
    if (sm_scpu_context_key(cpu) != 0x06F01412u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01412u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0282u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0285u;
    if (sm_scpu_context_key(cpu) != 0x06F0142Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0142Au: {
    static const uint8_t source_bytes[] = {0x82u, 0xAEu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0285u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0336u;
    if (sm_scpu_context_key(cpu) != 0x06F019B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01442u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0288u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x21u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x028Au;
    if (sm_scpu_context_key(cpu) != 0x06F01450u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01450u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x26u};
    if (sm_scpu_guard_code(cpu,bus,0xDE028Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x26u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x028Cu;
    if (sm_scpu_context_key(cpu) != 0x06F01460u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01460u: {
    static const uint8_t source_bytes[] = {0x65u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0xDE028Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x028Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01470u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01470u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE028Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x028Fu;
    if (sm_scpu_context_key(cpu) != 0x06F01478u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01478u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE028Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0292u;
    if (sm_scpu_context_key(cpu) != 0x06F01490u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01490u: {
    static const uint8_t source_bytes[] = {0x85u, 0x26u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0292u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x26u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0294u;
    if (sm_scpu_context_key(cpu) != 0x06F014A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F014A0u: {
    static const uint8_t source_bytes[] = {0x8Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0294u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = cpu->x;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0295u;
    if (sm_scpu_context_key(cpu) != 0x06F014A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F014A8u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0295u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0296u;
    if (sm_scpu_context_key(cpu) != 0x06F014B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F014B0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0296u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0299u;
    if (sm_scpu_context_key(cpu) != 0x06F014C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F014C8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE0299u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x029Bu;
    if (sm_scpu_context_key(cpu) != 0x06F014D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F014D8u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0xDE029Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x029Du;
    if (sm_scpu_context_key(cpu) != 0x06F014E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F014E8u: {
    static const uint8_t source_bytes[] = {0x38u};
    if (sm_scpu_guard_code(cpu,bus,0xDE029Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | SM_P_C);
    cpu->pc = 0x029Eu;
    if (sm_scpu_context_key(cpu) != 0x06F014F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F014F0u: {
    static const uint8_t source_bytes[] = {0xE5u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE029Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x0Du);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a & 0xFFFFu;
    uint32_t sum = (uint32_t)left + (value ^ 0xFFFFu) + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = sum & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (((left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x02A0u;
    if (sm_scpu_context_key(cpu) != 0x06F01500u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01500u: {
    static const uint8_t source_bytes[] = {0xB0u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) != 0u) {
        cpu->pc = 0x02AAu;
        cycles = 3u;
    } else {
        cpu->pc = 0x02A2u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F01510u && sm_scpu_context_key(cpu) != 0x06F01550u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F01510u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02A4u;
    if (sm_scpu_context_key(cpu) != 0x06F01520u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01520u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02A6u;
    if (sm_scpu_context_key(cpu) != 0x06F01530u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01530u: {
    static const uint8_t source_bytes[] = {0x64u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02A6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02A8u;
    if (sm_scpu_context_key(cpu) != 0x06F01540u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01540u: {
    static const uint8_t source_bytes[] = {0x80u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02ACu;
    if (sm_scpu_context_key(cpu) != 0x06F01560u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01550u: {
    static const uint8_t source_bytes[] = {0x85u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02ACu;
    if (sm_scpu_context_key(cpu) != 0x06F01560u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01560u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x02AEu;
    if (sm_scpu_context_key(cpu) != 0x06F01572u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01572u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x02B0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0158Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x0Eu};
    if (sm_scpu_guard_code(cpu,bus,0xDE02B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Eu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02B3u;
    if (sm_scpu_context_key(cpu) != 0x06F0159Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0159Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02B3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02B6u;
    if (sm_scpu_context_key(cpu) != 0x06F015B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F015B2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02B6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Du);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02B8u;
    if (sm_scpu_context_key(cpu) != 0x06F015C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F015C2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02B8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02BBu;
    if (sm_scpu_context_key(cpu) != 0x06F015DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F015DAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Du;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02BDu;
    if (sm_scpu_context_key(cpu) != 0x06F015EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F015EAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02BDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02C0u;
    if (sm_scpu_context_key(cpu) != 0x06F01602u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01602u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02C3u;
    if (sm_scpu_context_key(cpu) != 0x06F0161Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0161Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02C5u;
    if (sm_scpu_context_key(cpu) != 0x06F0162Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0162Au: {
    static const uint8_t source_bytes[] = {0xE6u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    value = (uint8_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,address,value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02C7u;
    if (sm_scpu_context_key(cpu) != 0x06F0163Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0163Au: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02C7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x02CAu;
    if (sm_scpu_context_key(cpu) != 0x06F01652u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01652u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE02CAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x02C7u;
        cycles = 3u;
    } else {
        cpu->pc = 0x02CCu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0163Au && sm_scpu_context_key(cpu) != 0x06F01662u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F01662u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02CCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02CEu;
    if (sm_scpu_context_key(cpu) != 0x06F01672u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01672u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02CFu;
    if (sm_scpu_context_key(cpu) != 0x06F0167Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0167Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02CFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02D2u;
    if (sm_scpu_context_key(cpu) != 0x06F01692u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01692u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02D4u;
    if (sm_scpu_context_key(cpu) != 0x06F016A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F016A2u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02D5u;
    if (sm_scpu_context_key(cpu) != 0x06F016AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F016AAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02D5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02D8u;
    if (sm_scpu_context_key(cpu) != 0x06F016C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F016C2u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02DAu;
    if (sm_scpu_context_key(cpu) != 0x06F016D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F016D2u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02DBu;
    if (sm_scpu_context_key(cpu) != 0x06F016DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F016DAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02DEu;
    if (sm_scpu_context_key(cpu) != 0x06F016F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F016F2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Du;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02E0u;
    if (sm_scpu_context_key(cpu) != 0x06F01702u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01702u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02E3u;
    if (sm_scpu_context_key(cpu) != 0x06F0171Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0171Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02E5u;
    if (sm_scpu_context_key(cpu) != 0x06F0172Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0172Au: {
    static const uint8_t source_bytes[] = {0xE6u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02E5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    value = (uint8_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,address,value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02E7u;
    if (sm_scpu_context_key(cpu) != 0x06F0173Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0173Au: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02E7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x02EAu;
    if (sm_scpu_context_key(cpu) != 0x06F01752u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01752u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE02EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x02E7u;
        cycles = 3u;
    } else {
        cpu->pc = 0x02ECu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0173Au && sm_scpu_context_key(cpu) != 0x06F01762u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F01762u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02EEu;
    if (sm_scpu_context_key(cpu) != 0x06F01772u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01772u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02EFu;
    if (sm_scpu_context_key(cpu) != 0x06F0177Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0177Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02F2u;
    if (sm_scpu_context_key(cpu) != 0x06F01792u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01792u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02F2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02F4u;
    if (sm_scpu_context_key(cpu) != 0x06F017A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F017A2u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02F5u;
    if (sm_scpu_context_key(cpu) != 0x06F017AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F017AAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02F8u;
    if (sm_scpu_context_key(cpu) != 0x06F017C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F017C2u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02FAu;
    if (sm_scpu_context_key(cpu) != 0x06F017D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F017D2u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02FAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x02FBu;
    if (sm_scpu_context_key(cpu) != 0x06F017DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F017DAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE02FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x02FEu;
    if (sm_scpu_context_key(cpu) != 0x06F017F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F017F2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE02FEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Du;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0300u;
    if (sm_scpu_context_key(cpu) != 0x06F01802u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01802u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0300u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0303u;
    if (sm_scpu_context_key(cpu) != 0x06F0181Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0181Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0303u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0305u;
    if (sm_scpu_context_key(cpu) != 0x06F0182Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0182Au: {
    static const uint8_t source_bytes[] = {0xE6u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0305u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    value = (uint8_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,address,value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0307u;
    if (sm_scpu_context_key(cpu) != 0x06F0183Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0183Au: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0307u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x030Au;
    if (sm_scpu_context_key(cpu) != 0x06F01852u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01852u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE030Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0307u;
        cycles = 3u;
    } else {
        cpu->pc = 0x030Cu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0183Au && sm_scpu_context_key(cpu) != 0x06F01862u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F01862u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE030Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x030Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01872u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01872u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE030Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x030Fu;
    if (sm_scpu_context_key(cpu) != 0x06F0187Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0187Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE030Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0312u;
    if (sm_scpu_context_key(cpu) != 0x06F01892u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01892u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE0312u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0314u;
    if (sm_scpu_context_key(cpu) != 0x06F018A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F018A2u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0314u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0315u;
    if (sm_scpu_context_key(cpu) != 0x06F018AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F018AAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0315u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0318u;
    if (sm_scpu_context_key(cpu) != 0x06F018C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F018C2u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE0318u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x1Du);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x031Au;
    if (sm_scpu_context_key(cpu) != 0x06F018D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F018D2u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE031Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x031Bu;
    if (sm_scpu_context_key(cpu) != 0x06F018DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F018DAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE031Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x031Eu;
    if (sm_scpu_context_key(cpu) != 0x06F018F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F018F2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE031Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Du;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0320u;
    if (sm_scpu_context_key(cpu) != 0x06F01902u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01902u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0320u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0323u;
    if (sm_scpu_context_key(cpu) != 0x06F0191Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0191Au: {
    static const uint8_t source_bytes[] = {0xC6u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE0323u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Du);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0325u;
    if (sm_scpu_context_key(cpu) != 0x06F0192Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0192Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0x9Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0325u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x02C3u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0327u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0161Au && sm_scpu_context_key(cpu) != 0x06F0193Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0193Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0327u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x21u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0329u;
    if (sm_scpu_context_key(cpu) != 0x06F01948u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01948u: {
    static const uint8_t source_bytes[] = {0x98u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0329u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = cpu->y;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x032Au;
    if (sm_scpu_context_key(cpu) != 0x06F01950u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01950u: {
    static const uint8_t source_bytes[] = {0x65u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE032Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x1Du);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x032Cu;
    if (sm_scpu_context_key(cpu) != 0x06F01960u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01960u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE032Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x032Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01970u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01970u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE032Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0330u;
    if (sm_scpu_context_key(cpu) != 0x06F01982u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01982u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0330u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0332u;
    if (sm_scpu_context_key(cpu) != 0x06F01992u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01992u: {
    static const uint8_t source_bytes[] = {0x65u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0332u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x1Fu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = sum & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x80u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFu ? SM_P_C : 0u));
    cpu->pc = 0x0334u;
    if (sm_scpu_context_key(cpu) != 0x06F019A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F019A2u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0334u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0336u;
    if (sm_scpu_context_key(cpu) != 0x06F019B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F019B2u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x11u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0336u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x11u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0338u;
    if (sm_scpu_context_key(cpu) != 0x06F019C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F019C2u: {
    static const uint8_t source_bytes[] = {0xE4u, 0x13u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0338u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x13u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(cpu->x - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->x >= value ? SM_P_C : 0u));
    cpu->pc = 0x033Au;
    if (sm_scpu_context_key(cpu) != 0x06F019D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F019D2u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x33u};
    if (sm_scpu_guard_code(cpu,bus,0xDE033Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x036Fu;
        cycles = 3u;
    } else {
        cpu->pc = 0x033Cu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F019E2u && sm_scpu_context_key(cpu) != 0x06F01B7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F019E2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE033Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x033Eu;
    if (sm_scpu_context_key(cpu) != 0x06F019F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F019F2u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE033Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    value = (uint8_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,address,value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0340u;
    if (sm_scpu_context_key(cpu) != 0x06F01A02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01A02u: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0340u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x0343u;
    if (sm_scpu_context_key(cpu) != 0x06F01A1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01A1Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0343u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0340u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0345u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F01A02u && sm_scpu_context_key(cpu) != 0x06F01A2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F01A2Au: {
    static const uint8_t source_bytes[] = {0xBFu, 0x03u, 0x30u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0345u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E3003u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0349u;
    if (sm_scpu_context_key(cpu) != 0x06F01A4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F01A4Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0349u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x034Cu;
    if (sm_scpu_context_key(cpu) != 0x06F01A62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01A62u: {
    static const uint8_t source_bytes[] = {0xBFu, 0x02u, 0x30u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0xDE034Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E3002u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0350u;
    if (sm_scpu_context_key(cpu) != 0x06F01A82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F01A82u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0350u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0353u;
    if (sm_scpu_context_key(cpu) != 0x06F01A9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01A9Au: {
    static const uint8_t source_bytes[] = {0xBFu, 0x01u, 0x30u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0353u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E3001u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0357u;
    if (sm_scpu_context_key(cpu) != 0x06F01ABAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F01ABAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0357u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x035Au;
    if (sm_scpu_context_key(cpu) != 0x06F01AD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01AD2u: {
    static const uint8_t source_bytes[] = {0xBFu, 0x00u, 0x30u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0xDE035Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E3000u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x035Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01AF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F01AF2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE035Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0361u;
    if (sm_scpu_context_key(cpu) != 0x06F01B0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01B0Au: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0361u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0362u;
    if (sm_scpu_context_key(cpu) != 0x06F01B12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01B12u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0362u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0363u;
    if (sm_scpu_context_key(cpu) != 0x06F01B1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01B1Au: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0363u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0364u;
    if (sm_scpu_context_key(cpu) != 0x06F01B22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01B22u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0364u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0365u;
    if (sm_scpu_context_key(cpu) != 0x06F01B2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01B2Au: {
    static const uint8_t source_bytes[] = {0xE0u, 0x80u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0365u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    uint16_t result = (uint16_t)(cpu->x - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->x >= value ? SM_P_C : 0u));
    cpu->pc = 0x0368u;
    if (sm_scpu_context_key(cpu) != 0x06F01B42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01B42u: {
    static const uint8_t source_bytes[] = {0x90u, 0xCEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0368u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0x0338u;
        cycles = 3u;
    } else {
        cpu->pc = 0x036Au;
    }
    if (sm_scpu_context_key(cpu) != 0x06F019C2u && sm_scpu_context_key(cpu) != 0x06F01B52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F01B52u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE036Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x036Du;
    if (sm_scpu_context_key(cpu) != 0x06F01B6Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01B6Au: {
    static const uint8_t source_bytes[] = {0x80u, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0xDE036Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0338u;
    if (sm_scpu_context_key(cpu) != 0x06F019C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01B7Au: {
    static const uint8_t source_bytes[] = {0x86u, 0x11u};
    if (sm_scpu_guard_code(cpu,bus,0xDE036Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x11u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0371u;
    if (sm_scpu_context_key(cpu) != 0x06F01B8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01B8Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0371u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0373u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01BA2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0374u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0098u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0376u;
    if (sm_scpu_context_key(cpu) != 0x06F01BB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01BB2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0376u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0379u;
    if (sm_scpu_context_key(cpu) != 0x06F01BCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01BCAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x40u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0379u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0040u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x037Bu;
    if (sm_scpu_context_key(cpu) != 0x06F01BDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01BDAu: {
    static const uint8_t source_bytes[] = {0x14u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE037Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint8_t modified = (uint8_t)(value & ~(cpu->a & 0xFFu));
    if (sm_scpu_write8(cpu,bus,address,modified) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & value & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x037Du;
    if (sm_scpu_context_key(cpu) != 0x06F01BEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01BEAu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE037Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01BF2u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x13u};
    if (sm_scpu_guard_code(cpu,bus,0xDE037Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x13u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0380u;
    if (sm_scpu_context_key(cpu) != 0x06F01C02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01C02u: {
    static const uint8_t source_bytes[] = {0x9Fu, 0x00u, 0x30u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0380u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E3000u + (uint32_t)cpu->x) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0384u;
    if (sm_scpu_context_key(cpu) != 0x06F01C22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F01C22u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0384u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0385u;
    if (sm_scpu_context_key(cpu) != 0x06F01C2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01C2Au: {
    static const uint8_t source_bytes[] = {0x9Fu, 0x03u, 0x30u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0385u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E3003u + (uint32_t)cpu->x) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0389u;
    if (sm_scpu_context_key(cpu) != 0x06F01C4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F01C4Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0389u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x038Bu;
    if (sm_scpu_context_key(cpu) != 0x06F01C58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01C58u: {
    static const uint8_t source_bytes[] = {0x98u};
    if (sm_scpu_guard_code(cpu,bus,0xDE038Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = cpu->y;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x038Cu;
    if (sm_scpu_context_key(cpu) != 0x06F01C60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01C60u: {
    static const uint8_t source_bytes[] = {0x9Fu, 0x01u, 0x30u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0xDE038Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E3001u + (uint32_t)cpu->x) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0390u;
    if (sm_scpu_context_key(cpu) != 0x06F01C80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01C80u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0390u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0392u;
    if (sm_scpu_context_key(cpu) != 0x06F01C92u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01C92u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0392u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0393u;
    if (sm_scpu_context_key(cpu) != 0x06F01C9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01C9Au: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0393u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0394u;
    if (sm_scpu_context_key(cpu) != 0x06F01CA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01CA2u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0394u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0395u;
    if (sm_scpu_context_key(cpu) != 0x06F01CAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01CAAu: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0395u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0396u;
    if (sm_scpu_context_key(cpu) != 0x06F01CB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01CB2u: {
    static const uint8_t source_bytes[] = {0xE0u, 0x80u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0396u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    uint16_t result = (uint16_t)(cpu->x - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->x >= value ? SM_P_C : 0u));
    cpu->pc = 0x0399u;
    if (sm_scpu_context_key(cpu) != 0x06F01CCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01CCAu: {
    static const uint8_t source_bytes[] = {0x90u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0399u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0x039Eu;
        cycles = 3u;
    } else {
        cpu->pc = 0x039Bu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F01CDAu && sm_scpu_context_key(cpu) != 0x06F01CF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F01CDAu: {
    static const uint8_t source_bytes[] = {0xA2u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE039Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x039Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01CF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01CF2u: {
    static const uint8_t source_bytes[] = {0x86u, 0x13u};
    if (sm_scpu_guard_code(cpu,bus,0xDE039Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x13u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03A0u;
    if (sm_scpu_context_key(cpu) != 0x06F01D02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01D02u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u && sm_scpu_context_key(cpu) != 0x06F02212u && sm_scpu_context_key(cpu) != 0x06F022CAu && sm_scpu_context_key(cpu) != 0x06F0237Au && sm_scpu_context_key(cpu) != 0x06F0242Au && sm_scpu_context_key(cpu) != 0x06F024A2u && sm_scpu_context_key(cpu) != 0x06F0251Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01D12u: {
    static const uint8_t source_bytes[] = {0x64u, 0x28u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x28u);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03A4u;
    if (sm_scpu_context_key(cpu) != 0x06F01D22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01D22u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x80u, 0x40u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x4080u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03A7u;
    if (sm_scpu_context_key(cpu) != 0x06F01D3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01D3Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x03A9u;
    if (sm_scpu_context_key(cpu) != 0x06F01D48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01D48u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03A9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03ACu;
    if (sm_scpu_context_key(cpu) != 0x06F01D60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01D60u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03AEu;
    if (sm_scpu_context_key(cpu) != 0x06F01D70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01D70u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03AFu;
    if (sm_scpu_context_key(cpu) != 0x06F01D78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01D78u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03AFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03B0u;
    if (sm_scpu_context_key(cpu) != 0x06F01D80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01D80u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03B0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03B1u;
    if (sm_scpu_context_key(cpu) != 0x06F01D88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01D88u: {
    static const uint8_t source_bytes[] = {0x65u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x03B3u;
    if (sm_scpu_context_key(cpu) != 0x06F01D98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01D98u: {
    static const uint8_t source_bytes[] = {0x6Fu, 0x02u, 0x00u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE03B3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = 0xDE0002u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x03B7u;
    if (sm_scpu_context_key(cpu) != 0x06F01DB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01DB8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03B9u;
    if (sm_scpu_context_key(cpu) != 0x06F01DC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01DC8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x03BBu;
    if (sm_scpu_context_key(cpu) != 0x06F01DDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01DDAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE03BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00DEu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03BDu;
    if (sm_scpu_context_key(cpu) != 0x06F01DEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01DEAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE03BDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03BFu;
    if (sm_scpu_context_key(cpu) != 0x06F01DFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01DFAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE03BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03C1u;
    if (sm_scpu_context_key(cpu) != 0x06F01E0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01E0Au: {
    static const uint8_t source_bytes[] = {0x09u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03C1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    uint16_t result = (cpu->a | value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03C3u;
    if (sm_scpu_context_key(cpu) != 0x06F01E1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01E1Au: {
    static const uint8_t source_bytes[] = {0x29u, 0xF7u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00F7u;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03C5u;
    if (sm_scpu_context_key(cpu) != 0x06F01E2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01E2Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE03C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03C7u;
    if (sm_scpu_context_key(cpu) != 0x06F01E3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01E3Au: {
    static const uint8_t source_bytes[] = {0x84u, 0x2Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03C7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x2Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03C9u;
    if (sm_scpu_context_key(cpu) != 0x06F01E4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01E4Au: {
    static const uint8_t source_bytes[] = {0xA0u, 0x02u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03CCu;
    if (sm_scpu_context_key(cpu) != 0x06F01E62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01E62u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03CCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x0Au);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03CEu;
    if (sm_scpu_context_key(cpu) != 0x06F01E72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01E72u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE03CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03D0u;
    if (sm_scpu_context_key(cpu) != 0x06F01E82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01E82u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03D0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x03D2u;
    if (sm_scpu_context_key(cpu) != 0x06F01E90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01E90u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x0Au);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03D4u;
    if (sm_scpu_context_key(cpu) != 0x06F01EA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01EA0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE03D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03D6u;
    if (sm_scpu_context_key(cpu) != 0x06F01EB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01EB0u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x07u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03D6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0007u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03D9u;
    if (sm_scpu_context_key(cpu) != 0x06F01EC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01EC8u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03D9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x0Au);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03DBu;
    if (sm_scpu_context_key(cpu) != 0x06F01ED8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01ED8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03DDu;
    if (sm_scpu_context_key(cpu) != 0x06F01EE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01EE8u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x03u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0003u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03E0u;
    if (sm_scpu_context_key(cpu) != 0x06F01F00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01F00u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE03E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x0Au);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03E2u;
    if (sm_scpu_context_key(cpu) != 0x06F01F10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01F10u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03E2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03E4u;
    if (sm_scpu_context_key(cpu) != 0x06F01F20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01F20u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03E4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x03E6u;
    if (sm_scpu_context_key(cpu) != 0x06F01F32u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01F32u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03E6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4202u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03E9u;
    if (sm_scpu_context_key(cpu) != 0x06F01F4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01F4Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x56u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0056u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03EBu;
    if (sm_scpu_context_key(cpu) != 0x06F01F5Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01F5Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4203u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03EEu;
    if (sm_scpu_context_key(cpu) != 0x06F01F72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01F72u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x03EFu;
    if (sm_scpu_context_key(cpu) != 0x06F01F7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01F7Au: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03F0u;
    if (sm_scpu_context_key(cpu) != 0x06F01F82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01F82u: {
    static const uint8_t source_bytes[] = {0xADu, 0x17u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4217u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03F3u;
    if (sm_scpu_context_key(cpu) != 0x06F01F9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01F9Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03F5u;
    if (sm_scpu_context_key(cpu) != 0x06F01FAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F01FAAu: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE03F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03F6u;
    if (sm_scpu_context_key(cpu) != 0x06F01FB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01FB2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4202u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03F9u;
    if (sm_scpu_context_key(cpu) != 0x06F01FCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01FCAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x03FBu;
    if (sm_scpu_context_key(cpu) != 0x06F01FDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F01FDAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4203u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x03FEu;
    if (sm_scpu_context_key(cpu) != 0x06F01FF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F01FF2u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03FEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x03FFu;
    if (sm_scpu_context_key(cpu) != 0x06F01FFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F01FFAu: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03FFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0400u;
    if (sm_scpu_context_key(cpu) != 0x06F02002u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02002u: {
    static const uint8_t source_bytes[] = {0xADu, 0x16u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0400u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4216u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0403u;
    if (sm_scpu_context_key(cpu) != 0x06F0201Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0201Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x25u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0403u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x25u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0405u;
    if (sm_scpu_context_key(cpu) != 0x06F0202Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0202Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0405u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0407u;
    if (sm_scpu_context_key(cpu) != 0x06F0203Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0203Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0407u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4202u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x040Au;
    if (sm_scpu_context_key(cpu) != 0x06F02052u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02052u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE040Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x040Cu;
    if (sm_scpu_context_key(cpu) != 0x06F02062u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02062u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE040Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4203u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x040Fu;
    if (sm_scpu_context_key(cpu) != 0x06F0207Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0207Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE040Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x21u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0411u;
    if (sm_scpu_context_key(cpu) != 0x06F02088u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02088u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0411u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0413u;
    if (sm_scpu_context_key(cpu) != 0x06F02098u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02098u: {
    static const uint8_t source_bytes[] = {0x6Du, 0x16u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0413u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4216u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a & 0xFFFFu;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = sum & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x0416u;
    if (sm_scpu_context_key(cpu) != 0x06F020B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F020B0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0416u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0418u;
    if (sm_scpu_context_key(cpu) != 0x06F020C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F020C0u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0418u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x041Au;
    if (sm_scpu_context_key(cpu) != 0x06F020D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F020D2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE041Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x21u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x041Cu;
    if (sm_scpu_context_key(cpu) != 0x06F020E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F020E2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE041Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4202u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x041Fu;
    if (sm_scpu_context_key(cpu) != 0x06F020FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F020FAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x56u};
    if (sm_scpu_guard_code(cpu,bus,0xDE041Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0056u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0421u;
    if (sm_scpu_context_key(cpu) != 0x06F0210Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0210Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0421u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4203u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0424u;
    if (sm_scpu_context_key(cpu) != 0x06F02122u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02122u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0424u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x21u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0426u;
    if (sm_scpu_context_key(cpu) != 0x06F02130u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02130u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0426u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0428u;
    if (sm_scpu_context_key(cpu) != 0x06F02140u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02140u: {
    static const uint8_t source_bytes[] = {0x6Du, 0x16u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0428u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4216u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a & 0xFFFFu;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = sum & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x042Bu;
    if (sm_scpu_context_key(cpu) != 0x06F02158u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F02158u: {
    static const uint8_t source_bytes[] = {0x85u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0xDE042Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x042Du;
    if (sm_scpu_context_key(cpu) != 0x06F02168u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02168u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE042Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x042Eu;
    if (sm_scpu_context_key(cpu) != 0x06F02170u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02170u: {
    static const uint8_t source_bytes[] = {0x85u, 0x26u};
    if (sm_scpu_guard_code(cpu,bus,0xDE042Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x26u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0430u;
    if (sm_scpu_context_key(cpu) != 0x06F02180u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02180u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0430u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0432u;
    if (sm_scpu_context_key(cpu) != 0x06F02192u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02192u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0432u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0434u;
    if (sm_scpu_context_key(cpu) != 0x06F021A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F021A2u: {
    static const uint8_t source_bytes[] = {0x04u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0434u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t modified = (uint8_t)(value | (cpu->a & 0xFFu));
    if (sm_scpu_write8(cpu,bus,address,modified) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & value & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0436u;
    if (sm_scpu_context_key(cpu) != 0x06F021B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F021B2u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0436u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F021E2u: {
    static const uint8_t source_bytes[] = {0xA8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE043Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x043Du;
    if (sm_scpu_context_key(cpu) != 0x06F021EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F021EAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x87u};
    if (sm_scpu_guard_code(cpu,bus,0xDE043Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0087u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x043Fu;
    if (sm_scpu_context_key(cpu) != 0x06F021FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F021FAu: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Eu, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE043Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0441u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x037Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01BF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02212u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0442u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0221Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0443u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0445u;
    if (sm_scpu_context_key(cpu) != 0x06F0222Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0222Au: {
    static const uint8_t source_bytes[] = {0x84u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0445u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x03u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0447u;
    if (sm_scpu_context_key(cpu) != 0x06F0223Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0223Au: {
    static const uint8_t source_bytes[] = {0x20u, 0x8Fu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0447u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0449u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x078Fu;
    if (sm_scpu_context_key(cpu) != 0x06F03C7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02252u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE044Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x044Cu;
    if (sm_scpu_context_key(cpu) != 0x06F02262u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02262u: {
    static const uint8_t source_bytes[] = {0xB0u, 0x0Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE044Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) != 0u) {
        cpu->pc = 0x0459u;
        cycles = 3u;
    } else {
        cpu->pc = 0x044Eu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F02272u && sm_scpu_context_key(cpu) != 0x06F022CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F02272u: {
    static const uint8_t source_bytes[] = {0x09u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0xDE044Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0088u;
    uint16_t result = (cpu->a | value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0450u;
    if (sm_scpu_context_key(cpu) != 0x06F02282u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02282u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0450u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0451u;
    if (sm_scpu_context_key(cpu) != 0x06F0228Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0228Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0451u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0453u;
    if (sm_scpu_context_key(cpu) != 0x06F0229Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0229Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0453u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0454u;
    if (sm_scpu_context_key(cpu) != 0x06F022A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F022A2u: {
    static const uint8_t source_bytes[] = {0xA4u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0454u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0456u;
    if (sm_scpu_context_key(cpu) != 0x06F022B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F022B2u: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Eu, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0456u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0458u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x037Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01BF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F022CAu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0459u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F022D2u: {
    static const uint8_t source_bytes[] = {0x84u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE045Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x03u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x045Cu;
    if (sm_scpu_context_key(cpu) != 0x06F022E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F022E2u: {
    static const uint8_t source_bytes[] = {0x20u, 0x8Fu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE045Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x045Eu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x078Fu;
    if (sm_scpu_context_key(cpu) != 0x06F03C7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F022FAu: {
    static const uint8_t source_bytes[] = {0xC9u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE045Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0461u;
    if (sm_scpu_context_key(cpu) != 0x06F0230Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0230Au: {
    static const uint8_t source_bytes[] = {0xB0u, 0x0Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0461u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) != 0u) {
        cpu->pc = 0x046Fu;
        cycles = 3u;
    } else {
        cpu->pc = 0x0463u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0231Au && sm_scpu_context_key(cpu) != 0x06F0237Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0231Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0463u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0465u;
    if (sm_scpu_context_key(cpu) != 0x06F0232Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0232Au: {
    static const uint8_t source_bytes[] = {0xA4u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0465u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0467u;
    if (sm_scpu_context_key(cpu) != 0x06F0233Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0233Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0467u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0469u;
    if (sm_scpu_context_key(cpu) != 0x06F0234Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0234Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0469u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x046Au;
    if (sm_scpu_context_key(cpu) != 0x06F02352u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02352u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x94u};
    if (sm_scpu_guard_code(cpu,bus,0xDE046Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0094u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x046Cu;
    if (sm_scpu_context_key(cpu) != 0x06F02362u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02362u: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Eu, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE046Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x046Eu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x037Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01BF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0237Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE046Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02382u: {
    static const uint8_t source_bytes[] = {0x84u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0470u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x03u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0472u;
    if (sm_scpu_context_key(cpu) != 0x06F02392u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02392u: {
    static const uint8_t source_bytes[] = {0x20u, 0x8Fu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0472u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0474u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x078Fu;
    if (sm_scpu_context_key(cpu) != 0x06F03C7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F023AAu: {
    static const uint8_t source_bytes[] = {0xC9u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0475u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0477u;
    if (sm_scpu_context_key(cpu) != 0x06F023BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F023BAu: {
    static const uint8_t source_bytes[] = {0xB0u, 0x0Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0477u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) != 0u) {
        cpu->pc = 0x0485u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0479u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F023CAu && sm_scpu_context_key(cpu) != 0x06F0242Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F023CAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0479u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x047Bu;
    if (sm_scpu_context_key(cpu) != 0x06F023DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F023DAu: {
    static const uint8_t source_bytes[] = {0xA4u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE047Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x047Du;
    if (sm_scpu_context_key(cpu) != 0x06F023EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F023EAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE047Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x047Fu;
    if (sm_scpu_context_key(cpu) != 0x06F023FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F023FAu: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE047Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0480u;
    if (sm_scpu_context_key(cpu) != 0x06F02402u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02402u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x95u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0480u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0095u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0482u;
    if (sm_scpu_context_key(cpu) != 0x06F02412u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02412u: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Eu, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0482u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0484u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x037Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01BF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0242Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0485u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02432u: {
    static const uint8_t source_bytes[] = {0x85u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0486u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0488u;
    if (sm_scpu_context_key(cpu) != 0x06F02442u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02442u: {
    static const uint8_t source_bytes[] = {0x84u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0488u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x03u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x048Au;
    if (sm_scpu_context_key(cpu) != 0x06F02452u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02452u: {
    static const uint8_t source_bytes[] = {0xA4u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE048Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x048Cu;
    if (sm_scpu_context_key(cpu) != 0x06F02462u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02462u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE048Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x048Eu;
    if (sm_scpu_context_key(cpu) != 0x06F02472u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02472u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE048Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x048Fu;
    if (sm_scpu_context_key(cpu) != 0x06F0247Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0247Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x96u};
    if (sm_scpu_guard_code(cpu,bus,0xDE048Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0096u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0491u;
    if (sm_scpu_context_key(cpu) != 0x06F0248Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0248Au: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Eu, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0491u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0493u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x037Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01BF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F024A2u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0494u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F024AAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0495u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0497u;
    if (sm_scpu_context_key(cpu) != 0x06F024BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F024BAu: {
    static const uint8_t source_bytes[] = {0x84u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0497u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x03u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0499u;
    if (sm_scpu_context_key(cpu) != 0x06F024CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F024CAu: {
    static const uint8_t source_bytes[] = {0xA4u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0499u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x049Bu;
    if (sm_scpu_context_key(cpu) != 0x06F024DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F024DAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE049Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x049Du;
    if (sm_scpu_context_key(cpu) != 0x06F024EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F024EAu: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE049Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x049Eu;
    if (sm_scpu_context_key(cpu) != 0x06F024F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F024F2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x97u};
    if (sm_scpu_guard_code(cpu,bus,0xDE049Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0097u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04A0u;
    if (sm_scpu_context_key(cpu) != 0x06F02502u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02502u: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Eu, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x04A2u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x037Eu;
    if (sm_scpu_context_key(cpu) != 0x06F01BF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0251Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04A3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02522u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE04A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04A5u;
    if (sm_scpu_context_key(cpu) != 0x06F0252Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0252Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04A5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04A7u;
    if (sm_scpu_context_key(cpu) != 0x06F0253Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0253Au: {
    static const uint8_t source_bytes[] = {0x04u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE04A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t modified = (uint8_t)(value | (cpu->a & 0xFFu));
    if (sm_scpu_write8(cpu,bus,address,modified) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & value & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04A9u;
    if (sm_scpu_context_key(cpu) != 0x06F0254Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0254Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE04A9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04AAu;
    if (sm_scpu_context_key(cpu) != 0x06F02552u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02552u: {
    static const uint8_t source_bytes[] = {0x29u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0007u;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04ACu;
    if (sm_scpu_context_key(cpu) != 0x06F02562u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02562u: {
    static const uint8_t source_bytes[] = {0x09u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    uint16_t result = (cpu->a | value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04AEu;
    if (sm_scpu_context_key(cpu) != 0x06F02572u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02572u: {
    static const uint8_t source_bytes[] = {0x85u, 0x29u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x29u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x04B0u;
    if (sm_scpu_context_key(cpu) != 0x06F02582u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02582u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04B0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02732u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04E6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x04E8u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0274Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04EBu;
    if (sm_scpu_context_key(cpu) != 0x06F0275Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0275Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x04EEu;
    if (sm_scpu_context_key(cpu) != 0x06F02772u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02772u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x99u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0099u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04F0u;
    if (sm_scpu_context_key(cpu) != 0x06F02782u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02782u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x04F3u;
    if (sm_scpu_context_key(cpu) != 0x06F0279Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0279Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04F5u;
    if (sm_scpu_context_key(cpu) != 0x06F027AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F027AAu: {
    static const uint8_t source_bytes[] = {0x14u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE04F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint8_t modified = (uint8_t)(value & ~(cpu->a & 0xFFu));
    if (sm_scpu_write8(cpu,bus,address,modified) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & value & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04F7u;
    if (sm_scpu_context_key(cpu) != 0x06F027BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F027BAu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04F7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00D3Au && sm_scpu_context_key(cpu) != 0x06F00DBAu && sm_scpu_context_key(cpu) != 0x06F00E4Au && sm_scpu_context_key(cpu) != 0x06F01002u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F03C7Au: {
    static const uint8_t source_bytes[] = {0x29u, 0x7Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE078Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Fu;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0791u;
    if (sm_scpu_context_key(cpu) != 0x06F03C8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03C8Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0791u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0793u;
    if (sm_scpu_context_key(cpu) != 0x06F03C9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03C9Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0793u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Au);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0795u;
    if (sm_scpu_context_key(cpu) != 0x06F03CAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03CAAu: {
    static const uint8_t source_bytes[] = {0xC9u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0795u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FFu;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0797u;
    if (sm_scpu_context_key(cpu) != 0x06F03CBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03CBAu: {
    static const uint8_t source_bytes[] = {0xF0u, 0x1Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0797u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x07B4u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0799u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F03CCAu && sm_scpu_context_key(cpu) != 0x06F03DA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F03CCAu: {
    static const uint8_t source_bytes[] = {0x64u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0799u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x01u);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x079Bu;
    if (sm_scpu_context_key(cpu) != 0x06F03CDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03CDAu: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE079Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x079Cu;
    if (sm_scpu_context_key(cpu) != 0x06F03CE2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03CE2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE079Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x079Eu;
    if (sm_scpu_context_key(cpu) != 0x06F03CF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03CF2u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE079Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x07A0u;
    if (sm_scpu_context_key(cpu) != 0x06F03D00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03D00u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE07A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07A1u;
    if (sm_scpu_context_key(cpu) != 0x06F03D08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03D08u: {
    static const uint8_t source_bytes[] = {0x05u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07A1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a | value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07A3u;
    if (sm_scpu_context_key(cpu) != 0x06F03D18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03D18u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE07A3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07A4u;
    if (sm_scpu_context_key(cpu) != 0x06F03D20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03D20u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE07A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07A5u;
    if (sm_scpu_context_key(cpu) != 0x06F03D28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03D28u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07A5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x07A7u;
    if (sm_scpu_context_key(cpu) != 0x06F03D3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03D3Au: {
    static const uint8_t source_bytes[] = {0xBFu, 0x30u, 0x29u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE07A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE2930u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07ABu;
    if (sm_scpu_context_key(cpu) != 0x06F03D5Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F03D5Au: {
    static const uint8_t source_bytes[] = {0xB0u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07ABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) != 0u) {
        cpu->pc = 0x07B1u;
        cycles = 3u;
    } else {
        cpu->pc = 0x07ADu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F03D6Au && sm_scpu_context_key(cpu) != 0x06F03D8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F03D6Au: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE07ADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = left >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07AEu;
    if (sm_scpu_context_key(cpu) != 0x06F03D72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03D72u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE07AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = left >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07AFu;
    if (sm_scpu_context_key(cpu) != 0x06F03D7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03D7Au: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE07AFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = left >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07B0u;
    if (sm_scpu_context_key(cpu) != 0x06F03D82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03D82u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE07B0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = left >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07B1u;
    if (sm_scpu_context_key(cpu) != 0x06F03D8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03D8Au: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE07B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07B3u;
    if (sm_scpu_context_key(cpu) != 0x06F03D9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03D9Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07B3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F02252u && sm_scpu_context_key(cpu) != 0x06F022FAu && sm_scpu_context_key(cpu) != 0x06F023AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F03DA2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE07B4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x07B6u;
    if (sm_scpu_context_key(cpu) != 0x06F03DB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03DB2u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE07B6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F02252u && sm_scpu_context_key(cpu) != 0x06F022FAu && sm_scpu_context_key(cpu) != 0x06F023AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
