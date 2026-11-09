#include "sm_v18_shared.h"
SmScpuExecResult sm_v18_body_0050(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x54u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t payload ; if ( sm_scpu_read8 ( cpu , bus , ( ((unsigned int)smp[1]) << 16u ) | cpu -> x , & payload ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( ((unsigned int)smp[0]) << 16u ) | cpu -> y , payload ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> dbr = ((unsigned int)smp[0]) ; cpu -> a = ( uint16_t ) ( cpu -> a - 1u ) ; cpu -> x = ( uint16_t ) ( cpu -> x + 1u ) ; cpu -> y = ( uint16_t ) ( cpu -> y + 1u ) ; if ( cpu -> a == 0xFFFFu ) { cpu -> pc = ((unsigned int)smp[3]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[4]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; } else { cpu -> pc = ((unsigned int)smp[5]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[6]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; } return sm_scpu_finish ( cpu , bus , 7u ) ;
}

SmScpuExecResult sm_v18_body_0051(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x6Bu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t low , high , saved_bank ; if ( sm_scpu_pull8 ( cpu , bus , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_pull8 ( cpu , bus , & high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_pull8 ( cpu , bus , & saved_bank ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ( uint16_t ) ( ( ( uint16_t ) high << 8 ) + low + 1u ) ; cpu -> pbr = saved_bank ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[1]) && sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0052(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x74u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) + cpu -> x ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( 0u >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , ( uint8_t ) ( 0u >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0053(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x9Fu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) , ((unsigned int)smp[2]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[3]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ((unsigned int)smp[4]) + ( uint32_t ) cpu -> x ) & 0xFFFFFFu ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , ( uint8_t ) ( cpu -> a >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[5]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[6]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0054(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x7Du , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( ( cpu -> p & SM_P_D ) != 0u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_DECIMAL_MODE" ) ; uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ) + ( uint32_t ) cpu -> x ) & 0xFFFFFFu ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t left = cpu -> a ; uint32_t sum = ( uint32_t ) left + value + ( ( cpu -> p & SM_P_C ) != 0u ) ; uint16_t result = ( uint16_t ) sum ; cpu -> a = result ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_V | SM_P_Z | SM_P_C ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( ( ( ~ ( left ^ value ) & ( left ^ result ) ) & 0x8000u ) != 0u ? SM_P_V : 0u ) | ( result == 0u ? SM_P_Z : 0u ) | ( sum > 0xFFFFu ? SM_P_C : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0055(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x9Cu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; if ( sm_scpu_write8 ( cpu , bus , address , 0u ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u ) ;
}

SmScpuExecResult sm_v18_body_0056(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x88u } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> y = ( uint16_t ) ( cpu -> y - 1u ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> y & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> y == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_0057(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x60u } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t low , high ; if ( sm_scpu_pull8 ( cpu , bus , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_pull8 ( cpu , bus , & high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ( uint16_t ) ( ( ( uint16_t ) high << 8 ) + low + 1u ) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[1]) && sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) && sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0058(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xC5u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t result = ( uint16_t ) ( cpu -> a - value ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z | SM_P_C ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) | ( cpu -> a >= value ? SM_P_C : 0u ) ) ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0059(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x99u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ) + ( uint32_t ) cpu -> y ) & 0xFFFFFFu ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_005A(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x91u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t pointer = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t pointer_low , pointer_high ; if ( sm_scpu_read8 ( cpu , bus , pointer , & pointer_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 1u ) & 0xFFFFu , & pointer_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16 ) | ( ( uint32_t ) pointer_high << 8 ) | pointer_low ) + cpu -> y ) & 0xFFFFFFu ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , ( uint8_t ) ( cpu -> a >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 7u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_005B(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xE9u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( ( cpu -> p & SM_P_D ) != 0u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_DECIMAL_MODE" ) ; uint16_t value = ((unsigned int)smp[3]) ; uint16_t left = cpu -> a ; uint32_t sum = ( uint32_t ) left + ( value ^ 0xFFFFu ) + ( ( cpu -> p & SM_P_C ) != 0u ) ; uint16_t result = ( uint16_t ) sum ; cpu -> a = result ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_V | SM_P_Z | SM_P_C ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( ( ( left ^ value ) & ( left ^ result ) & 0x8000u ) != 0u ? SM_P_V : 0u ) | ( result == 0u ? SM_P_Z : 0u ) | ( sum > 0xFFFFu ? SM_P_C : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_005C(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x84u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> y >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , ( uint8_t ) ( cpu -> y >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_005D(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x09u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ((unsigned int)smp[2]) ; uint16_t result = ( cpu -> a | value ) & 0xFFu ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | result ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x80u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[3]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[4]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_005E(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xABu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t value ; if ( sm_scpu_pull8 ( cpu , bus , & value ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> dbr = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x80u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u ) ;
}

SmScpuExecResult sm_v18_body_005F(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x8Au } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> a = cpu -> x ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> a & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> a == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

