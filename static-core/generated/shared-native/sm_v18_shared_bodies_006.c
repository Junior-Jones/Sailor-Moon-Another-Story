#include "sm_v18_shared.h"
SmScpuExecResult sm_v18_body_0060(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xB9u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ) + ( uint32_t ) cpu -> y ) & 0xFFFFFFu ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = data_low ; uint16_t result = value ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | result ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x80u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_0061(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xCAu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> x = ( uint16_t ) ( cpu -> x - 1u ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> x & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> x == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_0062(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x8Fu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) , ((unsigned int)smp[2]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[3]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ((unsigned int)smp[4]) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , ( uint8_t ) ( cpu -> a >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[5]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[6]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0063(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xFAu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t low , high ; if ( sm_scpu_pull8 ( cpu , bus , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_pull8 ( cpu , bus , & high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> x = ( uint16_t ) ( low | ( ( uint16_t ) high << 8 ) ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> x & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> x == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_0064(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xDAu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( cpu -> x >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( cpu -> x >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u ) ;
}

SmScpuExecResult sm_v18_body_0065(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xB7u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t pointer = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t pointer_low , pointer_high , pointer_bank ; if ( sm_scpu_read8 ( cpu , bus , pointer , & pointer_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 1u ) & 0xFFFFu , & pointer_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 2u ) & 0xFFFFu , & pointer_bank ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) pointer_bank << 16 ) | ( ( uint32_t ) pointer_high << 8 ) | pointer_low ; address = ( address + cpu -> y ) & 0xFFFFFFu ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = data_low ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | value ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x80u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0066(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x98u } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> a = cpu -> y ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> a & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> a == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_0067(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x64u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; if ( sm_scpu_write8 ( cpu , bus , address , 0u ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0068(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xACu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; cpu -> y = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_0069(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x7Au } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t low , high ; if ( sm_scpu_pull8 ( cpu , bus , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_pull8 ( cpu , bus , & high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( low | ( ( uint16_t ) high << 8 ) ) ; cpu -> y = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_006A(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA5u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = data_low ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | value ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x80u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_006B(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x97u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t pointer = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t pointer_low , pointer_high , pointer_bank ; if ( sm_scpu_read8 ( cpu , bus , pointer , & pointer_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 1u ) & 0xFFFFu , & pointer_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 2u ) & 0xFFFFu , & pointer_bank ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) pointer_bank << 16 ) | ( ( uint32_t ) pointer_high << 8 ) | pointer_low ; address = ( address + cpu -> y ) & 0xFFFFFFu ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , ( uint8_t ) ( cpu -> a >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 7u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_006C(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x5Au } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( cpu -> y >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( cpu -> y >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u ) ;
}

SmScpuExecResult sm_v18_body_006D(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x85u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_006E(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x95u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) + cpu -> x ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_006F(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x3Au } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = cpu -> a ; uint16_t result = ( uint16_t ) ( value - 1u ) ; cpu -> a = result ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

