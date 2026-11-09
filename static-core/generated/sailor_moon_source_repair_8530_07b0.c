#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_source_repair_8530_07b0(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x040C2980u: {
    static const uint8_t source_bytes[] = {0xAEu, 0xB6u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x818530u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B6u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8533u;
    if (sm_scpu_context_key(cpu) != 0x040C2998u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040C2998u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x37u, 0x85u};
    if (sm_scpu_guard_code(cpu,bus,0x818533u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u || cpu->x == 0x0006u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0x8535u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x8537u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0x853Fu) || (cpu->x == 0x0002u && target == 0x854Fu) || (cpu->x == 0x0004u && target == 0x854Fu) || (cpu->x == 0x0006u && target == 0x8557u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x040C29F8u && sm_scpu_context_key(cpu) != 0x040C2A78u && sm_scpu_context_key(cpu) != 0x040C2AB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C29B0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x818536u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C01B0u && sm_scpu_context_key(cpu) != 0x040C2238u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C29F8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x81853Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8541u;
    if (sm_scpu_context_key(cpu) != 0x040C2A0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2A0Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x47u};
    if (sm_scpu_guard_code(cpu,bus,0x818541u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0047u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8543u;
    if (sm_scpu_context_key(cpu) != 0x040C2A1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C2A1Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x72u};
    if (sm_scpu_guard_code(cpu,bus,0x818543u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x72u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8545u;
    if (sm_scpu_context_key(cpu) != 0x040C2A2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C2A2Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x818545u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8547u;
    if (sm_scpu_context_key(cpu) != 0x040C2A38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2A38u: {
    static const uint8_t source_bytes[] = {0xEEu, 0xB6u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x818547u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B6u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x854Au;
    if (sm_scpu_context_key(cpu) != 0x040C2A50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2A50u: {
    static const uint8_t source_bytes[] = {0xEEu, 0xB6u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x81854Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B6u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x854Du;
    if (sm_scpu_context_key(cpu) != 0x040C2A68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2A68u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81854Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x854Eu;
    if (sm_scpu_context_key(cpu) != 0x040C2A70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C2A70u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81854Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C29B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2A78u: {
    static const uint8_t source_bytes[] = {0xEEu, 0xB6u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x81854Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B6u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8552u;
    if (sm_scpu_context_key(cpu) != 0x040C2A90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2A90u: {
    static const uint8_t source_bytes[] = {0xEEu, 0xB6u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x818552u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B6u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8555u;
    if (sm_scpu_context_key(cpu) != 0x040C2AA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2AA8u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x818555u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x8556u;
    if (sm_scpu_context_key(cpu) != 0x040C2AB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C2AB0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x818556u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C29B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2AB8u: {
    static const uint8_t source_bytes[] = {0x20u, 0x2Fu, 0x86u};
    if (sm_scpu_guard_code(cpu,bus,0x818557u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x8559u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x862Fu;
    if (sm_scpu_context_key(cpu) != 0x040C3178u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2AD0u: {
    static const uint8_t source_bytes[] = {0x20u, 0x67u, 0x85u};
    if (sm_scpu_guard_code(cpu,bus,0x81855Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x855Cu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8567u;
    if (sm_scpu_context_key(cpu) != 0x040C2B38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2AE8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81855Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8560u;
    if (sm_scpu_context_key(cpu) != 0x040C2B00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2B00u: {
    static const uint8_t source_bytes[] = {0x85u, 0x96u};
    if (sm_scpu_guard_code(cpu,bus,0x818560u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x96u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8562u;
    if (sm_scpu_context_key(cpu) != 0x040C2B10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C2B10u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0xB6u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x818562u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B6u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8565u;
    if (sm_scpu_context_key(cpu) != 0x040C2B28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040C2B28u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x818565u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x8566u;
    if (sm_scpu_context_key(cpu) != 0x040C2B30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C2B30u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x818566u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C29B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2B38u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x818567u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8569u;
    if (sm_scpu_context_key(cpu) != 0x040C2B48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2B48u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x818569u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x856Cu;
    if (sm_scpu_context_key(cpu) != 0x040C2B60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2B60u: {
    static const uint8_t source_bytes[] = {0x22u, 0xB3u, 0x9Cu, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x81856Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x856Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x9CB3u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x0404E598u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2B83u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x818570u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8572u;
    if (sm_scpu_context_key(cpu) != 0x040C2B90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2B90u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x05u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x818572u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0005u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8575u;
    if (sm_scpu_context_key(cpu) != 0x040C2BA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2BA8u: {
    static const uint8_t source_bytes[] = {0x22u, 0xB3u, 0x9Cu, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x818575u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x8578u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x9CB3u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x0404E598u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2BCBu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x818579u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x857Bu;
    if (sm_scpu_context_key(cpu) != 0x040C2BD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2BD8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x06u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81857Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0006u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x857Eu;
    if (sm_scpu_context_key(cpu) != 0x040C2BF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2BF0u: {
    static const uint8_t source_bytes[] = {0x22u, 0xB3u, 0x9Cu, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x81857Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x8581u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x9CB3u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x0404E598u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2C13u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x818582u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8584u;
    if (sm_scpu_context_key(cpu) != 0x040C2C20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2C20u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x07u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x818584u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0007u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8587u;
    if (sm_scpu_context_key(cpu) != 0x040C2C38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2C38u: {
    static const uint8_t source_bytes[] = {0x22u, 0xB3u, 0x9Cu, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x818587u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x858Au;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x9CB3u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x0404E598u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2C5Bu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x81858Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x858Du;
    if (sm_scpu_context_key(cpu) != 0x040C2C68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2C68u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81858Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8590u;
    if (sm_scpu_context_key(cpu) != 0x040C2C80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2C80u: {
    static const uint8_t source_bytes[] = {0x22u, 0x64u, 0x92u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x818590u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x8593u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x9264u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04049320u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2CA0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x818594u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8596u;
    if (sm_scpu_context_key(cpu) != 0x040C2CB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2CB0u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x92u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x818596u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0792u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8599u;
    if (sm_scpu_context_key(cpu) != 0x040C2CC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040C2CC8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x818599u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x859Cu;
    if (sm_scpu_context_key(cpu) != 0x040C2CE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2CE0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x9Cu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x81859Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x079Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x859Fu;
    if (sm_scpu_context_key(cpu) != 0x040C2CF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040C2CF8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81859Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85A2u;
    if (sm_scpu_context_key(cpu) != 0x040C2D10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2D10u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x8Au, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8185A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x078Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85A5u;
    if (sm_scpu_context_key(cpu) != 0x040C2D28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040C2D28u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8185A5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85A7u;
    if (sm_scpu_context_key(cpu) != 0x040C2D38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2D38u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x30u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8185A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0030u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85AAu;
    if (sm_scpu_context_key(cpu) != 0x040C2D50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2D50u: {
    static const uint8_t source_bytes[] = {0x8Du, 0xB2u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8185AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B2u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85ADu;
    if (sm_scpu_context_key(cpu) != 0x040C2D68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040C2D68u: {
    static const uint8_t source_bytes[] = {0x22u, 0xDCu, 0x8Bu, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x8185ADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x85B0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8BDCu;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04045EE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2D88u: {
    static const uint8_t source_bytes[] = {0x22u, 0x1Du, 0x88u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x8185B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x85B4u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x881Du;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x040440E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2DA8u: {
    static const uint8_t source_bytes[] = {0x22u, 0xEFu, 0x93u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x8185B5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x85B8u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x93EFu;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04049F78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2DC8u: {
    static const uint8_t source_bytes[] = {0x22u, 0xDCu, 0x96u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x8185B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x85BCu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x96DCu;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x0404B6E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2DE8u: {
    static const uint8_t source_bytes[] = {0x20u, 0xC3u, 0x85u};
    if (sm_scpu_guard_code(cpu,bus,0x8185BDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x85BFu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x85C3u;
    if (sm_scpu_context_key(cpu) != 0x040C2E18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2E00u: {
    static const uint8_t source_bytes[] = {0x90u, 0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x8185C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0x85ADu;
        cycles = 3u;
    } else {
        cpu->pc = 0x85C2u;
    }
    if (sm_scpu_context_key(cpu) != 0x040C2D68u && sm_scpu_context_key(cpu) != 0x040C2E10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040C2E10u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8185C2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C2AE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2E18u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8185C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85C5u;
    if (sm_scpu_context_key(cpu) != 0x040C2E28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2E28u: {
    static const uint8_t source_bytes[] = {0xAEu, 0xB0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8185C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B0u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85C8u;
    if (sm_scpu_context_key(cpu) != 0x040C2E40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040C2E40u: {
    static const uint8_t source_bytes[] = {0xFCu, 0xCCu, 0x85u};
    if (sm_scpu_guard_code(cpu,bus,0x8185C8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0x85CAu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x85CCu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0x85D0u) || (cpu->x == 0x0002u && target == 0x85EFu))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x040C2E80u && sm_scpu_context_key(cpu) != 0x040C2F78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2E58u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8185CBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C2E00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2E80u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8185D0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85D2u;
    if (sm_scpu_context_key(cpu) != 0x040C2E90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2E90u: {
    static const uint8_t source_bytes[] = {0xCEu, 0xB2u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8185D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B2u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value - 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(result >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85D5u;
    if (sm_scpu_context_key(cpu) != 0x040C2EA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2EA8u: {
    static const uint8_t source_bytes[] = {0xD0u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x8185D5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x85EBu;
        cycles = 3u;
    } else {
        cpu->pc = 0x85D7u;
    }
    if (sm_scpu_context_key(cpu) != 0x040C2EB8u && sm_scpu_context_key(cpu) != 0x040C2F58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040C2EB8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x8185D7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85D9u;
    if (sm_scpu_context_key(cpu) != 0x040C2ECAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2ECAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x8185D9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85DBu;
    if (sm_scpu_context_key(cpu) != 0x040C2EDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2EDAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x8185DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85DDu;
    if (sm_scpu_context_key(cpu) != 0x040C2EEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C2EEAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Bu};
    if (sm_scpu_guard_code(cpu,bus,0x8185DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85DFu;
    if (sm_scpu_context_key(cpu) != 0x040C2EFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C2EFAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x8185DFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C0u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85E1u;
    if (sm_scpu_context_key(cpu) != 0x040C2F0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C2F0Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x8185E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85E3u;
    if (sm_scpu_context_key(cpu) != 0x040C2F1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C2F1Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8185E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85E5u;
    if (sm_scpu_context_key(cpu) != 0x040C2F28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2F28u: {
    static const uint8_t source_bytes[] = {0xEEu, 0xB0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8185E5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B0u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85E8u;
    if (sm_scpu_context_key(cpu) != 0x040C2F40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2F40u: {
    static const uint8_t source_bytes[] = {0xEEu, 0xB0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8185E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B0u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85EBu;
    if (sm_scpu_context_key(cpu) != 0x040C2F58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040C2F58u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8185EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85EDu;
    if (sm_scpu_context_key(cpu) != 0x040C2F68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2F68u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x8185EDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x85EEu;
    if (sm_scpu_context_key(cpu) != 0x040C2F70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C2F70u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8185EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C2E58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2F78u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8185EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85F1u;
    if (sm_scpu_context_key(cpu) != 0x040C2F88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2F88u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x8185F1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85F3u;
    if (sm_scpu_context_key(cpu) != 0x040C2F98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C2F98u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8185F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x85F6u;
    if (sm_scpu_context_key(cpu) != 0x040C2FB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2FB0u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x8185F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x85FAu;
        cycles = 3u;
    } else {
        cpu->pc = 0x85F8u;
    }
    if (sm_scpu_context_key(cpu) != 0x040C2FC0u && sm_scpu_context_key(cpu) != 0x040C2FD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040C2FC0u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x8185F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x85F9u;
    if (sm_scpu_context_key(cpu) != 0x040C2FC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C2FC8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8185F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C2E58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C2FD0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8185FAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x85FCu;
    if (sm_scpu_context_key(cpu) != 0x040C2FE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C2FE0u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0xB0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8185FCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07B0u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x85FFu;
    if (sm_scpu_context_key(cpu) != 0x040C2FF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040C2FF8u: {
    static const uint8_t source_bytes[] = {0x38u};
    if (sm_scpu_guard_code(cpu,bus,0x8185FFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | SM_P_C);
    cpu->pc = 0x8600u;
    if (sm_scpu_context_key(cpu) != 0x040C3000u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C3000u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x818600u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C2E58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
