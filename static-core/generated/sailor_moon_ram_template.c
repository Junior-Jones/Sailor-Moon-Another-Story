#include "../internal/sailor_moon_scpu.h"

SmScpuExecResult sm_scpu_ram_template(SmScpuState *cpu, const SmScpuBus *bus) {
    switch (sm_scpu_context_key(cpu)) {
case 0x04000400u: {
    static const uint8_t shape[] = {0x54u,0u,0u,0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x7E0080u,shape,sizeof(shape)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t destination_bank, source_bank, payload;
    if (sm_scpu_read8(cpu,bus,0x800081u,&destination_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,0x800082u,&source_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)source_bank << 16) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,((uint32_t)destination_bank << 16) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = destination_bank;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0x0083u;
        if (sm_scpu_expect_next(cpu,0x04000418u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    } else {
        cpu->pc = 0x0080u;
        if (sm_scpu_expect_next(cpu,0x04000400u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x04000402u: {
    static const uint8_t shape[] = {0x54u,0u,0u,0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x7E0080u,shape,sizeof(shape)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t destination_bank, source_bank, payload;
    if (sm_scpu_read8(cpu,bus,0x800081u,&destination_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,0x800082u,&source_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)source_bank << 16) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,((uint32_t)destination_bank << 16) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = destination_bank;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0x0083u;
        if (sm_scpu_expect_next(cpu,0x0400041Au) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    } else {
        cpu->pc = 0x0080u;
        if (sm_scpu_expect_next(cpu,0x04000402u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x04000418u: {
    static const uint8_t shape[] = {0x54u,0u,0u,0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x7E0080u,shape,sizeof(shape)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_expect_next(cpu,0x04046A08u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x0400041Au: {
    static const uint8_t shape[] = {0x54u,0u,0u,0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x7E0080u,shape,sizeof(shape)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_expect_next(cpu,0x0404DA72u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x04100400u: {
    static const uint8_t shape[] = {0x54u,0u,0u,0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x7E0080u,shape,sizeof(shape)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t destination_bank, source_bank, payload;
    if (sm_scpu_read8(cpu,bus,0x820081u,&destination_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,0x820082u,&source_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)source_bank << 16) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,((uint32_t)destination_bank << 16) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = destination_bank;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0x0083u;
        if (sm_scpu_expect_next(cpu,0x04100418u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    } else {
        cpu->pc = 0x0080u;
        if (sm_scpu_expect_next(cpu,0x04100400u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x04100418u: {
    static const uint8_t shape[] = {0x54u,0u,0u,0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x7E0080u,shape,sizeof(shape)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_expect_next(cpu,0x041704B0u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    return sm_scpu_finish(cpu,bus,6u);
}
case 0x05400400u: {
    static const uint8_t shape[] = {0x54u,0u,0u,0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x7E0080u,shape,sizeof(shape)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t destination_bank, source_bank, payload;
    if (sm_scpu_read8(cpu,bus,0xA80081u,&destination_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,0xA80082u,&source_bank) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_read8(cpu,bus,((uint32_t)source_bank << 16) | cpu->x,&payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_write8(cpu,bus,((uint32_t)destination_bank << 16) | cpu->y,payload) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->dbr = destination_bank;
    cpu->a = (uint16_t)(cpu->a - 1u);
    cpu->x = (uint16_t)(cpu->x + 1u);
    cpu->y = (uint16_t)(cpu->y + 1u);
    if (cpu->a == 0xFFFFu) {
        cpu->pc = 0x0083u;
        if (sm_scpu_expect_next(cpu,0x05400418u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    } else {
        cpu->pc = 0x0080u;
        if (sm_scpu_expect_next(cpu,0x05400400u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    }
    return sm_scpu_finish(cpu,bus,7u);
}
case 0x05400418u: {
    static const uint8_t shape[] = {0x54u,0u,0u,0x60u};
    if (sm_scpu_guard_code(cpu,bus,0x7E0080u,shape,sizeof(shape)) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    uint8_t low, high;
    if (sm_scpu_pull8(cpu,bus,&low) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    if (sm_scpu_pull8(cpu,bus,&high) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    cpu->pc = (uint16_t)(((uint16_t)high << 8) + low + 1u);
    if (sm_scpu_expect_next(cpu,0x05452178u) != SM_SCPU_EXECUTED) return SM_SCPU_STOPPED;
    return sm_scpu_finish(cpu,bus,6u);
}
    default: return SM_SCPU_NOT_MINE;
    }
}
