#include "sm_v18_shared.h"
SmScpuExecResult sm_v18_body_0020(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x08u } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( cpu -> p >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_0021(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x10u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t cycles = 2u ; if ( ( cpu -> p & SM_P_N ) == 0u ) { cpu -> pc = ((unsigned int)smp[2]) ; cycles = 3u ; } else { cpu -> pc = ((unsigned int)smp[3]) ; } if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[4]) && sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , cycles ) ;
}

SmScpuExecResult sm_v18_body_0022(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA6u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; cpu -> x = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0023(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x85u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) cpu -> a ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0024(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xE6u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; value = ( uint16_t ) ( value + 1u ) ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , ( uint8_t ) ( value >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) value ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 7u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0025(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xB5u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) + cpu -> x ) ; uint8_t low , high ; if ( sm_scpu_read8 ( cpu , bus , address , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , & high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( low | ( ( uint16_t ) high << 8 ) ) ; cpu -> a = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0026(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x80u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_0027(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x6Bu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t low , high , saved_bank ; if ( sm_scpu_pull8 ( cpu , bus , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_pull8 ( cpu , bus , & high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_pull8 ( cpu , bus , & saved_bank ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ( uint16_t ) ( ( ( uint16_t ) high << 8 ) + low + 1u ) ; cpu -> pbr = saved_bank ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[1]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0028(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xEEu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t result = ( uint16_t ) ( value + 1u ) ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , ( uint8_t ) ( result >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) result ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 8u ) ;
}

SmScpuExecResult sm_v18_body_0029(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x28u } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t low ; if ( sm_scpu_pull8 ( cpu , bus , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> p = low ; if ( ( cpu -> p & SM_P_X ) != 0u ) { cpu -> x = ( uint8_t ) cpu -> x ; cpu -> y = ( uint8_t ) cpu -> y ; } cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u ) ;
}

SmScpuExecResult sm_v18_body_002A(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA4u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; cpu -> y = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_002B(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x95u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) + cpu -> x ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , ( uint8_t ) ( cpu -> a >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_002C(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA5u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; uint8_t value ; if ( sm_scpu_read8 ( cpu , bus , address , & value ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | value ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( value & SM_P_N ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_002D(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x69u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( ( cpu -> p & SM_P_D ) != 0u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_DECIMAL_MODE" ) ; uint16_t value = ((unsigned int)smp[3]) ; uint16_t left = cpu -> a ; uint32_t sum = ( uint32_t ) left + value + ( ( cpu -> p & SM_P_C ) != 0u ) ; uint16_t result = ( uint16_t ) sum ; cpu -> a = result ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_V | SM_P_Z | SM_P_C ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( ( ~ ( left ^ value ) & ( left ^ result ) & 0x8000u ) != 0u ? SM_P_V : 0u ) | ( result == 0u ? SM_P_Z : 0u ) | ( sum > 0xFFFFu ? SM_P_C : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_002E(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xAEu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; cpu -> x = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_002F(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA8u } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> y = cpu -> a ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> y & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> y == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

