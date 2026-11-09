#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_tranche_373_471(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x04043198u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808633u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8635u;
    if (sm_scpu_context_key(cpu) != 0x040431A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04043199u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808633u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8635u;
    if (sm_scpu_context_key(cpu) != 0x040431A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040431A8u: {
    static const uint8_t source_bytes[] = {0xAEu, 0xEAu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x808635u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07EAu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8638u;
    if (sm_scpu_context_key(cpu) != 0x040431C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040431C0u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x3Cu, 0x86u};
    if (sm_scpu_guard_code(cpu,bus,0x808638u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0x863Au;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x863Cu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0x864Du) || (cpu->x == 0x0002u && target == 0x865Eu))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x04043268u && sm_scpu_context_key(cpu) != 0x040432F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040431D8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80863Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04041460u && sm_scpu_context_key(cpu) != 0x04041798u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040431DAu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80863Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04041462u && sm_scpu_context_key(cpu) != 0x0404179Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04043200u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808640u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8642u;
    if (sm_scpu_context_key(cpu) != 0x04043210u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04043202u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808640u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8642u;
    if (sm_scpu_context_key(cpu) != 0x04043210u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04043210u: {
    static const uint8_t source_bytes[] = {0xAEu, 0xECu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x808642u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07ECu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8645u;
    if (sm_scpu_context_key(cpu) != 0x04043228u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04043228u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x49u, 0x86u};
    if (sm_scpu_guard_code(cpu,bus,0x808645u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0x8647u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x8649u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0x8693u) || (cpu->x == 0x0002u && target == 0x86A5u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x04043498u && sm_scpu_context_key(cpu) != 0x04043528u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04043240u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808648u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040417B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040436C0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8086D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x86DAu;
    if (sm_scpu_context_key(cpu) != 0x040436D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040436C1u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8086D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x86DAu;
    if (sm_scpu_context_key(cpu) != 0x040436D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040436D0u: {
    static const uint8_t source_bytes[] = {0xAEu, 0x5Au, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x8086DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A5Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x86DDu;
    if (sm_scpu_context_key(cpu) != 0x040436E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040436E8u: {
    static const uint8_t source_bytes[] = {0xFCu, 0xE1u, 0x86u};
    if (sm_scpu_guard_code(cpu,bus,0x8086DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0x86DFu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x86E1u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0x86E7u) || (cpu->x == 0x0002u && target == 0x86E8u) || (cpu->x == 0x0004u && target == 0x86E7u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x04043738u && sm_scpu_context_key(cpu) != 0x04043740u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04043700u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8086E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04040D70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04043740u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Cu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x8086E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A5Cu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x86EBu;
    if (sm_scpu_context_key(cpu) != 0x04043758u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04043758u: {
    static const uint8_t source_bytes[] = {0x38u};
    if (sm_scpu_guard_code(cpu,bus,0x8086EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | SM_P_C);
    cpu->pc = 0x86ECu;
    if (sm_scpu_context_key(cpu) != 0x04043760u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043760u: {
    static const uint8_t source_bytes[] = {0xEDu, 0x6Au, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x8086ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A6Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + (value ^ 0xFFFFu) + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (((left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x86EFu;
    if (sm_scpu_context_key(cpu) != 0x04043778u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04043778u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x5Cu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x8086EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A5Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x86F2u;
    if (sm_scpu_context_key(cpu) != 0x04043790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04043790u: {
    static const uint8_t source_bytes[] = {0xD0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8086F2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x86FBu;
        cycles = 3u;
    } else {
        cpu->pc = 0x86F4u;
    }
    if (sm_scpu_context_key(cpu) != 0x040437A0u && sm_scpu_context_key(cpu) != 0x040437D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040437A0u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x5Au, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x8086F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A5Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x86F7u;
    if (sm_scpu_context_key(cpu) != 0x040437B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040437B8u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x5Au, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x8086F7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A5Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x86FAu;
    if (sm_scpu_context_key(cpu) != 0x040437D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x040437D0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8086FAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04043700u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040437D8u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Cu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x8086FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A5Cu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x86FEu;
    if (sm_scpu_context_key(cpu) != 0x040437F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040437F0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x8086FEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x86FFu;
    if (sm_scpu_context_key(cpu) != 0x040437F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040437F8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x3Eu};
    if (sm_scpu_guard_code(cpu,bus,0x8086FFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x3Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8701u;
    if (sm_scpu_context_key(cpu) != 0x04043808u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043808u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Cu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808701u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A5Cu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8704u;
    if (sm_scpu_context_key(cpu) != 0x04043820u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04043820u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFEu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x808704u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFFFEu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8707u;
    if (sm_scpu_context_key(cpu) != 0x04043838u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04043838u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x808707u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x8708u;
    if (sm_scpu_context_key(cpu) != 0x04043840u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043840u: {
    static const uint8_t source_bytes[] = {0x65u, 0x3Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808708u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x3Eu);
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
    cpu->pc = 0x870Au;
    if (sm_scpu_context_key(cpu) != 0x04043850u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043850u: {
    static const uint8_t source_bytes[] = {0x69u, 0x46u, 0xA9u};
    if (sm_scpu_guard_code(cpu,bus,0x80870Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint16_t value = 0xA946u;
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + value + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((~(left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0x870Du;
    if (sm_scpu_context_key(cpu) != 0x04043868u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04043868u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80870Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4352u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8710u;
    if (sm_scpu_context_key(cpu) != 0x04043880u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04043880u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808710u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04043700u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04043AC3u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808758u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x875Au;
    if (sm_scpu_context_key(cpu) != 0x04043AD3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04043AD3u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x02u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80875Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2102u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x875Du;
    if (sm_scpu_context_key(cpu) != 0x04043AEBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043AEBu: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x03u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80875Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2103u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8760u;
    if (sm_scpu_context_key(cpu) != 0x04043B03u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B03u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x00u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808760u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4300u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8763u;
    if (sm_scpu_context_key(cpu) != 0x04043B1Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B1Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x808763u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8765u;
    if (sm_scpu_context_key(cpu) != 0x04043B2Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043B2Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808765u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4301u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8768u;
    if (sm_scpu_context_key(cpu) != 0x04043B43u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B43u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808768u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x876Au;
    if (sm_scpu_context_key(cpu) != 0x04043B53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043B53u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80876Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4302u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x876Du;
    if (sm_scpu_context_key(cpu) != 0x04043B6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B6Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x80876Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x876Fu;
    if (sm_scpu_context_key(cpu) != 0x04043B7Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043B7Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80876Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4303u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8772u;
    if (sm_scpu_context_key(cpu) != 0x04043B93u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043B93u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808772u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8774u;
    if (sm_scpu_context_key(cpu) != 0x04043BA3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043BA3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x04u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808774u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4304u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8777u;
    if (sm_scpu_context_key(cpu) != 0x04043BBBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043BBBu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808777u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8779u;
    if (sm_scpu_context_key(cpu) != 0x04043BCBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043BCBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808779u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4305u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x877Cu;
    if (sm_scpu_context_key(cpu) != 0x04043BE3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043BE3u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x80877Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x877Eu;
    if (sm_scpu_context_key(cpu) != 0x04043BF3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043BF3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80877Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4306u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8781u;
    if (sm_scpu_context_key(cpu) != 0x04043C0Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043C0Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x84u};
    if (sm_scpu_guard_code(cpu,bus,0x808781u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x84u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8783u;
    if (sm_scpu_context_key(cpu) != 0x04043C1Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043C1Bu: {
    static const uint8_t source_bytes[] = {0xF0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x808783u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x878Cu;
        cycles = 3u;
    } else {
        cpu->pc = 0x8785u;
    }
    if (sm_scpu_context_key(cpu) != 0x04043C2Bu && sm_scpu_context_key(cpu) != 0x04043C63u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x04043C2Bu: {
    static const uint8_t source_bytes[] = {0x64u, 0x84u};
    if (sm_scpu_guard_code(cpu,bus,0x808785u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x84u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8787u;
    if (sm_scpu_context_key(cpu) != 0x04043C3Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043C3Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x808787u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8789u;
    if (sm_scpu_context_key(cpu) != 0x04043C4Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04043C4Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808789u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x878Cu;
    if (sm_scpu_context_key(cpu) != 0x04043C63u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043C63u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x40u};
    if (sm_scpu_guard_code(cpu,bus,0x80878Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x40u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x878Eu;
    if (sm_scpu_context_key(cpu) != 0x04043C73u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043C73u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x00u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80878Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2100u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8791u;
    if (sm_scpu_context_key(cpu) != 0x04043C8Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043C8Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808791u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x42u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8793u;
    if (sm_scpu_context_key(cpu) != 0x04043C9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043C9Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808793u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2105u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8796u;
    if (sm_scpu_context_key(cpu) != 0x04043CB3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043CB3u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808796u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x43u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8798u;
    if (sm_scpu_context_key(cpu) != 0x04043CC3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043CC3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808798u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2106u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x879Bu;
    if (sm_scpu_context_key(cpu) != 0x04043CDBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043CDBu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x44u};
    if (sm_scpu_guard_code(cpu,bus,0x80879Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x44u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x879Du;
    if (sm_scpu_context_key(cpu) != 0x04043CEBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043CEBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x07u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80879Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2107u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87A0u;
    if (sm_scpu_context_key(cpu) != 0x04043D03u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043D03u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x45u};
    if (sm_scpu_guard_code(cpu,bus,0x8087A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x45u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87A2u;
    if (sm_scpu_context_key(cpu) != 0x04043D13u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043D13u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x08u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2108u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87A5u;
    if (sm_scpu_context_key(cpu) != 0x04043D2Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043D2Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x46u};
    if (sm_scpu_guard_code(cpu,bus,0x8087A5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x46u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87A7u;
    if (sm_scpu_context_key(cpu) != 0x04043D3Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043D3Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x09u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2109u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87AAu;
    if (sm_scpu_context_key(cpu) != 0x04043D53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043D53u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x47u};
    if (sm_scpu_guard_code(cpu,bus,0x8087AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x47u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87ACu;
    if (sm_scpu_context_key(cpu) != 0x04043D63u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043D63u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87AFu;
    if (sm_scpu_context_key(cpu) != 0x04043D7Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043D7Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x48u};
    if (sm_scpu_guard_code(cpu,bus,0x8087AFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x48u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87B1u;
    if (sm_scpu_context_key(cpu) != 0x04043D8Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043D8Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87B4u;
    if (sm_scpu_context_key(cpu) != 0x04043DA3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043DA3u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x49u};
    if (sm_scpu_guard_code(cpu,bus,0x8087B4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x49u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87B6u;
    if (sm_scpu_context_key(cpu) != 0x04043DB3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043DB3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087B6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87B9u;
    if (sm_scpu_context_key(cpu) != 0x04043DCBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043DCBu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x8087B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87BBu;
    if (sm_scpu_context_key(cpu) != 0x04043DDBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043DDBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87BEu;
    if (sm_scpu_context_key(cpu) != 0x04043DF3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043DF3u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x8087BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Bu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87C0u;
    if (sm_scpu_context_key(cpu) != 0x04043E03u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043E03u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87C3u;
    if (sm_scpu_context_key(cpu) != 0x04043E1Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043E1Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Cu};
    if (sm_scpu_guard_code(cpu,bus,0x8087C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87C5u;
    if (sm_scpu_context_key(cpu) != 0x04043E2Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043E2Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87C8u;
    if (sm_scpu_context_key(cpu) != 0x04043E43u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043E43u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Du};
    if (sm_scpu_guard_code(cpu,bus,0x8087C8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Du);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87CAu;
    if (sm_scpu_context_key(cpu) != 0x04043E53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043E53u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087CAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87CDu;
    if (sm_scpu_context_key(cpu) != 0x04043E6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043E6Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Eu};
    if (sm_scpu_guard_code(cpu,bus,0x8087CDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87CFu;
    if (sm_scpu_context_key(cpu) != 0x04043E7Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04043E7Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087CFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2101u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87D2u;
    if (sm_scpu_context_key(cpu) != 0x04043E93u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043E93u: {
    static const uint8_t source_bytes[] = {0xADu, 0x58u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0058u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87D5u;
    if (sm_scpu_context_key(cpu) != 0x04043EABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043EABu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x26u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087D5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2126u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87D8u;
    if (sm_scpu_context_key(cpu) != 0x04043EC3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043EC3u: {
    static const uint8_t source_bytes[] = {0xADu, 0x59u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0059u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87DBu;
    if (sm_scpu_context_key(cpu) != 0x04043EDBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043EDBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x27u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087DBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2127u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87DEu;
    if (sm_scpu_context_key(cpu) != 0x04043EF3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043EF3u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Au, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x005Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87E1u;
    if (sm_scpu_context_key(cpu) != 0x04043F0Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F0Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x28u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2128u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87E4u;
    if (sm_scpu_context_key(cpu) != 0x04043F23u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F23u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Bu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087E4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x005Bu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87E7u;
    if (sm_scpu_context_key(cpu) != 0x04043F3Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F3Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x29u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087E7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2129u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87EAu;
    if (sm_scpu_context_key(cpu) != 0x04043F53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F53u: {
    static const uint8_t source_bytes[] = {0xADu, 0x53u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0053u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87EDu;
    if (sm_scpu_context_key(cpu) != 0x04043F6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F6Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x25u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087EDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2125u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87F0u;
    if (sm_scpu_context_key(cpu) != 0x04043F83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F83u: {
    static const uint8_t source_bytes[] = {0xADu, 0x51u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0051u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87F3u;
    if (sm_scpu_context_key(cpu) != 0x04043F9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043F9Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x23u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2123u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87F6u;
    if (sm_scpu_context_key(cpu) != 0x04043FB3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043FB3u: {
    static const uint8_t source_bytes[] = {0xADu, 0x52u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0052u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87F9u;
    if (sm_scpu_context_key(cpu) != 0x04043FCBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043FCBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x24u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2124u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x87FCu;
    if (sm_scpu_context_key(cpu) != 0x04043FE3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043FE3u: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8087FCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x004Fu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x87FFu;
    if (sm_scpu_context_key(cpu) != 0x04043FFBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04043FFBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8087FFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8802u;
    if (sm_scpu_context_key(cpu) != 0x04044013u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044013u: {
    static const uint8_t source_bytes[] = {0xADu, 0x50u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808802u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0050u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8805u;
    if (sm_scpu_context_key(cpu) != 0x0404402Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404402Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808805u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8808u;
    if (sm_scpu_context_key(cpu) != 0x04044043u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044043u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x55u};
    if (sm_scpu_guard_code(cpu,bus,0x808808u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x55u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x880Au;
    if (sm_scpu_context_key(cpu) != 0x04044053u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04044053u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x30u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80880Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2130u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x880Du;
    if (sm_scpu_context_key(cpu) != 0x0404406Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404406Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x56u};
    if (sm_scpu_guard_code(cpu,bus,0x80880Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x56u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x880Fu;
    if (sm_scpu_context_key(cpu) != 0x0404407Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404407Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x31u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80880Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2131u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8812u;
    if (sm_scpu_context_key(cpu) != 0x04044093u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044093u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x57u};
    if (sm_scpu_guard_code(cpu,bus,0x808812u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x57u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8814u;
    if (sm_scpu_context_key(cpu) != 0x040440A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040440A3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x32u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808814u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2132u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8817u;
    if (sm_scpu_context_key(cpu) != 0x040440BBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040440BBu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x71u};
    if (sm_scpu_guard_code(cpu,bus,0x808817u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x71u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8819u;
    if (sm_scpu_context_key(cpu) != 0x040440CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040440CBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808819u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x881Cu;
    if (sm_scpu_context_key(cpu) != 0x040440E3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040440E3u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80881Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0404128Bu && sm_scpu_context_key(cpu) != 0x040413CBu && sm_scpu_context_key(cpu) != 0x04041523u && sm_scpu_context_key(cpu) != 0x04041AABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04044138u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808827u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8829u;
    if (sm_scpu_context_key(cpu) != 0x0404414Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404413Au: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808827u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8829u;
    if (sm_scpu_context_key(cpu) != 0x0404414Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404413Bu: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808827u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8829u;
    if (sm_scpu_context_key(cpu) != 0x0404414Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404414Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x7Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808829u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Bu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x882Bu;
    if (sm_scpu_context_key(cpu) != 0x0404415Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404414Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x7Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808829u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Bu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x882Bu;
    if (sm_scpu_context_key(cpu) != 0x0404415Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404415Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80882Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x882Du;
    if (sm_scpu_context_key(cpu) != 0x0404416Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404415Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80882Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x882Du;
    if (sm_scpu_context_key(cpu) != 0x0404416Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404416Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x80882Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x882Fu;
    if (sm_scpu_context_key(cpu) != 0x0404417Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404416Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x80882Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x882Fu;
    if (sm_scpu_context_key(cpu) != 0x0404417Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404417Au: {
    static const uint8_t source_bytes[] = {0xF0u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80882Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x8851u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8831u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404418Au && sm_scpu_context_key(cpu) != 0x0404428Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0404417Bu: {
    static const uint8_t source_bytes[] = {0xF0u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80882Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x8851u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8831u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404418Bu && sm_scpu_context_key(cpu) != 0x0404428Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0404418Au: {
    static const uint8_t source_bytes[] = {0x10u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x808831u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_N) == 0u) {
        cpu->pc = 0x8842u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8833u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404419Au && sm_scpu_context_key(cpu) != 0x04044212u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0404418Bu: {
    static const uint8_t source_bytes[] = {0x10u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x808831u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_N) == 0u) {
        cpu->pc = 0x8842u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8833u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404419Bu && sm_scpu_context_key(cpu) != 0x04044213u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0404419Au: {
    static const uint8_t source_bytes[] = {0xE6u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x808833u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    value = (uint8_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,address,value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8835u;
    if (sm_scpu_context_key(cpu) != 0x040441AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404419Bu: {
    static const uint8_t source_bytes[] = {0xE6u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x808833u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value + 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8835u;
    if (sm_scpu_context_key(cpu) != 0x040441ABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040441AAu: {
    static const uint8_t source_bytes[] = {0xC6u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808835u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8837u;
    if (sm_scpu_context_key(cpu) != 0x040441BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040441ABu: {
    static const uint8_t source_bytes[] = {0xC6u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808835u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8837u;
    if (sm_scpu_context_key(cpu) != 0x040441BBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040441BAu: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFAu};
    if (sm_scpu_guard_code(cpu,bus,0x808837u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x8833u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8839u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404419Au && sm_scpu_context_key(cpu) != 0x040441CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040441BBu: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFAu};
    if (sm_scpu_guard_code(cpu,bus,0x808837u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x8833u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8839u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404419Bu && sm_scpu_context_key(cpu) != 0x040441CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040441CAu: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x808839u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = left >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x883Au;
    if (sm_scpu_context_key(cpu) != 0x040441D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040441CBu: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x808839u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a & 0xFFu;
    uint16_t result = value >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (value & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x883Au;
    if (sm_scpu_context_key(cpu) != 0x040441D3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040441D2u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80883Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = left >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x883Bu;
    if (sm_scpu_context_key(cpu) != 0x040441DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040441D3u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80883Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a & 0xFFu;
    uint16_t result = value >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (value & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x883Bu;
    if (sm_scpu_context_key(cpu) != 0x040441DBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040441DAu: {
    static const uint8_t source_bytes[] = {0x49u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80883Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a ^ value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x883Du;
    if (sm_scpu_context_key(cpu) != 0x040441EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040441DBu: {
    static const uint8_t source_bytes[] = {0x49u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80883Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a ^ value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x883Du;
    if (sm_scpu_context_key(cpu) != 0x040441EBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040441EAu: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80883Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x883Fu;
    if (sm_scpu_context_key(cpu) != 0x040441FAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040441EBu: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80883Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x883Fu;
    if (sm_scpu_context_key(cpu) != 0x040441FBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040441FAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x70u};
    if (sm_scpu_guard_code(cpu,bus,0x80883Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x70u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8841u;
    if (sm_scpu_context_key(cpu) != 0x0404420Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040441FBu: {
    static const uint8_t source_bytes[] = {0x85u, 0x70u};
    if (sm_scpu_guard_code(cpu,bus,0x80883Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x70u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8841u;
    if (sm_scpu_context_key(cpu) != 0x0404420Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404420Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808841u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04044122u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0404420Bu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808841u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04044123u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04044212u: {
    static const uint8_t source_bytes[] = {0x3Au};
    if (sm_scpu_guard_code(cpu,bus,0x808842u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a & 0xFFu;
    uint16_t result = (value - 1u) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8843u;
    if (sm_scpu_context_key(cpu) != 0x0404421Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044213u: {
    static const uint8_t source_bytes[] = {0x3Au};
    if (sm_scpu_guard_code(cpu,bus,0x808842u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a & 0xFFu;
    uint16_t result = (value - 1u) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8843u;
    if (sm_scpu_context_key(cpu) != 0x0404421Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404421Au: {
    static const uint8_t source_bytes[] = {0xC6u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808843u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8845u;
    if (sm_scpu_context_key(cpu) != 0x0404422Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404421Bu: {
    static const uint8_t source_bytes[] = {0xC6u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808843u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8845u;
    if (sm_scpu_context_key(cpu) != 0x0404422Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404422Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0x808845u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x8842u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8847u;
    }
    if (sm_scpu_context_key(cpu) != 0x04044212u && sm_scpu_context_key(cpu) != 0x0404423Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0404422Bu: {
    static const uint8_t source_bytes[] = {0xD0u, 0xFBu};
    if (sm_scpu_guard_code(cpu,bus,0x808845u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x8842u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8847u;
    }
    if (sm_scpu_context_key(cpu) != 0x04044213u && sm_scpu_context_key(cpu) != 0x0404423Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0404423Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x808847u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8849u;
    if (sm_scpu_context_key(cpu) != 0x0404424Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404423Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x808847u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8849u;
    if (sm_scpu_context_key(cpu) != 0x0404424Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404424Au: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x808849u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = left >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x884Au;
    if (sm_scpu_context_key(cpu) != 0x04044252u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404424Bu: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x808849u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a & 0xFFu;
    uint16_t result = value >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (value & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x884Au;
    if (sm_scpu_context_key(cpu) != 0x04044253u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044252u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80884Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a & 0xFFu;
    uint16_t result = left >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x884Bu;
    if (sm_scpu_context_key(cpu) != 0x0404425Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044253u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80884Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = cpu->a & 0xFFu;
    uint16_t result = value >> 1u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (value & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x884Bu;
    if (sm_scpu_context_key(cpu) != 0x0404425Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404425Au: {
    static const uint8_t source_bytes[] = {0x49u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80884Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a ^ value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x884Du;
    if (sm_scpu_context_key(cpu) != 0x0404426Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404425Bu: {
    static const uint8_t source_bytes[] = {0x49u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80884Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a ^ value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x884Du;
    if (sm_scpu_context_key(cpu) != 0x0404426Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404426Au: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80884Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x884Fu;
    if (sm_scpu_context_key(cpu) != 0x0404427Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404426Bu: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80884Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Fu;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x884Fu;
    if (sm_scpu_context_key(cpu) != 0x0404427Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404427Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x70u};
    if (sm_scpu_guard_code(cpu,bus,0x80884Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x70u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8851u;
    if (sm_scpu_context_key(cpu) != 0x0404428Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404427Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x70u};
    if (sm_scpu_guard_code(cpu,bus,0x80884Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x70u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8851u;
    if (sm_scpu_context_key(cpu) != 0x0404428Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404428Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808851u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04044122u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0404428Bu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808851u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04044123u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04044328u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x808865u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8866u;
    if (sm_scpu_context_key(cpu) != 0x04044330u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044330u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808866u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8867u;
    if (sm_scpu_context_key(cpu) != 0x04044338u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044338u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808867u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8868u;
    if (sm_scpu_context_key(cpu) != 0x04044340u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044340u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808868u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8869u;
    if (sm_scpu_context_key(cpu) != 0x04044348u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044348u: {
    static const uint8_t source_bytes[] = {0x20u, 0xEAu, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x808869u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x886Bu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x88EAu;
    if (sm_scpu_context_key(cpu) != 0x04044750u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04044362u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80886Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x886Du;
    if (sm_scpu_context_key(cpu) != 0x0404436Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404436Au: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x80886Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x886Eu;
    if (sm_scpu_context_key(cpu) != 0x04044370u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044370u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80886Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x041C0D40u && sm_scpu_context_key(cpu) != 0x041C96E0u && sm_scpu_context_key(cpu) != 0x041E9090u && sm_scpu_context_key(cpu) != 0x041EA6A0u && sm_scpu_context_key(cpu) != 0x041EE598u && sm_scpu_context_key(cpu) != 0x041F4FE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04044378u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x80886Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8870u;
    if (sm_scpu_context_key(cpu) != 0x04044380u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044380u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808870u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8871u;
    if (sm_scpu_context_key(cpu) != 0x04044388u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044388u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808871u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8872u;
    if (sm_scpu_context_key(cpu) != 0x04044390u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044390u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808872u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8873u;
    if (sm_scpu_context_key(cpu) != 0x04044398u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044398u: {
    static const uint8_t source_bytes[] = {0x20u, 0xEAu, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x808873u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x8875u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x88EAu;
    if (sm_scpu_context_key(cpu) != 0x04044750u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040443B2u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808876u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8877u;
    if (sm_scpu_context_key(cpu) != 0x040443BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040443BAu: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x808877u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8878u;
    if (sm_scpu_context_key(cpu) != 0x040443C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040443C0u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808878u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040C0448u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040443C8u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x808879u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x887Au;
    if (sm_scpu_context_key(cpu) != 0x040443D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040443D0u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80887Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x887Bu;
    if (sm_scpu_context_key(cpu) != 0x040443D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040443D8u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80887Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x887Cu;
    if (sm_scpu_context_key(cpu) != 0x040443E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040443E0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80887Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x887Du;
    if (sm_scpu_context_key(cpu) != 0x040443E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040443E8u: {
    static const uint8_t source_bytes[] = {0x20u, 0x83u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x80887Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x887Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8883u;
    if (sm_scpu_context_key(cpu) != 0x04044418u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04044402u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808880u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8881u;
    if (sm_scpu_context_key(cpu) != 0x0404440Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404440Au: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x808881u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8882u;
    if (sm_scpu_context_key(cpu) != 0x04044410u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044410u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808882u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04240170u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04044753u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x8088EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x88ECu;
    if (sm_scpu_context_key(cpu) != 0x04044763u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044763u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8088ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x88EEu;
    if (sm_scpu_context_key(cpu) != 0x04044773u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044773u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x16u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8088EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2116u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x88F1u;
    if (sm_scpu_context_key(cpu) != 0x0404478Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404478Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8088F1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x88F3u;
    if (sm_scpu_context_key(cpu) != 0x0404479Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404479Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x17u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8088F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2117u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x88F6u;
    if (sm_scpu_context_key(cpu) != 0x040447B3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040447B3u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x09u};
    if (sm_scpu_guard_code(cpu,bus,0x8088F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0009u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x88F8u;
    if (sm_scpu_context_key(cpu) != 0x040447C3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040447C3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x00u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x8088F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4300u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x88FBu;
    if (sm_scpu_context_key(cpu) != 0x040447DBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040447DBu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x8088FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0018u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x88FDu;
    if (sm_scpu_context_key(cpu) != 0x040447EBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040447EBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x8088FDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4301u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8900u;
    if (sm_scpu_context_key(cpu) != 0x04044803u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044803u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x808900u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x001Fu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8902u;
    if (sm_scpu_context_key(cpu) != 0x04044813u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044813u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808902u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4302u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8905u;
    if (sm_scpu_context_key(cpu) != 0x0404482Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404482Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x89u};
    if (sm_scpu_guard_code(cpu,bus,0x808905u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0089u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8907u;
    if (sm_scpu_context_key(cpu) != 0x0404483Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404483Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808907u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4303u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x890Au;
    if (sm_scpu_context_key(cpu) != 0x04044853u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044853u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80890Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x890Cu;
    if (sm_scpu_context_key(cpu) != 0x04044863u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044863u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x04u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80890Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4304u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x890Fu;
    if (sm_scpu_context_key(cpu) != 0x0404487Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404487Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80890Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8911u;
    if (sm_scpu_context_key(cpu) != 0x0404488Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404488Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808911u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4305u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8914u;
    if (sm_scpu_context_key(cpu) != 0x040448A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040448A3u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808914u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8916u;
    if (sm_scpu_context_key(cpu) != 0x040448B3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040448B3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808916u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4306u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8919u;
    if (sm_scpu_context_key(cpu) != 0x040448CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040448CBu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x808919u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x891Bu;
    if (sm_scpu_context_key(cpu) != 0x040448DBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040448DBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x80891Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x891Eu;
    if (sm_scpu_context_key(cpu) != 0x040448F3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040448F3u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80891Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040442E3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04044A48u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808949u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x894Bu;
    if (sm_scpu_context_key(cpu) != 0x04044A5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044A4Au: {
    static const uint8_t source_bytes[] = {0xE2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808949u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x894Bu;
    if (sm_scpu_context_key(cpu) != 0x04044A5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04044A5Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x8Fu};
    if (sm_scpu_guard_code(cpu,bus,0x80894Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x008Fu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x894Du;
    if (sm_scpu_context_key(cpu) != 0x04044A6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044A6Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x00u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80894Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2100u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8950u;
    if (sm_scpu_context_key(cpu) != 0x04044A83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044A83u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x00u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808950u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4200u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8953u;
    if (sm_scpu_context_key(cpu) != 0x04044A9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044A9Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808953u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8955u;
    if (sm_scpu_context_key(cpu) != 0x04044AABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044AABu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808955u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2101u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8958u;
    if (sm_scpu_context_key(cpu) != 0x04044AC3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044AC3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808958u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2102u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x895Bu;
    if (sm_scpu_context_key(cpu) != 0x04044ADBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044ADBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80895Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2103u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x895Eu;
    if (sm_scpu_context_key(cpu) != 0x04044AF3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044AF3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80895Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2105u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8961u;
    if (sm_scpu_context_key(cpu) != 0x04044B0Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044B0Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808961u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2106u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8964u;
    if (sm_scpu_context_key(cpu) != 0x04044B23u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044B23u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x07u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808964u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2107u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8967u;
    if (sm_scpu_context_key(cpu) != 0x04044B3Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044B3Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x08u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808967u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2108u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x896Au;
    if (sm_scpu_context_key(cpu) != 0x04044B53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044B53u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x09u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80896Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2109u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x896Du;
    if (sm_scpu_context_key(cpu) != 0x04044B6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044B6Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80896Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8970u;
    if (sm_scpu_context_key(cpu) != 0x04044B83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044B83u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808970u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8973u;
    if (sm_scpu_context_key(cpu) != 0x04044B9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044B9Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808973u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8976u;
    if (sm_scpu_context_key(cpu) != 0x04044BB3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044BB3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808976u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8979u;
    if (sm_scpu_context_key(cpu) != 0x04044BCBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044BCBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808979u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x897Cu;
    if (sm_scpu_context_key(cpu) != 0x04044BE3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044BE3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80897Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x897Fu;
    if (sm_scpu_context_key(cpu) != 0x04044BFBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044BFBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x10u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80897Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2110u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8982u;
    if (sm_scpu_context_key(cpu) != 0x04044C13u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044C13u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x11u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808982u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2111u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8985u;
    if (sm_scpu_context_key(cpu) != 0x04044C2Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044C2Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x12u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808985u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2112u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8988u;
    if (sm_scpu_context_key(cpu) != 0x04044C43u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044C43u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x13u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808988u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2113u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x898Bu;
    if (sm_scpu_context_key(cpu) != 0x04044C5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044C5Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x14u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80898Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2114u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x898Eu;
    if (sm_scpu_context_key(cpu) != 0x04044C73u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044C73u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80898Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8990u;
    if (sm_scpu_context_key(cpu) != 0x04044C83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044C83u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x15u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808990u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2115u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8993u;
    if (sm_scpu_context_key(cpu) != 0x04044C9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044C9Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808993u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8995u;
    if (sm_scpu_context_key(cpu) != 0x04044CABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044CABu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808995u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8998u;
    if (sm_scpu_context_key(cpu) != 0x04044CC3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044CC3u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808998u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x899Au;
    if (sm_scpu_context_key(cpu) != 0x04044CD3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044CD3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80899Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x899Du;
    if (sm_scpu_context_key(cpu) != 0x04044CEBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044CEBu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80899Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x899Fu;
    if (sm_scpu_context_key(cpu) != 0x04044CFBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044CFBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80899Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89A2u;
    if (sm_scpu_context_key(cpu) != 0x04044D13u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044D13u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8089A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x89A4u;
    if (sm_scpu_context_key(cpu) != 0x04044D23u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044D23u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89A7u;
    if (sm_scpu_context_key(cpu) != 0x04044D3Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044D3Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89AAu;
    if (sm_scpu_context_key(cpu) != 0x04044D53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044D53u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089AAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89ADu;
    if (sm_scpu_context_key(cpu) != 0x04044D6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044D6Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089ADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89B0u;
    if (sm_scpu_context_key(cpu) != 0x04044D83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044D83u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8089B0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x89B2u;
    if (sm_scpu_context_key(cpu) != 0x04044D93u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044D93u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089B2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89B5u;
    if (sm_scpu_context_key(cpu) != 0x04044DABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044DABu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x8089B5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x89B7u;
    if (sm_scpu_context_key(cpu) != 0x04044DBBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044DBBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89BAu;
    if (sm_scpu_context_key(cpu) != 0x04044DD3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044DD3u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8089BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x89BCu;
    if (sm_scpu_context_key(cpu) != 0x04044DE3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044DE3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89BFu;
    if (sm_scpu_context_key(cpu) != 0x04044DFBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044DFBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89C2u;
    if (sm_scpu_context_key(cpu) != 0x04044E13u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044E13u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x20u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089C2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2120u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89C5u;
    if (sm_scpu_context_key(cpu) != 0x04044E2Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044E2Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x20u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2120u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89C8u;
    if (sm_scpu_context_key(cpu) != 0x04044E43u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044E43u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x23u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089C8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2123u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89CBu;
    if (sm_scpu_context_key(cpu) != 0x04044E5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044E5Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x24u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089CBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2124u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89CEu;
    if (sm_scpu_context_key(cpu) != 0x04044E73u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044E73u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x25u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2125u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89D1u;
    if (sm_scpu_context_key(cpu) != 0x04044E8Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044E8Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x26u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2126u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89D4u;
    if (sm_scpu_context_key(cpu) != 0x04044EA3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044EA3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x27u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2127u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89D7u;
    if (sm_scpu_context_key(cpu) != 0x04044EBBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044EBBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x28u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089D7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2128u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89DAu;
    if (sm_scpu_context_key(cpu) != 0x04044ED3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044ED3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x29u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2129u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89DDu;
    if (sm_scpu_context_key(cpu) != 0x04044EEBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044EEBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089DDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89E0u;
    if (sm_scpu_context_key(cpu) != 0x04044F03u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044F03u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089E0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89E3u;
    if (sm_scpu_context_key(cpu) != 0x04044F1Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044F1Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89E6u;
    if (sm_scpu_context_key(cpu) != 0x04044F33u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044F33u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089E6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89E9u;
    if (sm_scpu_context_key(cpu) != 0x04044F4Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044F4Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89ECu;
    if (sm_scpu_context_key(cpu) != 0x04044F63u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044F63u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89EFu;
    if (sm_scpu_context_key(cpu) != 0x04044F7Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044F7Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8089EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0030u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x89F1u;
    if (sm_scpu_context_key(cpu) != 0x04044F8Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044F8Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x30u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089F1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2130u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89F4u;
    if (sm_scpu_context_key(cpu) != 0x04044FA3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044FA3u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8089F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x89F6u;
    if (sm_scpu_context_key(cpu) != 0x04044FB3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044FB3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x31u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2131u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89F9u;
    if (sm_scpu_context_key(cpu) != 0x04044FCBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044FCBu: {
    static const uint8_t source_bytes[] = {0xA9u, 0xE0u};
    if (sm_scpu_guard_code(cpu,bus,0x8089F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00E0u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x89FBu;
    if (sm_scpu_context_key(cpu) != 0x04044FDBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04044FDBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x32u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8089FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2132u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x89FEu;
    if (sm_scpu_context_key(cpu) != 0x04044FF3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04044FF3u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8089FEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A00u;
    if (sm_scpu_context_key(cpu) != 0x04045003u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045003u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x33u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808A00u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2133u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A03u;
    if (sm_scpu_context_key(cpu) != 0x0404501Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404501Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x808A03u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A05u;
    if (sm_scpu_context_key(cpu) != 0x0404502Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404502Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A05u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4201u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A08u;
    if (sm_scpu_context_key(cpu) != 0x04045043u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045043u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808A08u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A0Au;
    if (sm_scpu_context_key(cpu) != 0x04045053u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045053u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A0Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4202u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A0Du;
    if (sm_scpu_context_key(cpu) != 0x0404506Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404506Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A0Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4203u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A10u;
    if (sm_scpu_context_key(cpu) != 0x04045083u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045083u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x04u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A10u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4204u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A13u;
    if (sm_scpu_context_key(cpu) != 0x0404509Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404509Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A13u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4205u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A16u;
    if (sm_scpu_context_key(cpu) != 0x040450B3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040450B3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A16u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4206u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A19u;
    if (sm_scpu_context_key(cpu) != 0x040450CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040450CBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x07u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A19u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4207u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A1Cu;
    if (sm_scpu_context_key(cpu) != 0x040450E3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040450E3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x08u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A1Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4208u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A1Fu;
    if (sm_scpu_context_key(cpu) != 0x040450FBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040450FBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x09u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A1Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4209u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A22u;
    if (sm_scpu_context_key(cpu) != 0x04045113u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045113u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Au, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A22u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A25u;
    if (sm_scpu_context_key(cpu) != 0x0404512Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404512Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A25u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A28u;
    if (sm_scpu_context_key(cpu) != 0x04045143u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045143u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Cu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A28u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A2Bu;
    if (sm_scpu_context_key(cpu) != 0x0404515Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404515Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x808A2Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A2Du;
    if (sm_scpu_context_key(cpu) != 0x0404516Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404516Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Du, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A2Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A30u;
    if (sm_scpu_context_key(cpu) != 0x04045183u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045183u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808A30u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040442CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045240u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808A48u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8A49u;
    if (sm_scpu_context_key(cpu) != 0x04045248u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045242u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808A48u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8A49u;
    if (sm_scpu_context_key(cpu) != 0x0404524Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045248u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808A49u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8A4Au;
    if (sm_scpu_context_key(cpu) != 0x04045250u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404524Au: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808A49u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8A4Au;
    if (sm_scpu_context_key(cpu) != 0x04045252u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045250u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808A4Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A4Bu;
    if (sm_scpu_context_key(cpu) != 0x04045258u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045252u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808A4Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A4Bu;
    if (sm_scpu_context_key(cpu) != 0x0404525Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045258u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808A4Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8A4Du;
    if (sm_scpu_context_key(cpu) != 0x04045268u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404525Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808A4Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8A4Du;
    if (sm_scpu_context_key(cpu) != 0x04045268u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045268u: {
    static const uint8_t source_bytes[] = {0x64u, 0x86u};
    if (sm_scpu_guard_code(cpu,bus,0x808A4Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x86u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A4Fu;
    if (sm_scpu_context_key(cpu) != 0x04045278u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045278u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x00u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x808A4Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0200u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A52u;
    if (sm_scpu_context_key(cpu) != 0x04045290u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04045290u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x00u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x808A52u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0200u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A55u;
    if (sm_scpu_context_key(cpu) != 0x040452A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040452A8u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x01u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x808A55u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0201u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A58u;
    if (sm_scpu_context_key(cpu) != 0x040452C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040452C0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x1Eu, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x808A58u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x021Eu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A5Bu;
    if (sm_scpu_context_key(cpu) != 0x040452D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040452D8u: {
    static const uint8_t source_bytes[] = {0x54u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808A5Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t payload;
    if (sm_scpu_read8(cpu,bus,(0x00u << 16u) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(0x00u << 16u) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = 0x00u;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0x8A5Eu;
        if (sm_scpu_context_key(cpu) != 0x040452F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    } else {
        cpu->pc = 0x8A5Bu;
        if (sm_scpu_context_key(cpu) != 0x040452D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x040452F0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808A5Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A5Fu;
    if (sm_scpu_context_key(cpu) != 0x040452F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040452F8u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808A5Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040C0110u && sm_scpu_context_key(cpu) != 0x040C1140u && sm_scpu_context_key(cpu) != 0x040C11E8u && sm_scpu_context_key(cpu) != 0x040E3DF8u && sm_scpu_context_key(cpu) != 0x0415D5F0u && sm_scpu_context_key(cpu) != 0x041C10F0u && sm_scpu_context_key(cpu) != 0x041C9968u && sm_scpu_context_key(cpu) != 0x041E9308u && sm_scpu_context_key(cpu) != 0x041EAA20u && sm_scpu_context_key(cpu) != 0x041EE800u && sm_scpu_context_key(cpu) != 0x041F5250u && sm_scpu_context_key(cpu) != 0x043D6288u && sm_scpu_context_key(cpu) != 0x043D7BB8u && sm_scpu_context_key(cpu) != 0x043D84F8u && sm_scpu_context_key(cpu) != 0x043D8A38u && sm_scpu_context_key(cpu) != 0x043D9218u && sm_scpu_context_key(cpu) != 0x043D9A58u && sm_scpu_context_key(cpu) != 0x043DA2A8u && sm_scpu_context_key(cpu) != 0x043DAC20u && sm_scpu_context_key(cpu) != 0x043DAD48u && sm_scpu_context_key(cpu) != 0x043DB728u && sm_scpu_context_key(cpu) != 0x043DD708u && sm_scpu_context_key(cpu) != 0x043E0DB0u && sm_scpu_context_key(cpu) != 0x043E1180u && sm_scpu_context_key(cpu) != 0x043E3C18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045302u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808A60u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8A62u;
    if (sm_scpu_context_key(cpu) != 0x04045312u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045303u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808A60u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8A62u;
    if (sm_scpu_context_key(cpu) != 0x04045313u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045312u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808A62u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8A64u;
    if (sm_scpu_context_key(cpu) != 0x04045322u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045313u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808A62u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8A64u;
    if (sm_scpu_context_key(cpu) != 0x04045322u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045322u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x21u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808A64u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2121u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A67u;
    if (sm_scpu_context_key(cpu) != 0x0404533Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404533Au: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x00u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808A67u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4300u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A6Au;
    if (sm_scpu_context_key(cpu) != 0x04045352u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045352u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x808A6Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0022u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A6Cu;
    if (sm_scpu_context_key(cpu) != 0x04045362u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045362u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808A6Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4301u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A6Fu;
    if (sm_scpu_context_key(cpu) != 0x0404537Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404537Au: {
    static const uint8_t source_bytes[] = {0xACu, 0x40u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x808A6Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0740u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A72u;
    if (sm_scpu_context_key(cpu) != 0x04045392u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04045392u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x02u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808A72u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4302u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A75u;
    if (sm_scpu_context_key(cpu) != 0x040453AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040453AAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808A75u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A77u;
    if (sm_scpu_context_key(cpu) != 0x040453BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040453BAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x04u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808A77u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4304u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A7Au;
    if (sm_scpu_context_key(cpu) != 0x040453D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040453D2u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x808A7Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0200u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A7Du;
    if (sm_scpu_context_key(cpu) != 0x040453EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040453EAu: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x05u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x808A7Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4305u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A80u;
    if (sm_scpu_context_key(cpu) != 0x04045402u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04045402u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x808A80u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A82u;
    if (sm_scpu_context_key(cpu) != 0x04045412u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045412u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A82u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A85u;
    if (sm_scpu_context_key(cpu) != 0x0404542Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404542Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808A85u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040407D2u && sm_scpu_context_key(cpu) != 0x04040C6Au && sm_scpu_context_key(cpu) != 0x040412A2u && sm_scpu_context_key(cpu) != 0x040413E2u && sm_scpu_context_key(cpu) != 0x0404153Au && sm_scpu_context_key(cpu) != 0x040416B2u && sm_scpu_context_key(cpu) != 0x040418CAu && sm_scpu_context_key(cpu) != 0x04041AC2u && sm_scpu_context_key(cpu) != 0x04041C4Au && sm_scpu_context_key(cpu) != 0x04044312u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045430u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x808A86u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8A87u;
    if (sm_scpu_context_key(cpu) != 0x04045438u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045438u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808A87u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8A88u;
    if (sm_scpu_context_key(cpu) != 0x04045440u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045440u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808A88u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8A89u;
    if (sm_scpu_context_key(cpu) != 0x04045448u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045448u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808A89u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A8Au;
    if (sm_scpu_context_key(cpu) != 0x04045450u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045450u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808A8Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8A8Cu;
    if (sm_scpu_context_key(cpu) != 0x04045460u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045460u: {
    static const uint8_t source_bytes[] = {0x86u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808A8Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->x) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A8Eu;
    if (sm_scpu_context_key(cpu) != 0x04045470u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045470u: {
    static const uint8_t source_bytes[] = {0x84u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x808A8Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x12u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A90u;
    if (sm_scpu_context_key(cpu) != 0x04045480u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045480u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808A90u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8A92u;
    if (sm_scpu_context_key(cpu) != 0x04045493u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045493u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808A92u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A94u;
    if (sm_scpu_context_key(cpu) != 0x040454A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040454A3u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808A94u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8A96u;
    if (sm_scpu_context_key(cpu) != 0x040454B3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040454B3u: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808A96u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A98u;
    if (sm_scpu_context_key(cpu) != 0x040454C3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040454C3u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808A98u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A99u;
    if (sm_scpu_context_key(cpu) != 0x040454CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040454CBu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808A99u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8A9Bu;
    if (sm_scpu_context_key(cpu) != 0x040454DBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040454DBu: {
    static const uint8_t source_bytes[] = {0x85u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808A9Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x42u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8A9Du;
    if (sm_scpu_context_key(cpu) != 0x040454EBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040454EBu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808A9Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8A9Eu;
    if (sm_scpu_context_key(cpu) != 0x040454F3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040454F3u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808A9Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AA0u;
    if (sm_scpu_context_key(cpu) != 0x04045503u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045503u: {
    static const uint8_t source_bytes[] = {0x85u, 0x44u};
    if (sm_scpu_guard_code(cpu,bus,0x808AA0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x44u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AA2u;
    if (sm_scpu_context_key(cpu) != 0x04045513u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045513u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AA2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AA3u;
    if (sm_scpu_context_key(cpu) != 0x0404551Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404551Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AA3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AA5u;
    if (sm_scpu_context_key(cpu) != 0x0404552Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404552Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x45u};
    if (sm_scpu_guard_code(cpu,bus,0x808AA5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x45u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AA7u;
    if (sm_scpu_context_key(cpu) != 0x0404553Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404553Bu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AA7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AA8u;
    if (sm_scpu_context_key(cpu) != 0x04045543u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045543u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AA8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AAAu;
    if (sm_scpu_context_key(cpu) != 0x04045553u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045553u: {
    static const uint8_t source_bytes[] = {0x85u, 0x46u};
    if (sm_scpu_guard_code(cpu,bus,0x808AAAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x46u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AACu;
    if (sm_scpu_context_key(cpu) != 0x04045563u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045563u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AADu;
    if (sm_scpu_context_key(cpu) != 0x0404556Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404556Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AAFu;
    if (sm_scpu_context_key(cpu) != 0x0404557Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404557Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x47u};
    if (sm_scpu_guard_code(cpu,bus,0x808AAFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x47u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AB1u;
    if (sm_scpu_context_key(cpu) != 0x0404558Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404558Bu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AB1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AB2u;
    if (sm_scpu_context_key(cpu) != 0x04045593u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045593u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AB2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AB4u;
    if (sm_scpu_context_key(cpu) != 0x040455A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040455A3u: {
    static const uint8_t source_bytes[] = {0x85u, 0x48u};
    if (sm_scpu_guard_code(cpu,bus,0x808AB4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x48u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AB6u;
    if (sm_scpu_context_key(cpu) != 0x040455B3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040455B3u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AB6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AB7u;
    if (sm_scpu_context_key(cpu) != 0x040455BBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040455BBu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AB7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AB9u;
    if (sm_scpu_context_key(cpu) != 0x040455CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040455CBu: {
    static const uint8_t source_bytes[] = {0x85u, 0x49u};
    if (sm_scpu_guard_code(cpu,bus,0x808AB9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x49u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8ABBu;
    if (sm_scpu_context_key(cpu) != 0x040455DBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040455DBu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808ABBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8ABCu;
    if (sm_scpu_context_key(cpu) != 0x040455E3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040455E3u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808ABCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8ABEu;
    if (sm_scpu_context_key(cpu) != 0x040455F3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040455F3u: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x808ABEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AC0u;
    if (sm_scpu_context_key(cpu) != 0x04045603u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045603u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AC0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AC1u;
    if (sm_scpu_context_key(cpu) != 0x0404560Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404560Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AC1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AC3u;
    if (sm_scpu_context_key(cpu) != 0x0404561Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404561Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808AC3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AC5u;
    if (sm_scpu_context_key(cpu) != 0x0404562Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404562Bu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AC5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AC6u;
    if (sm_scpu_context_key(cpu) != 0x04045633u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045633u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AC6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AC8u;
    if (sm_scpu_context_key(cpu) != 0x04045643u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045643u: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808AC8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8ACAu;
    if (sm_scpu_context_key(cpu) != 0x04045653u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045653u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808ACAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8ACBu;
    if (sm_scpu_context_key(cpu) != 0x0404565Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404565Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808ACBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8ACDu;
    if (sm_scpu_context_key(cpu) != 0x0404566Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404566Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Du};
    if (sm_scpu_guard_code(cpu,bus,0x808ACDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8ACFu;
    if (sm_scpu_context_key(cpu) != 0x0404567Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404567Bu: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808ACFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AD0u;
    if (sm_scpu_context_key(cpu) != 0x04045683u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045683u: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x808AD0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8AD1u;
    if (sm_scpu_context_key(cpu) != 0x04045688u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045688u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808AD1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040C0B08u && sm_scpu_context_key(cpu) != 0x040C0DD8u && sm_scpu_context_key(cpu) != 0x041C0DC0u && sm_scpu_context_key(cpu) != 0x041C9760u && sm_scpu_context_key(cpu) != 0x041E9110u && sm_scpu_context_key(cpu) != 0x041EA720u && sm_scpu_context_key(cpu) != 0x041EE618u && sm_scpu_context_key(cpu) != 0x041F5068u && sm_scpu_context_key(cpu) != 0x04240150u && sm_scpu_context_key(cpu) != 0x043D6F20u && sm_scpu_context_key(cpu) != 0x043D8CE8u && sm_scpu_context_key(cpu) != 0x043D94A0u && sm_scpu_context_key(cpu) != 0x043D9CE0u && sm_scpu_context_key(cpu) != 0x043DA530u && sm_scpu_context_key(cpu) != 0x043DF2C8u && sm_scpu_context_key(cpu) != 0x043DF5A8u && sm_scpu_context_key(cpu) != 0x043E0900u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045690u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x808AD2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8AD3u;
    if (sm_scpu_context_key(cpu) != 0x04045698u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045698u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808AD3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8AD4u;
    if (sm_scpu_context_key(cpu) != 0x040456A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040456A0u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808AD4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8AD5u;
    if (sm_scpu_context_key(cpu) != 0x040456A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040456A8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808AD5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AD6u;
    if (sm_scpu_context_key(cpu) != 0x040456B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040456B0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808AD6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8AD8u;
    if (sm_scpu_context_key(cpu) != 0x040456C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040456C0u: {
    static const uint8_t source_bytes[] = {0x86u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AD8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x10u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->x) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8ADAu;
    if (sm_scpu_context_key(cpu) != 0x040456D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040456D0u: {
    static const uint8_t source_bytes[] = {0x84u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x808ADAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x12u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->y >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8ADCu;
    if (sm_scpu_context_key(cpu) != 0x040456E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040456E0u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808ADCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8ADEu;
    if (sm_scpu_context_key(cpu) != 0x040456F3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040456F3u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x808ADEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AE0u;
    if (sm_scpu_context_key(cpu) != 0x04045703u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045703u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AE0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AE2u;
    if (sm_scpu_context_key(cpu) != 0x04045713u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045713u: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808AE2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AE4u;
    if (sm_scpu_context_key(cpu) != 0x04045723u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045723u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AE4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AE5u;
    if (sm_scpu_context_key(cpu) != 0x0404572Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404572Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AE5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AE7u;
    if (sm_scpu_context_key(cpu) != 0x0404573Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404573Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808AE7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x42u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AE9u;
    if (sm_scpu_context_key(cpu) != 0x0404574Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404574Bu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AE9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AEAu;
    if (sm_scpu_context_key(cpu) != 0x04045753u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045753u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AEAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AECu;
    if (sm_scpu_context_key(cpu) != 0x04045763u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045763u: {
    static const uint8_t source_bytes[] = {0x85u, 0x44u};
    if (sm_scpu_guard_code(cpu,bus,0x808AECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x44u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AEEu;
    if (sm_scpu_context_key(cpu) != 0x04045773u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045773u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AEEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AEFu;
    if (sm_scpu_context_key(cpu) != 0x0404577Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404577Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AEFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AF1u;
    if (sm_scpu_context_key(cpu) != 0x0404578Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404578Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x45u};
    if (sm_scpu_guard_code(cpu,bus,0x808AF1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x45u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AF3u;
    if (sm_scpu_context_key(cpu) != 0x0404579Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404579Bu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AF3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AF4u;
    if (sm_scpu_context_key(cpu) != 0x040457A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040457A3u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AF4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AF6u;
    if (sm_scpu_context_key(cpu) != 0x040457B3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040457B3u: {
    static const uint8_t source_bytes[] = {0x85u, 0x46u};
    if (sm_scpu_guard_code(cpu,bus,0x808AF6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x46u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AF8u;
    if (sm_scpu_context_key(cpu) != 0x040457C3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040457C3u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AF8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AF9u;
    if (sm_scpu_context_key(cpu) != 0x040457CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040457CBu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AF9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8AFBu;
    if (sm_scpu_context_key(cpu) != 0x040457DBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040457DBu: {
    static const uint8_t source_bytes[] = {0x85u, 0x47u};
    if (sm_scpu_guard_code(cpu,bus,0x808AFBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x47u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8AFDu;
    if (sm_scpu_context_key(cpu) != 0x040457EBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040457EBu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808AFDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8AFEu;
    if (sm_scpu_context_key(cpu) != 0x040457F3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040457F3u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808AFEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B00u;
    if (sm_scpu_context_key(cpu) != 0x04045803u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045803u: {
    static const uint8_t source_bytes[] = {0x85u, 0x48u};
    if (sm_scpu_guard_code(cpu,bus,0x808B00u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x48u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B02u;
    if (sm_scpu_context_key(cpu) != 0x04045813u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045813u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808B02u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B03u;
    if (sm_scpu_context_key(cpu) != 0x0404581Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404581Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808B03u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B05u;
    if (sm_scpu_context_key(cpu) != 0x0404582Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404582Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x49u};
    if (sm_scpu_guard_code(cpu,bus,0x808B05u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x49u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B07u;
    if (sm_scpu_context_key(cpu) != 0x0404583Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404583Bu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808B07u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B08u;
    if (sm_scpu_context_key(cpu) != 0x04045843u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045843u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808B08u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B0Au;
    if (sm_scpu_context_key(cpu) != 0x04045853u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045853u: {
    static const uint8_t source_bytes[] = {0x85u, 0x71u};
    if (sm_scpu_guard_code(cpu,bus,0x808B0Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x71u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B0Cu;
    if (sm_scpu_context_key(cpu) != 0x04045863u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045863u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808B0Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B0Du;
    if (sm_scpu_context_key(cpu) != 0x0404586Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404586Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808B0Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B0Fu;
    if (sm_scpu_context_key(cpu) != 0x0404587Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404587Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B0Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B11u;
    if (sm_scpu_context_key(cpu) != 0x0404588Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404588Bu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808B11u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B12u;
    if (sm_scpu_context_key(cpu) != 0x04045893u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045893u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808B12u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B14u;
    if (sm_scpu_context_key(cpu) != 0x040458A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040458A3u: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808B14u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B16u;
    if (sm_scpu_context_key(cpu) != 0x040458B3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040458B3u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808B16u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B17u;
    if (sm_scpu_context_key(cpu) != 0x040458BBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040458BBu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808B17u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B19u;
    if (sm_scpu_context_key(cpu) != 0x040458CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040458CBu: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B19u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B1Bu;
    if (sm_scpu_context_key(cpu) != 0x040458DBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040458DBu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808B1Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B1Cu;
    if (sm_scpu_context_key(cpu) != 0x040458E3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040458E3u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808B1Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B1Eu;
    if (sm_scpu_context_key(cpu) != 0x040458F3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040458F3u: {
    static const uint8_t source_bytes[] = {0x85u, 0x4Du};
    if (sm_scpu_guard_code(cpu,bus,0x808B1Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B20u;
    if (sm_scpu_context_key(cpu) != 0x04045903u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045903u: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808B20u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B21u;
    if (sm_scpu_context_key(cpu) != 0x0404590Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0404590Bu: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808B21u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B23u;
    if (sm_scpu_context_key(cpu) != 0x0404591Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404591Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x55u};
    if (sm_scpu_guard_code(cpu,bus,0x808B23u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x55u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B25u;
    if (sm_scpu_context_key(cpu) != 0x0404592Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0404592Bu: {
    static const uint8_t source_bytes[] = {0xC8u};
    if (sm_scpu_guard_code(cpu,bus,0x808B25u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->y = (uint8_t)(cpu->y + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->y & 0x80u) != 0u ? SM_P_N : 0u) | (cpu->y == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B26u;
    if (sm_scpu_context_key(cpu) != 0x04045933u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045933u: {
    static const uint8_t source_bytes[] = {0xB7u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808B26u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t pointer = (uint16_t)(cpu->d + 0x10u);
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
    cpu->pc = 0x8B28u;
    if (sm_scpu_context_key(cpu) != 0x04045943u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045943u: {
    static const uint8_t source_bytes[] = {0x85u, 0x56u};
    if (sm_scpu_guard_code(cpu,bus,0x808B28u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x56u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B2Au;
    if (sm_scpu_context_key(cpu) != 0x04045953u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045953u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808B2Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B2Bu;
    if (sm_scpu_context_key(cpu) != 0x0404595Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404595Bu: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x808B2Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B2Cu;
    if (sm_scpu_context_key(cpu) != 0x04045960u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045960u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808B2Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04063D18u && sm_scpu_context_key(cpu) != 0x0415D430u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045968u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B2Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B2Fu;
    if (sm_scpu_context_key(cpu) != 0x0404597Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045969u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B2Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B2Fu;
    if (sm_scpu_context_key(cpu) != 0x0404597Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404596Au: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B2Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B2Fu;
    if (sm_scpu_context_key(cpu) != 0x0404597Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404597Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x12u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B2Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4212u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B32u;
    if (sm_scpu_context_key(cpu) != 0x04045992u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0404597Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x12u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B2Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4212u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B32u;
    if (sm_scpu_context_key(cpu) != 0x04045993u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045992u: {
    static const uint8_t source_bytes[] = {0x29u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x808B32u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B34u;
    if (sm_scpu_context_key(cpu) != 0x040459A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04045993u: {
    static const uint8_t source_bytes[] = {0x29u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x808B32u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B34u;
    if (sm_scpu_context_key(cpu) != 0x040459A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040459A2u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xF9u};
    if (sm_scpu_guard_code(cpu,bus,0x808B34u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x8B2Fu;
        cycles = 3u;
    } else {
        cpu->pc = 0x8B36u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404597Au && sm_scpu_context_key(cpu) != 0x040459B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040459A3u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xF9u};
    if (sm_scpu_guard_code(cpu,bus,0x808B34u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x8B2Fu;
        cycles = 3u;
    } else {
        cpu->pc = 0x8B36u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404597Bu && sm_scpu_context_key(cpu) != 0x040459B3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040459B2u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B36u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B38u;
    if (sm_scpu_context_key(cpu) != 0x040459C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040459B3u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B36u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B38u;
    if (sm_scpu_context_key(cpu) != 0x040459C1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040459C0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x5Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B38u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B3Au;
    if (sm_scpu_context_key(cpu) != 0x040459D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040459C1u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x5Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B38u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B3Au;
    if (sm_scpu_context_key(cpu) != 0x040459D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040459D0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x64u};
    if (sm_scpu_guard_code(cpu,bus,0x808B3Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x64u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B3Cu;
    if (sm_scpu_context_key(cpu) != 0x040459E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040459D1u: {
    static const uint8_t source_bytes[] = {0x85u, 0x64u};
    if (sm_scpu_guard_code(cpu,bus,0x808B3Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x64u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B3Cu;
    if (sm_scpu_context_key(cpu) != 0x040459E1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040459E0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808B3Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B3Eu;
    if (sm_scpu_context_key(cpu) != 0x040459F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040459E1u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808B3Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B3Eu;
    if (sm_scpu_context_key(cpu) != 0x040459F1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040459F0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x66u};
    if (sm_scpu_guard_code(cpu,bus,0x808B3Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x66u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B40u;
    if (sm_scpu_context_key(cpu) != 0x04045A00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040459F1u: {
    static const uint8_t source_bytes[] = {0x85u, 0x66u};
    if (sm_scpu_guard_code(cpu,bus,0x808B3Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x66u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B40u;
    if (sm_scpu_context_key(cpu) != 0x04045A01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045A00u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B40u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B42u;
    if (sm_scpu_context_key(cpu) != 0x04045A12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045A01u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B40u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B42u;
    if (sm_scpu_context_key(cpu) != 0x04045A13u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045A12u: {
    static const uint8_t source_bytes[] = {0xADu, 0x18u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B42u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4218u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B45u;
    if (sm_scpu_context_key(cpu) != 0x04045A2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045A13u: {
    static const uint8_t source_bytes[] = {0xADu, 0x18u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B42u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4218u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B45u;
    if (sm_scpu_context_key(cpu) != 0x04045A2Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045A2Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x5Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B45u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B47u;
    if (sm_scpu_context_key(cpu) != 0x04045A3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045A2Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x5Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B45u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Cu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B47u;
    if (sm_scpu_context_key(cpu) != 0x04045A3Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045A3Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x19u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B47u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4219u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B4Au;
    if (sm_scpu_context_key(cpu) != 0x04045A52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045A3Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x19u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B47u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4219u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B4Au;
    if (sm_scpu_context_key(cpu) != 0x04045A53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045A52u: {
    static const uint8_t source_bytes[] = {0x85u, 0x5Du};
    if (sm_scpu_guard_code(cpu,bus,0x808B4Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B4Cu;
    if (sm_scpu_context_key(cpu) != 0x04045A62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045A53u: {
    static const uint8_t source_bytes[] = {0x85u, 0x5Du};
    if (sm_scpu_guard_code(cpu,bus,0x808B4Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B4Cu;
    if (sm_scpu_context_key(cpu) != 0x04045A63u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045A62u: {
    static const uint8_t source_bytes[] = {0xADu, 0x1Au, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B4Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x421Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B4Fu;
    if (sm_scpu_context_key(cpu) != 0x04045A7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045A63u: {
    static const uint8_t source_bytes[] = {0xADu, 0x1Au, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B4Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x421Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B4Fu;
    if (sm_scpu_context_key(cpu) != 0x04045A7Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045A7Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808B4Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B51u;
    if (sm_scpu_context_key(cpu) != 0x04045A8Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045A7Bu: {
    static const uint8_t source_bytes[] = {0x85u, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808B4Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B51u;
    if (sm_scpu_context_key(cpu) != 0x04045A8Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045A8Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x1Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B51u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x421Bu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B54u;
    if (sm_scpu_context_key(cpu) != 0x04045AA2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045A8Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x1Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808B51u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x421Bu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B54u;
    if (sm_scpu_context_key(cpu) != 0x04045AA3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045AA2u: {
    static const uint8_t source_bytes[] = {0x85u, 0x5Fu};
    if (sm_scpu_guard_code(cpu,bus,0x808B54u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B56u;
    if (sm_scpu_context_key(cpu) != 0x04045AB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AA3u: {
    static const uint8_t source_bytes[] = {0x85u, 0x5Fu};
    if (sm_scpu_guard_code(cpu,bus,0x808B54u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Fu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B56u;
    if (sm_scpu_context_key(cpu) != 0x04045AB3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AB2u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B56u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B58u;
    if (sm_scpu_context_key(cpu) != 0x04045AC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045AB3u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B56u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B58u;
    if (sm_scpu_context_key(cpu) != 0x04045AC1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045AC0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x5Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B58u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B5Au;
    if (sm_scpu_context_key(cpu) != 0x04045AD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AC1u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x5Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B58u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B5Au;
    if (sm_scpu_context_key(cpu) != 0x04045AD1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AD0u: {
    static const uint8_t source_bytes[] = {0x45u, 0x64u};
    if (sm_scpu_guard_code(cpu,bus,0x808B5Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x64u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a ^ value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B5Cu;
    if (sm_scpu_context_key(cpu) != 0x04045AE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AD1u: {
    static const uint8_t source_bytes[] = {0x45u, 0x64u};
    if (sm_scpu_guard_code(cpu,bus,0x808B5Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x64u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a ^ value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B5Cu;
    if (sm_scpu_context_key(cpu) != 0x04045AE1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AE0u: {
    static const uint8_t source_bytes[] = {0x25u, 0x5Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B5Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a & value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B5Eu;
    if (sm_scpu_context_key(cpu) != 0x04045AF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AE1u: {
    static const uint8_t source_bytes[] = {0x25u, 0x5Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808B5Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a & value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B5Eu;
    if (sm_scpu_context_key(cpu) != 0x04045AF1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AF0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808B5Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x60u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B60u;
    if (sm_scpu_context_key(cpu) != 0x04045B00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045AF1u: {
    static const uint8_t source_bytes[] = {0x85u, 0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808B5Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x60u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B60u;
    if (sm_scpu_context_key(cpu) != 0x04045B01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B00u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808B60u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B62u;
    if (sm_scpu_context_key(cpu) != 0x04045B10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B01u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808B60u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B62u;
    if (sm_scpu_context_key(cpu) != 0x04045B11u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B10u: {
    static const uint8_t source_bytes[] = {0x45u, 0x66u};
    if (sm_scpu_guard_code(cpu,bus,0x808B62u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x66u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a ^ value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B64u;
    if (sm_scpu_context_key(cpu) != 0x04045B20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B11u: {
    static const uint8_t source_bytes[] = {0x45u, 0x66u};
    if (sm_scpu_guard_code(cpu,bus,0x808B62u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x66u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a ^ value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B64u;
    if (sm_scpu_context_key(cpu) != 0x04045B21u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B20u: {
    static const uint8_t source_bytes[] = {0x25u, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808B64u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a & value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B66u;
    if (sm_scpu_context_key(cpu) != 0x04045B30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B21u: {
    static const uint8_t source_bytes[] = {0x25u, 0x5Eu};
    if (sm_scpu_guard_code(cpu,bus,0x808B64u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x5Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (cpu->a & value) & 0xFFFFu;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B66u;
    if (sm_scpu_context_key(cpu) != 0x04045B31u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B30u: {
    static const uint8_t source_bytes[] = {0x85u, 0x62u};
    if (sm_scpu_guard_code(cpu,bus,0x808B66u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x62u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B68u;
    if (sm_scpu_context_key(cpu) != 0x04045B40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B31u: {
    static const uint8_t source_bytes[] = {0x85u, 0x62u};
    if (sm_scpu_guard_code(cpu,bus,0x808B66u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x62u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B68u;
    if (sm_scpu_context_key(cpu) != 0x04045B41u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045B40u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808B68u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04041228u && sm_scpu_context_key(cpu) != 0x04041478u && sm_scpu_context_key(cpu) != 0x04041598u && sm_scpu_context_key(cpu) != 0x040417C8u && sm_scpu_context_key(cpu) != 0x04041A00u && sm_scpu_context_key(cpu) != 0x04041D10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045B41u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808B68u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04041A01u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045B49u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B69u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B6Bu;
    if (sm_scpu_context_key(cpu) != 0x04045B5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045B4Bu: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808B69u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8B6Bu;
    if (sm_scpu_context_key(cpu) != 0x04045B5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045B5Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x00u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B6Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A00u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B6Eu;
    if (sm_scpu_context_key(cpu) != 0x04045B73u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045B73u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B6Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B71u;
    if (sm_scpu_context_key(cpu) != 0x04045B8Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045B8Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x01u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B71u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A01u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B74u;
    if (sm_scpu_context_key(cpu) != 0x04045BA3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045BA3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B74u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B77u;
    if (sm_scpu_context_key(cpu) != 0x04045BBBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045BBBu: {
    static const uint8_t source_bytes[] = {0xADu, 0x02u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B77u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A02u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B7Au;
    if (sm_scpu_context_key(cpu) != 0x04045BD3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045BD3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B7Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B7Du;
    if (sm_scpu_context_key(cpu) != 0x04045BEBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045BEBu: {
    static const uint8_t source_bytes[] = {0xADu, 0x03u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B7Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A03u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B80u;
    if (sm_scpu_context_key(cpu) != 0x04045C03u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C03u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B80u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B83u;
    if (sm_scpu_context_key(cpu) != 0x04045C1Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C1Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x06u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B83u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A06u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B86u;
    if (sm_scpu_context_key(cpu) != 0x04045C33u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C33u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x10u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B86u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2110u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B89u;
    if (sm_scpu_context_key(cpu) != 0x04045C4Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C4Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x07u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B89u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A07u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B8Cu;
    if (sm_scpu_context_key(cpu) != 0x04045C63u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C63u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x10u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B8Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2110u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B8Fu;
    if (sm_scpu_context_key(cpu) != 0x04045C7Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C7Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x04u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B8Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A04u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B92u;
    if (sm_scpu_context_key(cpu) != 0x04045C93u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045C93u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B92u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B95u;
    if (sm_scpu_context_key(cpu) != 0x04045CABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045CABu: {
    static const uint8_t source_bytes[] = {0xADu, 0x05u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B95u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A05u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B98u;
    if (sm_scpu_context_key(cpu) != 0x04045CC3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045CC3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B98u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8B9Bu;
    if (sm_scpu_context_key(cpu) != 0x04045CDBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045CDBu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Au, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808B9Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8B9Eu;
    if (sm_scpu_context_key(cpu) != 0x04045CF3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045CF3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x12u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808B9Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2112u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BA1u;
    if (sm_scpu_context_key(cpu) != 0x04045D0Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D0Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Bu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BA1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Bu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BA4u;
    if (sm_scpu_context_key(cpu) != 0x04045D23u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D23u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x12u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BA4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2112u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BA7u;
    if (sm_scpu_context_key(cpu) != 0x04045D3Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D3Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x08u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BA7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A08u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BAAu;
    if (sm_scpu_context_key(cpu) != 0x04045D53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D53u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x11u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BAAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2111u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BADu;
    if (sm_scpu_context_key(cpu) != 0x04045D6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D6Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x09u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A09u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BB0u;
    if (sm_scpu_context_key(cpu) != 0x04045D83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D83u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x11u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BB0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2111u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BB3u;
    if (sm_scpu_context_key(cpu) != 0x04045D9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045D9Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Eu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BB3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BB6u;
    if (sm_scpu_context_key(cpu) != 0x04045DB3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045DB3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x14u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BB6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2114u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BB9u;
    if (sm_scpu_context_key(cpu) != 0x04045DCBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045DCBu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Fu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BB9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Fu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BBCu;
    if (sm_scpu_context_key(cpu) != 0x04045DE3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045DE3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x14u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BBCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2114u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BBFu;
    if (sm_scpu_context_key(cpu) != 0x04045DFBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045DFBu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Cu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BBFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Cu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BC2u;
    if (sm_scpu_context_key(cpu) != 0x04045E13u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045E13u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x13u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BC2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2113u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BC5u;
    if (sm_scpu_context_key(cpu) != 0x04045E2Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045E2Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x0Du, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x808BC5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A0Du;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BC8u;
    if (sm_scpu_context_key(cpu) != 0x04045E43u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045E43u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x13u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x808BC8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2113u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BCBu;
    if (sm_scpu_context_key(cpu) != 0x04045E5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045E5Bu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808BCBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04040D3Bu && sm_scpu_context_key(cpu) != 0x040412EBu && sm_scpu_context_key(cpu) != 0x04041413u && sm_scpu_context_key(cpu) != 0x0404176Bu && sm_scpu_context_key(cpu) != 0x0404192Bu && sm_scpu_context_key(cpu) != 0x04041B2Bu && sm_scpu_context_key(cpu) != 0x04041CABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045EE0u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8BDDu;
    if (sm_scpu_context_key(cpu) != 0x04045EE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045EE2u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8BDDu;
    if (sm_scpu_context_key(cpu) != 0x04045EEAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045EE3u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8BDDu;
    if (sm_scpu_context_key(cpu) != 0x04045EEBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045EE8u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8BDEu;
    if (sm_scpu_context_key(cpu) != 0x04045EF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045EEAu: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8BDEu;
    if (sm_scpu_context_key(cpu) != 0x04045EF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045EEBu: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8BDEu;
    if (sm_scpu_context_key(cpu) != 0x04045EF3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045EF0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BDFu;
    if (sm_scpu_context_key(cpu) != 0x04045EF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045EF2u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BDFu;
    if (sm_scpu_context_key(cpu) != 0x04045EFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045EF3u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808BDEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BDFu;
    if (sm_scpu_context_key(cpu) != 0x04045EFBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045EF8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808BDFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8BE1u;
    if (sm_scpu_context_key(cpu) != 0x04045F0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045EFAu: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808BDFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8BE1u;
    if (sm_scpu_context_key(cpu) != 0x04045F0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045EFBu: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808BDFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8BE1u;
    if (sm_scpu_context_key(cpu) != 0x04045F0Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045F0Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808BE1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8BE3u;
    if (sm_scpu_context_key(cpu) != 0x04045F1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045F0Bu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x808BE1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8BE3u;
    if (sm_scpu_context_key(cpu) != 0x04045F1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045F1Au: {
    static const uint8_t source_bytes[] = {0x64u, 0x6Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808BE3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Cu);
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BE5u;
    if (sm_scpu_context_key(cpu) != 0x04045F2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045F2Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x6Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808BE5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Cu);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BE7u;
    if (sm_scpu_context_key(cpu) != 0x04045F3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045F3Au: {
    static const uint8_t source_bytes[] = {0xF0u, 0xFCu};
    if (sm_scpu_guard_code(cpu,bus,0x808BE7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x8BE5u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8BE9u;
    }
    if (sm_scpu_context_key(cpu) != 0x04045F2Au && sm_scpu_context_key(cpu) != 0x04045F4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x04045F4Au: {
    static const uint8_t source_bytes[] = {0x20u, 0xFCu, 0x8Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808BE9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x8BEBu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8CFCu;
    if (sm_scpu_context_key(cpu) != 0x040467E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04045F60u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808BECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8BEEu;
    if (sm_scpu_context_key(cpu) != 0x04045F70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04045F70u: {
    static const uint8_t source_bytes[] = {0xA5u, 0xB2u};
    if (sm_scpu_guard_code(cpu,bus,0x808BEEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xB2u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BF0u;
    if (sm_scpu_context_key(cpu) != 0x04045F80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045F80u: {
    static const uint8_t source_bytes[] = {0x85u, 0xD0u};
    if (sm_scpu_guard_code(cpu,bus,0x808BF0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xD0u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8BF2u;
    if (sm_scpu_context_key(cpu) != 0x04045F90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04045F90u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808BF2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8BF3u;
    if (sm_scpu_context_key(cpu) != 0x04045F98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04045F98u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808BF3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04045EA0u && sm_scpu_context_key(cpu) != 0x040713E0u && sm_scpu_context_key(cpu) != 0x04071400u && sm_scpu_context_key(cpu) != 0x040C0050u && sm_scpu_context_key(cpu) != 0x040C1180u && sm_scpu_context_key(cpu) != 0x040C11C0u && sm_scpu_context_key(cpu) != 0x040C1228u && sm_scpu_context_key(cpu) != 0x040C2D88u && sm_scpu_context_key(cpu) != 0x040E3DB8u && sm_scpu_context_key(cpu) != 0x041C1070u && sm_scpu_context_key(cpu) != 0x041C1220u && sm_scpu_context_key(cpu) != 0x041C98E8u && sm_scpu_context_key(cpu) != 0x041C9A80u && sm_scpu_context_key(cpu) != 0x041E9288u && sm_scpu_context_key(cpu) != 0x041E9438u && sm_scpu_context_key(cpu) != 0x041EA980u && sm_scpu_context_key(cpu) != 0x041EAB38u && sm_scpu_context_key(cpu) != 0x041EE780u && sm_scpu_context_key(cpu) != 0x041EE930u && sm_scpu_context_key(cpu) != 0x041F51D0u && sm_scpu_context_key(cpu) != 0x041F5380u && sm_scpu_context_key(cpu) != 0x043D6210u && sm_scpu_context_key(cpu) != 0x043D6400u && sm_scpu_context_key(cpu) != 0x043D7AE8u && sm_scpu_context_key(cpu) != 0x043D7B40u && sm_scpu_context_key(cpu) != 0x043D8410u && sm_scpu_context_key(cpu) != 0x043D8468u && sm_scpu_context_key(cpu) != 0x043D8968u && sm_scpu_context_key(cpu) != 0x043D89C0u && sm_scpu_context_key(cpu) != 0x043D9148u && sm_scpu_context_key(cpu) != 0x043D91A0u && sm_scpu_context_key(cpu) != 0x043D9988u && sm_scpu_context_key(cpu) != 0x043D99E0u && sm_scpu_context_key(cpu) != 0x043DA1D8u && sm_scpu_context_key(cpu) != 0x043DA230u && sm_scpu_context_key(cpu) != 0x043DAB60u && sm_scpu_context_key(cpu) != 0x043DABA8u && sm_scpu_context_key(cpu) != 0x043DACD0u && sm_scpu_context_key(cpu) != 0x043DB188u && sm_scpu_context_key(cpu) != 0x043DB4D8u && sm_scpu_context_key(cpu) != 0x043DB6E8u && sm_scpu_context_key(cpu) != 0x043DD690u && sm_scpu_context_key(cpu) != 0x043DD900u && sm_scpu_context_key(cpu) != 0x043E0D90u && sm_scpu_context_key(cpu) != 0x043E0E00u && sm_scpu_context_key(cpu) != 0x043E0E40u && sm_scpu_context_key(cpu) != 0x043E1140u && sm_scpu_context_key(cpu) != 0x043E3BC8u && sm_scpu_context_key(cpu) != 0x043E3D40u && sm_scpu_context_key(cpu) != 0x0546E738u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04046153u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x808C2Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8C2Bu;
    if (sm_scpu_context_key(cpu) != 0x0404615Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404615Bu: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x808C2Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8C2Du;
    if (sm_scpu_context_key(cpu) != 0x0404616Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404616Bu: {
    static const uint8_t source_bytes[] = {0xADu, 0x10u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x808C2Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4210u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8C30u;
    if (sm_scpu_context_key(cpu) != 0x04046183u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04046183u: {
    static const uint8_t source_bytes[] = {0x29u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x808C30u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    uint16_t result = (cpu->a & value) & 0xFFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8C32u;
    if (sm_scpu_context_key(cpu) != 0x04046193u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04046193u: {
    static const uint8_t source_bytes[] = {0xD0u, 0xF9u};
    if (sm_scpu_guard_code(cpu,bus,0x808C32u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x8C2Du;
        cycles = 3u;
    } else {
        cpu->pc = 0x8C34u;
    }
    if (sm_scpu_context_key(cpu) != 0x0404616Bu && sm_scpu_context_key(cpu) != 0x040461A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x040461A3u: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x808C34u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8C35u;
    if (sm_scpu_context_key(cpu) != 0x040461ABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040461ABu: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x808C35u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04048AA3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04046790u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808CF2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8CF3u;
    if (sm_scpu_context_key(cpu) != 0x04046798u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04046792u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808CF2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8CF3u;
    if (sm_scpu_context_key(cpu) != 0x0404679Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04046798u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808CF3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8CF4u;
    if (sm_scpu_context_key(cpu) != 0x040467A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0404679Au: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808CF3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8CF4u;
    if (sm_scpu_context_key(cpu) != 0x040467A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040467A0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808CF4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8CF5u;
    if (sm_scpu_context_key(cpu) != 0x040467A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040467A2u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808CF4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8CF5u;
    if (sm_scpu_context_key(cpu) != 0x040467AAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040467A8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808CF5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8CF7u;
    if (sm_scpu_context_key(cpu) != 0x040467B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040467AAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x808CF5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8CF7u;
    if (sm_scpu_context_key(cpu) != 0x040467B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040467B8u: {
    static const uint8_t source_bytes[] = {0x20u, 0xFCu, 0x8Cu};
    if (sm_scpu_guard_code(cpu,bus,0x808CF7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x8CF9u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8CFCu;
    if (sm_scpu_context_key(cpu) != 0x040467E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040467D0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x808CFAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8CFBu;
    if (sm_scpu_context_key(cpu) != 0x040467D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040467D8u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x808CFBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040EC3C0u && sm_scpu_context_key(cpu) != 0x04276928u && sm_scpu_context_key(cpu) != 0x04279810u && sm_scpu_context_key(cpu) != 0x043DBAA0u && sm_scpu_context_key(cpu) != 0x043DBD38u && sm_scpu_context_key(cpu) != 0x043DCCE8u && sm_scpu_context_key(cpu) != 0x043DCF80u && sm_scpu_context_key(cpu) != 0x043E41A8u && sm_scpu_context_key(cpu) != 0x05340250u && sm_scpu_context_key(cpu) != 0x053C6628u && sm_scpu_context_key(cpu) != 0x05447810u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04048F50u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x8091EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x91ECu;
    if (sm_scpu_context_key(cpu) != 0x04048F60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04048F51u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x8091EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x91ECu;
    if (sm_scpu_context_key(cpu) != 0x04048F61u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04048F60u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x8091ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x91EEu;
    if (sm_scpu_context_key(cpu) != 0x04048F71u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04048F61u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x8091ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x91EEu;
    if (sm_scpu_context_key(cpu) != 0x04048F71u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04048F71u: {
    static const uint8_t source_bytes[] = {0xADu, 0xD2u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8091EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07D2u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x91F1u;
    if (sm_scpu_context_key(cpu) != 0x04048F89u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04048F89u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x2Fu};
    if (sm_scpu_guard_code(cpu,bus,0x8091F1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x9222u;
        cycles = 3u;
    } else {
        cpu->pc = 0x91F3u;
    }
    if (sm_scpu_context_key(cpu) != 0x04048F99u && sm_scpu_context_key(cpu) != 0x04049111u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x04048F99u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x8091F3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x91F5u;
    if (sm_scpu_context_key(cpu) != 0x04048FA9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04048FA9u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x15u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8091F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2115u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x91F8u;
    if (sm_scpu_context_key(cpu) != 0x04048FC1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04048FC1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x8091F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0018u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x91FAu;
    if (sm_scpu_context_key(cpu) != 0x04048FD1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04048FD1u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x01u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x8091FAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4301u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x91FDu;
    if (sm_scpu_context_key(cpu) != 0x04048FE9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04048FE9u: {
    static const uint8_t source_bytes[] = {0xADu, 0xCCu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x8091FDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07CCu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9200u;
    if (sm_scpu_context_key(cpu) != 0x04049001u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04049001u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x16u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x809200u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2116u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9203u;
    if (sm_scpu_context_key(cpu) != 0x04049019u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04049019u: {
    static const uint8_t source_bytes[] = {0xADu, 0xD0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x809203u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07D0u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9206u;
    if (sm_scpu_context_key(cpu) != 0x04049031u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04049031u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x809206u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4305u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9209u;
    if (sm_scpu_context_key(cpu) != 0x04049049u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04049049u: {
    static const uint8_t source_bytes[] = {0xADu, 0xD2u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x809209u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07D2u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x920Cu;
    if (sm_scpu_context_key(cpu) != 0x04049061u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04049061u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x80920Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4302u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x920Fu;
    if (sm_scpu_context_key(cpu) != 0x04049079u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04049079u: {
    static const uint8_t source_bytes[] = {0xACu, 0xD4u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80920Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07D4u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9212u;
    if (sm_scpu_context_key(cpu) != 0x04049091u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04049091u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x04u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x809212u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4304u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9215u;
    if (sm_scpu_context_key(cpu) != 0x040490A9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040490A9u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x809215u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9217u;
    if (sm_scpu_context_key(cpu) != 0x040490B9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040490B9u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x00u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0x809217u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4300u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x921Au;
    if (sm_scpu_context_key(cpu) != 0x040490D1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040490D1u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80921Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x921Cu;
    if (sm_scpu_context_key(cpu) != 0x040490E1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040490E1u: {
    static const uint8_t source_bytes[] = {0x8Cu, 0x0Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x80921Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->y >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x921Fu;
    if (sm_scpu_context_key(cpu) != 0x040490F9u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040490F9u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0xD2u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80921Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x07D2u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x9222u;
    if (sm_scpu_context_key(cpu) != 0x04049111u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04049111u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x809222u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04041731u && sm_scpu_context_key(cpu) != 0x04041CE1u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04049320u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x809264u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x9265u;
    if (sm_scpu_context_key(cpu) != 0x04049328u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04049328u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x809265u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x9266u;
    if (sm_scpu_context_key(cpu) != 0x04049330u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04049330u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x809266u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9267u;
    if (sm_scpu_context_key(cpu) != 0x04049338u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04049338u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x809267u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x9269u;
    if (sm_scpu_context_key(cpu) != 0x04049348u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04049348u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x809269u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x926Cu;
    if (sm_scpu_context_key(cpu) != 0x04049360u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04049360u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x80926Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x926Du;
    if (sm_scpu_context_key(cpu) != 0x04049368u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04049368u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x72u, 0x92u};
    if (sm_scpu_guard_code(cpu,bus,0x80926Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0x926Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x9272u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0x9276u) || (cpu->x == 0x0002u && target == 0x92ABu))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x040493B0u && sm_scpu_context_key(cpu) != 0x04049558u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04049380u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x809270u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x9271u;
    if (sm_scpu_context_key(cpu) != 0x04049388u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04049388u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x809271u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040C2CA0u && sm_scpu_context_key(cpu) != 0x0414F818u && sm_scpu_context_key(cpu) != 0x04177688u && sm_scpu_context_key(cpu) != 0x043D7308u && sm_scpu_context_key(cpu) != 0x043DFA68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04057FB8u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80AFF7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xAFF8u;
    if (sm_scpu_context_key(cpu) != 0x04057FC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04057FC0u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80AFF8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xAFF9u;
    if (sm_scpu_context_key(cpu) != 0x04057FC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04057FC8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80AFF9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAFFAu;
    if (sm_scpu_context_key(cpu) != 0x04057FD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04057FD0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80AFFAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xAFFCu;
    if (sm_scpu_context_key(cpu) != 0x04057FE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04057FE0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80AFFCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAFFEu;
    if (sm_scpu_context_key(cpu) != 0x04057FF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04057FF0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x50u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80AFFEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0750u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB001u;
    if (sm_scpu_context_key(cpu) != 0x04058008u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058008u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x80B001u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB003u;
    if (sm_scpu_context_key(cpu) != 0x04058018u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058018u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x54u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B003u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0754u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB006u;
    if (sm_scpu_context_key(cpu) != 0x04058030u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058030u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x56u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B006u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0756u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB009u;
    if (sm_scpu_context_key(cpu) != 0x04058048u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058048u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x0Cu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B009u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Cu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB00Cu;
    if (sm_scpu_context_key(cpu) != 0x04058060u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058060u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B00Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0752u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB00Fu;
    if (sm_scpu_context_key(cpu) != 0x04058078u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058078u: {
    static const uint8_t source_bytes[] = {0x22u, 0xA1u, 0xB1u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80B00Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xB012u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB1A1u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04058D08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04058098u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B013u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB014u;
    if (sm_scpu_context_key(cpu) != 0x040580A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040580A0u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B014u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x0416E178u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04058218u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B043u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB044u;
    if (sm_scpu_context_key(cpu) != 0x04058220u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058220u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B044u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB045u;
    if (sm_scpu_context_key(cpu) != 0x04058228u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058228u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B045u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB046u;
    if (sm_scpu_context_key(cpu) != 0x04058230u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058230u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80B046u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB048u;
    if (sm_scpu_context_key(cpu) != 0x04058240u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058240u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80B048u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB04Au;
    if (sm_scpu_context_key(cpu) != 0x04058250u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058250u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x50u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B04Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0750u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB04Du;
    if (sm_scpu_context_key(cpu) != 0x04058268u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058268u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x80B04Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB04Fu;
    if (sm_scpu_context_key(cpu) != 0x04058278u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058278u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x54u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B04Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0754u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB052u;
    if (sm_scpu_context_key(cpu) != 0x04058290u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058290u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x56u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B052u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0756u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB055u;
    if (sm_scpu_context_key(cpu) != 0x040582A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040582A8u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0x80B055u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB057u;
    if (sm_scpu_context_key(cpu) != 0x040582B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040582B8u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x58u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B057u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0758u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB05Au;
    if (sm_scpu_context_key(cpu) != 0x040582D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040582D0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x0Au, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B05Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x000Au;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB05Du;
    if (sm_scpu_context_key(cpu) != 0x040582E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040582E8u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B05Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0752u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB060u;
    if (sm_scpu_context_key(cpu) != 0x04058300u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058300u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x26u};
    if (sm_scpu_guard_code(cpu,bus,0x80B060u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x26u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB062u;
    if (sm_scpu_context_key(cpu) != 0x04058310u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058310u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x86u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B062u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0786u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB065u;
    if (sm_scpu_context_key(cpu) != 0x04058328u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058328u: {
    static const uint8_t source_bytes[] = {0x22u, 0x0Du, 0xB2u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80B065u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xB068u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB20Du;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04059068u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04058348u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B069u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB06Au;
    if (sm_scpu_context_key(cpu) != 0x04058350u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058350u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B06Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04173BA0u && sm_scpu_context_key(cpu) != 0x04176650u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04058358u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B06Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB06Cu;
    if (sm_scpu_context_key(cpu) != 0x04058360u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058360u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B06Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB06Du;
    if (sm_scpu_context_key(cpu) != 0x04058368u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058368u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B06Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB06Eu;
    if (sm_scpu_context_key(cpu) != 0x04058370u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058370u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B06Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB070u;
    if (sm_scpu_context_key(cpu) != 0x04058380u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058380u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80B070u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB072u;
    if (sm_scpu_context_key(cpu) != 0x04058390u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058390u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x50u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B072u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0750u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB075u;
    if (sm_scpu_context_key(cpu) != 0x040583A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040583A8u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x80B075u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB077u;
    if (sm_scpu_context_key(cpu) != 0x040583B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040583B8u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x54u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B077u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0754u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB07Au;
    if (sm_scpu_context_key(cpu) != 0x040583D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040583D0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x56u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B07Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0756u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB07Du;
    if (sm_scpu_context_key(cpu) != 0x040583E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040583E8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B07Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB080u;
    if (sm_scpu_context_key(cpu) != 0x04058400u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058400u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B080u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0752u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB083u;
    if (sm_scpu_context_key(cpu) != 0x04058418u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058418u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B083u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB084u;
    if (sm_scpu_context_key(cpu) != 0x04058420u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058420u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B084u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04170930u && sm_scpu_context_key(cpu) != 0x041C3950u && sm_scpu_context_key(cpu) != 0x043DDAD0u && sm_scpu_context_key(cpu) != 0x043DDE78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04058428u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B085u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB086u;
    if (sm_scpu_context_key(cpu) != 0x04058430u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058430u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B086u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB087u;
    if (sm_scpu_context_key(cpu) != 0x04058438u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058438u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B087u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB088u;
    if (sm_scpu_context_key(cpu) != 0x04058440u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058440u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80B088u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB08Au;
    if (sm_scpu_context_key(cpu) != 0x04058450u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058450u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80B08Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB08Cu;
    if (sm_scpu_context_key(cpu) != 0x04058460u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058460u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x50u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B08Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0750u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB08Fu;
    if (sm_scpu_context_key(cpu) != 0x04058478u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058478u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x80B08Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB091u;
    if (sm_scpu_context_key(cpu) != 0x04058488u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058488u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x54u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B091u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0754u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB094u;
    if (sm_scpu_context_key(cpu) != 0x040584A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040584A0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x56u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B094u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0756u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB097u;
    if (sm_scpu_context_key(cpu) != 0x040584B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040584B8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B097u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB09Au;
    if (sm_scpu_context_key(cpu) != 0x040584D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040584D0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B09Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0752u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB09Du;
    if (sm_scpu_context_key(cpu) != 0x040584E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040584E8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B09Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB09Eu;
    if (sm_scpu_context_key(cpu) != 0x040584F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040584F0u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B09Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04170A18u && sm_scpu_context_key(cpu) != 0x041C39F0u && sm_scpu_context_key(cpu) != 0x043E2E58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040584F8u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B09Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB0A0u;
    if (sm_scpu_context_key(cpu) != 0x04058500u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058500u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB0A1u;
    if (sm_scpu_context_key(cpu) != 0x04058508u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058508u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0A1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0A2u;
    if (sm_scpu_context_key(cpu) != 0x04058510u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058510u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB0A4u;
    if (sm_scpu_context_key(cpu) != 0x04058520u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058520u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0A6u;
    if (sm_scpu_context_key(cpu) != 0x04058530u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058530u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x50u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0A6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0750u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB0A9u;
    if (sm_scpu_context_key(cpu) != 0x04058548u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058548u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0A9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0ABu;
    if (sm_scpu_context_key(cpu) != 0x04058558u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058558u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x54u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0ABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0754u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB0AEu;
    if (sm_scpu_context_key(cpu) != 0x04058570u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058570u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x56u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0756u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB0B1u;
    if (sm_scpu_context_key(cpu) != 0x04058588u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058588u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x06u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0006u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0B4u;
    if (sm_scpu_context_key(cpu) != 0x040585A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040585A0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0B4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0752u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB0B7u;
    if (sm_scpu_context_key(cpu) != 0x040585B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040585B8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0B8u;
    if (sm_scpu_context_key(cpu) != 0x040585C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040585C0u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0B8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x041738C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040585C8u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB0BAu;
    if (sm_scpu_context_key(cpu) != 0x040585D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040585D0u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB0BBu;
    if (sm_scpu_context_key(cpu) != 0x040585D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040585D8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0BCu;
    if (sm_scpu_context_key(cpu) != 0x040585E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040585E0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB0BEu;
    if (sm_scpu_context_key(cpu) != 0x040585F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040585F0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0C0u;
    if (sm_scpu_context_key(cpu) != 0x04058600u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058600u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x50u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0750u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB0C3u;
    if (sm_scpu_context_key(cpu) != 0x04058618u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058618u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0C5u;
    if (sm_scpu_context_key(cpu) != 0x04058628u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04058628u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x54u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0754u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB0C8u;
    if (sm_scpu_context_key(cpu) != 0x04058640u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058640u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x56u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0C8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0756u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB0CBu;
    if (sm_scpu_context_key(cpu) != 0x04058658u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058658u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x08u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0CBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0CEu;
    if (sm_scpu_context_key(cpu) != 0x04058670u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058670u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80B0CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0752u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xB0D1u;
    if (sm_scpu_context_key(cpu) != 0x04058688u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04058688u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB0D2u;
    if (sm_scpu_context_key(cpu) != 0x04058690u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058690u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B0D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x041739A8u && sm_scpu_context_key(cpu) != 0x043E2410u && sm_scpu_context_key(cpu) != 0x043E4010u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04058C70u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B18Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB18Fu;
    if (sm_scpu_context_key(cpu) != 0x04058C78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058C78u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B18Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB190u;
    if (sm_scpu_context_key(cpu) != 0x04058C80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058C80u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B190u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB191u;
    if (sm_scpu_context_key(cpu) != 0x04058C88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058C88u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B191u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB193u;
    if (sm_scpu_context_key(cpu) != 0x04058C98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058C98u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x00u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0x80B193u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x1D00u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB196u;
    if (sm_scpu_context_key(cpu) != 0x04058CB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058CB0u: {
    static const uint8_t source_bytes[] = {0xA0u, 0xE0u, 0x3Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B196u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x3BE0u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB199u;
    if (sm_scpu_context_key(cpu) != 0x04058CC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058CC8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80B199u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x01FFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB19Cu;
    if (sm_scpu_context_key(cpu) != 0x04058CE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058CE0u: {
    static const uint8_t source_bytes[] = {0x54u, 0x7Eu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B19Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t payload;
    if (sm_scpu_read8(cpu,bus,(0x00u << 16u) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(0x7Eu << 16u) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = 0x7Eu;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0xB19Fu;
        if (sm_scpu_context_key(cpu) != 0x04058CF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    } else {
        cpu->pc = 0xB19Cu;
        if (sm_scpu_context_key(cpu) != 0x04058CE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x04058CF8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B19Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB1A0u;
    if (sm_scpu_context_key(cpu) != 0x04058D00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058D00u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B1A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040581B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04058D08u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B1A1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB1A2u;
    if (sm_scpu_context_key(cpu) != 0x04058D10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058D10u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B1A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB1A3u;
    if (sm_scpu_context_key(cpu) != 0x04058D18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058D18u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B1A3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB1A4u;
    if (sm_scpu_context_key(cpu) != 0x04058D20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058D20u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B1A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB1A6u;
    if (sm_scpu_context_key(cpu) != 0x04058D30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058D30u: {
    static const uint8_t source_bytes[] = {0xA2u, 0xE0u, 0x3Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B1A6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x3BE0u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB1A9u;
    if (sm_scpu_context_key(cpu) != 0x04058D48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058D48u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0x80B1A9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x1D00u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB1ACu;
    if (sm_scpu_context_key(cpu) != 0x04058D60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058D60u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80B1ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x01FFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB1AFu;
    if (sm_scpu_context_key(cpu) != 0x04058D78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04058D78u: {
    static const uint8_t source_bytes[] = {0x54u, 0x00u, 0x7Eu};
    if (sm_scpu_guard_code(cpu,bus,0x80B1AFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t payload;
    if (sm_scpu_read8(cpu,bus,(0x7Eu << 16u) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(0x00u << 16u) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = 0x00u;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0xB1B2u;
        if (sm_scpu_context_key(cpu) != 0x04058D90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    } else {
        cpu->pc = 0xB1AFu;
        if (sm_scpu_context_key(cpu) != 0x04058D78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x04058D90u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B1B2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB1B3u;
    if (sm_scpu_context_key(cpu) != 0x04058D98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04058D98u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B1B3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04058098u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04059068u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B20Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB20Eu;
    if (sm_scpu_context_key(cpu) != 0x04059070u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405906Au: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B20Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB20Eu;
    if (sm_scpu_context_key(cpu) != 0x04059072u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059070u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B20Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB20Fu;
    if (sm_scpu_context_key(cpu) != 0x04059078u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059072u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B20Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB20Fu;
    if (sm_scpu_context_key(cpu) != 0x0405907Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059078u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B20Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB210u;
    if (sm_scpu_context_key(cpu) != 0x04059080u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405907Au: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B20Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB210u;
    if (sm_scpu_context_key(cpu) != 0x04059082u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04059080u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B210u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB212u;
    if (sm_scpu_context_key(cpu) != 0x04059090u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059082u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B210u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB212u;
    if (sm_scpu_context_key(cpu) != 0x04059090u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059090u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x00u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0x80B212u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0500u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB215u;
    if (sm_scpu_context_key(cpu) != 0x040590A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040590A8u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0x80B215u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x1D00u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB218u;
    if (sm_scpu_context_key(cpu) != 0x040590C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040590C0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80B218u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x01FFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB21Bu;
    if (sm_scpu_context_key(cpu) != 0x040590D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040590D8u: {
    static const uint8_t source_bytes[] = {0x54u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B21Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t payload;
    if (sm_scpu_read8(cpu,bus,(0x00u << 16u) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(0x00u << 16u) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = 0x00u;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0xB21Eu;
        if (sm_scpu_context_key(cpu) != 0x040590F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    } else {
        cpu->pc = 0xB21Bu;
        if (sm_scpu_context_key(cpu) != 0x040590D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x040590F0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B21Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB21Fu;
    if (sm_scpu_context_key(cpu) != 0x040590F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040590F8u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B21Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04058198u && sm_scpu_context_key(cpu) != 0x04058348u && sm_scpu_context_key(cpu) != 0x0416E348u && sm_scpu_context_key(cpu) != 0x04170A38u && sm_scpu_context_key(cpu) != 0x041739C8u && sm_scpu_context_key(cpu) != 0x041C3A10u && sm_scpu_context_key(cpu) != 0x043D7070u && sm_scpu_context_key(cpu) != 0x043DF7D0u && sm_scpu_context_key(cpu) != 0x043E20F0u && sm_scpu_context_key(cpu) != 0x043E2630u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04059100u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B220u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB221u;
    if (sm_scpu_context_key(cpu) != 0x04059108u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059108u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B221u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB222u;
    if (sm_scpu_context_key(cpu) != 0x04059110u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059110u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B222u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB223u;
    if (sm_scpu_context_key(cpu) != 0x04059118u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04059118u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80B223u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB225u;
    if (sm_scpu_context_key(cpu) != 0x04059128u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059128u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x00u, 0x1Du};
    if (sm_scpu_guard_code(cpu,bus,0x80B225u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x1D00u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB228u;
    if (sm_scpu_context_key(cpu) != 0x04059140u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059140u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x00u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0x80B228u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0500u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB22Bu;
    if (sm_scpu_context_key(cpu) != 0x04059158u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059158u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80B22Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x01FFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB22Eu;
    if (sm_scpu_context_key(cpu) != 0x04059170u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04059170u: {
    static const uint8_t source_bytes[] = {0x54u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80B22Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t payload;
    if (sm_scpu_read8(cpu,bus,(0x00u << 16u) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(0x00u << 16u) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = 0x00u;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0xB231u;
        if (sm_scpu_context_key(cpu) != 0x04059188u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    } else {
        cpu->pc = 0xB22Eu;
        if (sm_scpu_context_key(cpu) != 0x04059170u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x04059188u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80B231u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB232u;
    if (sm_scpu_context_key(cpu) != 0x04059190u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04059190u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80B232u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04058C00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405E730u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BCE6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBCE7u;
    if (sm_scpu_context_key(cpu) != 0x0405E738u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405E738u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BCE7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBCE8u;
    if (sm_scpu_context_key(cpu) != 0x0405E740u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405E740u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80BCE8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBCE9u;
    if (sm_scpu_context_key(cpu) != 0x0405E748u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405E748u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80BCE9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBCEBu;
    if (sm_scpu_context_key(cpu) != 0x0405E758u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405E758u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xA3u, 0xD2u};
    if (sm_scpu_guard_code(cpu,bus,0x80BCEBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xD2A3u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBCEEu;
    if (sm_scpu_context_key(cpu) != 0x0405E770u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405E770u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x4Cu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80BCEEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBCF1u;
    if (sm_scpu_context_key(cpu) != 0x0405E788u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405E788u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80BCF1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBCF4u;
    if (sm_scpu_context_key(cpu) != 0x0405E7A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0405E7A0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x4Eu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80BCF4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBCF7u;
    if (sm_scpu_context_key(cpu) != 0x0405E7B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0405E7B8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80BCF7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBCF8u;
    if (sm_scpu_context_key(cpu) != 0x0405E7C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0405E7C0u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80BCF8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x041606C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04063CA0u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80C794u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC795u;
    if (sm_scpu_context_key(cpu) != 0x04063CA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063CA8u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80C795u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC796u;
    if (sm_scpu_context_key(cpu) != 0x04063CB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063CB0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80C796u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC797u;
    if (sm_scpu_context_key(cpu) != 0x04063CB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04063CB8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80C797u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC799u;
    if (sm_scpu_context_key(cpu) != 0x04063CC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063CC8u: {
    static const uint8_t source_bytes[] = {0xA2u, 0x8Bu, 0xCBu};
    if (sm_scpu_guard_code(cpu,bus,0x80C799u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xCB8Bu;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC79Cu;
    if (sm_scpu_context_key(cpu) != 0x04063CE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063CE0u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x80u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80C79Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC79Fu;
    if (sm_scpu_context_key(cpu) != 0x04063CF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063CF8u: {
    static const uint8_t source_bytes[] = {0x22u, 0xD2u, 0x8Au, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x80C79Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xC7A2u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8AD2u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04045690u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04063D18u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7A3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC7A5u;
    if (sm_scpu_context_key(cpu) != 0x04063D28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063D28u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7A5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x07FFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC7A8u;
    if (sm_scpu_context_key(cpu) != 0x04063D40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063D40u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x64u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1964u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7ABu;
    if (sm_scpu_context_key(cpu) != 0x04063D58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04063D58u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x66u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7ABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1966u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7AEu;
    if (sm_scpu_context_key(cpu) != 0x04063D70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04063D70u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0100u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC7B1u;
    if (sm_scpu_context_key(cpu) != 0x04063D88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063D88u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x4Au, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7B4u;
    if (sm_scpu_context_key(cpu) != 0x04063DA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04063DA0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7B4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0100u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC7B7u;
    if (sm_scpu_context_key(cpu) != 0x04063DB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063DB8u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x4Cu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7BAu;
    if (sm_scpu_context_key(cpu) != 0x04063DD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04063DD0u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x4Eu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Eu;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7BDu;
    if (sm_scpu_context_key(cpu) != 0x04063DE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04063DE8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7BDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC7C0u;
    if (sm_scpu_context_key(cpu) != 0x04063E00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063E00u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x00u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C7C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A00u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7C3u;
    if (sm_scpu_context_key(cpu) != 0x04063E18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04063E18u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xA0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80C7C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00A0u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC7C6u;
    if (sm_scpu_context_key(cpu) != 0x04063E30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04063E30u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C7C6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A02u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7C9u;
    if (sm_scpu_context_key(cpu) != 0x04063E48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04063E48u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x80C7C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC7CAu;
    if (sm_scpu_context_key(cpu) != 0x04063E50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04063E50u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80C7CAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x043E24D0u && sm_scpu_context_key(cpu) != 0x043E30D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040648C0u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x80C918u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC919u;
    if (sm_scpu_context_key(cpu) != 0x040648C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040648C8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80C919u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC91Bu;
    if (sm_scpu_context_key(cpu) != 0x040648DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040648DAu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80C91Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC91Du;
    if (sm_scpu_context_key(cpu) != 0x040648EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040648EAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80C91Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC920u;
    if (sm_scpu_context_key(cpu) != 0x04064902u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04064902u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x31u};
    if (sm_scpu_guard_code(cpu,bus,0x80C920u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x31u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC922u;
    if (sm_scpu_context_key(cpu) != 0x04064912u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064912u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80C922u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC925u;
    if (sm_scpu_context_key(cpu) != 0x0406492Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0406492Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80C925u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC927u;
    if (sm_scpu_context_key(cpu) != 0x0406493Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0406493Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80C927u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC92Au;
    if (sm_scpu_context_key(cpu) != 0x04064952u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04064952u: {
    static const uint8_t source_bytes[] = {0xADu, 0x34u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80C92Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2134u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC92Du;
    if (sm_scpu_context_key(cpu) != 0x0406496Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0406496Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C92Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC92Fu;
    if (sm_scpu_context_key(cpu) != 0x0406497Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0406497Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x35u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80C92Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2135u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC932u;
    if (sm_scpu_context_key(cpu) != 0x04064992u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04064992u: {
    static const uint8_t source_bytes[] = {0x85u, 0x35u};
    if (sm_scpu_guard_code(cpu,bus,0x80C932u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x35u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC934u;
    if (sm_scpu_context_key(cpu) != 0x040649A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040649A2u: {
    static const uint8_t source_bytes[] = {0xADu, 0x36u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80C934u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2136u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC937u;
    if (sm_scpu_context_key(cpu) != 0x040649BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040649BAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x36u};
    if (sm_scpu_guard_code(cpu,bus,0x80C937u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x36u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC939u;
    if (sm_scpu_context_key(cpu) != 0x040649CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040649CAu: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x80C939u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC93Au;
    if (sm_scpu_context_key(cpu) != 0x040649D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040649D0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80C93Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04064A70u && sm_scpu_context_key(cpu) != 0x04064B30u && sm_scpu_context_key(cpu) != 0x04064C90u && sm_scpu_context_key(cpu) != 0x04064D88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040649D8u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x80C93Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC93Cu;
    if (sm_scpu_context_key(cpu) != 0x040649E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040649E0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80C93Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC93Eu;
    if (sm_scpu_context_key(cpu) != 0x040649F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040649F0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80C93Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC940u;
    if (sm_scpu_context_key(cpu) != 0x04064A00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064A00u: {
    static const uint8_t source_bytes[] = {0x85u, 0x3Eu};
    if (sm_scpu_guard_code(cpu,bus,0x80C940u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x3Eu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC942u;
    if (sm_scpu_context_key(cpu) != 0x04064A10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064A10u: {
    static const uint8_t source_bytes[] = {0x64u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C942u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC944u;
    if (sm_scpu_context_key(cpu) != 0x04064A20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064A20u: {
    static const uint8_t source_bytes[] = {0x64u, 0x36u};
    if (sm_scpu_guard_code(cpu,bus,0x80C944u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x36u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC946u;
    if (sm_scpu_context_key(cpu) != 0x04064A30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064A30u: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80C946u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x000Fu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC949u;
    if (sm_scpu_context_key(cpu) != 0x04064A48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04064A48u: {
    static const uint8_t source_bytes[] = {0x85u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80C949u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC94Bu;
    if (sm_scpu_context_key(cpu) != 0x04064A58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064A58u: {
    static const uint8_t source_bytes[] = {0x20u, 0x18u, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x80C94Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xC94Du;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC918u;
    if (sm_scpu_context_key(cpu) != 0x040648C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04064A70u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C94Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC950u;
    if (sm_scpu_context_key(cpu) != 0x04064A80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064A80u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x50u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C950u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1950u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC953u;
    if (sm_scpu_context_key(cpu) != 0x04064A98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064A98u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x36u};
    if (sm_scpu_guard_code(cpu,bus,0x80C953u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x36u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC955u;
    if (sm_scpu_context_key(cpu) != 0x04064AA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064AA8u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x52u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C955u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1952u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC958u;
    if (sm_scpu_context_key(cpu) != 0x04064AC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064AC0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x3Eu};
    if (sm_scpu_guard_code(cpu,bus,0x80C958u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x3Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC95Au;
    if (sm_scpu_context_key(cpu) != 0x04064AD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064AD0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C95Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC95Bu;
    if (sm_scpu_context_key(cpu) != 0x04064AD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064AD8u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C95Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC95Cu;
    if (sm_scpu_context_key(cpu) != 0x04064AE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064AE0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C95Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC95Du;
    if (sm_scpu_context_key(cpu) != 0x04064AE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064AE8u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C95Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC95Eu;
    if (sm_scpu_context_key(cpu) != 0x04064AF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064AF0u: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80C95Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x000Fu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC961u;
    if (sm_scpu_context_key(cpu) != 0x04064B08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04064B08u: {
    static const uint8_t source_bytes[] = {0x85u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80C961u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC963u;
    if (sm_scpu_context_key(cpu) != 0x04064B18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064B18u: {
    static const uint8_t source_bytes[] = {0x20u, 0x18u, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x80C963u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xC965u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC918u;
    if (sm_scpu_context_key(cpu) != 0x040648C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04064B30u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C966u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC968u;
    if (sm_scpu_context_key(cpu) != 0x04064B40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064B40u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C968u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC969u;
    if (sm_scpu_context_key(cpu) != 0x04064B48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064B48u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C969u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC96Au;
    if (sm_scpu_context_key(cpu) != 0x04064B50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064B50u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C96Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC96Bu;
    if (sm_scpu_context_key(cpu) != 0x04064B58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064B58u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C96Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC96Cu;
    if (sm_scpu_context_key(cpu) != 0x04064B60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064B60u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x54u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C96Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1954u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC96Fu;
    if (sm_scpu_context_key(cpu) != 0x04064B78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064B78u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C96Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC971u;
    if (sm_scpu_context_key(cpu) != 0x04064B88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064B88u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x80C971u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC972u;
    if (sm_scpu_context_key(cpu) != 0x04064B90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04064B90u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C972u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC973u;
    if (sm_scpu_context_key(cpu) != 0x04064B98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064B98u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C973u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC974u;
    if (sm_scpu_context_key(cpu) != 0x04064BA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064BA0u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C974u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC975u;
    if (sm_scpu_context_key(cpu) != 0x04064BA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064BA8u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C975u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC976u;
    if (sm_scpu_context_key(cpu) != 0x04064BB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064BB0u: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80C976u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x000Fu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC979u;
    if (sm_scpu_context_key(cpu) != 0x04064BC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04064BC8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C979u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC97Bu;
    if (sm_scpu_context_key(cpu) != 0x04064BD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064BD8u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x36u};
    if (sm_scpu_guard_code(cpu,bus,0x80C97Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x36u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC97Du;
    if (sm_scpu_context_key(cpu) != 0x04064BE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064BE8u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C97Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC97Eu;
    if (sm_scpu_context_key(cpu) != 0x04064BF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064BF0u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C97Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC97Fu;
    if (sm_scpu_context_key(cpu) != 0x04064BF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064BF8u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C97Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC980u;
    if (sm_scpu_context_key(cpu) != 0x04064C00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064C00u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C980u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC981u;
    if (sm_scpu_context_key(cpu) != 0x04064C08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064C08u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80C981u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xC982u;
    if (sm_scpu_context_key(cpu) != 0x04064C10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064C10u: {
    static const uint8_t source_bytes[] = {0x65u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C982u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
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
    cpu->pc = 0xC984u;
    if (sm_scpu_context_key(cpu) != 0x04064C20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064C20u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x56u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C984u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1956u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC987u;
    if (sm_scpu_context_key(cpu) != 0x04064C38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064C38u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x3Eu};
    if (sm_scpu_guard_code(cpu,bus,0x80C987u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x3Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC989u;
    if (sm_scpu_context_key(cpu) != 0x04064C48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064C48u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x80C989u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC98Au;
    if (sm_scpu_context_key(cpu) != 0x04064C50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04064C50u: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80C98Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x000Fu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC98Du;
    if (sm_scpu_context_key(cpu) != 0x04064C68u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04064C68u: {
    static const uint8_t source_bytes[] = {0x85u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80C98Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC98Fu;
    if (sm_scpu_context_key(cpu) != 0x04064C78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064C78u: {
    static const uint8_t source_bytes[] = {0x20u, 0x18u, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x80C98Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xC991u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC918u;
    if (sm_scpu_context_key(cpu) != 0x040648C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04064C90u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x58u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C992u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1958u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC995u;
    if (sm_scpu_context_key(cpu) != 0x04064CA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064CA8u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x5Au, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C995u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x195Au;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC998u;
    if (sm_scpu_context_key(cpu) != 0x04064CC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064CC0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C998u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC99Au;
    if (sm_scpu_context_key(cpu) != 0x04064CD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064CD0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x59u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C99Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1959u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC99Du;
    if (sm_scpu_context_key(cpu) != 0x04064CE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064CE8u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x36u};
    if (sm_scpu_guard_code(cpu,bus,0x80C99Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x36u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC99Fu;
    if (sm_scpu_context_key(cpu) != 0x04064CF8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064CF8u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x5Bu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C99Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x195Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC9A2u;
    if (sm_scpu_context_key(cpu) != 0x04064D10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064D10u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x3Eu};
    if (sm_scpu_guard_code(cpu,bus,0x80C9A2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x3Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9A4u;
    if (sm_scpu_context_key(cpu) != 0x04064D20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064D20u: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0x80C9A4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9A5u;
    if (sm_scpu_context_key(cpu) != 0x04064D28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04064D28u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C9A5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9A6u;
    if (sm_scpu_context_key(cpu) != 0x04064D30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064D30u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C9A6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9A7u;
    if (sm_scpu_context_key(cpu) != 0x04064D38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064D38u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C9A7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9A8u;
    if (sm_scpu_context_key(cpu) != 0x04064D40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064D40u: {
    static const uint8_t source_bytes[] = {0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C9A8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    cpu->a = (uint16_t)(left >> 1u);
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | (left & 1u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9A9u;
    if (sm_scpu_context_key(cpu) != 0x04064D48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064D48u: {
    static const uint8_t source_bytes[] = {0x29u, 0x0Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9A9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x000Fu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9ACu;
    if (sm_scpu_context_key(cpu) != 0x04064D60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04064D60u: {
    static const uint8_t source_bytes[] = {0x85u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9ACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC9AEu;
    if (sm_scpu_context_key(cpu) != 0x04064D70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064D70u: {
    static const uint8_t source_bytes[] = {0x20u, 0x18u, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9AEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xC9B0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC918u;
    if (sm_scpu_context_key(cpu) != 0x040648C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04064D88u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x5Cu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9B1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x195Cu;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC9B4u;
    if (sm_scpu_context_key(cpu) != 0x04064DA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064DA0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x34u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9B4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x34u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9B6u;
    if (sm_scpu_context_key(cpu) != 0x04064DB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064DB0u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C9B6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9B7u;
    if (sm_scpu_context_key(cpu) != 0x04064DB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064DB8u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C9B7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9B8u;
    if (sm_scpu_context_key(cpu) != 0x04064DC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064DC0u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C9B8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9B9u;
    if (sm_scpu_context_key(cpu) != 0x04064DC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064DC8u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x80C9B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9BAu;
    if (sm_scpu_context_key(cpu) != 0x04064DD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064DD0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x5Du, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x195Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC9BDu;
    if (sm_scpu_context_key(cpu) != 0x04064DE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064DE8u: {
    static const uint8_t source_bytes[] = {0xADu, 0x51u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9BDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1951u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9C0u;
    if (sm_scpu_context_key(cpu) != 0x04064E00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064E00u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xC9C1u;
    if (sm_scpu_context_key(cpu) != 0x04064E08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064E08u: {
    static const uint8_t source_bytes[] = {0x6Du, 0x55u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9C1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1955u;
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
    cpu->pc = 0xC9C4u;
    if (sm_scpu_context_key(cpu) != 0x04064E20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064E20u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9C4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xC9C5u;
    if (sm_scpu_context_key(cpu) != 0x04064E28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064E28u: {
    static const uint8_t source_bytes[] = {0x6Du, 0x59u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1959u;
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
    cpu->pc = 0xC9C8u;
    if (sm_scpu_context_key(cpu) != 0x04064E40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064E40u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9C8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xC9C9u;
    if (sm_scpu_context_key(cpu) != 0x04064E48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04064E48u: {
    static const uint8_t source_bytes[] = {0x6Du, 0x5Du, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x195Du;
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
    cpu->pc = 0xC9CCu;
    if (sm_scpu_context_key(cpu) != 0x04064E60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04064E60u: {
    static const uint8_t source_bytes[] = {0x85u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9CCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC9CEu;
    if (sm_scpu_context_key(cpu) != 0x04064E70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04064E70u: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = low;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC9CFu;
    if (sm_scpu_context_key(cpu) != 0x04064E78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04064E78u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80C9CFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04065800u && sm_scpu_context_key(cpu) != 0x04065890u && sm_scpu_context_key(cpu) != 0x04065920u && sm_scpu_context_key(cpu) != 0x040659B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04065702u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAE0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xCAE2u;
    if (sm_scpu_context_key(cpu) != 0x04065710u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04065703u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAE0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xCAE2u;
    if (sm_scpu_context_key(cpu) != 0x04065710u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04065710u: {
    static const uint8_t source_bytes[] = {0xADu, 0x40u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAE2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1940u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCAE5u;
    if (sm_scpu_context_key(cpu) != 0x04065728u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04065728u: {
    static const uint8_t source_bytes[] = {0xD0u, 0x03u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAE5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0xCAEAu;
        cycles = 3u;
    } else {
        cpu->pc = 0xCAE7u;
    }
    if (sm_scpu_context_key(cpu) != 0x04065738u && sm_scpu_context_key(cpu) != 0x04065750u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x04065738u: {
    static const uint8_t source_bytes[] = {0x82u, 0xA0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAE7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB8Au;
    if (sm_scpu_context_key(cpu) != 0x04065C50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065750u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAEAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xCAEBu;
    if (sm_scpu_context_key(cpu) != 0x04065758u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04065758u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAEBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xCAEDu;
    if (sm_scpu_context_key(cpu) != 0x0406576Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0406576Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAEDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCAEFu;
    if (sm_scpu_context_key(cpu) != 0x0406577Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0406577Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAEFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2105u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCAF2u;
    if (sm_scpu_context_key(cpu) != 0x04065792u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065792u: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAF2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xCAF3u;
    if (sm_scpu_context_key(cpu) != 0x04065798u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065798u: {
    static const uint8_t source_bytes[] = {0xADu, 0x42u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAF3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1942u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCAF6u;
    if (sm_scpu_context_key(cpu) != 0x040657B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040657B0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAF6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCAF8u;
    if (sm_scpu_context_key(cpu) != 0x040657C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040657C0u: {
    static const uint8_t source_bytes[] = {0xADu, 0x64u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAF8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1964u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCAFBu;
    if (sm_scpu_context_key(cpu) != 0x040657D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040657D8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAFBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCAFDu;
    if (sm_scpu_context_key(cpu) != 0x040657E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040657E8u: {
    static const uint8_t source_bytes[] = {0x20u, 0x3Bu, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x80CAFDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xCAFFu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC93Bu;
    if (sm_scpu_context_key(cpu) != 0x040649D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04065800u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB00u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB02u;
    if (sm_scpu_context_key(cpu) != 0x04065810u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04065810u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB02u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1942u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB05u;
    if (sm_scpu_context_key(cpu) != 0x04065828u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04065828u: {
    static const uint8_t source_bytes[] = {0xADu, 0x44u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB05u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1944u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB08u;
    if (sm_scpu_context_key(cpu) != 0x04065840u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04065840u: {
    static const uint8_t source_bytes[] = {0x85u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB08u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB0Au;
    if (sm_scpu_context_key(cpu) != 0x04065850u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04065850u: {
    static const uint8_t source_bytes[] = {0xADu, 0x64u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB0Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1964u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB0Du;
    if (sm_scpu_context_key(cpu) != 0x04065868u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04065868u: {
    static const uint8_t source_bytes[] = {0x85u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB0Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB0Fu;
    if (sm_scpu_context_key(cpu) != 0x04065878u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04065878u: {
    static const uint8_t source_bytes[] = {0x20u, 0x3Bu, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB0Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xCB11u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC93Bu;
    if (sm_scpu_context_key(cpu) != 0x040649D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04065890u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB12u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB14u;
    if (sm_scpu_context_key(cpu) != 0x040658A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040658A0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x44u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB14u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1944u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB17u;
    if (sm_scpu_context_key(cpu) != 0x040658B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040658B8u: {
    static const uint8_t source_bytes[] = {0xADu, 0x46u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB17u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1946u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB1Au;
    if (sm_scpu_context_key(cpu) != 0x040658D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040658D0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB1Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB1Cu;
    if (sm_scpu_context_key(cpu) != 0x040658E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040658E0u: {
    static const uint8_t source_bytes[] = {0xADu, 0x66u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB1Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1966u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB1Fu;
    if (sm_scpu_context_key(cpu) != 0x040658F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040658F8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB1Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB21u;
    if (sm_scpu_context_key(cpu) != 0x04065908u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04065908u: {
    static const uint8_t source_bytes[] = {0x20u, 0x3Bu, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB21u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xCB23u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC93Bu;
    if (sm_scpu_context_key(cpu) != 0x040649D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04065920u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB24u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB26u;
    if (sm_scpu_context_key(cpu) != 0x04065930u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04065930u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x46u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB26u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1946u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB29u;
    if (sm_scpu_context_key(cpu) != 0x04065948u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04065948u: {
    static const uint8_t source_bytes[] = {0xADu, 0x48u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB29u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1948u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB2Cu;
    if (sm_scpu_context_key(cpu) != 0x04065960u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04065960u: {
    static const uint8_t source_bytes[] = {0x85u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB2Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB2Eu;
    if (sm_scpu_context_key(cpu) != 0x04065970u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04065970u: {
    static const uint8_t source_bytes[] = {0xADu, 0x66u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB2Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1966u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB31u;
    if (sm_scpu_context_key(cpu) != 0x04065988u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x04065988u: {
    static const uint8_t source_bytes[] = {0x85u, 0x32u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB31u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x32u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB33u;
    if (sm_scpu_context_key(cpu) != 0x04065998u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04065998u: {
    static const uint8_t source_bytes[] = {0x20u, 0x3Bu, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB33u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xCB35u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC93Bu;
    if (sm_scpu_context_key(cpu) != 0x040649D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040659B0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB36u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x30u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB38u;
    if (sm_scpu_context_key(cpu) != 0x040659C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040659C0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x48u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB38u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1948u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB3Bu;
    if (sm_scpu_context_key(cpu) != 0x040659D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040659D8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB3Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xCB3Du;
    if (sm_scpu_context_key(cpu) != 0x040659EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040659EAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x42u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB3Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1942u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB40u;
    if (sm_scpu_context_key(cpu) != 0x04065A02u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065A02u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB40u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB43u;
    if (sm_scpu_context_key(cpu) != 0x04065A1Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065A1Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x43u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB43u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1943u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB46u;
    if (sm_scpu_context_key(cpu) != 0x04065A32u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065A32u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB46u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB49u;
    if (sm_scpu_context_key(cpu) != 0x04065A4Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065A4Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x44u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB49u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1944u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB4Cu;
    if (sm_scpu_context_key(cpu) != 0x04065A62u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065A62u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB4Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB4Fu;
    if (sm_scpu_context_key(cpu) != 0x04065A7Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065A7Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x45u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB4Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1945u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB52u;
    if (sm_scpu_context_key(cpu) != 0x04065A92u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065A92u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB52u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB55u;
    if (sm_scpu_context_key(cpu) != 0x04065AAAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065AAAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x46u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB55u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1946u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB58u;
    if (sm_scpu_context_key(cpu) != 0x04065AC2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065AC2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB58u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB5Bu;
    if (sm_scpu_context_key(cpu) != 0x04065ADAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065ADAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x47u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB5Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1947u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB5Eu;
    if (sm_scpu_context_key(cpu) != 0x04065AF2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065AF2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB5Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB61u;
    if (sm_scpu_context_key(cpu) != 0x04065B0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065B0Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x48u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB61u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1948u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB64u;
    if (sm_scpu_context_key(cpu) != 0x04065B22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065B22u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB64u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB67u;
    if (sm_scpu_context_key(cpu) != 0x04065B3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065B3Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x49u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB67u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1949u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB6Au;
    if (sm_scpu_context_key(cpu) != 0x04065B52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065B52u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB6Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB6Du;
    if (sm_scpu_context_key(cpu) != 0x04065B6Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065B6Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Au, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB6Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB70u;
    if (sm_scpu_context_key(cpu) != 0x04065B82u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065B82u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB70u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB73u;
    if (sm_scpu_context_key(cpu) != 0x04065B9Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065B9Au: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Bu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB73u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Bu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB76u;
    if (sm_scpu_context_key(cpu) != 0x04065BB2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065BB2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB76u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x211Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB79u;
    if (sm_scpu_context_key(cpu) != 0x04065BCAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065BCAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Cu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB79u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Cu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB7Cu;
    if (sm_scpu_context_key(cpu) != 0x04065BE2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065BE2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x20u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB7Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2120u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB7Fu;
    if (sm_scpu_context_key(cpu) != 0x04065BFAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065BFAu: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Du, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB7Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x194Du;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB82u;
    if (sm_scpu_context_key(cpu) != 0x04065C12u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065C12u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x20u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB82u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2120u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB85u;
    if (sm_scpu_context_key(cpu) != 0x04065C2Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065C2Au: {
    static const uint8_t source_bytes[] = {0xA5u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB85u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x42u);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB87u;
    if (sm_scpu_context_key(cpu) != 0x04065C3Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04065C3Au: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB87u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2105u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB8Au;
    if (sm_scpu_context_key(cpu) != 0x04065C52u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x04065C50u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB8Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04041428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04065C52u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80CB8Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0404142Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04075A02u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x80EB40u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xEB41u;
    if (sm_scpu_context_key(cpu) != 0x04075A0Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04075A0Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x80EB41u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xEB43u;
    if (sm_scpu_context_key(cpu) != 0x04075A18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0407AF19u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F5E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407A931u && sm_scpu_context_key(cpu) != 0x0407A981u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0407B031u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80F606u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0407A931u && sm_scpu_context_key(cpu) != 0x0407A981u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040D6228u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x81AC45u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xAC47u;
    if (sm_scpu_context_key(cpu) != 0x040D6238u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040D6238u: {
    static const uint8_t source_bytes[] = {0xADu, 0x44u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x81AC47u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F44u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAC4Au;
    if (sm_scpu_context_key(cpu) != 0x040D6250u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6250u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Du, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81AC4Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A2Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC4Du;
    if (sm_scpu_context_key(cpu) != 0x040D6268u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6268u: {
    static const uint8_t source_bytes[] = {0xADu, 0x46u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x81AC4Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F46u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAC50u;
    if (sm_scpu_context_key(cpu) != 0x040D6280u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6280u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x31u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81AC50u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A31u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC53u;
    if (sm_scpu_context_key(cpu) != 0x040D6298u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6298u: {
    static const uint8_t source_bytes[] = {0xADu, 0x40u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x81AC53u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F40u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAC56u;
    if (sm_scpu_context_key(cpu) != 0x040D62B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D62B0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x81AC56u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x100Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC59u;
    if (sm_scpu_context_key(cpu) != 0x040D62C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D62C8u: {
    static const uint8_t source_bytes[] = {0x38u};
    if (sm_scpu_guard_code(cpu,bus,0x81AC59u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | SM_P_C);
    cpu->pc = 0xAC5Au;
    if (sm_scpu_context_key(cpu) != 0x040D62D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040D62D0u: {
    static const uint8_t source_bytes[] = {0xEDu, 0x2Du, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81AC5Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A2Du;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + (value ^ 0xFFFFu) + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (((left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xAC5Du;
    if (sm_scpu_context_key(cpu) != 0x040D62E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D62E8u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x16u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x81AC5Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1016u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC60u;
    if (sm_scpu_context_key(cpu) != 0x040D6300u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6300u: {
    static const uint8_t source_bytes[] = {0xADu, 0x42u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x81AC60u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F42u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAC63u;
    if (sm_scpu_context_key(cpu) != 0x040D6318u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6318u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Fu, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x81AC63u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x100Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC66u;
    if (sm_scpu_context_key(cpu) != 0x040D6330u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6330u: {
    static const uint8_t source_bytes[] = {0x38u};
    if (sm_scpu_guard_code(cpu,bus,0x81AC66u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | SM_P_C);
    cpu->pc = 0xAC67u;
    if (sm_scpu_context_key(cpu) != 0x040D6338u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040D6338u: {
    static const uint8_t source_bytes[] = {0xEDu, 0x31u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81AC67u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A31u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t left = cpu->a;
    uint32_t sum = (uint32_t)left + (value ^ 0xFFFFu) + ((cpu->p & SM_P_C) != 0u);
    uint16_t result = (uint16_t)sum;
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_V | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (((left ^ value) & (left ^ result) & 0x8000u) != 0u ? SM_P_V : 0u) | (result == 0u ? SM_P_Z : 0u) | (sum > 0xFFFFu ? SM_P_C : 0u));
    cpu->pc = 0xAC6Au;
    if (sm_scpu_context_key(cpu) != 0x040D6350u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6350u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x18u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x81AC6Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1018u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC6Du;
    if (sm_scpu_context_key(cpu) != 0x040D6368u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6368u: {
    static const uint8_t source_bytes[] = {0xADu, 0x48u, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x81AC6Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F48u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAC70u;
    if (sm_scpu_context_key(cpu) != 0x040D6380u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6380u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x18u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81AC70u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A18u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC73u;
    if (sm_scpu_context_key(cpu) != 0x040D6398u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6398u: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Au, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x81AC73u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F4Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAC76u;
    if (sm_scpu_context_key(cpu) != 0x040D63B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D63B0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Au, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81AC76u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A1Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC79u;
    if (sm_scpu_context_key(cpu) != 0x040D63C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D63C8u: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Cu, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x81AC79u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F4Cu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAC7Cu;
    if (sm_scpu_context_key(cpu) != 0x040D63E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D63E0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Cu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81AC7Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A1Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC7Fu;
    if (sm_scpu_context_key(cpu) != 0x040D63F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D63F8u: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Eu, 0x1Fu};
    if (sm_scpu_guard_code(cpu,bus,0x81AC7Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1F4Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xAC82u;
    if (sm_scpu_context_key(cpu) != 0x040D6410u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6410u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x1Eu, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x81AC82u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A1Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xAC85u;
    if (sm_scpu_context_key(cpu) != 0x040D6428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x040D6428u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81AC85u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040D5C88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040E4F48u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9E9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC9EAu;
    if (sm_scpu_context_key(cpu) != 0x040E4F50u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040E4F50u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9EAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC9EBu;
    if (sm_scpu_context_key(cpu) != 0x040E4F58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040E4F58u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9ECu;
    if (sm_scpu_context_key(cpu) != 0x040E4F60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040E4F60u: {
    static const uint8_t source_bytes[] = {0x20u, 0xDEu, 0xC9u};
    if (sm_scpu_guard_code(cpu,bus,0x81C9ECu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xC9EEu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC9DEu;
    if (sm_scpu_context_key(cpu) != 0x040E4EF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040E4F78u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC9F0u;
    if (sm_scpu_context_key(cpu) != 0x040E4F80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040E4F80u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81C9F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04076770u && sm_scpu_context_key(cpu) != 0x040768E0u && sm_scpu_context_key(cpu) != 0x040C1270u && sm_scpu_context_key(cpu) != 0x040C3540u && sm_scpu_context_key(cpu) != 0x040E0090u && sm_scpu_context_key(cpu) != 0x040E0F20u && sm_scpu_context_key(cpu) != 0x040E1E98u && sm_scpu_context_key(cpu) != 0x040E37F8u && sm_scpu_context_key(cpu) != 0x0414CFC0u && sm_scpu_context_key(cpu) != 0x04151B78u && sm_scpu_context_key(cpu) != 0x041521C0u && sm_scpu_context_key(cpu) != 0x041522F8u && sm_scpu_context_key(cpu) != 0x04152598u && sm_scpu_context_key(cpu) != 0x041526B8u && sm_scpu_context_key(cpu) != 0x0415E798u && sm_scpu_context_key(cpu) != 0x0416F930u && sm_scpu_context_key(cpu) != 0x0416F998u && sm_scpu_context_key(cpu) != 0x0416FA30u && sm_scpu_context_key(cpu) != 0x0416FAC8u && sm_scpu_context_key(cpu) != 0x0416FB60u && sm_scpu_context_key(cpu) != 0x0416FBF8u && sm_scpu_context_key(cpu) != 0x0416FC90u && sm_scpu_context_key(cpu) != 0x0416FD28u && sm_scpu_context_key(cpu) != 0x0416FDC0u && sm_scpu_context_key(cpu) != 0x0417C4B0u && sm_scpu_context_key(cpu) != 0x041EFFB0u && sm_scpu_context_key(cpu) != 0x043DE5F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040F0CD0u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81E19Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xE19Bu;
    if (sm_scpu_context_key(cpu) != 0x040F0CD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F0CD8u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81E19Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xE19Cu;
    if (sm_scpu_context_key(cpu) != 0x040F0CE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F0CE0u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x81E19Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE19Du;
    if (sm_scpu_context_key(cpu) != 0x040F0CE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040F0CE8u: {
    static const uint8_t source_bytes[] = {0x20u, 0xA2u, 0xE1u};
    if (sm_scpu_guard_code(cpu,bus,0x81E19Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xE19Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xE1A2u;
    if (sm_scpu_context_key(cpu) != 0x040F0D10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040F0D00u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x81E1A0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE1A1u;
    if (sm_scpu_context_key(cpu) != 0x040F0D08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040F0D08u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81E1A1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040E15B0u && sm_scpu_context_key(cpu) != 0x040F0EA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040F0DC8u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81E1B9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xE1BAu;
    if (sm_scpu_context_key(cpu) != 0x040F0DD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F0DD0u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81E1BAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xE1BBu;
    if (sm_scpu_context_key(cpu) != 0x040F0DD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040F0DD8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x81E1BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE1BCu;
    if (sm_scpu_context_key(cpu) != 0x040F0DE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040F0DE0u: {
    static const uint8_t source_bytes[] = {0x20u, 0xC1u, 0xE1u};
    if (sm_scpu_guard_code(cpu,bus,0x81E1BCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xE1BEu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xE1C1u;
    if (sm_scpu_context_key(cpu) != 0x040F0E08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040F0DF8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0x81E1BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE1C0u;
    if (sm_scpu_context_key(cpu) != 0x040F0E00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040F0E00u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81E1C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040E1938u && sm_scpu_context_key(cpu) != 0x040F0F10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0415D798u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82BAF3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBAF5u;
    if (sm_scpu_context_key(cpu) != 0x0415D7ABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415D7ABu: {
    static const uint8_t source_bytes[] = {0xC6u, 0x84u};
    if (sm_scpu_guard_code(cpu,bus,0x82BAF5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x84u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBAF7u;
    if (sm_scpu_context_key(cpu) != 0x0415D7BBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0415D7BBu: {
    static const uint8_t source_bytes[] = {0xC6u, 0xACu};
    if (sm_scpu_guard_code(cpu,bus,0x82BAF7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xACu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBAF9u;
    if (sm_scpu_context_key(cpu) != 0x0415D7CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0415D7CBu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82BAF9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBAFBu;
    if (sm_scpu_context_key(cpu) != 0x0415D7D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415D7D8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82BAFBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0415D620u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0415DAD8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB5Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBB5Du;
    if (sm_scpu_context_key(cpu) != 0x0415DAE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415DAE8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB5Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB60u;
    if (sm_scpu_context_key(cpu) != 0x0415DB00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415DB00u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x74u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB60u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1974u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBB63u;
    if (sm_scpu_context_key(cpu) != 0x0415DB18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415DB18u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x08u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB63u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0008u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB66u;
    if (sm_scpu_context_key(cpu) != 0x0415DB30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415DB30u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x7Au, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB66u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x197Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBB69u;
    if (sm_scpu_context_key(cpu) != 0x0415DB48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415DB48u: {
    static const uint8_t source_bytes[] = {0xAEu, 0x16u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB69u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1916u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBB6Cu;
    if (sm_scpu_context_key(cpu) != 0x0415DB60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415DB60u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x70u, 0xBBu};
    if (sm_scpu_guard_code(cpu,bus,0x82BB6Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xBB6Eu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xBB70u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xBB74u) || (cpu->x == 0x0002u && target == 0xBB88u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x0415DBA0u && sm_scpu_context_key(cpu) != 0x0415DC40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x0415DB78u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82BB6Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0415DAB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0415EA60u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82BD4Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBD4Eu;
    if (sm_scpu_context_key(cpu) != 0x0415EA70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415EA70u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x1Eu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x82BD4Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x191Eu;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD51u;
    if (sm_scpu_context_key(cpu) != 0x0415EA88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415EA88u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82BD51u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD54u;
    if (sm_scpu_context_key(cpu) != 0x0415EAA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0415EAA0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Cu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x82BD54u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x190Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD57u;
    if (sm_scpu_context_key(cpu) != 0x0415EAB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415EAB8u: {
    static const uint8_t source_bytes[] = {0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0x82BD57u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a + 1u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD58u;
    if (sm_scpu_context_key(cpu) != 0x0415EAC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0415EAC0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Au, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x82BD58u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x190Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD5Bu;
    if (sm_scpu_context_key(cpu) != 0x0415EAD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415EAD8u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x04u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x82BD5Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A04u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD5Eu;
    if (sm_scpu_context_key(cpu) != 0x0415EAF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415EAF0u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x06u, 0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x82BD5Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0A06u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xBD61u;
    if (sm_scpu_context_key(cpu) != 0x0415EB08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415EB08u: {
    static const uint8_t source_bytes[] = {0xAEu, 0x82u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x82BD61u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0782u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD64u;
    if (sm_scpu_context_key(cpu) != 0x0415EB20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x0415EB20u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x68u, 0xBDu};
    if (sm_scpu_guard_code(cpu,bus,0x82BD64u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u || cpu->x == 0x0006u || cpu->x == 0x0008u || cpu->x == 0x000Au)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xBD66u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xBD68u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xBD74u) || (cpu->x == 0x0002u && target == 0xBD87u) || (cpu->x == 0x0004u && target == 0xBD9Au) || (cpu->x == 0x0006u && target == 0xBDADu) || (cpu->x == 0x0008u && target == 0xBDC0u) || (cpu->x == 0x000Au && target == 0xBDD3u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x0415EBA0u && sm_scpu_context_key(cpu) != 0x0415EC38u && sm_scpu_context_key(cpu) != 0x0415ECD0u && sm_scpu_context_key(cpu) != 0x0415ED68u && sm_scpu_context_key(cpu) != 0x0415EE00u && sm_scpu_context_key(cpu) != 0x0415EE98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x0415EB38u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82BD67u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0415D3D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04160690u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82C0D2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC0D4u;
    if (sm_scpu_context_key(cpu) != 0x041606A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041606A0u: {
    static const uint8_t source_bytes[] = {0x22u, 0xE6u, 0xBCu, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x82C0D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xC0D7u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBCE6u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x0405E730u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041606C0u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x82C0D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC0DAu;
    if (sm_scpu_context_key(cpu) != 0x041606D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041606D2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x06u};
    if (sm_scpu_guard_code(cpu,bus,0x82C0DAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0006u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC0DCu;
    if (sm_scpu_context_key(cpu) != 0x041606E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041606E2u: {
    static const uint8_t source_bytes[] = {0x85u, 0x9Au};
    if (sm_scpu_guard_code(cpu,bus,0x82C0DCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x9Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC0DEu;
    if (sm_scpu_context_key(cpu) != 0x041606F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041606F2u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82C0DEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0415D812u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04165B50u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB6Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xCB6Cu;
    if (sm_scpu_context_key(cpu) != 0x04165B63u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04165B63u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB6Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xCB6Eu;
    if (sm_scpu_context_key(cpu) != 0x04165B73u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04165B73u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x44u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB6Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0044u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB70u;
    if (sm_scpu_context_key(cpu) != 0x04165B83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04165B83u: {
    static const uint8_t source_bytes[] = {0x85u, 0x73u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB70u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x73u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xCB72u;
    if (sm_scpu_context_key(cpu) != 0x04165B93u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04165B93u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB72u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xCB74u;
    if (sm_scpu_context_key(cpu) != 0x04165BA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04165BA0u: {
    static const uint8_t source_bytes[] = {0xEEu, 0xF0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB74u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x00F0u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB77u;
    if (sm_scpu_context_key(cpu) != 0x04165BB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04165BB8u: {
    static const uint8_t source_bytes[] = {0xEEu, 0xF0u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB77u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x00F0u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xCB7Au;
    if (sm_scpu_context_key(cpu) != 0x04165BD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04165BD0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB7Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041659B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0416E090u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC12u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xDC14u;
    if (sm_scpu_context_key(cpu) != 0x0416E0A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416E0A0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xEFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x82DC14u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFFEFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xDC17u;
    if (sm_scpu_context_key(cpu) != 0x0416E0B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0416E0B8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC17u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xDC19u;
    if (sm_scpu_context_key(cpu) != 0x0416E0C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416E0C8u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC19u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x88u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xDC1Bu;
    if (sm_scpu_context_key(cpu) != 0x0416E0D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416E0D8u: {
    static const uint8_t source_bytes[] = {0x20u, 0xF9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC1Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xDC1Du;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8F9u;
    if (sm_scpu_context_key(cpu) != 0x0417C7C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0416E0F0u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC1Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xDC20u;
    if (sm_scpu_context_key(cpu) != 0x0416E100u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416E100u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC20u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xDC23u;
    if (sm_scpu_context_key(cpu) != 0x0416E118u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0416E118u: {
    static const uint8_t source_bytes[] = {0x85u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC23u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xDC25u;
    if (sm_scpu_context_key(cpu) != 0x0416E128u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416E128u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC25u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xDC27u;
    if (sm_scpu_context_key(cpu) != 0x0416E138u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416E138u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC27u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xDC29u;
    if (sm_scpu_context_key(cpu) != 0x0416E148u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416E148u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC29u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xDC2Bu;
    if (sm_scpu_context_key(cpu) != 0x0416E158u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416E158u: {
    static const uint8_t source_bytes[] = {0x22u, 0xF7u, 0xAFu, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC2Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xDC2Eu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xAFF7u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04057FB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x0416E178u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC2Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xDC32u;
    if (sm_scpu_context_key(cpu) != 0x0416E190u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0416E190u: {
    static const uint8_t source_bytes[] = {0x20u, 0xE9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC32u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xDC34u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8E9u;
    if (sm_scpu_context_key(cpu) != 0x0417C748u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0416E1A8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82DC35u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0416D180u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0416EA80u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82DD50u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xDD52u;
    if (sm_scpu_context_key(cpu) != 0x0416EA90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0416EA90u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x82DD52u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x88u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xDD54u;
    if (sm_scpu_context_key(cpu) != 0x0416EAA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416EAA0u: {
    static const uint8_t source_bytes[] = {0xB5u, 0x4Cu};
    if (sm_scpu_guard_code(cpu,bus,0x82DD54u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Cu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xDD56u;
    if (sm_scpu_context_key(cpu) != 0x0416EAB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x0416EAB0u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x82DD56u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xDD57u;
    if (sm_scpu_context_key(cpu) != 0x0416EAB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0416EAB8u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x5Bu, 0xDDu};
    if (sm_scpu_guard_code(cpu,bus,0x82DD57u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xDD59u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xDD5Bu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xDD61u) || (cpu->x == 0x0002u && target == 0xDD7Du) || (cpu->x == 0x0004u && target == 0xDD7Du))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x0416EB08u && sm_scpu_context_key(cpu) != 0x0416EBE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x0416EAD0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82DD5Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0416E978u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04170848u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82E109u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE10Bu;
    if (sm_scpu_context_key(cpu) != 0x04170858u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04170858u: {
    static const uint8_t source_bytes[] = {0x29u, 0xEFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x82E10Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFFEFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE10Eu;
    if (sm_scpu_context_key(cpu) != 0x04170870u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04170870u: {
    static const uint8_t source_bytes[] = {0x85u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82E10Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE110u;
    if (sm_scpu_context_key(cpu) != 0x04170880u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04170880u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x82E110u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x88u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE112u;
    if (sm_scpu_context_key(cpu) != 0x04170890u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04170890u: {
    static const uint8_t source_bytes[] = {0x20u, 0xF9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82E112u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xE114u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8F9u;
    if (sm_scpu_context_key(cpu) != 0x0417C7C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041708A8u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E115u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE117u;
    if (sm_scpu_context_key(cpu) != 0x041708B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041708B8u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82E117u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE11Au;
    if (sm_scpu_context_key(cpu) != 0x041708D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041708D0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x82E11Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE11Cu;
    if (sm_scpu_context_key(cpu) != 0x041708E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041708E0u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E11Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE11Eu;
    if (sm_scpu_context_key(cpu) != 0x041708F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041708F0u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E11Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE120u;
    if (sm_scpu_context_key(cpu) != 0x04170900u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04170900u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x82E120u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE122u;
    if (sm_scpu_context_key(cpu) != 0x04170910u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04170910u: {
    static const uint8_t source_bytes[] = {0x22u, 0x6Bu, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x82E122u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xE125u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB06Bu;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04058358u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04170930u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82E126u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE129u;
    if (sm_scpu_context_key(cpu) != 0x04170948u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04170948u: {
    static const uint8_t source_bytes[] = {0x20u, 0xE9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82E129u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xE12Bu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8E9u;
    if (sm_scpu_context_key(cpu) != 0x0417C748u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04170960u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82E12Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04170548u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04170DF8u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82E1BFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xE1C1u;
    if (sm_scpu_context_key(cpu) != 0x04170E08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04170E08u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x82E1C1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x88u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE1C3u;
    if (sm_scpu_context_key(cpu) != 0x04170E18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04170E18u: {
    static const uint8_t source_bytes[] = {0xB5u, 0x4Cu};
    if (sm_scpu_guard_code(cpu,bus,0x82E1C3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Cu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE1C5u;
    if (sm_scpu_context_key(cpu) != 0x04170E28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04170E28u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x82E1C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE1C6u;
    if (sm_scpu_context_key(cpu) != 0x04170E30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04170E30u: {
    static const uint8_t source_bytes[] = {0xFCu, 0xCAu, 0xE1u};
    if (sm_scpu_guard_code(cpu,bus,0x82E1C6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xE1C8u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xE1CAu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xE1CEu) || (cpu->x == 0x0002u && target == 0xE1E5u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x04170E70u && sm_scpu_context_key(cpu) != 0x04170F28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04170E48u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82E1C9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04170548u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041737D8u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82E6FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE6FDu;
    if (sm_scpu_context_key(cpu) != 0x041737E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041737E8u: {
    static const uint8_t source_bytes[] = {0x29u, 0xEFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x82E6FDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFFEFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE700u;
    if (sm_scpu_context_key(cpu) != 0x04173800u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04173800u: {
    static const uint8_t source_bytes[] = {0x85u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82E700u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE702u;
    if (sm_scpu_context_key(cpu) != 0x04173810u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173810u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x82E702u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x88u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE704u;
    if (sm_scpu_context_key(cpu) != 0x04173820u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173820u: {
    static const uint8_t source_bytes[] = {0x20u, 0xF9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82E704u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xE706u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8F9u;
    if (sm_scpu_context_key(cpu) != 0x0417C7C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04173838u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E707u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE709u;
    if (sm_scpu_context_key(cpu) != 0x04173848u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173848u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82E709u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE70Cu;
    if (sm_scpu_context_key(cpu) != 0x04173860u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04173860u: {
    static const uint8_t source_bytes[] = {0x85u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x82E70Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE70Eu;
    if (sm_scpu_context_key(cpu) != 0x04173870u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173870u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E70Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE710u;
    if (sm_scpu_context_key(cpu) != 0x04173880u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173880u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E710u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE712u;
    if (sm_scpu_context_key(cpu) != 0x04173890u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173890u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x82E712u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE714u;
    if (sm_scpu_context_key(cpu) != 0x041738A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041738A0u: {
    static const uint8_t source_bytes[] = {0x22u, 0x9Fu, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x82E714u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xE717u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB09Fu;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x040584F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041738C0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82E718u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE71Bu;
    if (sm_scpu_context_key(cpu) != 0x041738D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041738D8u: {
    static const uint8_t source_bytes[] = {0x20u, 0xE9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82E71Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xE71Du;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8E9u;
    if (sm_scpu_context_key(cpu) != 0x0417C748u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041738F0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82E71Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041735B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04173A38u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82E747u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE749u;
    if (sm_scpu_context_key(cpu) != 0x04173A48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173A48u: {
    static const uint8_t source_bytes[] = {0x29u, 0xEFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x82E749u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFFEFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE74Cu;
    if (sm_scpu_context_key(cpu) != 0x04173A60u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04173A60u: {
    static const uint8_t source_bytes[] = {0x85u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82E74Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE74Eu;
    if (sm_scpu_context_key(cpu) != 0x04173A70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173A70u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x82E74Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x88u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE750u;
    if (sm_scpu_context_key(cpu) != 0x04173A80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173A80u: {
    static const uint8_t source_bytes[] = {0x20u, 0xF9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82E750u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xE752u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8F9u;
    if (sm_scpu_context_key(cpu) != 0x0417C7C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04173A98u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E753u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE755u;
    if (sm_scpu_context_key(cpu) != 0x04173AA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173AA8u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82E755u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE758u;
    if (sm_scpu_context_key(cpu) != 0x04173AC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04173AC0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x82E758u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE75Au;
    if (sm_scpu_context_key(cpu) != 0x04173AD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173AD0u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E75Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE75Cu;
    if (sm_scpu_context_key(cpu) != 0x04173AE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173AE0u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E75Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE75Eu;
    if (sm_scpu_context_key(cpu) != 0x04173AF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173AF0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x82E75Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE760u;
    if (sm_scpu_context_key(cpu) != 0x04173B00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173B00u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E760u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE762u;
    if (sm_scpu_context_key(cpu) != 0x04173B10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173B10u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E762u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE764u;
    if (sm_scpu_context_key(cpu) != 0x04173B20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173B20u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82E764u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xE766u;
    if (sm_scpu_context_key(cpu) != 0x04173B30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173B30u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82E766u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE769u;
    if (sm_scpu_context_key(cpu) != 0x04173B48u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04173B48u: {
    static const uint8_t source_bytes[] = {0x85u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0x82E769u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE76Bu;
    if (sm_scpu_context_key(cpu) != 0x04173B58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173B58u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x82E76Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE76Eu;
    if (sm_scpu_context_key(cpu) != 0x04173B70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04173B70u: {
    static const uint8_t source_bytes[] = {0x85u, 0x26u};
    if (sm_scpu_guard_code(cpu,bus,0x82E76Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x26u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xE770u;
    if (sm_scpu_context_key(cpu) != 0x04173B80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04173B80u: {
    static const uint8_t source_bytes[] = {0x22u, 0x43u, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x82E770u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xE773u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB043u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04058218u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04173BA0u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x05u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82E774u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0005u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xE777u;
    if (sm_scpu_context_key(cpu) != 0x04173BB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04173BB8u: {
    static const uint8_t source_bytes[] = {0x20u, 0xE9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82E777u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xE779u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8E9u;
    if (sm_scpu_context_key(cpu) != 0x0417C748u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04173BD0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82E77Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041735B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041764D0u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82EC9Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xEC9Cu;
    if (sm_scpu_context_key(cpu) != 0x041764E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041764E0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xEFu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x82EC9Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0xFFEFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xEC9Fu;
    if (sm_scpu_context_key(cpu) != 0x041764F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041764F8u: {
    static const uint8_t source_bytes[] = {0x85u, 0x98u};
    if (sm_scpu_guard_code(cpu,bus,0x82EC9Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x98u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xECA1u;
    if (sm_scpu_context_key(cpu) != 0x04176508u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176508u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECA1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x88u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xECA3u;
    if (sm_scpu_context_key(cpu) != 0x04176518u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176518u: {
    static const uint8_t source_bytes[] = {0x20u, 0xF9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECA3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xECA5u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8F9u;
    if (sm_scpu_context_key(cpu) != 0x0417C7C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04176530u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECA6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECA8u;
    if (sm_scpu_context_key(cpu) != 0x04176540u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176540u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECA8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xECABu;
    if (sm_scpu_context_key(cpu) != 0x04176558u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04176558u: {
    static const uint8_t source_bytes[] = {0x85u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xECADu;
    if (sm_scpu_context_key(cpu) != 0x04176568u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176568u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECAFu;
    if (sm_scpu_context_key(cpu) != 0x04176578u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176578u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECAFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECB1u;
    if (sm_scpu_context_key(cpu) != 0x04176588u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176588u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECB1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xECB3u;
    if (sm_scpu_context_key(cpu) != 0x04176598u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176598u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECB3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECB5u;
    if (sm_scpu_context_key(cpu) != 0x041765A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041765A8u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECB5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECB7u;
    if (sm_scpu_context_key(cpu) != 0x041765B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041765B8u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECB7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECB9u;
    if (sm_scpu_context_key(cpu) != 0x041765C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041765C8u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECB9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xECBCu;
    if (sm_scpu_context_key(cpu) != 0x041765E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041765E0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x24u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECBCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x24u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xECBEu;
    if (sm_scpu_context_key(cpu) != 0x041765F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041765F0u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECBEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECC0u;
    if (sm_scpu_context_key(cpu) != 0x04176600u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176600u: {
    static const uint8_t source_bytes[] = {0xE6u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECC0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECC2u;
    if (sm_scpu_context_key(cpu) != 0x04176610u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176610u: {
    static const uint8_t source_bytes[] = {0xA7u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECC2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
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
    cpu->pc = 0xECC4u;
    if (sm_scpu_context_key(cpu) != 0x04176620u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,7u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176620u: {
    static const uint8_t source_bytes[] = {0x85u, 0x26u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECC4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x26u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xECC6u;
    if (sm_scpu_context_key(cpu) != 0x04176630u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04176630u: {
    static const uint8_t source_bytes[] = {0x22u, 0x43u, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECC6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xECC9u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB043u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04058218u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04176650u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x07u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECCAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0007u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xECCDu;
    if (sm_scpu_context_key(cpu) != 0x04176668u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04176668u: {
    static const uint8_t source_bytes[] = {0x20u, 0xE9u, 0xF8u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECCDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xECCFu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xF8E9u;
    if (sm_scpu_context_key(cpu) != 0x0417C748u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04176680u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82ECD0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04175258u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04177140u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x82EE28u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xEE2Au;
    if (sm_scpu_context_key(cpu) != 0x04177150u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x04177150u: {
    static const uint8_t source_bytes[] = {0x86u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x82EE2Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x02u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->x) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->x >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xEE2Cu;
    if (sm_scpu_context_key(cpu) != 0x04177160u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04177160u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x88u};
    if (sm_scpu_guard_code(cpu,bus,0x82EE2Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x88u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xEE2Eu;
    if (sm_scpu_context_key(cpu) != 0x04177170u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04177170u: {
    static const uint8_t source_bytes[] = {0xB5u, 0x4Cu};
    if (sm_scpu_guard_code(cpu,bus,0x82EE2Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Cu + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xEE30u;
    if (sm_scpu_context_key(cpu) != 0x04177180u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x04177180u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x82EE30u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xEE31u;
    if (sm_scpu_context_key(cpu) != 0x04177188u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04177188u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x35u, 0xEEu};
    if (sm_scpu_guard_code(cpu,bus,0x82EE31u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xEE33u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xEE35u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xEE39u) || (cpu->x == 0x0002u && target == 0xEE49u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x041771C8u && sm_scpu_context_key(cpu) != 0x04177248u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041771A0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82EE34u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04175258u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041C38F8u: {
    static const uint8_t source_bytes[] = {0x64u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x83871Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8721u;
    if (sm_scpu_context_key(cpu) != 0x041C3908u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C3908u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFEu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x838721u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFEu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8724u;
    if (sm_scpu_context_key(cpu) != 0x041C3920u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C3920u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x838724u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8726u;
    if (sm_scpu_context_key(cpu) != 0x041C3930u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C3930u: {
    static const uint8_t source_bytes[] = {0x22u, 0x6Bu, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x838726u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x8729u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB06Bu;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04058358u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041C3950u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x00u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x83872Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1900u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x872Du;
    if (sm_scpu_context_key(cpu) != 0x041C3968u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041C3968u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x00u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x83872Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1900u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8730u;
    if (sm_scpu_context_key(cpu) != 0x041C3980u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041C3980u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x838730u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041C3E38u && sm_scpu_context_key(cpu) != 0x041EEB08u && sm_scpu_context_key(cpu) != 0x041F5520u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041C3988u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x838731u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8733u;
    if (sm_scpu_context_key(cpu) != 0x041C3998u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C3998u: {
    static const uint8_t source_bytes[] = {0x64u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x838733u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8735u;
    if (sm_scpu_context_key(cpu) != 0x041C39A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C39A8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFEu, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0x838735u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xFFFEu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8738u;
    if (sm_scpu_context_key(cpu) != 0x041C39C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C39C0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x838738u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x873Au;
    if (sm_scpu_context_key(cpu) != 0x041C39D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C39D0u: {
    static const uint8_t source_bytes[] = {0x22u, 0x85u, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x83873Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x873Du;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB085u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04058428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041C39F0u: {
    static const uint8_t source_bytes[] = {0x22u, 0x0Du, 0xB2u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x83873Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0x8741u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB20Du;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04059068u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041C3A10u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x00u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x838742u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1900u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8745u;
    if (sm_scpu_context_key(cpu) != 0x041C3A28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041C3A28u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x00u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x838745u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1900u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8748u;
    if (sm_scpu_context_key(cpu) != 0x041C3A40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041C3A40u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x838748u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041C4118u && sm_scpu_context_key(cpu) != 0x041EEB78u && sm_scpu_context_key(cpu) != 0x041F5590u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041C3E10u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8387C2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x87C4u;
    if (sm_scpu_context_key(cpu) != 0x041C3E20u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C3E20u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Fu, 0x87u};
    if (sm_scpu_guard_code(cpu,bus,0x8387C4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x87C6u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x871Fu;
    if (sm_scpu_context_key(cpu) != 0x041C38F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041C3E38u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8387C7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041C46B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041CBF08u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x8397E1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x97E3u;
    if (sm_scpu_context_key(cpu) != 0x041CBF18u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CBF18u: {
    static const uint8_t source_bytes[] = {0x20u, 0x53u, 0x85u};
    if (sm_scpu_guard_code(cpu,bus,0x8397E3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x97E5u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8553u;
    if (sm_scpu_context_key(cpu) != 0x041C2A98u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041CBF30u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x8397E6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x97E8u;
    if (sm_scpu_context_key(cpu) != 0x041CBF40u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041CBF40u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8397E8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x97EBu;
    if (sm_scpu_context_key(cpu) != 0x041CBF58u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041CBF58u: {
    static const uint8_t source_bytes[] = {0xD0u, 0x08u};
    if (sm_scpu_guard_code(cpu,bus,0x8397EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x97F5u;
        cycles = 3u;
    } else {
        cpu->pc = 0x97EDu;
    }
    if (sm_scpu_context_key(cpu) != 0x041CBF68u && sm_scpu_context_key(cpu) != 0x041CBFA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x041CBF68u: {
    static const uint8_t source_bytes[] = {0xADu, 0x2Eu, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x8397EDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x192Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x97F0u;
    if (sm_scpu_context_key(cpu) != 0x041CBF80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x041CBF80u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0x8397F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x97F1u;
    if (sm_scpu_context_key(cpu) != 0x041CBF88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041CBF88u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0x8397F1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x97F2u;
    if (sm_scpu_context_key(cpu) != 0x041CBF90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041CBF90u: {
    static const uint8_t source_bytes[] = {0xFCu, 0xF6u, 0x97u};
    if (sm_scpu_guard_code(cpu,bus,0x8397F2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0x97F4u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x97F6u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0x97FCu) || (cpu->x == 0x0002u && target == 0x9828u) || (cpu->x == 0x0004u && target == 0x9854u))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x041CBFE0u && sm_scpu_context_key(cpu) != 0x041CC140u && sm_scpu_context_key(cpu) != 0x041CC2A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x041CBFA8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8397F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041CBF00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041EEAF0u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Fu, 0x87u};
    if (sm_scpu_guard_code(cpu,bus,0x83DD5Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xDD60u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x871Fu;
    if (sm_scpu_context_key(cpu) != 0x041C38F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041EEB08u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83DD61u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041EEA00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041F5508u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Fu, 0x87u};
    if (sm_scpu_guard_code(cpu,bus,0x83EAA1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0xEAA3u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x871Fu;
    if (sm_scpu_context_key(cpu) != 0x041C38F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041F5520u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83EAA4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041F5418u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04265388u: {
    static const uint8_t source_bytes[] = {0x22u, 0x07u, 0xBDu, 0xA6u};
    if (sm_scpu_guard_code(cpu,bus,0x84CA71u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xCA74u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBD07u;
    cpu->pbr = 0xA6u;
    if (sm_scpu_context_key(cpu) != 0x0535E838u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x042653A8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84CA75u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x042653D8u: {
    static const uint8_t source_bytes[] = {0x22u, 0x6Eu, 0xBDu, 0xA6u};
    if (sm_scpu_guard_code(cpu,bus,0x84CA7Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xCA7Eu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBD6Eu;
    cpu->pbr = 0xA6u;
    if (sm_scpu_context_key(cpu) != 0x0535EB70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x042653F8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84CA7Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04265540u: {
    static const uint8_t source_bytes[] = {0x22u, 0x35u, 0xC6u, 0xA6u};
    if (sm_scpu_guard_code(cpu,bus,0x84CAA8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xCAABu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC635u;
    cpu->pbr = 0xA6u;
    if (sm_scpu_context_key(cpu) != 0x053631A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04265560u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84CAACu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04265568u: {
    static const uint8_t source_bytes[] = {0x22u, 0x35u, 0xC6u, 0xA6u};
    if (sm_scpu_guard_code(cpu,bus,0x84CAADu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xCAB0u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC635u;
    cpu->pbr = 0xA6u;
    if (sm_scpu_context_key(cpu) != 0x053631A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x04265588u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84CAB1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04265590u: {
    static const uint8_t source_bytes[] = {0x22u, 0x35u, 0xC6u, 0xA6u};
    if (sm_scpu_guard_code(cpu,bus,0x84CAB2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xCAB5u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC635u;
    cpu->pbr = 0xA6u;
    if (sm_scpu_context_key(cpu) != 0x053631A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x042655B0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84CAB6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x042655B8u: {
    static const uint8_t source_bytes[] = {0x22u, 0x4Eu, 0xC6u, 0xA6u};
    if (sm_scpu_guard_code(cpu,bus,0x84CAB7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xCABAu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC64Eu;
    cpu->pbr = 0xA6u;
    if (sm_scpu_context_key(cpu) != 0x05363270u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x042655D8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x84CABBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04240790u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043DCAB0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x87B956u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xB958u;
    if (sm_scpu_context_key(cpu) != 0x043DCAC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043DCAC0u: {
    static const uint8_t source_bytes[] = {0xAEu, 0x02u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87B958u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1802u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xB95Bu;
    if (sm_scpu_context_key(cpu) != 0x043DCAD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x043DCAD8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87B95Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043DBB28u && sm_scpu_context_key(cpu) != 0x043DCD70u && sm_scpu_context_key(cpu) != 0x043E4230u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E08A0u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x10u};
    if (sm_scpu_guard_code(cpu,bus,0x87C114u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x10u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC116u;
    if (sm_scpu_context_key(cpu) != 0x043E08B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E08B0u: {
    static const uint8_t source_bytes[] = {0xA2u, 0xA0u, 0xAFu};
    if (sm_scpu_guard_code(cpu,bus,0x87C116u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0xAFA0u;
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC119u;
    if (sm_scpu_context_key(cpu) != 0x043E08C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E08C8u: {
    static const uint8_t source_bytes[] = {0xA0u, 0x87u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87C119u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0087u;
    cpu->y = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC11Cu;
    if (sm_scpu_context_key(cpu) != 0x043E08E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E08E0u: {
    static const uint8_t source_bytes[] = {0x22u, 0x86u, 0x8Au, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x87C11Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xC11Fu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8A86u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04045430u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E0900u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C120u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043D7D78u && sm_scpu_context_key(cpu) != 0x043D8628u && sm_scpu_context_key(cpu) != 0x043D8B58u && sm_scpu_context_key(cpu) != 0x043D9310u && sm_scpu_context_key(cpu) != 0x043D9B50u && sm_scpu_context_key(cpu) != 0x043DA3A0u && sm_scpu_context_key(cpu) != 0x043DB248u && sm_scpu_context_key(cpu) != 0x043DB598u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E0C40u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x87C188u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xC18Au;
    if (sm_scpu_context_key(cpu) != 0x043E0C53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E0C53u: {
    static const uint8_t source_bytes[] = {0xC6u, 0x84u};
    if (sm_scpu_guard_code(cpu,bus,0x87C18Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x84u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC18Cu;
    if (sm_scpu_context_key(cpu) != 0x043E0C63u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E0C63u: {
    static const uint8_t source_bytes[] = {0xC6u, 0xACu};
    if (sm_scpu_guard_code(cpu,bus,0x87C18Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0xACu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC18Eu;
    if (sm_scpu_context_key(cpu) != 0x043E0C73u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E0C73u: {
    static const uint8_t source_bytes[] = {0xC6u, 0x7Cu};
    if (sm_scpu_guard_code(cpu,bus,0x87C18Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    uint16_t result = (value - 1u) & 0xFFu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x80u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC190u;
    if (sm_scpu_context_key(cpu) != 0x043E0C83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E0C83u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C190u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043D7C43u && sm_scpu_context_key(cpu) != 0x043D856Bu && sm_scpu_context_key(cpu) != 0x043D8A53u && sm_scpu_context_key(cpu) != 0x043D9233u && sm_scpu_context_key(cpu) != 0x043D9AB3u && sm_scpu_context_key(cpu) != 0x043DA303u && sm_scpu_context_key(cpu) != 0x043DAC3Bu && sm_scpu_context_key(cpu) != 0x043DAD63u && sm_scpu_context_key(cpu) != 0x043DB783u && sm_scpu_context_key(cpu) != 0x043E11DBu && sm_scpu_context_key(cpu) != 0x043E3CA3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E2378u: {
    static const uint8_t source_bytes[] = {0xADu, 0x64u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x87C46Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1964u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC472u;
    if (sm_scpu_context_key(cpu) != 0x043E2390u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x043E2390u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x40u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x87C472u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0140u;
    uint16_t left = cpu->a & 0xFFFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((result & 0xFFFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0xC475u;
    if (sm_scpu_context_key(cpu) != 0x043E23A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E23A8u: {
    static const uint8_t source_bytes[] = {0x10u, 0x12u};
    if (sm_scpu_guard_code(cpu,bus,0x87C475u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_N) == 0u) {
        cpu->pc = 0xC489u;
        cycles = 3u;
    } else {
        cpu->pc = 0xC477u;
    }
    if (sm_scpu_context_key(cpu) != 0x043E23B8u && sm_scpu_context_key(cpu) != 0x043E2448u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x043E23B8u: {
    static const uint8_t source_bytes[] = {0x64u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x87C477u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC479u;
    if (sm_scpu_context_key(cpu) != 0x043E23C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E23C8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFEu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87C479u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FEu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC47Cu;
    if (sm_scpu_context_key(cpu) != 0x043E23E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E23E0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x87C47Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC47Eu;
    if (sm_scpu_context_key(cpu) != 0x043E23F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E23F0u: {
    static const uint8_t source_bytes[] = {0x22u, 0xB9u, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x87C47Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xC481u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB0B9u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x040585C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E2410u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x0Eu, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C482u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x180Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC485u;
    if (sm_scpu_context_key(cpu) != 0x043E2428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E2428u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x0Eu, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C485u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x180Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC488u;
    if (sm_scpu_context_key(cpu) != 0x043E2440u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E2440u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C488u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E2328u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E2448u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C489u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E2328u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E2DC0u: {
    static const uint8_t source_bytes[] = {0xADu, 0x64u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5B8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1964u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC5BBu;
    if (sm_scpu_context_key(cpu) != 0x043E2DD8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x043E2DD8u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x1Cu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5BBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x001Cu;
    uint16_t left = cpu->a & 0xFFFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((result & 0xFFFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0xC5BEu;
    if (sm_scpu_context_key(cpu) != 0x043E2DF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E2DF0u: {
    static const uint8_t source_bytes[] = {0x10u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5BEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_N) == 0u) {
        cpu->pc = 0xC5D8u;
        cycles = 3u;
    } else {
        cpu->pc = 0xC5C0u;
    }
    if (sm_scpu_context_key(cpu) != 0x043E2E00u && sm_scpu_context_key(cpu) != 0x043E2EC0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x043E2E00u: {
    static const uint8_t source_bytes[] = {0x64u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5C0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC5C2u;
    if (sm_scpu_context_key(cpu) != 0x043E2E10u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E2E10u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5C2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x07FFu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC5C5u;
    if (sm_scpu_context_key(cpu) != 0x043E2E28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E2E28u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5C5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC5C7u;
    if (sm_scpu_context_key(cpu) != 0x043E2E38u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E2E38u: {
    static const uint8_t source_bytes[] = {0x22u, 0x85u, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5C7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xC5CAu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB085u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x04058428u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E2E58u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x0Eu, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5CBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x180Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC5CEu;
    if (sm_scpu_context_key(cpu) != 0x043E2E70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E2E70u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x0Eu, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5CEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x180Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC5D1u;
    if (sm_scpu_context_key(cpu) != 0x043E2E88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E2E88u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x20u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5D1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC5D4u;
    if (sm_scpu_context_key(cpu) != 0x043E2EA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E2EA0u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x14u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5D4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1814u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC5D7u;
    if (sm_scpu_context_key(cpu) != 0x043E2EB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x043E2EB8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5D7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E2D78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E2EC0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C5D8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E2D78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E3F78u: {
    static const uint8_t source_bytes[] = {0xADu, 0x64u, 0x19u};
    if (sm_scpu_guard_code(cpu,bus,0x87C7EFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x1964u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC7F2u;
    if (sm_scpu_context_key(cpu) != 0x043E3F90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x043E3F90u: {
    static const uint8_t source_bytes[] = {0xC9u, 0x40u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0x87C7F2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0140u;
    uint16_t left = cpu->a & 0xFFFFu;
    uint16_t result = (uint16_t)(left - value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z | SM_P_C)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | ((result & 0xFFFFu) == 0u ? SM_P_Z : 0u) | (left >= value ? SM_P_C : 0u));
    cpu->pc = 0xC7F5u;
    if (sm_scpu_context_key(cpu) != 0x043E3FA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E3FA8u: {
    static const uint8_t source_bytes[] = {0x10u, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C7F5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_N) == 0u) {
        cpu->pc = 0xC80Fu;
        cycles = 3u;
    } else {
        cpu->pc = 0xC7F7u;
    }
    if (sm_scpu_context_key(cpu) != 0x043E3FB8u && sm_scpu_context_key(cpu) != 0x043E4078u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x043E3FB8u: {
    static const uint8_t source_bytes[] = {0x64u, 0x22u};
    if (sm_scpu_guard_code(cpu,bus,0x87C7F7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x22u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(0u >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7F9u;
    if (sm_scpu_context_key(cpu) != 0x043E3FC8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E3FC8u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFEu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87C7F9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FEu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC7FCu;
    if (sm_scpu_context_key(cpu) != 0x043E3FE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E3FE0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x87C7FCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x20u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC7FEu;
    if (sm_scpu_context_key(cpu) != 0x043E3FF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x043E3FF0u: {
    static const uint8_t source_bytes[] = {0x22u, 0xB9u, 0xB0u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0x87C7FEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint16_t saved_pc = 0xC801u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xB0B9u;
    cpu->pbr = 0x80u;
    if (sm_scpu_context_key(cpu) != 0x040585C8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E4010u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x0Eu, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C802u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x180Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC805u;
    if (sm_scpu_context_key(cpu) != 0x043E4028u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E4028u: {
    static const uint8_t source_bytes[] = {0xEEu, 0x0Eu, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C805u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x180Eu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    uint16_t result = (uint16_t)(value + 1u);
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(result >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)result) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC808u;
    if (sm_scpu_context_key(cpu) != 0x043E4040u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x043E4040u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x80u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x87C808u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0080u;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC80Bu;
    if (sm_scpu_context_key(cpu) != 0x043E4058u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x043E4058u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x3Au, 0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x87C80Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x183Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC80Eu;
    if (sm_scpu_context_key(cpu) != 0x043E4070u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x043E4070u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C80Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E3F28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E4078u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C80Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E3F28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x05343008u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA68601u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8602u;
    if (sm_scpu_context_key(cpu) != 0x05343010u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05343010u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xA68602u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8603u;
    if (sm_scpu_context_key(cpu) != 0x05343018u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05343018u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA68603u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8604u;
    if (sm_scpu_context_key(cpu) != 0x05343020u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05343020u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA68604u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8605u;
    if (sm_scpu_context_key(cpu) != 0x05343028u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05343028u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0xA68605u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8607u;
    if (sm_scpu_context_key(cpu) != 0x05343038u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05343038u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA68607u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x00u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8609u;
    if (sm_scpu_context_key(cpu) != 0x05343048u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05343048u: {
    static const uint8_t source_bytes[] = {0x0Au};
    if (sm_scpu_guard_code(cpu,bus,0xA68609u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t left = cpu->a;
    uint16_t result = (uint16_t)((uint32_t)left << 1u);
    cpu->a = result;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_C) | ((left & 0x8000u) != 0u ? SM_P_C : 0u));
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((result & 0x8000u) != 0u ? SM_P_N : 0u) | (result == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x860Au;
    if (sm_scpu_context_key(cpu) != 0x05343050u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x05343050u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0xA6860Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x860Bu;
    if (sm_scpu_context_key(cpu) != 0x05343058u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x05343058u: {
    static const uint8_t source_bytes[] = {0xBFu, 0xC4u, 0xFAu, 0xECu};
    if (sm_scpu_guard_code(cpu,bus,0xA6860Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (0xECFAC4u + (uint32_t)cpu->x) & 0xFFFFFFu;
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,address,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(low | ((uint16_t)high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x860Fu;
    if (sm_scpu_context_key(cpu) != 0x05343078u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x05343078u: {
    static const uint8_t source_bytes[] = {0x85u, 0x14u};
    if (sm_scpu_guard_code(cpu,bus,0xA6860Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x14u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8611u;
    if (sm_scpu_context_key(cpu) != 0x05343088u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05343088u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xECu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA68611u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00ECu;
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8614u;
    if (sm_scpu_context_key(cpu) != 0x053430A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x053430A0u: {
    static const uint8_t source_bytes[] = {0x85u, 0x16u};
    if (sm_scpu_guard_code(cpu,bus,0xA68614u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x16u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8616u;
    if (sm_scpu_context_key(cpu) != 0x053430B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x053430B0u: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0xA68616u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = low;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8617u;
    if (sm_scpu_context_key(cpu) != 0x053430B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x053430B8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA68617u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8618u;
    if (sm_scpu_context_key(cpu) != 0x053430C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x053430C0u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA68618u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04268AB8u && sm_scpu_context_key(cpu) != 0x04268BF0u && sm_scpu_context_key(cpu) != 0x04268CA0u && sm_scpu_context_key(cpu) != 0x04269280u && sm_scpu_context_key(cpu) != 0x04269490u && sm_scpu_context_key(cpu) != 0x04269920u && sm_scpu_context_key(cpu) != 0x04269F30u && sm_scpu_context_key(cpu) != 0x053424A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0535E838u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD07u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBD08u;
    if (sm_scpu_context_key(cpu) != 0x0535E840u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0535E840u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD08u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBD09u;
    if (sm_scpu_context_key(cpu) != 0x0535E848u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0535E848u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD09u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBD0Au;
    if (sm_scpu_context_key(cpu) != 0x0535E850u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0535E850u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD0Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD0Bu;
    if (sm_scpu_context_key(cpu) != 0x0535E858u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0535E858u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD0Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBD0Du;
    if (sm_scpu_context_key(cpu) != 0x0535E868u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0535E868u: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD0Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = low;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBD0Eu;
    if (sm_scpu_context_key(cpu) != 0x0535E870u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0535E870u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD0Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD0Fu;
    if (sm_scpu_context_key(cpu) != 0x0535E878u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0535E878u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD0Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x042653A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0535EB70u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD6Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBD6Fu;
    if (sm_scpu_context_key(cpu) != 0x0535EB78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0535EB78u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD6Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBD70u;
    if (sm_scpu_context_key(cpu) != 0x0535EB80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0535EB80u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD70u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xBD71u;
    if (sm_scpu_context_key(cpu) != 0x0535EB88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0535EB88u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD71u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD72u;
    if (sm_scpu_context_key(cpu) != 0x0535EB90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0535EB90u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD72u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBD74u;
    if (sm_scpu_context_key(cpu) != 0x0535EBA0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0535EBA0u: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD74u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = low;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0xBD75u;
    if (sm_scpu_context_key(cpu) != 0x0535EBA8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0535EBA8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD75u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xBD76u;
    if (sm_scpu_context_key(cpu) != 0x0535EBB0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0535EBB0u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6BD76u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x042653F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x053631A8u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C635u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC636u;
    if (sm_scpu_context_key(cpu) != 0x053631B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x053631B0u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C636u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC637u;
    if (sm_scpu_context_key(cpu) != 0x053631B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x053631B8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C637u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC638u;
    if (sm_scpu_context_key(cpu) != 0x053631C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x053631C0u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x40u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C638u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0440u;
    if (sm_scpu_write8(cpu,bus,address,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFFFu,0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0xC63Bu;
    if (sm_scpu_context_key(cpu) != 0x053631D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x053631D8u: {
    static const uint8_t source_bytes[] = {0xADu, 0x84u, 0x0Du};
    if (sm_scpu_guard_code(cpu,bus,0xA6C63Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0D84u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->a = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC63Eu;
    if (sm_scpu_context_key(cpu) != 0x053631F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x053631F0u: {
    static const uint8_t source_bytes[] = {0x29u, 0xFFu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C63Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x00FFu);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC641u;
    if (sm_scpu_context_key(cpu) != 0x05363208u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05363208u: {
    static const uint8_t source_bytes[] = {0xAAu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C641u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->x = cpu->a;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->x & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->x == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC642u;
    if (sm_scpu_context_key(cpu) != 0x05363210u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x05363210u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x47u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C642u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u || cpu->x == 0x0004u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xC644u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xC647u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xC64Du) || (cpu->x == 0x0002u && target == 0xC64Du) || (cpu->x == 0x0004u && target == 0xC64Du))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x05363268u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x05363228u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C645u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC646u;
    if (sm_scpu_context_key(cpu) != 0x05363230u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05363230u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C646u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x04265560u && sm_scpu_context_key(cpu) != 0x04265588u && sm_scpu_context_key(cpu) != 0x042655B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x05363270u: {
    static const uint8_t source_bytes[] = {0x8Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C64Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->dbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC64Fu;
    if (sm_scpu_context_key(cpu) != 0x05363278u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05363278u: {
    static const uint8_t source_bytes[] = {0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C64Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->pbr >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0xC650u;
    if (sm_scpu_context_key(cpu) != 0x05363280u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05363280u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C650u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC651u;
    if (sm_scpu_context_key(cpu) != 0x05363288u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05363288u: {
    static const uint8_t source_bytes[] = {0xAEu, 0x40u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C651u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0440u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC654u;
    if (sm_scpu_context_key(cpu) != 0x053632A0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,5u);
}
case 0x053632A0u: {
    static const uint8_t source_bytes[] = {0xFCu, 0x59u, 0xC6u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C654u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (!(cpu->x == 0x0000u || cpu->x == 0x0002u)) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_DOMAIN");
    uint16_t saved_pc = 0xC656u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xC659u + cpu->x);
    uint8_t low, high;
    if (sm_scpu_read8(cpu,bus,pointer,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)cpu->pbr << 16) | (uint16_t)(pointer + 1u),&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t target = (uint16_t)(low | ((uint16_t)high << 8));
    if (!((cpu->x == 0x0000u && target == 0xC65Du) || (cpu->x == 0x0002u && target == 0xC65Du))) return sm_scpu_stop(cpu,bus,"UNPROVED_INDEXED_CALL_TARGET");
    cpu->pc = target;
    if (sm_scpu_context_key(cpu) != 0x053632E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,8u);
}
case 0x053632B8u: {
    static const uint8_t source_bytes[] = {0xABu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C657u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->dbr = (uint8_t)value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0xC658u;
    if (sm_scpu_context_key(cpu) != 0x053632C0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x053632C0u: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA6C658u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x042655D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x054475F8u: {
    static const uint8_t source_bytes[] = {0x08u};
    if (sm_scpu_guard_code(cpu,bus,0xA88EBFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->p >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x8EC0u;
    if (sm_scpu_context_key(cpu) != 0x05447600u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05447600u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xA88EC0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8EC2u;
    if (sm_scpu_context_key(cpu) != 0x05447612u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x05447612u: {
    static const uint8_t source_bytes[] = {0xADu, 0x11u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xA88EC2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4211u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8EC5u;
    if (sm_scpu_context_key(cpu) != 0x0544762Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0544762Au: {
    static const uint8_t source_bytes[] = {0x89u, 0x80u};
    if (sm_scpu_guard_code(cpu,bus,0xA88EC5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)((cpu->p & ~SM_P_Z) | ((cpu->a & 0x80u & 0xFFu) == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8EC7u;
    if (sm_scpu_context_key(cpu) != 0x0544763Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0544763Au: {
    static const uint8_t source_bytes[] = {0xD0u, 0xF9u};
    if (sm_scpu_guard_code(cpu,bus,0xA88EC7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) == 0u) {
        cpu->pc = 0x8EC2u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8EC9u;
    }
    if (sm_scpu_context_key(cpu) != 0x05447612u && sm_scpu_context_key(cpu) != 0x0544764Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x0544764Au: {
    static const uint8_t source_bytes[] = {0x28u};
    if (sm_scpu_guard_code(cpu,bus,0xA88EC9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t value;
    if (sm_scpu_pull8(cpu,bus,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = value;
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8ECAu;
    if (sm_scpu_context_key(cpu) != 0x05447650u && sm_scpu_context_key(cpu) != 0x05447652u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447650u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xA88ECAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x054473A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x05447652u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xA88ECAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x05447412u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x05447819u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F03u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8F05u;
    if (sm_scpu_context_key(cpu) != 0x0544782Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x0544782Bu: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x02u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F05u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2102u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F08u;
    if (sm_scpu_context_key(cpu) != 0x05447843u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447843u: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x03u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F08u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2103u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F0Bu;
    if (sm_scpu_context_key(cpu) != 0x0544785Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0544785Bu: {
    static const uint8_t source_bytes[] = {0x9Cu, 0x00u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F0Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4300u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F0Eu;
    if (sm_scpu_context_key(cpu) != 0x05447873u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447873u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F0Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F10u;
    if (sm_scpu_context_key(cpu) != 0x05447883u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x05447883u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F10u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4301u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F13u;
    if (sm_scpu_context_key(cpu) != 0x0544789Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0544789Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F13u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F15u;
    if (sm_scpu_context_key(cpu) != 0x054478ABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x054478ABu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x02u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F15u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4302u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F18u;
    if (sm_scpu_context_key(cpu) != 0x054478C3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x054478C3u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F18u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F1Au;
    if (sm_scpu_context_key(cpu) != 0x054478D3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x054478D3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x03u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F1Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4303u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F1Du;
    if (sm_scpu_context_key(cpu) != 0x054478EBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x054478EBu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F1Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F1Fu;
    if (sm_scpu_context_key(cpu) != 0x054478FBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x054478FBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x04u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F1Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4304u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F22u;
    if (sm_scpu_context_key(cpu) != 0x05447913u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447913u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F22u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F24u;
    if (sm_scpu_context_key(cpu) != 0x05447923u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x05447923u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F24u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4305u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F27u;
    if (sm_scpu_context_key(cpu) != 0x0544793Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x0544793Bu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F27u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F29u;
    if (sm_scpu_context_key(cpu) != 0x0544794Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x0544794Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F29u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4306u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F2Cu;
    if (sm_scpu_context_key(cpu) != 0x05447963u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447963u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x84u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F2Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x84u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F2Eu;
    if (sm_scpu_context_key(cpu) != 0x05447973u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447973u: {
    static const uint8_t source_bytes[] = {0xF0u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F2Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t cycles = 2u;
    if ((cpu->p & SM_P_Z) != 0u) {
        cpu->pc = 0x8F37u;
        cycles = 3u;
    } else {
        cpu->pc = 0x8F30u;
    }
    if (sm_scpu_context_key(cpu) != 0x05447983u && sm_scpu_context_key(cpu) != 0x054479BBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,cycles);
}
case 0x05447983u: {
    static const uint8_t source_bytes[] = {0x64u, 0x84u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F30u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x84u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(0u >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F32u;
    if (sm_scpu_context_key(cpu) != 0x05447993u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447993u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x01u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F32u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0001u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F34u;
    if (sm_scpu_context_key(cpu) != 0x054479A3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x054479A3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F34u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x420Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F37u;
    if (sm_scpu_context_key(cpu) != 0x054479BBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x054479BBu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F37u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x42u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F39u;
    if (sm_scpu_context_key(cpu) != 0x054479CBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x054479CBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x05u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F39u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2105u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F3Cu;
    if (sm_scpu_context_key(cpu) != 0x054479E3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x054479E3u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x43u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F3Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x43u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F3Eu;
    if (sm_scpu_context_key(cpu) != 0x054479F3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x054479F3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x06u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F3Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2106u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F41u;
    if (sm_scpu_context_key(cpu) != 0x05447A0Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447A0Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x44u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F41u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x44u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F43u;
    if (sm_scpu_context_key(cpu) != 0x05447A1Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447A1Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x07u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F43u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2107u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F46u;
    if (sm_scpu_context_key(cpu) != 0x05447A33u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447A33u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x45u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F46u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x45u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F48u;
    if (sm_scpu_context_key(cpu) != 0x05447A43u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447A43u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x08u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F48u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2108u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F4Bu;
    if (sm_scpu_context_key(cpu) != 0x05447A5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447A5Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x46u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F4Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x46u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F4Du;
    if (sm_scpu_context_key(cpu) != 0x05447A6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447A6Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x09u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F4Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2109u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F50u;
    if (sm_scpu_context_key(cpu) != 0x05447A83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447A83u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x47u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F50u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x47u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F52u;
    if (sm_scpu_context_key(cpu) != 0x05447A93u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447A93u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F52u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F55u;
    if (sm_scpu_context_key(cpu) != 0x05447AABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447AABu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F55u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x48u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F57u;
    if (sm_scpu_context_key(cpu) != 0x05447ABBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447ABBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F57u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F5Au;
    if (sm_scpu_context_key(cpu) != 0x05447AD3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447AD3u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x49u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F5Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x49u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F5Cu;
    if (sm_scpu_context_key(cpu) != 0x05447AE3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447AE3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x0Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F5Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x210Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F5Fu;
    if (sm_scpu_context_key(cpu) != 0x05447AFBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447AFBu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Au};
    if (sm_scpu_guard_code(cpu,bus,0xA88F5Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Au);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F61u;
    if (sm_scpu_context_key(cpu) != 0x05447B0Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447B0Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Cu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F61u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Cu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F64u;
    if (sm_scpu_context_key(cpu) != 0x05447B23u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447B23u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA88F64u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Bu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F66u;
    if (sm_scpu_context_key(cpu) != 0x05447B33u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447B33u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Du, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F66u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Du;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F69u;
    if (sm_scpu_context_key(cpu) != 0x05447B4Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447B4Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Cu};
    if (sm_scpu_guard_code(cpu,bus,0xA88F69u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Cu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F6Bu;
    if (sm_scpu_context_key(cpu) != 0x05447B5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447B5Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Eu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F6Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Eu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F6Eu;
    if (sm_scpu_context_key(cpu) != 0x05447B73u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447B73u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Du};
    if (sm_scpu_guard_code(cpu,bus,0xA88F6Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Du);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F70u;
    if (sm_scpu_context_key(cpu) != 0x05447B83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447B83u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Fu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F70u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Fu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F73u;
    if (sm_scpu_context_key(cpu) != 0x05447B9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447B9Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x4Eu};
    if (sm_scpu_guard_code(cpu,bus,0xA88F73u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x4Eu);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F75u;
    if (sm_scpu_context_key(cpu) != 0x05447BABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447BABu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x01u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F75u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2101u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F78u;
    if (sm_scpu_context_key(cpu) != 0x05447BC3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447BC3u: {
    static const uint8_t source_bytes[] = {0xADu, 0x58u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F78u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0058u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F7Bu;
    if (sm_scpu_context_key(cpu) != 0x05447BDBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447BDBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x26u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F7Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2126u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F7Eu;
    if (sm_scpu_context_key(cpu) != 0x05447BF3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447BF3u: {
    static const uint8_t source_bytes[] = {0xADu, 0x59u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F7Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0059u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F81u;
    if (sm_scpu_context_key(cpu) != 0x05447C0Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447C0Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x27u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F81u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2127u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F84u;
    if (sm_scpu_context_key(cpu) != 0x05447C23u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447C23u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Au, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F84u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x005Au;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F87u;
    if (sm_scpu_context_key(cpu) != 0x05447C3Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447C3Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x28u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F87u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2128u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F8Au;
    if (sm_scpu_context_key(cpu) != 0x05447C53u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447C53u: {
    static const uint8_t source_bytes[] = {0xADu, 0x5Bu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F8Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x005Bu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F8Du;
    if (sm_scpu_context_key(cpu) != 0x05447C6Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447C6Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x29u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F8Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2129u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F90u;
    if (sm_scpu_context_key(cpu) != 0x05447C83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447C83u: {
    static const uint8_t source_bytes[] = {0xADu, 0x53u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F90u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0053u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F93u;
    if (sm_scpu_context_key(cpu) != 0x05447C9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447C9Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x25u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F93u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2125u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F96u;
    if (sm_scpu_context_key(cpu) != 0x05447CB3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447CB3u: {
    static const uint8_t source_bytes[] = {0xADu, 0x51u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F96u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0051u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F99u;
    if (sm_scpu_context_key(cpu) != 0x05447CCBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447CCBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x23u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F99u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2123u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8F9Cu;
    if (sm_scpu_context_key(cpu) != 0x05447CE3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447CE3u: {
    static const uint8_t source_bytes[] = {0xADu, 0x52u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F9Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0052u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8F9Fu;
    if (sm_scpu_context_key(cpu) != 0x05447CFBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447CFBu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x24u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88F9Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2124u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8FA2u;
    if (sm_scpu_context_key(cpu) != 0x05447D13u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447D13u: {
    static const uint8_t source_bytes[] = {0xADu, 0x4Fu, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FA2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x004Fu;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8FA5u;
    if (sm_scpu_context_key(cpu) != 0x05447D2Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447D2Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Au, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FA5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Au;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8FA8u;
    if (sm_scpu_context_key(cpu) != 0x05447D43u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447D43u: {
    static const uint8_t source_bytes[] = {0xADu, 0x50u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FA8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x0050u;
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8FABu;
    if (sm_scpu_context_key(cpu) != 0x05447D5Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447D5Bu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x2Bu, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FABu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x212Bu;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8FAEu;
    if (sm_scpu_context_key(cpu) != 0x05447D73u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447D73u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x55u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FAEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x55u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8FB0u;
    if (sm_scpu_context_key(cpu) != 0x05447D83u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447D83u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x30u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FB0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2130u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8FB3u;
    if (sm_scpu_context_key(cpu) != 0x05447D9Bu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447D9Bu: {
    static const uint8_t source_bytes[] = {0xA5u, 0x56u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FB3u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x56u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8FB5u;
    if (sm_scpu_context_key(cpu) != 0x05447DABu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447DABu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x31u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FB5u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2131u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8FB8u;
    if (sm_scpu_context_key(cpu) != 0x05447DC3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447DC3u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x57u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FB8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x57u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = data_low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8FBAu;
    if (sm_scpu_context_key(cpu) != 0x05447DD3u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x05447DD3u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x32u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xA88FBAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2132u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8FBDu;
    if (sm_scpu_context_key(cpu) != 0x05447DEBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x05447DEBu: {
    static const uint8_t source_bytes[] = {0x6Bu};
    if (sm_scpu_guard_code(cpu,bus,0xA88FBDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high, saved_bank;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&saved_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    cpu->pbr = saved_bank;
    if (sm_scpu_context_key(cpu) != 0x040407BBu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
