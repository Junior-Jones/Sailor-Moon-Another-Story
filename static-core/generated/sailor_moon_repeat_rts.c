#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_repeat_rts(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x04043738u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8086E7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04043700u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04048C10u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x809182u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04048BE0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0404A010u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x809402u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04049FD0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0404A930u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x809526u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0404A8F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0404B7B8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x8096F7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0404B778u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04057B28u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80AF65u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04057AE8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040588C0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80B118u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040586F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0405BA68u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x80B74Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x0405B568u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C3318u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x818663u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C31D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040C7FC8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x818FF9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040C7E70u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040DF020u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81BE04u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040DEF88u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040ED290u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81DA52u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040ECE30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x040F0F58u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x81E1EBu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x040F0EF0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04140280u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x828050u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041400D0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04161CE0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82C39Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x04161C90u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041657C0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82CAF8u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041654F0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04165B48u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x82CB69u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041659B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041D5438u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83AA87u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041D5390u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041D6788u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83ACF1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041D6500u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041D6D48u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83ADA9u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041D6978u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041F0638u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83E0C7u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041F0610u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041F0A30u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83E146u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041F0A08u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041F4248u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83E849u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041F4210u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x041F5B58u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x83EB6Bu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x041F5B30u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043D7668u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87AECDu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043D73A8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043D78E0u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87AF1Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043D7800u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043DE360u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87BC6Cu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043DE318u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043DEA70u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD4Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043DE7B0u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043DEB70u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87BD6Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043DEAB8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E0C38u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C187u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E0B80u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E2370u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C46Eu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E0B80u && sm_scpu_context_key(cpu) != 0x043E2328u && sm_scpu_context_key(cpu) != 0x043E2D78u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E3F70u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C7EEu,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E3F28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x043E4180u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x87C830u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x043E3F28u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x05363268u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C64Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x05363228u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x053632E8u: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xA6C65Du,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x053632B8u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x06F01D0Au: {
    static const uint8_t source_bytes[] = {0x60u};
    if (sm_scpu_guard_code(cpu,bus,0xDE03A1u,source_bytes,sizeof(source_bytes)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_context_key(cpu) != 0x06F00302u) return sm_scpu_stop(cpu,bus,"UNPROVED_SUCCESSOR_CONTEXT");
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
