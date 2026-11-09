#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_tranche_067_070(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x040C1390u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x818272u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8274u;
    if (sm_scpu_context_key(cpu) != 0x040C13A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C13A2u: {
    static const uint8_t source_bytes[] = {0x64u, 0x6Fu};
    if (sm_scpu_guard_code(cpu,bus,0x818274u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Fu);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8276u;
    if (sm_scpu_context_key(cpu) != 0x040C13B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C13B2u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x0Cu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x818276u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Cu;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8279u;
    if (sm_scpu_context_key(cpu) != 0x040C13CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040C13CAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x818279u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x827Bu;
    if (sm_scpu_context_key(cpu) != 0x040C13D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C13D8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81827Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C0F78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040F02C8u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x81E059u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x12u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE05Bu;
    if (sm_scpu_context_key(cpu) != 0x040F02D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F02D8u: {
    static const uint8_t source_bytes[] = {0x29u, 0x00u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x81E05Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFF00u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE05Eu;
    if (sm_scpu_context_key(cpu) != 0x040F02F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F02F0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E05Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE05Fu;
    if (sm_scpu_context_key(cpu) != 0x040F02F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F02F8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E05Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE061u;
    if (sm_scpu_context_key(cpu) != 0x040F0308u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0308u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x81E061u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE063u;
    if (sm_scpu_context_key(cpu) != 0x040F0318u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0318u: {
    static const uint8_t source_bytes[] = {0x29u, 0xE0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E063u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00E0u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE066u;
    if (sm_scpu_context_key(cpu) != 0x040F0330u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F0330u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E066u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE067u;
    if (sm_scpu_context_key(cpu) != 0x040F0338u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0338u: {
    static const uint8_t source_bytes[] = {0x85u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x81E067u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE069u;
    if (sm_scpu_context_key(cpu) != 0x040F0348u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0348u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x81E069u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE06Bu;
    if (sm_scpu_context_key(cpu) != 0x040F0358u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0358u: {
    static const uint8_t source_bytes[] = {0x29u, 0x00u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x81E06Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFF00u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE06Eu;
    if (sm_scpu_context_key(cpu) != 0x040F0370u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F0370u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E06Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE06Fu;
    if (sm_scpu_context_key(cpu) != 0x040F0378u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0378u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E06Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE070u;
    if (sm_scpu_context_key(cpu) != 0x040F0380u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0380u: {
    static const uint8_t source_bytes[] = {0x85u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x81E070u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE072u;
    if (sm_scpu_context_key(cpu) != 0x040F0390u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0390u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x81E072u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x12u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE074u;
    if (sm_scpu_context_key(cpu) != 0x040F03A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F03A0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xE0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E074u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00E0u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE077u;
    if (sm_scpu_context_key(cpu) != 0x040F03B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F03B8u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E077u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE078u;
    if (sm_scpu_context_key(cpu) != 0x040F03C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F03C0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E078u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE079u;
    if (sm_scpu_context_key(cpu) != 0x040F03C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F03C8u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E079u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE07Au;
    if (sm_scpu_context_key(cpu) != 0x040F03D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F03D0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E07Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE07Bu;
    if (sm_scpu_context_key(cpu) != 0x040F03D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F03D8u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81E07Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xE07Cu;
    if (sm_scpu_context_key(cpu) != 0x040F03E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F03E0u: {
    static const uint8_t source_bytes[] = {0x65u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E07Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
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
    cpu->pc = 0xE07Eu;
    if (sm_scpu_context_key(cpu) != 0x040F03F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F03F0u: {
    static const uint8_t source_bytes[] = {0x65u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x81E07Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
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
    cpu->pc = 0xE080u;
    if (sm_scpu_context_key(cpu) != 0x040F0400u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0400u: {
    static const uint8_t source_bytes[] = {0x65u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x81E080u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x04u);
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
    cpu->pc = 0xE082u;
    if (sm_scpu_context_key(cpu) != 0x040F0410u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0410u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x81E082u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE083u;
    if (sm_scpu_context_key(cpu) != 0x040F0418u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0418u: {
    static const uint8_t source_bytes[] = {0xBFu, 0x00u, 0x60u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0x81E083u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E6000u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE087u;
    if (sm_scpu_context_key(cpu) != 0x040F0438u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040F0438u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E087u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE088u;
    if (sm_scpu_context_key(cpu) != 0x040F0440u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0440u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E088u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE089u;
    if (sm_scpu_context_key(cpu) != 0x040F0448u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0448u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E089u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE08Au;
    if (sm_scpu_context_key(cpu) != 0x040F0450u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0450u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E08Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE08Cu;
    if (sm_scpu_context_key(cpu) != 0x040F0460u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0460u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x81E08Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x12u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE08Eu;
    if (sm_scpu_context_key(cpu) != 0x040F0470u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0470u: {
    static const uint8_t source_bytes[] = {0x29u, 0x10u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E08Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x0010u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE091u;
    if (sm_scpu_context_key(cpu) != 0x040F0488u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F0488u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E091u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE092u;
    if (sm_scpu_context_key(cpu) != 0x040F0490u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0490u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E092u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE093u;
    if (sm_scpu_context_key(cpu) != 0x040F0498u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0498u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E093u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE094u;
    if (sm_scpu_context_key(cpu) != 0x040F04A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F04A0u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81E094u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xE095u;
    if (sm_scpu_context_key(cpu) != 0x040F04A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F04A8u: {
    static const uint8_t source_bytes[] = {0x65u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E095u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
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
    cpu->pc = 0xE097u;
    if (sm_scpu_context_key(cpu) != 0x040F04B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F04B8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E097u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE099u;
    if (sm_scpu_context_key(cpu) != 0x040F04C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F04C8u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x81E099u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE09Bu;
    if (sm_scpu_context_key(cpu) != 0x040F04D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F04D8u: {
    static const uint8_t source_bytes[] = {0x29u, 0x10u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E09Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x0010u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE09Eu;
    if (sm_scpu_context_key(cpu) != 0x040F04F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F04F0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E09Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE09Fu;
    if (sm_scpu_context_key(cpu) != 0x040F04F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F04F8u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E09Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE0A0u;
    if (sm_scpu_context_key(cpu) != 0x040F0500u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0500u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81E0A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xE0A1u;
    if (sm_scpu_context_key(cpu) != 0x040F0508u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0508u: {
    static const uint8_t source_bytes[] = {0x65u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x81E0A1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
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
    cpu->pc = 0xE0A3u;
    if (sm_scpu_context_key(cpu) != 0x040F0518u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0518u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x81E0A3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE0A4u;
    if (sm_scpu_context_key(cpu) != 0x040F0520u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0520u: {
    static const uint8_t source_bytes[] = {0xBFu, 0x00u, 0x80u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0x81E0A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0x7E8000u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE0A8u;
    if (sm_scpu_context_key(cpu) != 0x040F0540u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040F0540u: {
    static const uint8_t source_bytes[] = {0x85u, 0x2Eu};
    if (sm_scpu_guard_code(cpu,bus,0x81E0A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x2Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE0AAu;
    if (sm_scpu_context_key(cpu) != 0x040F0550u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040F0550u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x81E0AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x03FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE0ADu;
    if (sm_scpu_context_key(cpu) != 0x040F0568u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F0568u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E0ADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE0AEu;
    if (sm_scpu_context_key(cpu) != 0x040F0570u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0570u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81E0AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE0AFu;
    if (sm_scpu_context_key(cpu) != 0x040F0578u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0578u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x81E0AFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE0B0u;
    if (sm_scpu_context_key(cpu) != 0x040F0580u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040F0580u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81E0B0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040F0150u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041611B8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x82C237u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC239u;
    if (sm_scpu_context_key(cpu) != 0x041611CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041611CAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x82C239u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC23Bu;
    if (sm_scpu_context_key(cpu) != 0x041611DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041611DAu: {
    static const uint8_t source_bytes[] = {0x64u, 0x6Cu};
    if (sm_scpu_guard_code(cpu,bus,0x82C23Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Cu);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC23Du;
    if (sm_scpu_context_key(cpu) != 0x041611EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041611EAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x6Cu};
    if (sm_scpu_guard_code(cpu,bus,0x82C23Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Cu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC23Fu;
    if (sm_scpu_context_key(cpu) != 0x041611FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041611FAu: {
    static const uint8_t source_bytes[] = {0xF0u, 0xFCu};
    if (sm_scpu_guard_code(cpu,bus,0x82C23Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0xC23Du;
        cycles = 3u;
    } else {
        cpu->pc = 0xC241u;
    }
    if (sm_scpu_context_key(cpu) != 0x041611EAu && sm_scpu_context_key(cpu) != 0x0416120Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0416120Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82C241u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0415D5B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0046Au: {
    static const uint8_t source_bytes[] = {0xA2u, 0xAAu, 0xBBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE008Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xBBAAu;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0090u;
    if (sm_scpu_context_key(cpu) != 0x06F00482u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00482u: {
    static const uint8_t source_bytes[] = {0xECu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0090u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->x;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0093u;
    if (sm_scpu_context_key(cpu) != 0x06F0049Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F0049Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0093u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0090u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0095u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F00482u && sm_scpu_context_key(cpu) != 0x06F004AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F004AAu: {
    static const uint8_t source_bytes[] = {0xA2u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0095u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0098u;
    if (sm_scpu_context_key(cpu) != 0x06F004C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F004C2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xCCu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0098u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00CCu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x009Au;
    if (sm_scpu_context_key(cpu) != 0x06F004D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F004D2u: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE009Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x009Bu;
    if (sm_scpu_context_key(cpu) != 0x06F004DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F004DAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE009Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x009Du;
    if (sm_scpu_context_key(cpu) != 0x06F004E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F004E8u: {
    static const uint8_t source_bytes[] = {0xBFu, 0xC1u, 0x07u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE009Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE07C1u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00A1u;
    if (sm_scpu_context_key(cpu) != 0x06F00508u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00508u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00A1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00A2u;
    if (sm_scpu_context_key(cpu) != 0x06F00510u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00510u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00A3u;
    if (sm_scpu_context_key(cpu) != 0x06F00518u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00518u: {
    static const uint8_t source_bytes[] = {0xA8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00A3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00A4u;
    if (sm_scpu_context_key(cpu) != 0x06F00520u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00520u: {
    static const uint8_t source_bytes[] = {0xBFu, 0xC1u, 0x07u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE07C1u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00A8u;
    if (sm_scpu_context_key(cpu) != 0x06F00540u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00540u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00A9u;
    if (sm_scpu_context_key(cpu) != 0x06F00548u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00548u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00A9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00AAu;
    if (sm_scpu_context_key(cpu) != 0x06F00550u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00550u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x00ACu;
    if (sm_scpu_context_key(cpu) != 0x06F00562u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00562u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x00AFu;
    if (sm_scpu_context_key(cpu) != 0x06F0057Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0057Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00AFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00B0u;
    if (sm_scpu_context_key(cpu) != 0x06F00582u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00582u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00B0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x00B3u;
    if (sm_scpu_context_key(cpu) != 0x06F0059Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0059Au: {
    static const uint8_t source_bytes[] = {0xC0u, 0x01u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00B3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    uint16_t left = cpu->y;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x00B6u;
    if (sm_scpu_context_key(cpu) != 0x06F005B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F005B2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00B6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00B8u;
    if (sm_scpu_context_key(cpu) != 0x06F005C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F005C2u: {
    static const uint8_t source_bytes[] = {0x2Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE00B8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t value = (uint16_t)(((left << 1u) | ((cpu->p & SM_P_C) != 0u)) & 0xFFu);
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x80u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00B9u;
    if (sm_scpu_context_key(cpu) != 0x06F005CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F005CAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x00BCu;
    if (sm_scpu_context_key(cpu) != 0x06F005E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F005E2u: {
    static const uint8_t source_bytes[] = {0x69u, 0x7Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x007Fu;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t sum = (uint16_t)(left + value + ((cpu->p & SM_P_C) != 0u));
    uint16_t result = sum & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x80u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFu ? SM_P_C : 0u));
    cpu->pc = 0x00BEu;
    if (sm_scpu_context_key(cpu) != 0x06F005F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F005F2u: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00BFu;
    if (sm_scpu_context_key(cpu) != 0x06F005FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F005FAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x00C2u;
    if (sm_scpu_context_key(cpu) != 0x06F00612u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00612u: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00C2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x00C5u;
    if (sm_scpu_context_key(cpu) != 0x06F0062Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0062Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x00C2u;
        cycles = 3u;
    } else {
        cpu->pc = 0x00C7u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F00612u && sm_scpu_context_key(cpu) != 0x06F0063Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0063Au: {
    static const uint8_t source_bytes[] = {0x50u, 0x2Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE00C7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_V) == 0u) {
        cpu->pc = 0x00F6u;
        cycles = 3u;
    } else {
        cpu->pc = 0x00C9u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0064Au && sm_scpu_context_key(cpu) != 0x06F007B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0064Au: {
    static const uint8_t source_bytes[] = {0xBFu, 0xC1u, 0x07u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE07C1u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00CDu;
    if (sm_scpu_context_key(cpu) != 0x06F0066Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F0066Au: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00CDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00CEu;
    if (sm_scpu_context_key(cpu) != 0x06F00672u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00672u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00CFu;
    if (sm_scpu_context_key(cpu) != 0x06F0067Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0067Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00CFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00D1u;
    if (sm_scpu_context_key(cpu) != 0x06F0068Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0068Au: {
    static const uint8_t source_bytes[] = {0x80u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xDE00D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x00E0u;
    if (sm_scpu_context_key(cpu) != 0x06F00702u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0069Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00D3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00D4u;
    if (sm_scpu_context_key(cpu) != 0x06F006A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F006A2u: {
    static const uint8_t source_bytes[] = {0xBFu, 0xC1u, 0x07u, 0xDEu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xDE07C1u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00D8u;
    if (sm_scpu_context_key(cpu) != 0x06F006C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F006C2u: {
    static const uint8_t source_bytes[] = {0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00D9u;
    if (sm_scpu_context_key(cpu) != 0x06F006CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F006CAu: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00D9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00DAu;
    if (sm_scpu_context_key(cpu) != 0x06F006D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F006D2u: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x00DDu;
    if (sm_scpu_context_key(cpu) != 0x06F006EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F006EAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x00DAu;
        cycles = 3u;
    } else {
        cpu->pc = 0x00DFu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F006D2u && sm_scpu_context_key(cpu) != 0x06F006FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F006FAu: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE00DFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (cpu->a + 1u) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00E0u;
    if (sm_scpu_context_key(cpu) != 0x06F00702u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00702u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00E1u;
    if (sm_scpu_context_key(cpu) != 0x06F0070Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0070Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x00E4u;
    if (sm_scpu_context_key(cpu) != 0x06F00722u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00722u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00E4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00E5u;
    if (sm_scpu_context_key(cpu) != 0x06F0072Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0072Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00E5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x00E8u;
    if (sm_scpu_context_key(cpu) != 0x06F00742u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00742u: {
    static const uint8_t source_bytes[] = {0x88u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint16_t)(cpu->y - 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00E9u;
    if (sm_scpu_context_key(cpu) != 0x06F0074Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0074Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0xE8u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x00D3u;
        cycles = 3u;
    } else {
        cpu->pc = 0x00EBu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0069Au && sm_scpu_context_key(cpu) != 0x06F0075Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0075Au: {
    static const uint8_t source_bytes[] = {0xCDu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x00EEu;
    if (sm_scpu_context_key(cpu) != 0x06F00772u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00772u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x00EBu;
        cycles = 3u;
    } else {
        cpu->pc = 0x00F0u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F0075Au && sm_scpu_context_key(cpu) != 0x06F00782u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F00782u: {
    static const uint8_t source_bytes[] = {0x69u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0x0003u;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t sum = (uint16_t)(left + value + ((cpu->p & SM_P_C) != 0u));
    uint16_t result = sum & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x80u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFu ? SM_P_C : 0u));
    cpu->pc = 0x00F2u;
    if (sm_scpu_context_key(cpu) != 0x06F00792u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00792u: {
    static const uint8_t source_bytes[] = {0xF0u, 0xFCu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00F2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x00F0u;
        cycles = 3u;
    } else {
        cpu->pc = 0x00F4u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F00782u && sm_scpu_context_key(cpu) != 0x06F007A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F007A2u: {
    static const uint8_t source_bytes[] = {0x80u, 0xA4u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x009Au;
    if (sm_scpu_context_key(cpu) != 0x06F004D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F007B2u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x89u, 0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xAB89u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00F9u;
    if (sm_scpu_context_key(cpu) != 0x06F007CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F007CAu: {
    static const uint8_t source_bytes[] = {0xA0u, 0xCDu, 0xEFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xEFCDu;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x00FCu;
    if (sm_scpu_context_key(cpu) != 0x06F007E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F007E2u: {
    static const uint8_t source_bytes[] = {0xECu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE00FCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->x;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x00FFu;
    if (sm_scpu_context_key(cpu) != 0x06F007FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F007FAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE00FFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x00FCu;
        cycles = 3u;
    } else {
        cpu->pc = 0x0101u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F007E2u && sm_scpu_context_key(cpu) != 0x06F0080Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F0080Au: {
    static const uint8_t source_bytes[] = {0xCCu, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0101u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->y;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0x0104u;
    if (sm_scpu_context_key(cpu) != 0x06F00822u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F00822u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xF6u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0104u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x00FCu;
        cycles = 3u;
    } else {
        cpu->pc = 0x0106u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F007E2u && sm_scpu_context_key(cpu) != 0x06F00832u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F00832u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0106u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0108u;
    if (sm_scpu_context_key(cpu) != 0x06F00842u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00842u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0108u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x010Bu;
    if (sm_scpu_context_key(cpu) != 0x06F0085Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0085Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x23u};
    if (sm_scpu_guard_code(cpu,bus,0xDE010Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0023u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x010Du;
    if (sm_scpu_context_key(cpu) != 0x06F0086Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F0086Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE010Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0110u;
    if (sm_scpu_context_key(cpu) != 0x06F00882u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00882u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x45u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0110u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0045u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0112u;
    if (sm_scpu_context_key(cpu) != 0x06F00892u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00892u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0112u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0115u;
    if (sm_scpu_context_key(cpu) != 0x06F008AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F008AAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x67u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0115u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0067u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0117u;
    if (sm_scpu_context_key(cpu) != 0x06F008BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F008BAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0117u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x011Au;
    if (sm_scpu_context_key(cpu) != 0x06F008D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F008D2u: {
    static const uint8_t source_bytes[] = {0xAEu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE011Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x011Du;
    if (sm_scpu_context_key(cpu) != 0x06F008EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F008EAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE011Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x011Au;
        cycles = 3u;
    } else {
        cpu->pc = 0x011Fu;
    }
    if (sm_scpu_context_key(cpu) != 0x06F008D2u && sm_scpu_context_key(cpu) != 0x06F008FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F008FAu: {
    static const uint8_t source_bytes[] = {0xAEu, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE011Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0122u;
    if (sm_scpu_context_key(cpu) != 0x06F00912u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x06F00912u: {
    static const uint8_t source_bytes[] = {0x86u, 0x15u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0122u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x15u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0124u;
    if (sm_scpu_context_key(cpu) != 0x06F00922u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00922u: {
    static const uint8_t source_bytes[] = {0x86u, 0x17u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0124u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x17u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->x >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0126u;
    if (sm_scpu_context_key(cpu) != 0x06F00932u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00932u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0126u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0129u;
    if (sm_scpu_context_key(cpu) != 0x06F0094Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0094Au: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0129u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x012Cu;
    if (sm_scpu_context_key(cpu) != 0x06F00962u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00962u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE012Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x012Fu;
    if (sm_scpu_context_key(cpu) != 0x06F0097Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0097Au: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE012Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0132u;
    if (sm_scpu_context_key(cpu) != 0x06F00992u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00992u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0132u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0134u;
    if (sm_scpu_context_key(cpu) != 0x06F009A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F009A2u: {
    static const uint8_t source_bytes[] = {0xCDu, 0x43u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0134u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2143u;
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t difference = (uint16_t)((cpu->a & 0xFFu) - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | (difference & SM_P_N) | ((difference & 0xFFu) == 0u ? SM_P_Z : 0u) | ((cpu->a & 0xFFu) >= value ? SM_P_C : 0u));
    cpu->pc = 0x0137u;
    if (sm_scpu_context_key(cpu) != 0x06F009BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F009BAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0137u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x0134u;
        cycles = 3u;
    } else {
        cpu->pc = 0x0139u;
    }
    if (sm_scpu_context_key(cpu) != 0x06F009A2u && sm_scpu_context_key(cpu) != 0x06F009CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x06F009CAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0139u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x19u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x013Bu;
    if (sm_scpu_context_key(cpu) != 0x06F009DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F009DAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE013Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x013Du;
    if (sm_scpu_context_key(cpu) != 0x06F009EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F009EAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE013Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x013Fu;
    if (sm_scpu_context_key(cpu) != 0x06F009FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F009FAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Cu};
    if (sm_scpu_guard_code(cpu,bus,0xDE013Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0141u;
    if (sm_scpu_context_key(cpu) != 0x06F00A0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00A0Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0141u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0143u;
    if (sm_scpu_context_key(cpu) != 0x06F00A1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00A1Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x29u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0143u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x29u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0145u;
    if (sm_scpu_context_key(cpu) != 0x06F00A2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00A2Au: {
    static const uint8_t source_bytes[] = {0x64u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0145u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x0Fu);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0147u;
    if (sm_scpu_context_key(cpu) != 0x06F00A3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00A3Au: {
    static const uint8_t source_bytes[] = {0x64u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0147u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0149u;
    if (sm_scpu_context_key(cpu) != 0x06F00A4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00A4Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0149u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x014Bu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00A62u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x16u};
    if (sm_scpu_guard_code(cpu,bus,0xDE014Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x16u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x014Eu;
    if (sm_scpu_context_key(cpu) != 0x06F00A72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00A72u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE014Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0151u;
    if (sm_scpu_context_key(cpu) != 0x06F00A8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00A8Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x15u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0151u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x15u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0153u;
    if (sm_scpu_context_key(cpu) != 0x06F00A9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00A9Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0153u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0156u;
    if (sm_scpu_context_key(cpu) != 0x06F00AB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00AB2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x90u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0156u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0090u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0158u;
    if (sm_scpu_context_key(cpu) != 0x06F00AC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00AC2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0158u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x015Bu;
    if (sm_scpu_context_key(cpu) != 0x06F00ADAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00ADAu: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE015Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x015Du;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00AF2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0xDE015Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x18u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0160u;
    if (sm_scpu_context_key(cpu) != 0x06F00B02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00B02u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0160u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0163u;
    if (sm_scpu_context_key(cpu) != 0x06F00B1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00B1Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x17u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0163u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x17u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0165u;
    if (sm_scpu_context_key(cpu) != 0x06F00B2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00B2Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0165u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0168u;
    if (sm_scpu_context_key(cpu) != 0x06F00B42u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00B42u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x91u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0168u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0091u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x016Au;
    if (sm_scpu_context_key(cpu) != 0x06F00B52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00B52u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE016Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x016Du;
    if (sm_scpu_context_key(cpu) != 0x06F00B6Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00B6Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE016Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x016Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00B82u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0170u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0172u;
    if (sm_scpu_context_key(cpu) != 0x06F00B92u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00B92u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0172u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0175u;
    if (sm_scpu_context_key(cpu) != 0x06F00BAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00BAAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x85u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0175u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0085u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0177u;
    if (sm_scpu_context_key(cpu) != 0x06F00BBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00BBAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0177u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x017Au;
    if (sm_scpu_context_key(cpu) != 0x06F00BD2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00BD2u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE017Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x017Cu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00BEAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x7Fu};
    if (sm_scpu_guard_code(cpu,bus,0xDE017Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x007Fu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x017Fu;
    if (sm_scpu_context_key(cpu) != 0x06F00BFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00BFAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE017Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0182u;
    if (sm_scpu_context_key(cpu) != 0x06F00C12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00C12u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x86u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0182u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0086u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0184u;
    if (sm_scpu_context_key(cpu) != 0x06F00C22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00C22u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0184u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0187u;
    if (sm_scpu_context_key(cpu) != 0x06F00C3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F00C3Au: {
    static const uint8_t source_bytes[] = {0x64u, 0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE0187u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Au);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0189u;
    if (sm_scpu_context_key(cpu) != 0x06F00C4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00C4Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xF8u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0189u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x018Bu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x04F8u;
    if (sm_scpu_context_key(cpu) != 0x06F027C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00C62u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE018Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x018Eu;
    if (sm_scpu_context_key(cpu) != 0x06F00C72u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F00C72u: {
    static const uint8_t source_bytes[] = {0x20u, 0x33u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0xDE018Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0190u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x0533u;
    if (sm_scpu_context_key(cpu) != 0x06F0299Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F00C8Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0191u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x0193u;
    if (sm_scpu_context_key(cpu) != 0x06F00C98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F00C98u: {
    static const uint8_t source_bytes[] = {0x64u, 0x11u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0193u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x11u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0195u;
    if (sm_scpu_context_key(cpu) != 0x06F00CA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00CA8u: {
    static const uint8_t source_bytes[] = {0x64u, 0x13u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0195u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x13u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0197u;
    if (sm_scpu_context_key(cpu) != 0x06F00CB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F00CB8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0197u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00300u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
