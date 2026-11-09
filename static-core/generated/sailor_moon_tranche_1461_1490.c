#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_tranche_1461_1490(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x0405B620u: {
    static const uint8_t source_bytes[] = {0xA7u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6C4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xC6u);
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
    cpu->pc = 0xB6C6u;
    if (sm_scpu_context_key(cpu) != 0x0405B630u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405B630u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6C6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB6C9u;
    if (sm_scpu_context_key(cpu) != 0x0405B648u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405B648u: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Au, 0xB8u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xB6CBu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB87Au;
    if (sm_scpu_context_key(cpu) != 0x0405C3D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405B660u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6CCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB6CEu;
    if (sm_scpu_context_key(cpu) != 0x0405B670u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405B670u: {
    static const uint8_t source_bytes[] = {0xADu, 0x04u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80B6CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F04u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB6D1u;
    if (sm_scpu_context_key(cpu) != 0x0405B688u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405B688u: {
    static const uint8_t source_bytes[] = {0x8Du, 0xC6u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80B6D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FC6u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB6D4u;
    if (sm_scpu_context_key(cpu) != 0x0405B6A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405B6A0u: {
    static const uint8_t source_bytes[] = {0xE6u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC6u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB6D6u;
    if (sm_scpu_context_key(cpu) != 0x0405B6B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405B6B0u: {
    static const uint8_t source_bytes[] = {0xA7u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6D6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xC6u);
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
    cpu->pc = 0xB6D8u;
    if (sm_scpu_context_key(cpu) != 0x0405B6C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405B6C0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB6DBu;
    if (sm_scpu_context_key(cpu) != 0x0405B6D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405B6D8u: {
    static const uint8_t source_bytes[] = {0xC9u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FFu;
    uint16_t left = cpu->a & 0xFFFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((result & 0xFFFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0xB6DEu;
    if (sm_scpu_context_key(cpu) != 0x0405B6F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405B6F0u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0xB6E7u;
        cycles = 3u;
    } else {
        cpu->pc = 0xB6E0u;
    }
    if (sm_scpu_context_key(cpu) != 0x0405B700u && sm_scpu_context_key(cpu) != 0x0405B738u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0405B700u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x10u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0010u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB6E3u;
    if (sm_scpu_context_key(cpu) != 0x0405B718u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405B718u: {
    static const uint8_t source_bytes[] = {0x8Du, 0xC4u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80B6E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FC4u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB6E6u;
    if (sm_scpu_context_key(cpu) != 0x0405B730u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405B730u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6E6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0405B568u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405B738u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6E7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB6E9u;
    if (sm_scpu_context_key(cpu) != 0x0405B748u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405B748u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB6ECu;
    if (sm_scpu_context_key(cpu) != 0x0405B760u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405B760u: {
    static const uint8_t source_bytes[] = {0x8Du, 0xC4u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80B6ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FC4u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB6EFu;
    if (sm_scpu_context_key(cpu) != 0x0405B778u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405B778u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80B6EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0405B568u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405C3D0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B87Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB87Cu;
    if (sm_scpu_context_key(cpu) != 0x0405C3E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405C3E0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xF8u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B87Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00F8u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB87Fu;
    if (sm_scpu_context_key(cpu) != 0x0405C3F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405C3F8u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80B87Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB880u;
    if (sm_scpu_context_key(cpu) != 0x0405C400u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0405C400u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80B880u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB881u;
    if (sm_scpu_context_key(cpu) != 0x0405C408u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0405C408u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x80B881u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB882u;
    if (sm_scpu_context_key(cpu) != 0x0405C410u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0405C410u: {
    static const uint8_t source_bytes[] = {0x20u, 0x98u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80B882u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xB884u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFD98u;
    if (sm_scpu_context_key(cpu) != 0x0407ECC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405C428u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80B885u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0405B660u && sm_scpu_context_key(cpu) != 0x0405C230u && sm_scpu_context_key(cpu) != 0x0405D8B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405D7C0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80BAF8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBAFAu;
    if (sm_scpu_context_key(cpu) != 0x0405D7D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405D7D0u: {
    static const uint8_t source_bytes[] = {0xE6u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x80BAFAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC0u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBAFCu;
    if (sm_scpu_context_key(cpu) != 0x0405D7E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405D7E0u: {
    static const uint8_t source_bytes[] = {0xA7u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x80BAFCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xC0u);
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
    cpu->pc = 0xBAFEu;
    if (sm_scpu_context_key(cpu) != 0x0405D7F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405D7F0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80BAFEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB01u;
    if (sm_scpu_context_key(cpu) != 0x0405D808u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405D808u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80BB01u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB02u;
    if (sm_scpu_context_key(cpu) != 0x0405D810u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0405D810u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB02u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB03u;
    if (sm_scpu_context_key(cpu) != 0x0405D818u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0405D818u: {
    static const uint8_t source_bytes[] = {0xBFu, 0x29u, 0xBBu, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB03u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x80BB29u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB07u;
    if (sm_scpu_context_key(cpu) != 0x0405D838u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405D838u: {
    static const uint8_t source_bytes[] = {0x85u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB07u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC6u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBB09u;
    if (sm_scpu_context_key(cpu) != 0x0405D848u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405D848u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB09u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB0Cu;
    if (sm_scpu_context_key(cpu) != 0x0405D860u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405D860u: {
    static const uint8_t source_bytes[] = {0x85u, 0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB0Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC8u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBB0Eu;
    if (sm_scpu_context_key(cpu) != 0x0405D870u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405D870u: {
    static const uint8_t source_bytes[] = {0xA7u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB0Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xC6u);
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
    cpu->pc = 0xBB10u;
    if (sm_scpu_context_key(cpu) != 0x0405D880u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405D880u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB10u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB13u;
    if (sm_scpu_context_key(cpu) != 0x0405D898u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405D898u: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Au, 0xB8u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB13u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xBB15u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB87Au;
    if (sm_scpu_context_key(cpu) != 0x0405C3D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405D8B0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB16u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB18u;
    if (sm_scpu_context_key(cpu) != 0x0405D8C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405D8C0u: {
    static const uint8_t source_bytes[] = {0xE6u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB18u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC6u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB1Au;
    if (sm_scpu_context_key(cpu) != 0x0405D8D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405D8D0u: {
    static const uint8_t source_bytes[] = {0xADu, 0x04u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB1Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F04u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB1Du;
    if (sm_scpu_context_key(cpu) != 0x0405D8E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405D8E8u: {
    static const uint8_t source_bytes[] = {0x8Du, 0xC6u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB1Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FC6u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBB20u;
    if (sm_scpu_context_key(cpu) != 0x0405D900u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405D900u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x10u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB20u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0010u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB23u;
    if (sm_scpu_context_key(cpu) != 0x0405D918u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405D918u: {
    static const uint8_t source_bytes[] = {0x8Du, 0xC4u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB23u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FC4u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBB26u;
    if (sm_scpu_context_key(cpu) != 0x0405D930u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405D930u: {
    static const uint8_t source_bytes[] = {0xE6u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB26u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xC0u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB28u;
    if (sm_scpu_context_key(cpu) != 0x0405D940u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0405D940u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB28u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0405C2F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405DBC0u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB78u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBB79u;
    if (sm_scpu_context_key(cpu) != 0x0405DBC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBC1u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB78u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBB79u;
    if (sm_scpu_context_key(cpu) != 0x0405DBC9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBC2u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB78u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBB79u;
    if (sm_scpu_context_key(cpu) != 0x0405DBCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBC3u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB78u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBB79u;
    if (sm_scpu_context_key(cpu) != 0x0405DBCBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBC8u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB79u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBB7Au;
    if (sm_scpu_context_key(cpu) != 0x0405DBD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBC9u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB79u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBB7Au;
    if (sm_scpu_context_key(cpu) != 0x0405DBD1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBCAu: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB79u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBB7Au;
    if (sm_scpu_context_key(cpu) != 0x0405DBD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBCBu: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB79u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBB7Au;
    if (sm_scpu_context_key(cpu) != 0x0405DBD3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBD0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB7Bu;
    if (sm_scpu_context_key(cpu) != 0x0405DBD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405DBD1u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB7Bu;
    if (sm_scpu_context_key(cpu) != 0x0405DBD9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405DBD2u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB7Bu;
    if (sm_scpu_context_key(cpu) != 0x0405DBDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405DBD3u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB7Bu;
    if (sm_scpu_context_key(cpu) != 0x0405DBDBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405DBD8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB7Du;
    if (sm_scpu_context_key(cpu) != 0x0405DBE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBD9u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB7Du;
    if (sm_scpu_context_key(cpu) != 0x0405DBE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBDAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB7Du;
    if (sm_scpu_context_key(cpu) != 0x0405DBE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBDBu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB7Du;
    if (sm_scpu_context_key(cpu) != 0x0405DBE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DBE8u: {
    static const uint8_t source_bytes[] = {0xAEu, 0xBAu, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB7Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FBAu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB80u;
    if (sm_scpu_context_key(cpu) != 0x0405DC00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405DC00u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x88u, 0xBBu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB80u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u || cpu->x == 0x0006u || cpu->x == 0x0008u || cpu->x == 0x000Au)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xBB82u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xBB88u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xBB94u) || (cpu->x == 0x0002u && target == 0xBBF4u) || (cpu->x == 0x0004u && target == 0xBC29u) || (cpu->x == 0x0006u && target == 0xBC57u) || (cpu->x == 0x0008u && target == 0xBCABu) || (cpu->x == 0x000Au && target == 0xBCAEu))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x0405DCA0u && sm_scpu_context_key(cpu) != 0x0405DFA0u && sm_scpu_context_key(cpu) != 0x0405E148u && sm_scpu_context_key(cpu) != 0x0405E2B8u && sm_scpu_context_key(cpu) != 0x0405E558u && sm_scpu_context_key(cpu) != 0x0405E570u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x0405DC18u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB1u, 0xBCu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB83u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xBB85u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBCB1u;
    if (sm_scpu_context_key(cpu) != 0x0405E588u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405DC19u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB1u, 0xBCu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB83u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xBB85u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBCB1u;
    if (sm_scpu_context_key(cpu) != 0x0405E589u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405DC30u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB86u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB87u;
    if (sm_scpu_context_key(cpu) != 0x0405DC38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405DC31u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB86u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB87u;
    if (sm_scpu_context_key(cpu) != 0x0405DC39u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405DC38u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB87u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04040D58u && sm_scpu_context_key(cpu) != 0x04041448u && sm_scpu_context_key(cpu) != 0x04041718u && sm_scpu_context_key(cpu) != 0x04041948u && sm_scpu_context_key(cpu) != 0x04041B10u && sm_scpu_context_key(cpu) != 0x04041CC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405DC39u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB87u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04040D59u && sm_scpu_context_key(cpu) != 0x04041449u && sm_scpu_context_key(cpu) != 0x04041719u && sm_scpu_context_key(cpu) != 0x04041949u && sm_scpu_context_key(cpu) != 0x04041B11u && sm_scpu_context_key(cpu) != 0x04041CC9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405DCA0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB94u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB96u;
    if (sm_scpu_context_key(cpu) != 0x0405DCB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DCB0u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB96u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB98u;
    if (sm_scpu_context_key(cpu) != 0x0405DCC1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405DCC1u: {
    static const uint8_t source_bytes[] = {0xADu, 0xB0u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB98u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FB0u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB9Bu;
    if (sm_scpu_context_key(cpu) != 0x0405DCD9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405DCD9u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80BB9Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0xBBA0u;
        cycles = 3u;
    } else {
        cpu->pc = 0xBB9Du;
    }
    if (sm_scpu_context_key(cpu) != 0x0405DCE9u && sm_scpu_context_key(cpu) != 0x0405DD01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0405DCE9u: {
    static const uint8_t source_bytes[] = {0x20u, 0xC5u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80BB9Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xBB9Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFDC5u;
    if (sm_scpu_context_key(cpu) != 0x0407EE29u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405DD01u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80BBA0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0405DC19u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A001u: {
    static const uint8_t source_bytes[] = {0xA0u, 0xC5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F400u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C5u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF402u;
    if (sm_scpu_context_key(cpu) != 0x0407A011u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A011u: {
    static const uint8_t source_bytes[] = {0x84u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x80F402u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xFFu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF404u;
    if (sm_scpu_context_key(cpu) != 0x0407A021u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A021u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F404u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF406u;
    if (sm_scpu_context_key(cpu) != 0x0407A031u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A031u: {
    static const uint8_t source_bytes[] = {0xAFu, 0x4Au, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F406u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = 0x00014Au;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF40Au;
    if (sm_scpu_context_key(cpu) != 0x0407A051u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A051u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F40Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF40Bu;
    if (sm_scpu_context_key(cpu) != 0x0407A059u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A059u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F40Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF40Cu;
    if (sm_scpu_context_key(cpu) != 0x0407A061u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A061u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F40Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF40Du;
    if (sm_scpu_context_key(cpu) != 0x0407A069u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A069u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x06u, 0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x80F40Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x2806u;
    uint16_t result = (cpu->a - value) & 0xFFFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->a >= value ? SM_P_C : 0u));
    cpu->pc = 0xF410u;
    if (sm_scpu_context_key(cpu) != 0x0407A081u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A081u: {
    static const uint8_t source_bytes[] = {0x90u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F410u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0xF415u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF412u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407A091u && sm_scpu_context_key(cpu) != 0x0407A0A9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407A091u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F412u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF415u;
    if (sm_scpu_context_key(cpu) != 0x0407A0A9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A0A9u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F415u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF416u;
    if (sm_scpu_context_key(cpu) != 0x0407A0B1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A0B1u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F416u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF417u;
    if (sm_scpu_context_key(cpu) != 0x0407A0B9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A0B9u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0x80F417u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF418u;
    if (sm_scpu_context_key(cpu) != 0x0407A0C1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407A0C1u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F418u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF419u;
    if (sm_scpu_context_key(cpu) != 0x0407A0C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A0C9u: {
    static const uint8_t source_bytes[] = {0x69u, 0xFEu, 0x09u};
    if (sm_scpu_guard_code(cpu,bus,0x80F419u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x09FEu;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF41Cu;
    if (sm_scpu_context_key(cpu) != 0x0407A0E1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A0E1u: {
    static const uint8_t source_bytes[] = {0x85u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F41Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xFDu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF41Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A0F1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A0F1u: {
    static const uint8_t source_bytes[] = {0xB7u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F41Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xFDu);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF420u;
    if (sm_scpu_context_key(cpu) != 0x0407A101u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A101u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F420u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF421u;
    if (sm_scpu_context_key(cpu) != 0x0407A109u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A109u: {
    static const uint8_t source_bytes[] = {0x6Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F421u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (value >> 1u) | ((cpu->p & SM_P_C) != 0u ? 0x8000u : 0u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF422u;
    if (sm_scpu_context_key(cpu) != 0x0407A111u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A111u: {
    static const uint8_t source_bytes[] = {0x6Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F422u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (value >> 1u) | ((cpu->p & SM_P_C) != 0u ? 0x8000u : 0u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF423u;
    if (sm_scpu_context_key(cpu) != 0x0407A119u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A119u: {
    static const uint8_t source_bytes[] = {0x6Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F423u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (value >> 1u) | ((cpu->p & SM_P_C) != 0u ? 0x8000u : 0u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF424u;
    if (sm_scpu_context_key(cpu) != 0x0407A121u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A121u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0x80F424u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF425u;
    if (sm_scpu_context_key(cpu) != 0x0407A129u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407A129u: {
    static const uint8_t source_bytes[] = {0xA5u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F425u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xFDu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF427u;
    if (sm_scpu_context_key(cpu) != 0x0407A139u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A139u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F427u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF428u;
    if (sm_scpu_context_key(cpu) != 0x0407A141u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A141u: {
    static const uint8_t source_bytes[] = {0x69u, 0x20u, 0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x80F428u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x2820u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF42Bu;
    if (sm_scpu_context_key(cpu) != 0x0407A159u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A159u: {
    static const uint8_t source_bytes[] = {0x85u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F42Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xFDu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF42Du;
    if (sm_scpu_context_key(cpu) != 0x0407A169u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A169u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0x80F42Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF42Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A171u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A171u: {
    static const uint8_t source_bytes[] = {0xD7u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F42Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xFDu);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a - value) & 0xFFFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->a >= value ? SM_P_C : 0u));
    cpu->pc = 0xF430u;
    if (sm_scpu_context_key(cpu) != 0x0407A181u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A181u: {
    static const uint8_t source_bytes[] = {0x80u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F430u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF435u;
    if (sm_scpu_context_key(cpu) != 0x0407A1A9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A1A9u: {
    static const uint8_t source_bytes[] = {0xADu, 0xB0u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80F435u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FB0u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF438u;
    if (sm_scpu_context_key(cpu) != 0x0407A1C1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A1C1u: {
    static const uint8_t source_bytes[] = {0x85u, 0xFAu};
    if (sm_scpu_guard_code(cpu,bus,0x80F438u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xFAu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF43Au;
    if (sm_scpu_context_key(cpu) != 0x0407A1D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A1D1u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F43Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF43Bu;
    if (sm_scpu_context_key(cpu) != 0x0407A1D9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A1D9u: {
    static const uint8_t source_bytes[] = {0x69u, 0x10u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F43Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0010u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF43Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A1F1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A1F1u: {
    static const uint8_t source_bytes[] = {0x85u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F43Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xFDu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF440u;
    if (sm_scpu_context_key(cpu) != 0x0407A201u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A201u: {
    static const uint8_t source_bytes[] = {0xA0u, 0xC0u};
    if (sm_scpu_guard_code(cpu,bus,0x80F440u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00C0u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF442u;
    if (sm_scpu_context_key(cpu) != 0x0407A211u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A211u: {
    static const uint8_t source_bytes[] = {0x84u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x80F442u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xFFu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF444u;
    if (sm_scpu_context_key(cpu) != 0x0407A221u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A221u: {
    static const uint8_t source_bytes[] = {0x84u, 0xFCu};
    if (sm_scpu_guard_code(cpu,bus,0x80F444u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xFCu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF446u;
    if (sm_scpu_context_key(cpu) != 0x0407A231u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A231u: {
    static const uint8_t source_bytes[] = {0xAFu, 0x48u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F446u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = 0x000148u;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF44Au;
    if (sm_scpu_context_key(cpu) != 0x0407A251u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A251u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x80F44Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF44Bu;
    if (sm_scpu_context_key(cpu) != 0x0407A259u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A259u: {
    static const uint8_t source_bytes[] = {0xBDu, 0x80u, 0xF7u};
    if (sm_scpu_guard_code(cpu,bus,0x80F44Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((((uint32_t)cpu->dbr << 16) | 0xF780u) + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF44Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A271u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((0x80u + cpu->x) > 0xFFu));
}
case 0x0407A271u: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F44Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    cpu->a = (uint16_t)(cpu->a & value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF451u;
    if (sm_scpu_context_key(cpu) != 0x0407A289u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A289u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x48u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F451u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0148u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF454u;
    if (sm_scpu_context_key(cpu) != 0x0407A2A1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A2A1u: {
    static const uint8_t source_bytes[] = {0xADu, 0xCCu, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80F454u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FCCu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF457u;
    if (sm_scpu_context_key(cpu) != 0x0407A2B9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A2B9u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F457u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    uint16_t result = (cpu->a - value) & 0xFFFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->a >= value ? SM_P_C : 0u));
    cpu->pc = 0xF45Au;
    if (sm_scpu_context_key(cpu) != 0x0407A2D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A2D1u: {
    static const uint8_t source_bytes[] = {0xD0u, 0x15u};
    if (sm_scpu_guard_code(cpu,bus,0x80F45Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0xF471u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF45Cu;
    }
    if (sm_scpu_context_key(cpu) != 0x0407A2E1u && sm_scpu_context_key(cpu) != 0x0407A389u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407A2E1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F45Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF45Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A2F1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A2F1u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0xCCu, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80F45Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FCCu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF461u;
    if (sm_scpu_context_key(cpu) != 0x0407A309u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407A309u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x46u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F461u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0146u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF464u;
    if (sm_scpu_context_key(cpu) != 0x0407A321u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A321u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x4Eu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F464u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x014Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF467u;
    if (sm_scpu_context_key(cpu) != 0x0407A339u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A339u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80F467u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->x = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF469u;
    if (sm_scpu_context_key(cpu) != 0x0407A349u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A349u: {
    static const uint8_t source_bytes[] = {0x20u, 0x57u, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F469u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF46Bu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF557u;
    if (sm_scpu_context_key(cpu) != 0x0407AAB9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A361u: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Fu, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F46Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF46Eu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF57Fu;
    if (sm_scpu_context_key(cpu) != 0x0407ABF9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A379u: {
    static const uint8_t source_bytes[] = {0x80u, 0x3Du};
    if (sm_scpu_guard_code(cpu,bus,0x80F46Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4AEu;
    if (sm_scpu_context_key(cpu) != 0x0407A571u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A389u: {
    static const uint8_t source_bytes[] = {0xAFu, 0x46u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F471u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = 0x000146u;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF475u;
    if (sm_scpu_context_key(cpu) != 0x0407A3A9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A3A9u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F475u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF476u;
    if (sm_scpu_context_key(cpu) != 0x0407A3B1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A3B1u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x80F476u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF477u;
    if (sm_scpu_context_key(cpu) != 0x0407A3B9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A3B9u: {
    static const uint8_t source_bytes[] = {0x20u, 0x57u, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F477u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF479u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF557u;
    if (sm_scpu_context_key(cpu) != 0x0407AAB9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A3D1u: {
    static const uint8_t source_bytes[] = {0xACu, 0x4Eu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F47Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x014Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF47Du;
    if (sm_scpu_context_key(cpu) != 0x0407A3E9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407A3E9u: {
    static const uint8_t source_bytes[] = {0xC0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F47Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    uint16_t result = (cpu->y - value) & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->y >= value ? SM_P_C : 0u));
    cpu->pc = 0xF47Fu;
    if (sm_scpu_context_key(cpu) != 0x0407A3F9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A3F9u: {
    static const uint8_t source_bytes[] = {0xD0u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80F47Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0xF4B3u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF481u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407A409u && sm_scpu_context_key(cpu) != 0x0407A599u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407A409u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F481u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0100u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF484u;
    if (sm_scpu_context_key(cpu) != 0x0407A421u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A421u: {
    static const uint8_t source_bytes[] = {0x85u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F484u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF6u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF486u;
    if (sm_scpu_context_key(cpu) != 0x0407A431u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A431u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x10u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F486u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0110u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF489u;
    if (sm_scpu_context_key(cpu) != 0x0407A449u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A449u: {
    static const uint8_t source_bytes[] = {0x85u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F489u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF8u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF48Bu;
    if (sm_scpu_context_key(cpu) != 0x0407A459u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A459u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x50u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F48Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0150u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF48Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A471u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A471u: {
    static const uint8_t source_bytes[] = {0x85u, 0xF2u};
    if (sm_scpu_guard_code(cpu,bus,0x80F48Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF2u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF490u;
    if (sm_scpu_context_key(cpu) != 0x0407A481u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A481u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x60u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F490u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0160u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF493u;
    if (sm_scpu_context_key(cpu) != 0x0407A499u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A499u: {
    static const uint8_t source_bytes[] = {0x85u, 0xF4u};
    if (sm_scpu_guard_code(cpu,bus,0x80F493u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF4u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF495u;
    if (sm_scpu_context_key(cpu) != 0x0407A4A9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A4A9u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Fu, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F495u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF497u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF51Fu;
    if (sm_scpu_context_key(cpu) != 0x0407A8F9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A4C1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80F498u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF49Au;
    if (sm_scpu_context_key(cpu) != 0x0407A4D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A4D1u: {
    static const uint8_t source_bytes[] = {0x84u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F49Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF6u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF49Cu;
    if (sm_scpu_context_key(cpu) != 0x0407A4E1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A4E1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80F49Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0030u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF49Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A4F1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A4F1u: {
    static const uint8_t source_bytes[] = {0x84u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F49Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF8u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4A0u;
    if (sm_scpu_context_key(cpu) != 0x0407A501u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A501u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x70u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0070u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4A2u;
    if (sm_scpu_context_key(cpu) != 0x0407A511u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A511u: {
    static const uint8_t source_bytes[] = {0x84u, 0xF2u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF2u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4A4u;
    if (sm_scpu_context_key(cpu) != 0x0407A521u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A521u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4A6u;
    if (sm_scpu_context_key(cpu) != 0x0407A531u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A531u: {
    static const uint8_t source_bytes[] = {0x84u, 0xF4u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4A6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF4u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4A8u;
    if (sm_scpu_context_key(cpu) != 0x0407A541u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A541u: {
    static const uint8_t source_bytes[] = {0x20u, 0x70u, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF4AAu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF570u;
    if (sm_scpu_context_key(cpu) != 0x0407AB81u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A559u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Fu, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4ABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF4ADu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF51Fu;
    if (sm_scpu_context_key(cpu) != 0x0407A8F9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A571u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0100u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4B1u;
    if (sm_scpu_context_key(cpu) != 0x0407A589u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A589u: {
    static const uint8_t source_bytes[] = {0x80u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4B9u;
    if (sm_scpu_context_key(cpu) != 0x0407A5C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A599u: {
    static const uint8_t source_bytes[] = {0x20u, 0x7Fu, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4B3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF4B5u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF57Fu;
    if (sm_scpu_context_key(cpu) != 0x0407ABF9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A5B1u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x50u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4B6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0150u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4B9u;
    if (sm_scpu_context_key(cpu) != 0x0407A5C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A5C9u: {
    static const uint8_t source_bytes[] = {0x20u, 0xA3u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F4B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF4BBu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFDA3u;
    if (sm_scpu_context_key(cpu) != 0x0407ED19u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A5E1u: {
    static const uint8_t source_bytes[] = {0xADu, 0x46u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0146u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4BFu;
    if (sm_scpu_context_key(cpu) != 0x0407A5F9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A5F9u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF4C0u;
    if (sm_scpu_context_key(cpu) != 0x0407A601u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A601u: {
    static const uint8_t source_bytes[] = {0x6Du, 0x48u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0148u;
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
    cpu->pc = 0xF4C3u;
    if (sm_scpu_context_key(cpu) != 0x0407A619u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A619u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x46u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0146u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4C6u;
    if (sm_scpu_context_key(cpu) != 0x0407A631u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A631u: {
    static const uint8_t source_bytes[] = {0x29u, 0xF0u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x80F4C6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFF0u;
    cpu->a = (uint16_t)(cpu->a & value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4C9u;
    if (sm_scpu_context_key(cpu) != 0x0407A649u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A649u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    uint16_t result = (cpu->a - value) & 0xFFFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->a >= value ? SM_P_C : 0u));
    cpu->pc = 0xF4CCu;
    if (sm_scpu_context_key(cpu) != 0x0407A661u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A661u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x3Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80F4CCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0xF509u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF4CEu;
    }
    if (sm_scpu_context_key(cpu) != 0x0407A671u && sm_scpu_context_key(cpu) != 0x0407A849u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407A671u: {
    static const uint8_t source_bytes[] = {0xADu, 0xCCu, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80F4CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FCCu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4D1u;
    if (sm_scpu_context_key(cpu) != 0x0407A689u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A689u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    uint16_t result = (cpu->a - value) & 0xFFFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->a >= value ? SM_P_C : 0u));
    cpu->pc = 0xF4D4u;
    if (sm_scpu_context_key(cpu) != 0x0407A6A1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A6A1u: {
    static const uint8_t source_bytes[] = {0xD0u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0xF4D9u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF4D6u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407A6B1u && sm_scpu_context_key(cpu) != 0x0407A6C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407A6B1u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4D6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4D9u;
    if (sm_scpu_context_key(cpu) != 0x0407A6C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A6C9u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4D9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF4DAu;
    if (sm_scpu_context_key(cpu) != 0x0407A6D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A6D1u: {
    static const uint8_t source_bytes[] = {0x69u, 0x20u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0020u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF4DDu;
    if (sm_scpu_context_key(cpu) != 0x0407A6E9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A6E9u: {
    static const uint8_t source_bytes[] = {0x8Du, 0xCCu, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80F4DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FCCu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4E0u;
    if (sm_scpu_context_key(cpu) != 0x0407A701u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A701u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF4E1u;
    if (sm_scpu_context_key(cpu) != 0x0407A709u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A709u: {
    static const uint8_t source_bytes[] = {0x6Du, 0xCAu, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80F4E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FCAu;
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
    cpu->pc = 0xF4E4u;
    if (sm_scpu_context_key(cpu) != 0x0407A721u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A721u: {
    static const uint8_t source_bytes[] = {0x8Du, 0xB8u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80F4E4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FB8u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4E7u;
    if (sm_scpu_context_key(cpu) != 0x0407A739u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A739u: {
    static const uint8_t source_bytes[] = {0xADu, 0x46u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4E7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0146u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4EAu;
    if (sm_scpu_context_key(cpu) != 0x0407A751u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A751u: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    cpu->a = (uint16_t)(cpu->a & value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4EDu;
    if (sm_scpu_context_key(cpu) != 0x0407A769u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A769u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x46u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4EDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0146u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4F0u;
    if (sm_scpu_context_key(cpu) != 0x0407A781u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A781u: {
    static const uint8_t source_bytes[] = {0xACu, 0x4Eu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x014Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4F3u;
    if (sm_scpu_context_key(cpu) != 0x0407A799u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407A799u: {
    static const uint8_t source_bytes[] = {0xC0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    uint16_t result = (cpu->y - value) & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->y >= value ? SM_P_C : 0u));
    cpu->pc = 0xF4F5u;
    if (sm_scpu_context_key(cpu) != 0x0407A7A9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A7A9u: {
    static const uint8_t source_bytes[] = {0xD0u, 0x09u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0xF500u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF4F7u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407A7B9u && sm_scpu_context_key(cpu) != 0x0407A801u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407A7B9u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4F7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4F8u;
    if (sm_scpu_context_key(cpu) != 0x0407A7C1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A7C1u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x4Eu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x014Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF4FBu;
    if (sm_scpu_context_key(cpu) != 0x0407A7D9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407A7D9u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x50u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0150u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF4FEu;
    if (sm_scpu_context_key(cpu) != 0x0407A7F1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A7F1u: {
    static const uint8_t source_bytes[] = {0x80u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0x80F4FEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF506u;
    if (sm_scpu_context_key(cpu) != 0x0407A831u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A801u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x4Eu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F500u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x014Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF503u;
    if (sm_scpu_context_key(cpu) != 0x0407A819u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A819u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F503u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0100u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF506u;
    if (sm_scpu_context_key(cpu) != 0x0407A831u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A831u: {
    static const uint8_t source_bytes[] = {0x20u, 0xA3u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F506u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF508u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFDA3u;
    if (sm_scpu_context_key(cpu) != 0x0407ED19u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A849u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0x80F509u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF50Au;
    if (sm_scpu_context_key(cpu) != 0x0407A851u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A851u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x4Au, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F50Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x014Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF50Du;
    if (sm_scpu_context_key(cpu) != 0x0407A869u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A869u: {
    static const uint8_t source_bytes[] = {0xADu, 0x46u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F50Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0146u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF510u;
    if (sm_scpu_context_key(cpu) != 0x0407A881u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A881u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80F510u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xF511u;
    if (sm_scpu_context_key(cpu) != 0x0407A889u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A889u: {
    static const uint8_t source_bytes[] = {0x6Du, 0x4Cu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F511u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x014Cu;
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
    cpu->pc = 0xF514u;
    if (sm_scpu_context_key(cpu) != 0x0407A8A1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A8A1u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x4Cu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F514u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x014Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF517u;
    if (sm_scpu_context_key(cpu) != 0x0407A8B9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407A8B9u: {
    static const uint8_t source_bytes[] = {0xEAu};
    if (sm_scpu_guard_code(cpu,bus,0x80F517u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF518u;
    if (sm_scpu_context_key(cpu) != 0x0407A8C1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A8C1u: {
    static const uint8_t source_bytes[] = {0xEAu};
    if (sm_scpu_guard_code(cpu,bus,0x80F518u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF519u;
    if (sm_scpu_context_key(cpu) != 0x0407A8C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A8C9u: {
    static const uint8_t source_bytes[] = {0xEAu};
    if (sm_scpu_guard_code(cpu,bus,0x80F519u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF51Au;
    if (sm_scpu_context_key(cpu) != 0x0407A8D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A8D1u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F51Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->x = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF51Cu;
    if (sm_scpu_context_key(cpu) != 0x0407A8E1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A8E1u: {
    static const uint8_t source_bytes[] = {0xDAu};
    if (sm_scpu_guard_code(cpu,bus,0x80F51Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF51Du;
    if (sm_scpu_context_key(cpu) != 0x0407A8E9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A8E9u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80F51Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF51Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A8F1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407A8F1u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F51Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407ED01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407A8F9u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F51Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF521u;
    if (sm_scpu_context_key(cpu) != 0x0407A909u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407A909u: {
    static const uint8_t source_bytes[] = {0xB7u, 0xFAu};
    if (sm_scpu_guard_code(cpu,bus,0x80F521u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xFAu);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF523u;
    if (sm_scpu_context_key(cpu) != 0x0407A919u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A919u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x1Bu, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F523u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u || cpu->x == 0x0006u || cpu->x == 0x0008u || cpu->x == 0x000Au || cpu->x == 0x000Cu || cpu->x == 0x000Eu || cpu->x == 0x0010u || cpu->x == 0x0012u || cpu->x == 0x0014u || cpu->x == 0x0016u || cpu->x == 0x0018u || cpu->x == 0x001Au || cpu->x == 0x001Cu || cpu->x == 0x001Eu || cpu->x == 0x0020u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xF525u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xF61Bu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xF5E3u) || (cpu->x == 0x0002u && target == 0xF5DDu) || (cpu->x == 0x0004u && target == 0xF5D7u) || (cpu->x == 0x0006u && target == 0xF5D1u) || (cpu->x == 0x0008u && target == 0xF5E4u) || (cpu->x == 0x000Au && target == 0xF5E8u) || (cpu->x == 0x000Cu && target == 0xF5ECu) || (cpu->x == 0x000Eu && target == 0xF5F0u) || (cpu->x == 0x0010u && target == 0xF5F4u) || (cpu->x == 0x0012u && target == 0xF613u) || (cpu->x == 0x0014u && target == 0xF60Du) || (cpu->x == 0x0016u && target == 0xF607u) || (cpu->x == 0x0018u && target == 0xF5F6u) || (cpu->x == 0x001Au && target == 0xF5FAu) || (cpu->x == 0x001Cu && target == 0xF5FEu) || (cpu->x == 0x001Eu && target == 0xF602u) || (cpu->x == 0x0020u && target == 0xF606u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x0407AE89u && sm_scpu_context_key(cpu) != 0x0407AEB9u && sm_scpu_context_key(cpu) != 0x0407AEE9u && sm_scpu_context_key(cpu) != 0x0407AF19u && sm_scpu_context_key(cpu) != 0x0407AF21u && sm_scpu_context_key(cpu) != 0x0407AF41u && sm_scpu_context_key(cpu) != 0x0407AF61u && sm_scpu_context_key(cpu) != 0x0407AF81u && sm_scpu_context_key(cpu) != 0x0407AFA1u && sm_scpu_context_key(cpu) != 0x0407AFB1u && sm_scpu_context_key(cpu) != 0x0407AFD1u && sm_scpu_context_key(cpu) != 0x0407AFF1u && sm_scpu_context_key(cpu) != 0x0407B011u && sm_scpu_context_key(cpu) != 0x0407B031u && sm_scpu_context_key(cpu) != 0x0407B039u && sm_scpu_context_key(cpu) != 0x0407B069u && sm_scpu_context_key(cpu) != 0x0407B099u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x0407A931u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x80F526u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF527u;
    if (sm_scpu_context_key(cpu) != 0x0407A939u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A939u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F527u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF529u;
    if (sm_scpu_context_key(cpu) != 0x0407A949u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A949u: {
    static const uint8_t source_bytes[] = {0x85u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x80F529u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF52Bu;
    if (sm_scpu_context_key(cpu) != 0x0407A959u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A959u: {
    static const uint8_t source_bytes[] = {0xB7u, 0xFDu};
    if (sm_scpu_guard_code(cpu,bus,0x80F52Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xFDu);
    uint8_t pointer_low, pointer_high, pointer_bank;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 2u) & 0xFFFFu,&pointer_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)pointer_bank << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF52Du;
    if (sm_scpu_context_key(cpu) != 0x0407A969u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A969u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x1Bu, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F52Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u || cpu->x == 0x0006u || cpu->x == 0x0008u || cpu->x == 0x000Au || cpu->x == 0x000Cu || cpu->x == 0x000Eu || cpu->x == 0x0010u || cpu->x == 0x0012u || cpu->x == 0x0014u || cpu->x == 0x0016u || cpu->x == 0x0018u || cpu->x == 0x001Au || cpu->x == 0x001Cu || cpu->x == 0x001Eu || cpu->x == 0x0020u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xF52Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xF61Bu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xF5E3u) || (cpu->x == 0x0002u && target == 0xF5DDu) || (cpu->x == 0x0004u && target == 0xF5D7u) || (cpu->x == 0x0006u && target == 0xF5D1u) || (cpu->x == 0x0008u && target == 0xF5E4u) || (cpu->x == 0x000Au && target == 0xF5E8u) || (cpu->x == 0x000Cu && target == 0xF5ECu) || (cpu->x == 0x000Eu && target == 0xF5F0u) || (cpu->x == 0x0010u && target == 0xF5F4u) || (cpu->x == 0x0012u && target == 0xF613u) || (cpu->x == 0x0014u && target == 0xF60Du) || (cpu->x == 0x0016u && target == 0xF607u) || (cpu->x == 0x0018u && target == 0xF5F6u) || (cpu->x == 0x001Au && target == 0xF5FAu) || (cpu->x == 0x001Cu && target == 0xF5FEu) || (cpu->x == 0x001Eu && target == 0xF602u) || (cpu->x == 0x0020u && target == 0xF606u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x0407AE89u && sm_scpu_context_key(cpu) != 0x0407AEB9u && sm_scpu_context_key(cpu) != 0x0407AEE9u && sm_scpu_context_key(cpu) != 0x0407AF19u && sm_scpu_context_key(cpu) != 0x0407AF21u && sm_scpu_context_key(cpu) != 0x0407AF41u && sm_scpu_context_key(cpu) != 0x0407AF61u && sm_scpu_context_key(cpu) != 0x0407AF81u && sm_scpu_context_key(cpu) != 0x0407AFA1u && sm_scpu_context_key(cpu) != 0x0407AFB1u && sm_scpu_context_key(cpu) != 0x0407AFD1u && sm_scpu_context_key(cpu) != 0x0407AFF1u && sm_scpu_context_key(cpu) != 0x0407B011u && sm_scpu_context_key(cpu) != 0x0407B031u && sm_scpu_context_key(cpu) != 0x0407B039u && sm_scpu_context_key(cpu) != 0x0407B069u && sm_scpu_context_key(cpu) != 0x0407B099u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x0407A981u: {
    static const uint8_t source_bytes[] = {0x85u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x80F530u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF532u;
    if (sm_scpu_context_key(cpu) != 0x0407A991u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A991u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F532u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x03u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF534u;
    if (sm_scpu_context_key(cpu) != 0x0407A9A1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A9A1u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x80F534u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF535u;
    if (sm_scpu_context_key(cpu) != 0x0407A9A9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A9A9u: {
    static const uint8_t source_bytes[] = {0x25u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0x80F535u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a & value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF537u;
    if (sm_scpu_context_key(cpu) != 0x0407A9B9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A9B9u: {
    static const uint8_t source_bytes[] = {0x11u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F537u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xF6u);
    uint8_t pointer_low, pointer_high;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = (uint16_t)(cpu->a | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF539u;
    if (sm_scpu_context_key(cpu) != 0x0407A9C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u) + (((uint32_t)pointer_low + cpu->y) > 0xFFu));
}
case 0x0407A9C9u: {
    static const uint8_t source_bytes[] = {0x91u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F539u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xF6u);
    uint8_t pointer_low, pointer_high;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF53Bu;
    if (sm_scpu_context_key(cpu) != 0x0407A9D9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A9D9u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F53Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x03u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF53Du;
    if (sm_scpu_context_key(cpu) != 0x0407A9E9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407A9E9u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x80F53Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF53Eu;
    if (sm_scpu_context_key(cpu) != 0x0407A9F1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407A9F1u: {
    static const uint8_t source_bytes[] = {0x25u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x80F53Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a & value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF540u;
    if (sm_scpu_context_key(cpu) != 0x0407AA01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AA01u: {
    static const uint8_t source_bytes[] = {0x91u, 0xF2u};
    if (sm_scpu_guard_code(cpu,bus,0x80F540u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xF2u);
    uint8_t pointer_low, pointer_high;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF542u;
    if (sm_scpu_context_key(cpu) != 0x0407AA11u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AA11u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F542u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x01u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF544u;
    if (sm_scpu_context_key(cpu) != 0x0407AA21u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AA21u: {
    static const uint8_t source_bytes[] = {0x25u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F544u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a & value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF546u;
    if (sm_scpu_context_key(cpu) != 0x0407AA31u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AA31u: {
    static const uint8_t source_bytes[] = {0x11u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F546u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xF8u);
    uint8_t pointer_low, pointer_high;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = (uint16_t)(cpu->a | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF548u;
    if (sm_scpu_context_key(cpu) != 0x0407AA41u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u) + (((uint32_t)pointer_low + cpu->y) > 0xFFu));
}
case 0x0407AA41u: {
    static const uint8_t source_bytes[] = {0x91u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F548u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xF8u);
    uint8_t pointer_low, pointer_high;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF54Au;
    if (sm_scpu_context_key(cpu) != 0x0407AA51u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AA51u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F54Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x01u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF54Cu;
    if (sm_scpu_context_key(cpu) != 0x0407AA61u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AA61u: {
    static const uint8_t source_bytes[] = {0x25u, 0x0Cu};
    if (sm_scpu_guard_code(cpu,bus,0x80F54Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a & value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF54Eu;
    if (sm_scpu_context_key(cpu) != 0x0407AA71u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AA71u: {
    static const uint8_t source_bytes[] = {0x91u, 0xF4u};
    if (sm_scpu_guard_code(cpu,bus,0x80F54Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0xF4u);
    uint8_t pointer_low, pointer_high;
    if (sm_scpu_read8(cpu,bus,pointer,&pointer_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(pointer + 1u) & 0xFFFFu,&pointer_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | ((uint32_t)pointer_high << 8) | pointer_low;
    address = (address + cpu->y) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF550u;
    if (sm_scpu_context_key(cpu) != 0x0407AA81u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AA81u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F550u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF551u;
    if (sm_scpu_context_key(cpu) != 0x0407AA89u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AA89u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F551u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF552u;
    if (sm_scpu_context_key(cpu) != 0x0407AA91u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AA91u: {
    static const uint8_t source_bytes[] = {0xC0u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x80F552u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0010u;
    uint16_t result = (cpu->y - value) & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (cpu->y >= value ? SM_P_C : 0u));
    cpu->pc = 0xF554u;
    if (sm_scpu_context_key(cpu) != 0x0407AAA1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AAA1u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xCBu};
    if (sm_scpu_guard_code(cpu,bus,0x80F554u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0xF521u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF556u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407A909u && sm_scpu_context_key(cpu) != 0x0407AAB1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407AAB1u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F556u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407A4C1u && sm_scpu_context_key(cpu) != 0x0407A571u && sm_scpu_context_key(cpu) != 0x0407ACB1u && sm_scpu_context_key(cpu) != 0x0407AD61u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407AAB9u: {
    static const uint8_t source_bytes[] = {0xBDu, 0x3Du, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F557u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((((uint32_t)cpu->dbr << 16) | 0xF63Du) + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF55Au;
    if (sm_scpu_context_key(cpu) != 0x0407AAD1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((0x3Du + cpu->x) > 0xFFu));
}
case 0x0407AAD1u: {
    static const uint8_t source_bytes[] = {0x85u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0x80F55Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF55Cu;
    if (sm_scpu_context_key(cpu) != 0x0407AAE1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AAE1u: {
    static const uint8_t source_bytes[] = {0xBDu, 0x81u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F55Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((((uint32_t)cpu->dbr << 16) | 0xF681u) + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF55Fu;
    if (sm_scpu_context_key(cpu) != 0x0407AAF9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((0x81u + cpu->x) > 0xFFu));
}
case 0x0407AAF9u: {
    static const uint8_t source_bytes[] = {0x85u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x80F55Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF561u;
    if (sm_scpu_context_key(cpu) != 0x0407AB09u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AB09u: {
    static const uint8_t source_bytes[] = {0xBDu, 0x5Fu, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F561u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((((uint32_t)cpu->dbr << 16) | 0xF65Fu) + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF564u;
    if (sm_scpu_context_key(cpu) != 0x0407AB21u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((0x5Fu + cpu->x) > 0xFFu));
}
case 0x0407AB21u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F564u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF566u;
    if (sm_scpu_context_key(cpu) != 0x0407AB31u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AB31u: {
    static const uint8_t source_bytes[] = {0xBDu, 0xA3u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F566u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((((uint32_t)cpu->dbr << 16) | 0xF6A3u) + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF569u;
    if (sm_scpu_context_key(cpu) != 0x0407AB49u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((0xA3u + cpu->x) > 0xFFu));
}
case 0x0407AB49u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Cu};
    if (sm_scpu_guard_code(cpu,bus,0x80F569u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF56Bu;
    if (sm_scpu_context_key(cpu) != 0x0407AB59u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AB59u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F56Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF56Du;
    if (sm_scpu_context_key(cpu) != 0x0407AB69u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AB69u: {
    static const uint8_t source_bytes[] = {0x5Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F56Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF56Eu;
    if (sm_scpu_context_key(cpu) != 0x0407AB71u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AB71u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80F56Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF56Fu;
    if (sm_scpu_context_key(cpu) != 0x0407AB79u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407AB79u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F56Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407A361u && sm_scpu_context_key(cpu) != 0x0407A3D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407ABF9u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x50u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F57Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0150u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF582u;
    if (sm_scpu_context_key(cpu) != 0x0407AC11u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AC11u: {
    static const uint8_t source_bytes[] = {0x85u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F582u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF6u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF584u;
    if (sm_scpu_context_key(cpu) != 0x0407AC21u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AC21u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x60u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F584u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0160u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF587u;
    if (sm_scpu_context_key(cpu) != 0x0407AC39u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AC39u: {
    static const uint8_t source_bytes[] = {0x85u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F587u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF8u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF589u;
    if (sm_scpu_context_key(cpu) != 0x0407AC49u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AC49u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F589u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0100u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF58Cu;
    if (sm_scpu_context_key(cpu) != 0x0407AC61u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AC61u: {
    static const uint8_t source_bytes[] = {0x85u, 0xF2u};
    if (sm_scpu_guard_code(cpu,bus,0x80F58Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF2u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF58Eu;
    if (sm_scpu_context_key(cpu) != 0x0407AC71u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AC71u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x10u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80F58Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0110u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF591u;
    if (sm_scpu_context_key(cpu) != 0x0407AC89u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AC89u: {
    static const uint8_t source_bytes[] = {0x85u, 0xF4u};
    if (sm_scpu_guard_code(cpu,bus,0x80F591u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF4u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF593u;
    if (sm_scpu_context_key(cpu) != 0x0407AC99u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AC99u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Fu, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F593u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF595u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF51Fu;
    if (sm_scpu_context_key(cpu) != 0x0407A8F9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407ACB1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x70u};
    if (sm_scpu_guard_code(cpu,bus,0x80F596u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0070u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF598u;
    if (sm_scpu_context_key(cpu) != 0x0407ACC1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407ACC1u: {
    static const uint8_t source_bytes[] = {0x84u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0x80F598u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF6u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF59Au;
    if (sm_scpu_context_key(cpu) != 0x0407ACD1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407ACD1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F59Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF59Cu;
    if (sm_scpu_context_key(cpu) != 0x0407ACE1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407ACE1u: {
    static const uint8_t source_bytes[] = {0x84u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x80F59Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF8u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF59Eu;
    if (sm_scpu_context_key(cpu) != 0x0407ACF1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407ACF1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80F59Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5A0u;
    if (sm_scpu_context_key(cpu) != 0x0407AD01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AD01u: {
    static const uint8_t source_bytes[] = {0x84u, 0xF2u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF2u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF5A2u;
    if (sm_scpu_context_key(cpu) != 0x0407AD11u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AD11u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0030u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5A4u;
    if (sm_scpu_context_key(cpu) != 0x0407AD21u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AD21u: {
    static const uint8_t source_bytes[] = {0x84u, 0xF4u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xF4u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xF5A6u;
    if (sm_scpu_context_key(cpu) != 0x0407AD31u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0407AD31u: {
    static const uint8_t source_bytes[] = {0x20u, 0x70u, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5A6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF5A8u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF570u;
    if (sm_scpu_context_key(cpu) != 0x0407AB81u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407AD49u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Fu, 0xF5u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5A9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xF5ABu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF51Fu;
    if (sm_scpu_context_key(cpu) != 0x0407A8F9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407AD61u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407A379u && sm_scpu_context_key(cpu) != 0x0407A5B1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407AE89u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5D2u;
    if (sm_scpu_context_key(cpu) != 0x0407AE91u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AE91u: {
    static const uint8_t source_bytes[] = {0x90u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0xF5D7u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF5D4u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407AEA1u && sm_scpu_context_key(cpu) != 0x0407AEB9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407AEA1u: {
    static const uint8_t source_bytes[] = {0x09u, 0x00u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x8000u;
    cpu->a = (uint16_t)(cpu->a | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5D7u;
    if (sm_scpu_context_key(cpu) != 0x0407AEB9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AEB9u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5D7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5D8u;
    if (sm_scpu_context_key(cpu) != 0x0407AEC1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AEC1u: {
    static const uint8_t source_bytes[] = {0x90u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0xF5DDu;
        cycles = 3u;
    } else {
        cpu->pc = 0xF5DAu;
    }
    if (sm_scpu_context_key(cpu) != 0x0407AED1u && sm_scpu_context_key(cpu) != 0x0407AEE9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407AED1u: {
    static const uint8_t source_bytes[] = {0x09u, 0x00u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x8000u;
    cpu->a = (uint16_t)(cpu->a | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5DDu;
    if (sm_scpu_context_key(cpu) != 0x0407AEE9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AEE9u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5DEu;
    if (sm_scpu_context_key(cpu) != 0x0407AEF1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AEF1u: {
    static const uint8_t source_bytes[] = {0x90u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0xF5E3u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF5E0u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407AF01u && sm_scpu_context_key(cpu) != 0x0407AF19u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407AF01u: {
    static const uint8_t source_bytes[] = {0x09u, 0x00u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x8000u;
    cpu->a = (uint16_t)(cpu->a | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5E3u;
    if (sm_scpu_context_key(cpu) != 0x0407AF19u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AF21u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5E4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5E5u;
    if (sm_scpu_context_key(cpu) != 0x0407AF29u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AF29u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5E5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0000u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF5E8u;
    if (sm_scpu_context_key(cpu) != 0x0407AF41u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AF41u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5E9u;
    if (sm_scpu_context_key(cpu) != 0x0407AF49u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AF49u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0000u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF5ECu;
    if (sm_scpu_context_key(cpu) != 0x0407AF61u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AF61u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5EDu;
    if (sm_scpu_context_key(cpu) != 0x0407AF69u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AF69u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5EDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0000u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF5F0u;
    if (sm_scpu_context_key(cpu) != 0x0407AF81u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AF81u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5F1u;
    if (sm_scpu_context_key(cpu) != 0x0407AF89u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AF89u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5F1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0000u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF5F4u;
    if (sm_scpu_context_key(cpu) != 0x0407AFA1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AFA1u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x80F5F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5F5u;
    if (sm_scpu_context_key(cpu) != 0x0407AFA9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AFA9u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407A931u && sm_scpu_context_key(cpu) != 0x0407A981u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407AFB1u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5F7u;
    if (sm_scpu_context_key(cpu) != 0x0407AFB9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AFB9u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5F7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0000u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF5FAu;
    if (sm_scpu_context_key(cpu) != 0x0407AFD1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AFD1u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5FAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5FBu;
    if (sm_scpu_context_key(cpu) != 0x0407AFD9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AFD9u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0000u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF5FEu;
    if (sm_scpu_context_key(cpu) != 0x0407AFF1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AFF1u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F5FEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF5FFu;
    if (sm_scpu_context_key(cpu) != 0x0407AFF9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407AFF9u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5FFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0000u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF602u;
    if (sm_scpu_context_key(cpu) != 0x0407B011u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407B011u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F602u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF603u;
    if (sm_scpu_context_key(cpu) != 0x0407B019u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407B019u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80F603u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0000u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xF606u;
    if (sm_scpu_context_key(cpu) != 0x0407B031u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407B039u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F607u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF608u;
    if (sm_scpu_context_key(cpu) != 0x0407B041u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407B041u: {
    static const uint8_t source_bytes[] = {0x90u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F608u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0xF60Du;
        cycles = 3u;
    } else {
        cpu->pc = 0xF60Au;
    }
    if (sm_scpu_context_key(cpu) != 0x0407B051u && sm_scpu_context_key(cpu) != 0x0407B069u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407B051u: {
    static const uint8_t source_bytes[] = {0x09u, 0x00u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F60Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x8000u;
    cpu->a = (uint16_t)(cpu->a | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF60Du;
    if (sm_scpu_context_key(cpu) != 0x0407B069u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407B069u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F60Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF60Eu;
    if (sm_scpu_context_key(cpu) != 0x0407B071u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407B071u: {
    static const uint8_t source_bytes[] = {0x90u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F60Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0xF613u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF610u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407B081u && sm_scpu_context_key(cpu) != 0x0407B099u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407B081u: {
    static const uint8_t source_bytes[] = {0x09u, 0x00u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F610u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x8000u;
    cpu->a = (uint16_t)(cpu->a | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF613u;
    if (sm_scpu_context_key(cpu) != 0x0407B099u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407B099u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80F613u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF614u;
    if (sm_scpu_context_key(cpu) != 0x0407B0A1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407B0A1u: {
    static const uint8_t source_bytes[] = {0x90u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80F614u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_C) == 0u) {
        cpu->pc = 0xF619u;
        cycles = 3u;
    } else {
        cpu->pc = 0xF616u;
    }
    if (sm_scpu_context_key(cpu) != 0x0407B0B1u && sm_scpu_context_key(cpu) != 0x0407B0C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407B0B1u: {
    static const uint8_t source_bytes[] = {0x09u, 0x00u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80F616u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x8000u;
    cpu->a = (uint16_t)(cpu->a | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF619u;
    if (sm_scpu_context_key(cpu) != 0x0407B0C9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407B0C9u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x80F619u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xF61Au;
    if (sm_scpu_context_key(cpu) != 0x0407B0D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407B0D1u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F61Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407A931u && sm_scpu_context_key(cpu) != 0x0407A981u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407ECC0u: {
    static const uint8_t source_bytes[] = {0x20u, 0x6Eu, 0xF3u};
    if (sm_scpu_guard_code(cpu,bus,0x80FD98u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xFD9Au;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF36Eu;
    if (sm_scpu_context_key(cpu) != 0x04079B70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407ECD8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x80FD9Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xFD9Du;
    if (sm_scpu_context_key(cpu) != 0x0407ECE9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407ECE9u: {
    static const uint8_t source_bytes[] = {0x20u, 0x00u, 0xF4u};
    if (sm_scpu_guard_code(cpu,bus,0x80FD9Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xFD9Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF400u;
    if (sm_scpu_context_key(cpu) != 0x0407A001u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407ED01u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDA0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xFDA2u;
    if (sm_scpu_context_key(cpu) != 0x0407ED10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407ED10u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDA2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0405C428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407ED19u: {
    static const uint8_t source_bytes[] = {0xDAu};
    if (sm_scpu_guard_code(cpu,bus,0x80FDA3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFDA4u;
    if (sm_scpu_context_key(cpu) != 0x0407ED21u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407ED21u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDA4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFDA5u;
    if (sm_scpu_context_key(cpu) != 0x0407ED29u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407ED29u: {
    static const uint8_t source_bytes[] = {0xADu, 0x90u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDA5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0190u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDA8u;
    if (sm_scpu_context_key(cpu) != 0x0407ED41u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407ED41u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80FDA8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDA9u;
    if (sm_scpu_context_key(cpu) != 0x0407ED49u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407ED49u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80FDA9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = (uint16_t)(value << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDAAu;
    if (sm_scpu_context_key(cpu) != 0x0407ED51u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407ED51u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x80FDAAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDABu;
    if (sm_scpu_context_key(cpu) != 0x0407ED59u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407ED59u: {
    static const uint8_t source_bytes[] = {0xA3u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->s + 0x01u);
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDADu;
    if (sm_scpu_context_key(cpu) != 0x0407ED69u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407ED69u: {
    static const uint8_t source_bytes[] = {0x9Fu, 0x92u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x000192u + cpu->x) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDB1u;
    if (sm_scpu_context_key(cpu) != 0x0407ED89u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407ED89u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDB1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDB2u;
    if (sm_scpu_context_key(cpu) != 0x0407ED91u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407ED91u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDB2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDB3u;
    if (sm_scpu_context_key(cpu) != 0x0407ED99u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407ED99u: {
    static const uint8_t source_bytes[] = {0xADu, 0xB8u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80FDB3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FB8u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDB6u;
    if (sm_scpu_context_key(cpu) != 0x0407EDB1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407EDB1u: {
    static const uint8_t source_bytes[] = {0x9Fu, 0x92u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDB6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x000192u + cpu->x) & 0xFFFFFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDBAu;
    if (sm_scpu_context_key(cpu) != 0x0407EDD1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407EDD1u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDBAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDBBu;
    if (sm_scpu_context_key(cpu) != 0x0407EDD9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EDD9u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDBBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDBCu;
    if (sm_scpu_context_key(cpu) != 0x0407EDE1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EDE1u: {
    static const uint8_t source_bytes[] = {0x8Au};
    if (sm_scpu_guard_code(cpu,bus,0x80FDBCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = cpu->x;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDBDu;
    if (sm_scpu_context_key(cpu) != 0x0407EDE9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EDE9u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80FDBDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDBEu;
    if (sm_scpu_context_key(cpu) != 0x0407EDF1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EDF1u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80FDBEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a;
    uint16_t result = value >> 1u;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((value & 1u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDBFu;
    if (sm_scpu_context_key(cpu) != 0x0407EDF9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EDF9u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x90u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDBFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0190u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDC2u;
    if (sm_scpu_context_key(cpu) != 0x0407EE11u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407EE11u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDC2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDC3u;
    if (sm_scpu_context_key(cpu) != 0x0407EE19u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407EE19u: {
    static const uint8_t source_bytes[] = {0xFAu};
    if (sm_scpu_guard_code(cpu,bus,0x80FDC3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = low;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDC4u;
    if (sm_scpu_context_key(cpu) != 0x0407EE21u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407EE21u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDC4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407A5E1u && sm_scpu_context_key(cpu) != 0x0407A849u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407EE29u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDC5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFDC6u;
    if (sm_scpu_context_key(cpu) != 0x0407EE31u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407EE31u: {
    static const uint8_t source_bytes[] = {0xDAu};
    if (sm_scpu_guard_code(cpu,bus,0x80FDC6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFDC7u;
    if (sm_scpu_context_key(cpu) != 0x0407EE39u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407EE39u: {
    static const uint8_t source_bytes[] = {0x5Au};
    if (sm_scpu_guard_code(cpu,bus,0x80FDC7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xFDC8u;
    if (sm_scpu_context_key(cpu) != 0x0407EE41u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407EE41u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDC8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->x = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDCAu;
    if (sm_scpu_context_key(cpu) != 0x0407EE51u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EE51u: {
    static const uint8_t source_bytes[] = {0xBFu, 0x92u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDCAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x000192u + cpu->x) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDCEu;
    if (sm_scpu_context_key(cpu) != 0x0407EE71u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407EE71u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDCEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4302u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDD1u;
    if (sm_scpu_context_key(cpu) != 0x0407EE89u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407EE89u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDD1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDD3u;
    if (sm_scpu_context_key(cpu) != 0x0407EE99u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EE99u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x00u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDD3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4300u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDD6u;
    if (sm_scpu_context_key(cpu) != 0x0407EEB1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407EEB1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDD6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0018u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDD8u;
    if (sm_scpu_context_key(cpu) != 0x0407EEC1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EEC1u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x01u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDD8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4301u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDDBu;
    if (sm_scpu_context_key(cpu) != 0x0407EED9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407EED9u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDDBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDDDu;
    if (sm_scpu_context_key(cpu) != 0x0407EEE9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EEE9u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x04u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDDDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4304u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDE0u;
    if (sm_scpu_context_key(cpu) != 0x0407EF01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407EF01u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDE0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDE1u;
    if (sm_scpu_context_key(cpu) != 0x0407EF09u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EF09u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDE1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDE2u;
    if (sm_scpu_context_key(cpu) != 0x0407EF11u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EF11u: {
    static const uint8_t source_bytes[] = {0xBFu, 0x92u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDE2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x000192u + cpu->x) & 0xFFFFFFu;
    uint8_t data_low, data_high;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDE6u;
    if (sm_scpu_context_key(cpu) != 0x0407EF31u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407EF31u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x16u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDE6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2116u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDE9u;
    if (sm_scpu_context_key(cpu) != 0x0407EF49u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407EF49u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x40u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDE9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0040u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDECu;
    if (sm_scpu_context_key(cpu) != 0x0407EF61u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407EF61u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4305u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDEFu;
    if (sm_scpu_context_key(cpu) != 0x0407EF79u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407EF79u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDEFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDF1u;
    if (sm_scpu_context_key(cpu) != 0x0407EF89u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EF89u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x0Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDF1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDF4u;
    if (sm_scpu_context_key(cpu) != 0x0407EFA1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407EFA1u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDF4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDF5u;
    if (sm_scpu_context_key(cpu) != 0x0407EFA9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EFA9u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDF5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint8_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDF6u;
    if (sm_scpu_context_key(cpu) != 0x0407EFB1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EFB1u: {
    static const uint8_t source_bytes[] = {0xADu, 0x90u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDF6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0190u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDF9u;
    if (sm_scpu_context_key(cpu) != 0x0407EFC9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407EFC9u: {
    static const uint8_t source_bytes[] = {0x3Au};
    if (sm_scpu_guard_code(cpu,bus,0x80FDF9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFDFAu;
    if (sm_scpu_context_key(cpu) != 0x0407EFD1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0407EFD1u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x90u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80FDFAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0190u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFDFDu;
    if (sm_scpu_context_key(cpu) != 0x0407EFE9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407EFE9u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xCBu};
    if (sm_scpu_guard_code(cpu,bus,0x80FDFDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0xFDCAu;
        cycles = 3u;
    } else {
        cpu->pc = 0xFDFFu;
    }
    if (sm_scpu_context_key(cpu) != 0x0407EE51u && sm_scpu_context_key(cpu) != 0x0407EFF9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0407EFF9u: {
    static const uint8_t source_bytes[] = {0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x80FDFFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = low;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFE00u;
    if (sm_scpu_context_key(cpu) != 0x0407F001u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407F001u: {
    static const uint8_t source_bytes[] = {0xFAu};
    if (sm_scpu_guard_code(cpu,bus,0x80FE00u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = low;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFE01u;
    if (sm_scpu_context_key(cpu) != 0x0407F009u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0407F009u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0x80FE01u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xFE02u;
    if (sm_scpu_context_key(cpu) != 0x0407F011u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407F011u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0xB0u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80FE02u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FB0u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFE05u;
    if (sm_scpu_context_key(cpu) != 0x0407F029u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0407F029u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80FE05u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0405DD01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
