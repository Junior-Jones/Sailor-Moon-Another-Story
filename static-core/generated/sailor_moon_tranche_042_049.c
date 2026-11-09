#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_tranche_042_049(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x040C0780u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x8180F0u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x80F2u;
    if (sm_scpu_context_key(cpu) != 0x040C0792u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C0792u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x8180F2u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0020u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x80F4u;
    if (sm_scpu_context_key(cpu) != 0x040C07A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C07A2u: {
    static const uint8_t source_bytes[] = {0x85u, 0x6Du};
    if (sm_scpu_guard_code(cpu,bus,0x8180F4u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x6Du);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x80F6u;
    if (sm_scpu_context_key(cpu) != 0x040C07B2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C07B2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0x8180F6u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0000u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x80F8u;
    if (sm_scpu_context_key(cpu) != 0x040C07C2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C07C2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x00u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0x8180F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2100u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x80FBu;
    if (sm_scpu_context_key(cpu) != 0x040C07DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040C07DAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x81u};
    if (sm_scpu_guard_code(cpu,bus,0x8180FBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0081u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x80FDu;
    if (sm_scpu_context_key(cpu) != 0x040C07EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C07EAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x00u, 0x42u};
    if (sm_scpu_guard_code(cpu,bus,0x8180FDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x4200u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8100u;
    if (sm_scpu_context_key(cpu) != 0x040C0802u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x040C0802u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x818100u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8102u;
    if (sm_scpu_context_key(cpu) != 0x040C0810u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C0810u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x818102u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C0658u && sm_scpu_context_key(cpu) != 0x040C06B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C0818u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x818103u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8105u;
    if (sm_scpu_context_key(cpu) != 0x040C082Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C082Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x40u};
    if (sm_scpu_guard_code(cpu,bus,0x818105u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0040u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8107u;
    if (sm_scpu_context_key(cpu) != 0x040C083Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C083Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Au};
    if (sm_scpu_guard_code(cpu,bus,0x818107u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Au);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8109u;
    if (sm_scpu_context_key(cpu) != 0x040C084Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C084Au: {
    static const uint8_t source_bytes[] = {0xA9u, 0x04u};
    if (sm_scpu_guard_code(cpu,bus,0x818109u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0004u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x810Bu;
    if (sm_scpu_context_key(cpu) != 0x040C085Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040C085Au: {
    static const uint8_t source_bytes[] = {0x85u, 0x7Bu};
    if (sm_scpu_guard_code(cpu,bus,0x81810Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x7Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x810Du;
    if (sm_scpu_context_key(cpu) != 0x040C086Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x040C086Au: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x81810Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x810Fu;
    if (sm_scpu_context_key(cpu) != 0x040C0878u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x040C0878u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81810Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C0688u && sm_scpu_context_key(cpu) != 0x040C06E8u && sm_scpu_context_key(cpu) != 0x040C0730u && sm_scpu_context_key(cpu) != 0x040C0778u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040E7CB0u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81CF96u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xCF97u;
    if (sm_scpu_context_key(cpu) != 0x040E7CB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040E7CB8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81CF97u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040E7B78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040E89D0u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x81D13Au,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xD13Bu;
    if (sm_scpu_context_key(cpu) != 0x040E89D8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x040E89D8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81D13Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040E8910u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04168C20u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0x82D184u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0xD185u;
    if (sm_scpu_context_key(cpu) != 0x04168C28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x04168C28u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82D185u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041674E8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041C1370u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x83826Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8270u;
    if (sm_scpu_context_key(cpu) != 0x041C1382u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C1382u: {
    static const uint8_t source_bytes[] = {0xA9u, 0x05u};
    if (sm_scpu_guard_code(cpu,bus,0x838270u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0005u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x8272u;
    if (sm_scpu_context_key(cpu) != 0x041C1392u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041C1392u: {
    static const uint8_t source_bytes[] = {0x85u, 0x72u};
    if (sm_scpu_guard_code(cpu,bus,0x838272u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x72u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x8274u;
    if (sm_scpu_context_key(cpu) != 0x041C13A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C13A2u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x838274u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8276u;
    if (sm_scpu_context_key(cpu) != 0x041C13B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C13B0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x838276u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041DE5B0u && sm_scpu_context_key(cpu) != 0x041DEA00u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041C13B8u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0x838277u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x8279u;
    if (sm_scpu_context_key(cpu) != 0x041C13CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C13CAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x02u};
    if (sm_scpu_guard_code(cpu,bus,0x838279u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0002u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x827Bu;
    if (sm_scpu_context_key(cpu) != 0x041C13DAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x041C13DAu: {
    static const uint8_t source_bytes[] = {0x85u, 0x72u};
    if (sm_scpu_guard_code(cpu,bus,0x83827Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x72u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x827Du;
    if (sm_scpu_context_key(cpu) != 0x041C13EAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x041C13EAu: {
    static const uint8_t source_bytes[] = {0xC2u, 0x30u};
    if (sm_scpu_guard_code(cpu,bus,0x83827Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x30u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x827Fu;
    if (sm_scpu_context_key(cpu) != 0x041C13F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x041C13F8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83827Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041C2B60u && sm_scpu_context_key(cpu) != 0x041C5C10u && sm_scpu_context_key(cpu) != 0x041C5CE0u && sm_scpu_context_key(cpu) != 0x041C6128u && sm_scpu_context_key(cpu) != 0x041C6240u && sm_scpu_context_key(cpu) != 0x041CC048u && sm_scpu_context_key(cpu) != 0x041CC108u && sm_scpu_context_key(cpu) != 0x041CC1A8u && sm_scpu_context_key(cpu) != 0x041CC268u && sm_scpu_context_key(cpu) != 0x041CC388u && sm_scpu_context_key(cpu) != 0x041CC7B0u && sm_scpu_context_key(cpu) != 0x041CCC88u && sm_scpu_context_key(cpu) != 0x041CCD50u && sm_scpu_context_key(cpu) != 0x041CED30u && sm_scpu_context_key(cpu) != 0x041CF178u && sm_scpu_context_key(cpu) != 0x041CF240u && sm_scpu_context_key(cpu) != 0x041D8E90u && sm_scpu_context_key(cpu) != 0x041D8F68u && sm_scpu_context_key(cpu) != 0x041D9500u && sm_scpu_context_key(cpu) != 0x041DB3B8u && sm_scpu_context_key(cpu) != 0x041DB4C0u && sm_scpu_context_key(cpu) != 0x041DC390u && sm_scpu_context_key(cpu) != 0x041DC438u && sm_scpu_context_key(cpu) != 0x041DC520u && sm_scpu_context_key(cpu) != 0x041DC638u && sm_scpu_context_key(cpu) != 0x041DDC70u && sm_scpu_context_key(cpu) != 0x041DF6A8u && sm_scpu_context_key(cpu) != 0x041DF878u && sm_scpu_context_key(cpu) != 0x041DFA08u && sm_scpu_context_key(cpu) != 0x041DFCC0u && sm_scpu_context_key(cpu) != 0x041DFDB8u && sm_scpu_context_key(cpu) != 0x041DFEE8u && sm_scpu_context_key(cpu) != 0x041DFFF8u && sm_scpu_context_key(cpu) != 0x041E0A50u && sm_scpu_context_key(cpu) != 0x041E0B80u && sm_scpu_context_key(cpu) != 0x041E2AC8u && sm_scpu_context_key(cpu) != 0x041E2BF8u && sm_scpu_context_key(cpu) != 0x041E4370u && sm_scpu_context_key(cpu) != 0x041E98D0u && sm_scpu_context_key(cpu) != 0x041E99B0u && sm_scpu_context_key(cpu) != 0x041E9B58u && sm_scpu_context_key(cpu) != 0x041E9DD0u && sm_scpu_context_key(cpu) != 0x041EAE40u && sm_scpu_context_key(cpu) != 0x041EAF00u && sm_scpu_context_key(cpu) != 0x041EB088u && sm_scpu_context_key(cpu) != 0x041ECB88u && sm_scpu_context_key(cpu) != 0x041F3660u && sm_scpu_context_key(cpu) != 0x041F3BB0u && sm_scpu_context_key(cpu) != 0x041F3C40u && sm_scpu_context_key(cpu) != 0x041F3EF0u && sm_scpu_context_key(cpu) != 0x041F4EB0u && sm_scpu_context_key(cpu) != 0x041F66F8u && sm_scpu_context_key(cpu) != 0x041F6B18u && sm_scpu_context_key(cpu) != 0x041F6BA8u && sm_scpu_context_key(cpu) != 0x041F6DC8u && sm_scpu_context_key(cpu) != 0x041F7470u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F027C2u: {
    static const uint8_t source_bytes[] = {0xA5u, 0x1Au};
    if (sm_scpu_guard_code(cpu,bus,0xDE04F8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Au);
    uint8_t value;
    if (sm_scpu_read8(cpu,bus,address,&value) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | (value & SM_P_N) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04FAu;
    if (sm_scpu_context_key(cpu) != 0x06F027D2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F027D2u: {
    static const uint8_t source_bytes[] = {0xC2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04FAu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~ 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x04FCu;
    if (sm_scpu_context_key(cpu) != 0x06F027E0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F027E0u: {
    static const uint8_t source_bytes[] = {0x29u, 0x07u, 0x00u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04FCu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)(cpu->a & 0x0007u);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((cpu->a & 0x8000u) != 0u ? SM_P_N : 0u) | (cpu->a == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x04FFu;
    if (sm_scpu_context_key(cpu) != 0x06F027F8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F027F8u: {
    static const uint8_t source_bytes[] = {0xA6u, 0x15u};
    if (sm_scpu_guard_code(cpu,bus,0xDE04FFu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x15u);
    uint8_t data_low;
    if (sm_scpu_read8(cpu,bus,address,&data_low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t data_high;
    if (sm_scpu_read8(cpu,bus,(address + 1u) & 0xFFFFu,&data_high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = (uint16_t)(data_low | ((uint16_t)data_high << 8));
    cpu->x = value;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x8000u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0501u;
    if (sm_scpu_context_key(cpu) != 0x06F02808u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02808u: {
    static const uint8_t source_bytes[] = {0x20u, 0x1Au, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0501u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x0503u;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x071Au;
    if (sm_scpu_context_key(cpu) != 0x06F038D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F02820u: {
    static const uint8_t source_bytes[] = {0x18u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0504u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p & ~SM_P_C);
    cpu->pc = 0x0505u;
    if (sm_scpu_context_key(cpu) != 0x06F02828u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F02828u: {
    static const uint8_t source_bytes[] = {0x65u, 0x15u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0505u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if ((cpu->p & SM_P_D) != 0u) return sm_scpu_stop(cpu,bus,"UNPROVED_DECIMAL_MODE");
    uint32_t address = (uint16_t)(cpu->d + 0x15u);
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
    cpu->pc = 0x0507u;
    if (sm_scpu_context_key(cpu) != 0x06F02838u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02838u: {
    static const uint8_t source_bytes[] = {0x85u, 0x17u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0507u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x17u);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,(address + 1u) & 0xFFFFu,(uint8_t)(cpu->a >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0509u;
    if (sm_scpu_context_key(cpu) != 0x06F02848u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02848u: {
    static const uint8_t source_bytes[] = {0xE2u, 0x20u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0509u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->p = (uint8_t)(cpu->p | 0x20u);
    if ((cpu->p & SM_P_X) != 0u) {
        cpu->x = (uint8_t)cpu->x;
        cpu->y = (uint8_t)cpu->y;
    }
    cpu->pc = 0x050Bu;
    if (sm_scpu_context_key(cpu) != 0x06F0285Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F0285Au: {
    static const uint8_t source_bytes[] = {0x48u};
    if (sm_scpu_guard_code(cpu,bus,0xDE050Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x050Cu;
    if (sm_scpu_context_key(cpu) != 0x06F02862u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F02862u: {
    static const uint8_t source_bytes[] = {0x20u, 0xB7u, 0x07u};
    if (sm_scpu_guard_code(cpu,bus,0xDE050Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t saved_pc = 0x050Eu;
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 8u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (sm_scpu_write8(cpu,bus,cpu->s,(uint8_t)(saved_pc >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->s = (uint16_t)(cpu->s - 1u);
    cpu->pc = 0x07B7u;
    if (sm_scpu_context_key(cpu) != 0x06F03DBAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F0287Au: {
    static const uint8_t source_bytes[] = {0x68u};
    if (sm_scpu_guard_code(cpu,bus,0xDE050Fu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = low;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0510u;
    if (sm_scpu_context_key(cpu) != 0x06F02882u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F02882u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x41u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0510u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2141u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0513u;
    if (sm_scpu_context_key(cpu) != 0x06F0289Au) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F0289Au: {
    static const uint8_t source_bytes[] = {0xEBu};
    if (sm_scpu_guard_code(cpu,bus,0xDE0513u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
    uint16_t value = cpu->a & 0xFFu;
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0514u;
    if (sm_scpu_context_key(cpu) != 0x06F028A2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u);
}
case 0x06F028A2u: {
    static const uint8_t source_bytes[] = {0x8Du, 0x42u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0514u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2142u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0517u;
    if (sm_scpu_context_key(cpu) != 0x06F028BAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F028BAu: {
    static const uint8_t source_bytes[] = {0xA9u, 0x91u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0517u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x0091u;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x0519u;
    if (sm_scpu_context_key(cpu) != 0x06F028CAu) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F028CAu: {
    static const uint8_t source_bytes[] = {0x8Du, 0x40u, 0x21u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0519u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = ((uint32_t)cpu->dbr << 16) | 0x2140u;
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)(cpu->a >> 0u)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x051Cu;
    if (sm_scpu_context_key(cpu) != 0x06F028E2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,4u);
}
case 0x06F028E2u: {
    static const uint8_t source_bytes[] = {0xA9u, 0xFFu};
    if (sm_scpu_guard_code(cpu,bus,0xDE051Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint16_t value = 0x00FFu;
    cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
    cpu->p = (uint8_t)((cpu->p & ~(SM_P_N | SM_P_Z)) | ((value & 0x80u) != 0u ? SM_P_N : 0u) | (value == 0u ? SM_P_Z : 0u));
    cpu->pc = 0x051Eu;
    if (sm_scpu_context_key(cpu) != 0x06F028F2u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,2u);
}
case 0x06F028F2u: {
    static const uint8_t source_bytes[] = {0x85u, 0x1Bu};
    if (sm_scpu_guard_code(cpu,bus,0xDE051Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint32_t address = (uint16_t)(cpu->d + 0x1Bu);
    if (sm_scpu_write8(cpu,bus,address,(uint8_t)cpu->a) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = 0x0520u;
    if (sm_scpu_context_key(cpu) != 0x06F02902u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,3u + ((cpu->d & 0xFFu) != 0u));
}
case 0x06F02902u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE0520u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00C62u && sm_scpu_context_key(cpu) != 0x06F00D22u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
