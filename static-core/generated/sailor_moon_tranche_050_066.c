#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_tranche_050_066(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x0007FD30u: {
    static const uint8_t source_bytes[] = {0x80u, 0xFEu};
    if (sm_scpu_guard_code(cpu,bus,0x00FFA6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xFFA6u;
    if (sm_scpu_context_key(cpu) != 0x0007FD30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405C898u: {
    static const uint8_t source_bytes[] = {0x80u, 0xFEu};
    if (sm_scpu_guard_code(cpu,bus,0x80B913u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB913u;
    if (sm_scpu_context_key(cpu) != 0x0405C898u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405E558u: {
    static const uint8_t source_bytes[] = {0x80u, 0xFEu};
    if (sm_scpu_guard_code(cpu,bus,0x80BCABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBCABu;
    if (sm_scpu_context_key(cpu) != 0x0405E558u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405E570u: {
    static const uint8_t source_bytes[] = {0x80u, 0xFEu};
    if (sm_scpu_guard_code(cpu,bus,0x80BCAEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBCAEu;
    if (sm_scpu_context_key(cpu) != 0x0405E570u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040E4E58u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9CBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xC9CCu;
    if (sm_scpu_context_key(cpu) != 0x040E4E60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040E4E60u: {
    static const uint8_t source_bytes[] = {0x69u, 0xFEu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9CCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0xFFFEu;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xC9CFu;
    if (sm_scpu_context_key(cpu) != 0x040E4E78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040E4E78u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9CFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xC9D0u;
    if (sm_scpu_context_key(cpu) != 0x040E4E80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040E4E80u: {
    static const uint8_t source_bytes[] = {0x65u, 0x9Cu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9D0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x9Cu);
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
    cpu->pc = 0xC9D2u;
    if (sm_scpu_context_key(cpu) != 0x040E4E90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040E4E90u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040E4AE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040E4E98u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9D3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9D6u;
    if (sm_scpu_context_key(cpu) != 0x040E4EB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040E4EB0u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9D6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xC9D7u;
    if (sm_scpu_context_key(cpu) != 0x040E4EB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040E4EB8u: {
    static const uint8_t source_bytes[] = {0x69u, 0xFFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9D7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0xFFFFu;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xC9DAu;
    if (sm_scpu_context_key(cpu) != 0x040E4ED0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040E4ED0u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xC9DBu;
    if (sm_scpu_context_key(cpu) != 0x040E4ED8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040E4ED8u: {
    static const uint8_t source_bytes[] = {0x65u, 0x9Cu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x9Cu);
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
    cpu->pc = 0xC9DDu;
    if (sm_scpu_context_key(cpu) != 0x040E4EE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040E4EE8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040E4B20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040E4EF0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x33u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x3300u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9E1u;
    if (sm_scpu_context_key(cpu) != 0x040E4F08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040E4F08u: {
    static const uint8_t source_bytes[] = {0x85u, 0xA2u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xA2u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC9E3u;
    if (sm_scpu_context_key(cpu) != 0x040E4F18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040E4F18u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9E6u;
    if (sm_scpu_context_key(cpu) != 0x040E4F30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040E4F30u: {
    static const uint8_t source_bytes[] = {0x85u, 0xA4u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9E6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xA4u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC9E8u;
    if (sm_scpu_context_key(cpu) != 0x040E4F40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040E4F40u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040E4500u && sm_scpu_context_key(cpu) != 0x040E4A10u && sm_scpu_context_key(cpu) != 0x040E4C10u && sm_scpu_context_key(cpu) != 0x040E4F78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04176270u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82EC4Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xEC50u;
    if (sm_scpu_context_key(cpu) != 0x04176280u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176280u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82EC50u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xEC52u;
    if (sm_scpu_context_key(cpu) != 0x04176290u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176290u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82EC52u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x14u);
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
    cpu->pc = 0xEC54u;
    if (sm_scpu_context_key(cpu) != 0x041762A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041762A0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82EC54u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04175FC8u && sm_scpu_context_key(cpu) != 0x04176008u && sm_scpu_context_key(cpu) != 0x04176038u && sm_scpu_context_key(cpu) != 0x04176068u && sm_scpu_context_key(cpu) != 0x04176098u && sm_scpu_context_key(cpu) != 0x041760C8u && sm_scpu_context_key(cpu) != 0x041760F8u && sm_scpu_context_key(cpu) != 0x04176128u && sm_scpu_context_key(cpu) != 0x04176158u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041C9338u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839267u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x926Au;
    if (sm_scpu_context_key(cpu) != 0x041C9350u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C9350u: {
    static const uint8_t source_bytes[] = {0x85u, 0x16u};
    if (sm_scpu_guard_code(cpu,bus,0x83926Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x16u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x926Cu;
    if (sm_scpu_context_key(cpu) != 0x041C9360u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C9360u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x60u, 0xE9u};
    if (sm_scpu_guard_code(cpu,bus,0x83926Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xE960u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x926Fu;
    if (sm_scpu_context_key(cpu) != 0x041C9378u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C9378u: {
    static const uint8_t source_bytes[] = {0x85u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x83926Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9271u;
    if (sm_scpu_context_key(cpu) != 0x041C9388u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C9388u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x87u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839271u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0087u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9274u;
    if (sm_scpu_context_key(cpu) != 0x041C93A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C93A0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x839274u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x12u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9276u;
    if (sm_scpu_context_key(cpu) != 0x041C93B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C93B0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839276u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9279u;
    if (sm_scpu_context_key(cpu) != 0x041C93C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C93C8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x839279u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x927Bu;
    if (sm_scpu_context_key(cpu) != 0x041C93D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C93D8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x16u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83927Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0016u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x927Eu;
    if (sm_scpu_context_key(cpu) != 0x041C93F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C93F0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x83927Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9280u;
    if (sm_scpu_context_key(cpu) != 0x041C9400u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C9400u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x3Cu};
    if (sm_scpu_guard_code(cpu,bus,0x839280u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x3C00u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9283u;
    if (sm_scpu_context_key(cpu) != 0x041C9418u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C9418u: {
    static const uint8_t source_bytes[] = {0x85u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0x839283u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9285u;
    if (sm_scpu_context_key(cpu) != 0x041C9428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C9428u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x03u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839285u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0003u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9288u;
    if (sm_scpu_context_key(cpu) != 0x041C9440u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C9440u: {
    static const uint8_t source_bytes[] = {0x85u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x839288u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x928Au;
    if (sm_scpu_context_key(cpu) != 0x041C9450u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C9450u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83928Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041C9160u && sm_scpu_context_key(cpu) != 0x041C91B8u && sm_scpu_context_key(cpu) != 0x041C9210u && sm_scpu_context_key(cpu) != 0x041C9268u && sm_scpu_context_key(cpu) != 0x041C92C0u && sm_scpu_context_key(cpu) != 0x041C9318u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041CBBE8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x0Eu, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x83977Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x5E0Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9780u;
    if (sm_scpu_context_key(cpu) != 0x041CBC00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CBC00u: {
    static const uint8_t source_bytes[] = {0x85u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x839780u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9782u;
    if (sm_scpu_context_key(cpu) != 0x041CBC10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CBC10u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839782u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9785u;
    if (sm_scpu_context_key(cpu) != 0x041CBC28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CBC28u: {
    static const uint8_t source_bytes[] = {0x85u, 0x16u};
    if (sm_scpu_guard_code(cpu,bus,0x839785u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x16u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9787u;
    if (sm_scpu_context_key(cpu) != 0x041CBC38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CBC38u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x839787u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041CBB20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041CBC40u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x0Eu, 0x66u};
    if (sm_scpu_guard_code(cpu,bus,0x839788u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x660Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x978Bu;
    if (sm_scpu_context_key(cpu) != 0x041CBC58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CBC58u: {
    static const uint8_t source_bytes[] = {0x85u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x83978Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x978Du;
    if (sm_scpu_context_key(cpu) != 0x041CBC68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CBC68u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x83978Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9790u;
    if (sm_scpu_context_key(cpu) != 0x041CBC80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CBC80u: {
    static const uint8_t source_bytes[] = {0x85u, 0x16u};
    if (sm_scpu_guard_code(cpu,bus,0x839790u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x16u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9792u;
    if (sm_scpu_context_key(cpu) != 0x041CBC90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CBC90u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x839792u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041CBBB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041CBC98u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x0Eu, 0x6Eu};
    if (sm_scpu_guard_code(cpu,bus,0x839793u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x6E0Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9796u;
    if (sm_scpu_context_key(cpu) != 0x041CBCB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CBCB0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x839796u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9798u;
    if (sm_scpu_context_key(cpu) != 0x041CBCC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CBCC0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x839798u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x979Bu;
    if (sm_scpu_context_key(cpu) != 0x041CBCD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CBCD8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x16u};
    if (sm_scpu_guard_code(cpu,bus,0x83979Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x16u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x979Du;
    if (sm_scpu_context_key(cpu) != 0x041CBCE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CBCE8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83979Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041CBB68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E0748u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x87C0E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC0EBu;
    if (sm_scpu_context_key(cpu) != 0x043E075Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E075Au: {
    static const uint8_t source_bytes[] = {0x9Cu, 0xE6u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x87C0EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0FE6u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC0EEu;
    if (sm_scpu_context_key(cpu) != 0x043E0772u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x043E0772u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x40u};
    if (sm_scpu_guard_code(cpu,bus,0x87C0EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0040u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC0F0u;
    if (sm_scpu_context_key(cpu) != 0x043E0782u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E0782u: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x87C0F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC0F2u;
    if (sm_scpu_context_key(cpu) != 0x043E0792u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E0792u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x87C0F2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC0F4u;
    if (sm_scpu_context_key(cpu) != 0x043E07A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x043E07A2u: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Bu};
    if (sm_scpu_guard_code(cpu,bus,0x87C0F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC0F6u;
    if (sm_scpu_context_key(cpu) != 0x043E07B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E07B2u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x87C0F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC0F8u;
    if (sm_scpu_context_key(cpu) != 0x043E07C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E07C0u: {
    static const uint8_t source_bytes[] = {0x64u, 0x94u};
    if (sm_scpu_guard_code(cpu,bus,0x87C0F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x94u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC0FAu;
    if (sm_scpu_context_key(cpu) != 0x043E07D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E07D0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C0FAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043D8DD0u && sm_scpu_context_key(cpu) != 0x043D9588u && sm_scpu_context_key(cpu) != 0x043D9DC8u && sm_scpu_context_key(cpu) != 0x043DA618u && sm_scpu_context_key(cpu) != 0x043E2108u && sm_scpu_context_key(cpu) != 0x043E2648u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x05363348u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C669u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC66Bu;
    if (sm_scpu_context_key(cpu) != 0x0536335Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0536335Au: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x84u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xA6C66Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0D84u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC66Eu;
    if (sm_scpu_context_key(cpu) != 0x05363372u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05363372u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C66Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC670u;
    if (sm_scpu_context_key(cpu) != 0x05363380u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05363380u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C670u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0534A348u && sm_scpu_context_key(cpu) != 0x0534C1A8u && sm_scpu_context_key(cpu) != 0x0534C660u && sm_scpu_context_key(cpu) != 0x0534CA90u && sm_scpu_context_key(cpu) != 0x0534CF08u && sm_scpu_context_key(cpu) != 0x0534D508u && sm_scpu_context_key(cpu) != 0x0534DB60u && sm_scpu_context_key(cpu) != 0x0534DFF8u && sm_scpu_context_key(cpu) != 0x0534E6A8u && sm_scpu_context_key(cpu) != 0x0534E868u && sm_scpu_context_key(cpu) != 0x0534EC08u && sm_scpu_context_key(cpu) != 0x0534EE90u && sm_scpu_context_key(cpu) != 0x0534F6C8u && sm_scpu_context_key(cpu) != 0x0534F978u && sm_scpu_context_key(cpu) != 0x0534FFF0u && sm_scpu_context_key(cpu) != 0x05350A58u && sm_scpu_context_key(cpu) != 0x05351240u && sm_scpu_context_key(cpu) != 0x05351498u && sm_scpu_context_key(cpu) != 0x05351950u && sm_scpu_context_key(cpu) != 0x05351D80u && sm_scpu_context_key(cpu) != 0x05352258u && sm_scpu_context_key(cpu) != 0x053524B0u && sm_scpu_context_key(cpu) != 0x05352940u && sm_scpu_context_key(cpu) != 0x05352CF0u && sm_scpu_context_key(cpu) != 0x05353368u && sm_scpu_context_key(cpu) != 0x053535C0u && sm_scpu_context_key(cpu) != 0x05353A50u && sm_scpu_context_key(cpu) != 0x05353E00u && sm_scpu_context_key(cpu) != 0x053542B8u && sm_scpu_context_key(cpu) != 0x053546E8u && sm_scpu_context_key(cpu) != 0x05354BC0u && sm_scpu_context_key(cpu) != 0x05354E18u && sm_scpu_context_key(cpu) != 0x05355758u && sm_scpu_context_key(cpu) != 0x053559B0u && sm_scpu_context_key(cpu) != 0x05356240u && sm_scpu_context_key(cpu) != 0x05356498u && sm_scpu_context_key(cpu) != 0x05356D28u && sm_scpu_context_key(cpu) != 0x05356F80u && sm_scpu_context_key(cpu) != 0x053575F8u && sm_scpu_context_key(cpu) != 0x05357850u && sm_scpu_context_key(cpu) != 0x05357CB8u && sm_scpu_context_key(cpu) != 0x05357F10u && sm_scpu_context_key(cpu) != 0x05358530u && sm_scpu_context_key(cpu) != 0x05358868u && sm_scpu_context_key(cpu) != 0x05359330u && sm_scpu_context_key(cpu) != 0x05359588u && sm_scpu_context_key(cpu) != 0x05359A40u && sm_scpu_context_key(cpu) != 0x05359E70u && sm_scpu_context_key(cpu) != 0x0535A348u && sm_scpu_context_key(cpu) != 0x0535A918u && sm_scpu_context_key(cpu) != 0x0535AFA0u && sm_scpu_context_key(cpu) != 0x0535B1F8u && sm_scpu_context_key(cpu) != 0x0535BA10u && sm_scpu_context_key(cpu) != 0x0535BC68u && sm_scpu_context_key(cpu) != 0x0535C120u && sm_scpu_context_key(cpu) != 0x0535C550u && sm_scpu_context_key(cpu) != 0x0535CA28u && sm_scpu_context_key(cpu) != 0x0535CC80u && sm_scpu_context_key(cpu) != 0x0535D138u && sm_scpu_context_key(cpu) != 0x0535D568u && sm_scpu_context_key(cpu) != 0x0535DA40u && sm_scpu_context_key(cpu) != 0x0535DC98u && sm_scpu_context_key(cpu) != 0x0535E450u && sm_scpu_context_key(cpu) != 0x0535EE38u && sm_scpu_context_key(cpu) != 0x0535FE80u && sm_scpu_context_key(cpu) != 0x05360358u && sm_scpu_context_key(cpu) != 0x05360788u && sm_scpu_context_key(cpu) != 0x05360F18u && sm_scpu_context_key(cpu) != 0x053630A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0290Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x1Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0521u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Bu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0523u;
    if (sm_scpu_context_key(cpu) != 0x06F0291Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0291Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0523u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x21u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0525u;
    if (sm_scpu_context_key(cpu) != 0x06F02928u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02928u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0525u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0528u;
    if (sm_scpu_context_key(cpu) != 0x06F02940u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02940u: {
    static const uint8_t source_bytes[] = {0x69u, 0x08u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0528u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0008u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x052Bu;
    if (sm_scpu_context_key(cpu) != 0x06F02958u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02958u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x17u};
    if (sm_scpu_guard_code(cpu,bus,0xDE052Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x17u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x052Du;
    if (sm_scpu_context_key(cpu) != 0x06F02968u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02968u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Au, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE052Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x052Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x071Au;
    if (sm_scpu_context_key(cpu) != 0x06F038D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02980u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0530u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0532u;
    if (sm_scpu_context_key(cpu) != 0x06F02992u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02992u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0532u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00DA2u && sm_scpu_context_key(cpu) != 0x06F00EBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0299Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0533u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0534u;
    if (sm_scpu_context_key(cpu) != 0x06F029A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F029A2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x1Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0534u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Cu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0536u;
    if (sm_scpu_context_key(cpu) != 0x06F029B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F029B2u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0536u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0538u;
    if (sm_scpu_context_key(cpu) != 0x06F029C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F029C2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0538u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x053Au;
    if (sm_scpu_context_key(cpu) != 0x06F029D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F029D2u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE053Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x053Bu;
    if (sm_scpu_context_key(cpu) != 0x06F029DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F029DAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE053Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x053Du;
    if (sm_scpu_context_key(cpu) != 0x06F029EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F029EAu: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE053Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x053Eu;
    if (sm_scpu_context_key(cpu) != 0x06F029F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F029F2u: {
    static const uint8_t source_bytes[] = {0xBFu, 0xD6u, 0x29u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE053Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE29D6u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0542u;
    if (sm_scpu_context_key(cpu) != 0x06F02A12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F02A12u: {
    static const uint8_t source_bytes[] = {0xC5u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0542u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x19u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0544u;
    if (sm_scpu_context_key(cpu) != 0x06F02A22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02A22u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0544u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x054Au;
        cycles = 3u;
    } else {
        cpu->pc = 0x0546u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F02A32u && sm_scpu_context_key(cpu) != 0x06F02A52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F02A32u: {
    static const uint8_t source_bytes[] = {0x85u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0546u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x19u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0548u;
    if (sm_scpu_context_key(cpu) != 0x06F02A42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02A42u: {
    static const uint8_t source_bytes[] = {0x80u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0548u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0559u;
    if (sm_scpu_context_key(cpu) != 0x06F02ACAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02A52u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE054Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x054Cu;
    if (sm_scpu_context_key(cpu) != 0x06F02A62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02A62u: {
    static const uint8_t source_bytes[] = {0xC9u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE054Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FFu;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x054Eu;
    if (sm_scpu_context_key(cpu) != 0x06F02A72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02A72u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x09u};
    if (sm_scpu_guard_code(cpu,bus,0xDE054Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x0559u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0550u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F02A82u && sm_scpu_context_key(cpu) != 0x06F02ACAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F02A82u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0550u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0552u;
    if (sm_scpu_context_key(cpu) != 0x06F02A90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02A90u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0552u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0555u;
    if (sm_scpu_context_key(cpu) != 0x06F02AA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02AA8u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0555u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0556u;
    if (sm_scpu_context_key(cpu) != 0x06F02AB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02AB0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0556u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0557u;
    if (sm_scpu_context_key(cpu) != 0x06F02AB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02AB8u: {
    static const uint8_t source_bytes[] = {0x80u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0557u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x055Eu;
    if (sm_scpu_context_key(cpu) != 0x06F02AF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02ACAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0559u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x055Bu;
    if (sm_scpu_context_key(cpu) != 0x06F02AD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02AD8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE055Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x055Eu;
    if (sm_scpu_context_key(cpu) != 0x06F02AF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02AF0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE055Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0560u;
    if (sm_scpu_context_key(cpu) != 0x06F02B00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02B00u: {
    static const uint8_t source_bytes[] = {0x8Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0560u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = cpu->x;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0561u;
    if (sm_scpu_context_key(cpu) != 0x06F02B08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02B08u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0561u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0562u;
    if (sm_scpu_context_key(cpu) != 0x06F02B10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02B10u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0562u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0563u;
    if (sm_scpu_context_key(cpu) != 0x06F02B18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02B18u: {
    static const uint8_t source_bytes[] = {0x85u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0563u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0565u;
    if (sm_scpu_context_key(cpu) != 0x06F02B28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02B28u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0565u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x18u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0567u;
    if (sm_scpu_context_key(cpu) != 0x06F02B38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02B38u: {
    static const uint8_t source_bytes[] = {0x29u, 0x00u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0567u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFF00u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x056Au;
    if (sm_scpu_context_key(cpu) != 0x06F02B50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02B50u: {
    static const uint8_t source_bytes[] = {0x69u, 0x00u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE056Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0200u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x056Du;
    if (sm_scpu_context_key(cpu) != 0x06F02B68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02B68u: {
    static const uint8_t source_bytes[] = {0x85u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE056Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x056Fu;
    if (sm_scpu_context_key(cpu) != 0x06F02B78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02B78u: {
    static const uint8_t source_bytes[] = {0x64u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE056Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0571u;
    if (sm_scpu_context_key(cpu) != 0x06F02B88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02B88u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0571u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0573u;
    if (sm_scpu_context_key(cpu) != 0x06F02B9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02B9Au: {
    static const uint8_t source_bytes[] = {0xA6u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0573u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0575u;
    if (sm_scpu_context_key(cpu) != 0x06F02BAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02BAAu: {
    static const uint8_t source_bytes[] = {0xBFu, 0xB0u, 0x1Au, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0575u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE1AB0u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0579u;
    if (sm_scpu_context_key(cpu) != 0x06F02BCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F02BCAu: {
    static const uint8_t source_bytes[] = {0xC9u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0579u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FFu;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x057Bu;
    if (sm_scpu_context_key(cpu) != 0x06F02BDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02BDAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0xDE057Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0596u;
        cycles = 3u;
    } else {
        cpu->pc = 0x057Du;
    }
    if (sm_scpu_context_key(cpu) != 0x06F02BEAu && sm_scpu_context_key(cpu) != 0x06F02CB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F02BEAu: {
    static const uint8_t source_bytes[] = {0xA6u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE057Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x057Fu;
    if (sm_scpu_context_key(cpu) != 0x06F02BFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02BFAu: {
    static const uint8_t source_bytes[] = {0x30u, 0x0Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE057Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_N) != 0u) {
        cpu->pc = 0x058Cu;
        cycles = 3u;
    } else {
        cpu->pc = 0x0581u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F02C0Au && sm_scpu_context_key(cpu) != 0x06F02C62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F02C0Au: {
    static const uint8_t source_bytes[] = {0xDFu, 0xB0u, 0x1Au, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0581u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE1AB0u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0585u;
    if (sm_scpu_context_key(cpu) != 0x06F02C2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F02C2Au: {
    static const uint8_t source_bytes[] = {0xF0u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0585u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x0591u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0587u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F02C3Au && sm_scpu_context_key(cpu) != 0x06F02C8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F02C3Au: {
    static const uint8_t source_bytes[] = {0xA2u, 0xFFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0587u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFFu;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x058Au;
    if (sm_scpu_context_key(cpu) != 0x06F02C52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02C52u: {
    static const uint8_t source_bytes[] = {0x86u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE058Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x058Cu;
    if (sm_scpu_context_key(cpu) != 0x06F02C62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02C62u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE058Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x058Eu;
    if (sm_scpu_context_key(cpu) != 0x06F02C70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02C70u: {
    static const uint8_t source_bytes[] = {0x82u, 0xCCu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE058Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x065Du;
    if (sm_scpu_context_key(cpu) != 0x06F032E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02C8Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0591u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0593u;
    if (sm_scpu_context_key(cpu) != 0x06F02C98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02C98u: {
    static const uint8_t source_bytes[] = {0x82u, 0xC5u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0593u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x065Bu;
    if (sm_scpu_context_key(cpu) != 0x06F032D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02CB2u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0596u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0598u;
    if (sm_scpu_context_key(cpu) != 0x06F02CC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02CC0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0598u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x059Bu;
    if (sm_scpu_context_key(cpu) != 0x06F02CD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02CD8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE059Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x059Du;
    if (sm_scpu_context_key(cpu) != 0x06F02CE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02CE8u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE059Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x059Eu;
    if (sm_scpu_context_key(cpu) != 0x06F02CF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02CF0u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE059Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x059Fu;
    if (sm_scpu_context_key(cpu) != 0x06F02CF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02CF8u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE059Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05A0u;
    if (sm_scpu_context_key(cpu) != 0x06F02D00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02D00u: {
    static const uint8_t source_bytes[] = {0x65u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x05A2u;
    if (sm_scpu_context_key(cpu) != 0x06F02D10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02D10u: {
    static const uint8_t source_bytes[] = {0x6Fu, 0x02u, 0x00u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE05A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x05A6u;
    if (sm_scpu_context_key(cpu) != 0x06F02D30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02D30u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05A6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x05A8u;
    if (sm_scpu_context_key(cpu) != 0x06F02D40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02D40u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x05AAu;
    if (sm_scpu_context_key(cpu) != 0x06F02D52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02D52u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE05AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00DEu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05ACu;
    if (sm_scpu_context_key(cpu) != 0x06F02D62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02D62u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE05ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x05AEu;
    if (sm_scpu_context_key(cpu) != 0x06F02D72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02D72u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x05B0u;
    if (sm_scpu_context_key(cpu) != 0x06F02D80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02D80u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x07u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05B0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0007u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05B3u;
    if (sm_scpu_context_key(cpu) != 0x06F02D98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02D98u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05B3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x05B5u;
    if (sm_scpu_context_key(cpu) != 0x06F02DA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02DA8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05B5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x05B7u;
    if (sm_scpu_context_key(cpu) != 0x06F02DB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02DB8u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05B8u;
    if (sm_scpu_context_key(cpu) != 0x06F02DC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02DC0u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05B8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05B9u;
    if (sm_scpu_context_key(cpu) != 0x06F02DC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02DC8u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05BAu;
    if (sm_scpu_context_key(cpu) != 0x06F02DD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02DD0u: {
    static const uint8_t source_bytes[] = {0x65u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
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
    cpu->pc = 0x05BCu;
    if (sm_scpu_context_key(cpu) != 0x06F02DE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02DE0u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05BDu;
    if (sm_scpu_context_key(cpu) != 0x06F02DE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02DE8u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05BDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05BEu;
    if (sm_scpu_context_key(cpu) != 0x06F02DF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02DF0u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x05BFu;
    if (sm_scpu_context_key(cpu) != 0x06F02DF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02DF8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x05C1u;
    if (sm_scpu_context_key(cpu) != 0x06F02E0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02E0Au: {
    static const uint8_t source_bytes[] = {0xA6u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05C1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05C3u;
    if (sm_scpu_context_key(cpu) != 0x06F02E1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02E1Au: {
    static const uint8_t source_bytes[] = {0xBFu, 0xB0u, 0x1Au, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE05C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE1AB0u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05C7u;
    if (sm_scpu_context_key(cpu) != 0x06F02E3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F02E3Au: {
    static const uint8_t source_bytes[] = {0xA6u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05C7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05C9u;
    if (sm_scpu_context_key(cpu) != 0x06F02E4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02E4Au: {
    static const uint8_t source_bytes[] = {0x30u, 0x15u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_N) != 0u) {
        cpu->pc = 0x05E0u;
        cycles = 3u;
    } else {
        cpu->pc = 0x05CBu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F02E5Au && sm_scpu_context_key(cpu) != 0x06F02F02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F02E5Au: {
    static const uint8_t source_bytes[] = {0xDFu, 0xB0u, 0x1Au, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE05CBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE1AB0u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((result & 0xFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x05CFu;
    if (sm_scpu_context_key(cpu) != 0x06F02E7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F02E7Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05CFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x05DBu;
        cycles = 3u;
    } else {
        cpu->pc = 0x05D1u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F02E8Au && sm_scpu_context_key(cpu) != 0x06F02EDAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F02E8Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x21u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x05D3u;
    if (sm_scpu_context_key(cpu) != 0x06F02E98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02E98u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05D3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05D4u;
    if (sm_scpu_context_key(cpu) != 0x06F02EA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F02EA0u: {
    static const uint8_t source_bytes[] = {0x65u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
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
    cpu->pc = 0x05D6u;
    if (sm_scpu_context_key(cpu) != 0x06F02EB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02EB0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05D6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x05D8u;
    if (sm_scpu_context_key(cpu) != 0x06F02EC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02EC0u: {
    static const uint8_t source_bytes[] = {0x82u, 0x80u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x065Bu;
    if (sm_scpu_context_key(cpu) != 0x06F032D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02EDAu: {
    static const uint8_t source_bytes[] = {0xA2u, 0xFFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE05DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFFu;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05DEu;
    if (sm_scpu_context_key(cpu) != 0x06F02EF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02EF2u: {
    static const uint8_t source_bytes[] = {0x86u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x05E0u;
    if (sm_scpu_context_key(cpu) != 0x06F02F02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02F02u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x05E2u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02F1Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x05E5u;
    if (sm_scpu_context_key(cpu) != 0x06F02F28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02F28u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05E5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05E7u;
    if (sm_scpu_context_key(cpu) != 0x06F02F38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02F38u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05E7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05E8u;
    if (sm_scpu_context_key(cpu) != 0x06F02F40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02F40u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05E9u;
    if (sm_scpu_context_key(cpu) != 0x06F02F48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02F48u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x05EAu;
    if (sm_scpu_context_key(cpu) != 0x06F02F50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02F50u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x05ECu;
    if (sm_scpu_context_key(cpu) != 0x06F02F62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02F62u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x05EFu;
    if (sm_scpu_context_key(cpu) != 0x06F02F7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02F7Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE05EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05F0u;
    if (sm_scpu_context_key(cpu) != 0x06F02F82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02F82u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x05F3u;
    if (sm_scpu_context_key(cpu) != 0x06F02F9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02F9Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE05F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Au;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05F5u;
    if (sm_scpu_context_key(cpu) != 0x06F02FAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02FAAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x05F8u;
    if (sm_scpu_context_key(cpu) != 0x06F02FC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02FC2u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x05FAu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02FDAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x09u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x09u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x05FDu;
    if (sm_scpu_context_key(cpu) != 0x06F02FEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02FEAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE05FDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0600u;
    if (sm_scpu_context_key(cpu) != 0x06F03002u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03002u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0600u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0602u;
    if (sm_scpu_context_key(cpu) != 0x06F03012u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03012u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0602u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0605u;
    if (sm_scpu_context_key(cpu) != 0x06F0302Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0302Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0605u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Au;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0607u;
    if (sm_scpu_context_key(cpu) != 0x06F0303Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0303Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0607u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x060Au;
    if (sm_scpu_context_key(cpu) != 0x06F03052u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03052u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE060Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x21u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x060Cu;
    if (sm_scpu_context_key(cpu) != 0x06F03060u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03060u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE060Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x060Du;
    if (sm_scpu_context_key(cpu) != 0x06F03068u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F03068u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x05u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE060Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0005u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0610u;
    if (sm_scpu_context_key(cpu) != 0x06F03080u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03080u: {
    static const uint8_t source_bytes[] = {0x77u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0610u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
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
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x0612u;
    if (sm_scpu_context_key(cpu) != 0x06F03090u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03090u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0612u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0613u;
    if (sm_scpu_context_key(cpu) != 0x06F03098u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03098u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x03u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0613u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0003u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0616u;
    if (sm_scpu_context_key(cpu) != 0x06F030B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F030B0u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0616u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x0618u;
    if (sm_scpu_context_key(cpu) != 0x06F030C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F030C0u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0618u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0619u;
    if (sm_scpu_context_key(cpu) != 0x06F030C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F030C8u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0619u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x061Bu;
    if (sm_scpu_context_key(cpu) != 0x06F030D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F030D8u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE061Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x061Cu;
    if (sm_scpu_context_key(cpu) != 0x06F030E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F030E0u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE061Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x061Fu;
    if (sm_scpu_context_key(cpu) != 0x06F030F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F030F8u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE061Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x0621u;
    if (sm_scpu_context_key(cpu) != 0x06F03108u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03108u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0621u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0623u;
    if (sm_scpu_context_key(cpu) != 0x06F03118u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03118u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0623u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0624u;
    if (sm_scpu_context_key(cpu) != 0x06F03120u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F03120u: {
    static const uint8_t source_bytes[] = {0x85u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0624u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0626u;
    if (sm_scpu_context_key(cpu) != 0x06F03130u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03130u: {
    static const uint8_t source_bytes[] = {0x88u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0626u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y - 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0627u;
    if (sm_scpu_context_key(cpu) != 0x06F03138u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03138u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0627u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0629u;
    if (sm_scpu_context_key(cpu) != 0x06F03148u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03148u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0629u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x062Au;
    if (sm_scpu_context_key(cpu) != 0x06F03150u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03150u: {
    static const uint8_t source_bytes[] = {0x65u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE062Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
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
    cpu->pc = 0x062Cu;
    if (sm_scpu_context_key(cpu) != 0x06F03160u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03160u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE062Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x062Du;
    if (sm_scpu_context_key(cpu) != 0x06F03168u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03168u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE062Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x062Fu;
    if (sm_scpu_context_key(cpu) != 0x06F0317Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0317Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE062Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0631u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F03192u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0632u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x0634u;
    if (sm_scpu_context_key(cpu) != 0x06F031A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F031A2u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0634u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0635u;
    if (sm_scpu_context_key(cpu) != 0x06F031AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F031AAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0635u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0638u;
    if (sm_scpu_context_key(cpu) != 0x06F031C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F031C2u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0638u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x063Au;
    if (sm_scpu_context_key(cpu) != 0x06F031D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F031D2u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE063Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x063Bu;
    if (sm_scpu_context_key(cpu) != 0x06F031DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F031DAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE063Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x063Eu;
    if (sm_scpu_context_key(cpu) != 0x06F031F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F031F2u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE063Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0x0640u;
    if (sm_scpu_context_key(cpu) != 0x06F03202u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03202u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0640u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0641u;
    if (sm_scpu_context_key(cpu) != 0x06F0320Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0320Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0641u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0644u;
    if (sm_scpu_context_key(cpu) != 0x06F03222u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03222u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0644u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Au;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0646u;
    if (sm_scpu_context_key(cpu) != 0x06F03232u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03232u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0646u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0649u;
    if (sm_scpu_context_key(cpu) != 0x06F0324Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0324Au: {
    static const uint8_t source_bytes[] = {0xCAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0649u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x - 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x064Au;
    if (sm_scpu_context_key(cpu) != 0x06F03252u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03252u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xE3u};
    if (sm_scpu_guard_code(cpu,bus,0xDE064Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x062Fu;
        cycles = 3u;
    } else {
        cpu->pc = 0x064Cu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0317Au && sm_scpu_context_key(cpu) != 0x06F03262u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F03262u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE064Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x064Eu;
    if (sm_scpu_context_key(cpu) != 0x06F03270u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03270u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE064Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x064Fu;
    if (sm_scpu_context_key(cpu) != 0x06F03278u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F03278u: {
    static const uint8_t source_bytes[] = {0xFAu};
    if (sm_scpu_guard_code(cpu,bus,0xDE064Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0650u;
    if (sm_scpu_context_key(cpu) != 0x06F03280u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F03280u: {
    static const uint8_t source_bytes[] = {0x20u, 0x85u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0650u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0652u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0685u;
    if (sm_scpu_context_key(cpu) != 0x06F03428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F03298u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0653u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t high;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0654u;
    if (sm_scpu_context_key(cpu) != 0x06F032A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F032A0u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0654u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x0655u;
    if (sm_scpu_context_key(cpu) != 0x06F032A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F032A8u: {
    static const uint8_t source_bytes[] = {0x65u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0655u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
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
    cpu->pc = 0x0657u;
    if (sm_scpu_context_key(cpu) != 0x06F032B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F032B8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0657u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0659u;
    if (sm_scpu_context_key(cpu) != 0x06F032C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F032C8u: {
    static const uint8_t source_bytes[] = {0x80u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0659u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x065Du;
    if (sm_scpu_context_key(cpu) != 0x06F032E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F032D8u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE065Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x065Du;
    if (sm_scpu_context_key(cpu) != 0x06F032E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F032E8u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE065Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x065Fu;
    if (sm_scpu_context_key(cpu) != 0x06F032F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F032F8u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE065Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    value = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(value >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0661u;
    if (sm_scpu_context_key(cpu) != 0x06F03308u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03308u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0661u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0663u;
    if (sm_scpu_context_key(cpu) != 0x06F03318u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03318u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x7Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0663u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Fu;
    uint16_t left = cpu->a & 0xFFFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((result & 0xFFFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0666u;
    if (sm_scpu_context_key(cpu) != 0x06F03330u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03330u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0666u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x066Bu;
        cycles = 3u;
    } else {
        cpu->pc = 0x0668u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F03340u && sm_scpu_context_key(cpu) != 0x06F03358u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F03340u: {
    static const uint8_t source_bytes[] = {0x82u, 0x06u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0668u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0571u;
    if (sm_scpu_context_key(cpu) != 0x06F02B88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03358u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0xDE066Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0100u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x066Eu;
    if (sm_scpu_context_key(cpu) != 0x06F03370u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03370u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE066Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0670u;
    if (sm_scpu_context_key(cpu) != 0x06F03380u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03380u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0670u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0671u;
    if (sm_scpu_context_key(cpu) != 0x06F03388u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03388u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0671u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0672u;
    if (sm_scpu_context_key(cpu) != 0x06F03390u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03390u: {
    static const uint8_t source_bytes[] = {0x20u, 0x85u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0672u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0674u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0685u;
    if (sm_scpu_context_key(cpu) != 0x06F03428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F033A8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0675u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0677u;
    if (sm_scpu_context_key(cpu) != 0x06F033BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F033BAu: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0677u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0679u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F033D2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0xDE067Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x19u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x067Cu;
    if (sm_scpu_context_key(cpu) != 0x06F033E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F033E2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE067Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x067Fu;
    if (sm_scpu_context_key(cpu) != 0x06F033FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F033FAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x92u};
    if (sm_scpu_guard_code(cpu,bus,0xDE067Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0092u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0681u;
    if (sm_scpu_context_key(cpu) != 0x06F0340Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0340Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0681u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0684u;
    if (sm_scpu_context_key(cpu) != 0x06F03422u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03422u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0684u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00C8Au && sm_scpu_context_key(cpu) != 0x06F00E12u && sm_scpu_context_key(cpu) != 0x06F00F5Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F03428u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0685u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0687u;
    if (sm_scpu_context_key(cpu) != 0x06F0343Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0343Au: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0687u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0688u;
    if (sm_scpu_context_key(cpu) != 0x06F03442u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03442u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0688u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x068Au;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0345Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE068Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x07u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x068Du;
    if (sm_scpu_context_key(cpu) != 0x06F0346Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0346Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE068Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0690u;
    if (sm_scpu_context_key(cpu) != 0x06F03482u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03482u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0690u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0692u;
    if (sm_scpu_context_key(cpu) != 0x06F03492u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03492u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0692u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0695u;
    if (sm_scpu_context_key(cpu) != 0x06F034AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F034AAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0695u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Bu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0697u;
    if (sm_scpu_context_key(cpu) != 0x06F034BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F034BAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0697u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x069Au;
    if (sm_scpu_context_key(cpu) != 0x06F034D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F034D2u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE069Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x069Cu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F034EAu: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE069Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06A0u;
    if (sm_scpu_context_key(cpu) != 0x06F03502u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03502u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06A2u;
    if (sm_scpu_context_key(cpu) != 0x06F03512u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03512u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06A5u;
    if (sm_scpu_context_key(cpu) != 0x06F0352Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0352Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE06A5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Bu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06A7u;
    if (sm_scpu_context_key(cpu) != 0x06F0353Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0353Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06AAu;
    if (sm_scpu_context_key(cpu) != 0x06F03552u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03552u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x06ACu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0356Au: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06ADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06AEu;
    if (sm_scpu_context_key(cpu) != 0x06F03572u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03572u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06B1u;
    if (sm_scpu_context_key(cpu) != 0x06F0358Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0358Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE06B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06B2u;
    if (sm_scpu_context_key(cpu) != 0x06F03592u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03592u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06B2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06B5u;
    if (sm_scpu_context_key(cpu) != 0x06F035AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F035AAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE06B5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Bu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06B7u;
    if (sm_scpu_context_key(cpu) != 0x06F035BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F035BAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06BAu;
    if (sm_scpu_context_key(cpu) != 0x06F035D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F035D2u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x06BCu;
    if (sm_scpu_context_key(cpu) != 0x06F035E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F035E0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x18u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06BEu;
    if (sm_scpu_context_key(cpu) != 0x06F035F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F035F0u: {
    static const uint8_t source_bytes[] = {0x29u, 0x00u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE06BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFF00u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06C1u;
    if (sm_scpu_context_key(cpu) != 0x06F03608u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03608u: {
    static const uint8_t source_bytes[] = {0x85u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06C1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06C3u;
    if (sm_scpu_context_key(cpu) != 0x06F03618u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03618u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06C5u;
    if (sm_scpu_context_key(cpu) != 0x06F03628u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03628u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE06C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06C6u;
    if (sm_scpu_context_key(cpu) != 0x06F03630u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03630u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE06C6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06C7u;
    if (sm_scpu_context_key(cpu) != 0x06F03638u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03638u: {
    static const uint8_t source_bytes[] = {0x65u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06C7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
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
    cpu->pc = 0x06C9u;
    if (sm_scpu_context_key(cpu) != 0x06F03648u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03648u: {
    static const uint8_t source_bytes[] = {0x86u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->x) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06CBu;
    if (sm_scpu_context_key(cpu) != 0x06F03658u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03658u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06CBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x06CDu;
    if (sm_scpu_context_key(cpu) != 0x06F0366Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0366Au: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06CDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x06CEu;
    if (sm_scpu_context_key(cpu) != 0x06F03672u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03672u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x06D0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0368Au: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06D2u;
    if (sm_scpu_context_key(cpu) != 0x06F03692u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03692u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06D5u;
    if (sm_scpu_context_key(cpu) != 0x06F036AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F036AAu: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE06D5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06D6u;
    if (sm_scpu_context_key(cpu) != 0x06F036B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F036B2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06D6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06D9u;
    if (sm_scpu_context_key(cpu) != 0x06F036CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F036CAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE06D9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Bu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06DBu;
    if (sm_scpu_context_key(cpu) != 0x06F036DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F036DAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06DEu;
    if (sm_scpu_context_key(cpu) != 0x06F036F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F036F2u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x06E0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0370Au: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06E4u;
    if (sm_scpu_context_key(cpu) != 0x06F03722u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03722u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06E4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06E6u;
    if (sm_scpu_context_key(cpu) != 0x06F03732u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F03732u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06E6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06E9u;
    if (sm_scpu_context_key(cpu) != 0x06F0374Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0374Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE06E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Bu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06EBu;
    if (sm_scpu_context_key(cpu) != 0x06F0375Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0375Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06EEu;
    if (sm_scpu_context_key(cpu) != 0x06F03772u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03772u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x06F0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0378Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06F1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x06F3u;
    if (sm_scpu_context_key(cpu) != 0x06F03798u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F03798u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x06u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06F5u;
    if (sm_scpu_context_key(cpu) != 0x06F037A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F037A8u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE06F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06F6u;
    if (sm_scpu_context_key(cpu) != 0x06F037B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F037B0u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE06F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06F7u;
    if (sm_scpu_context_key(cpu) != 0x06F037B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F037B8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06F7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x06F9u;
    if (sm_scpu_context_key(cpu) != 0x06F037CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F037CAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x06FCu;
    if (sm_scpu_context_key(cpu) != 0x06F037E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F037E2u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE06FCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x06FDu;
    if (sm_scpu_context_key(cpu) != 0x06F037EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F037EAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE06FDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0700u;
    if (sm_scpu_context_key(cpu) != 0x06F03802u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03802u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0700u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x08u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0702u;
    if (sm_scpu_context_key(cpu) != 0x06F03812u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F03812u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0702u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0705u;
    if (sm_scpu_context_key(cpu) != 0x06F0382Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0382Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0705u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Bu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0707u;
    if (sm_scpu_context_key(cpu) != 0x06F0383Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0383Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0707u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x070Au;
    if (sm_scpu_context_key(cpu) != 0x06F03852u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03852u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE070Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x070Cu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0386Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x09u};
    if (sm_scpu_guard_code(cpu,bus,0xDE070Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x09u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x070Fu;
    if (sm_scpu_context_key(cpu) != 0x06F0387Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F0387Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE070Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0712u;
    if (sm_scpu_context_key(cpu) != 0x06F03892u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F03892u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x9Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0712u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x009Bu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0714u;
    if (sm_scpu_context_key(cpu) != 0x06F038A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F038A2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0714u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0717u;
    if (sm_scpu_context_key(cpu) != 0x06F038BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F038BAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0717u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0719u;
    if (sm_scpu_context_key(cpu) != 0x06F038C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F038C8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0719u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F03298u && sm_scpu_context_key(cpu) != 0x06F033A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
