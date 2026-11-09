#include "sm_v18_shared.h"
SmScpuExecResult sm_v18_body_0010(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xBDu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ) + ( uint32_t ) cpu -> x ) & 0xFFFFFFu ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; cpu -> a = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0011(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x8Du , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u ) ;
}

SmScpuExecResult sm_v18_body_0012(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x9Cu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; if ( sm_scpu_write8 ( cpu , bus , address , 0u ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , 0u ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_0013(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xE2u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( cpu -> p | ((unsigned int)smp[0]) ) ; if ( ( cpu -> p & SM_P_X ) != 0u ) { cpu -> x = ( uint8_t ) cpu -> x ; cpu -> y = ( uint8_t ) cpu -> y ; } cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_0014(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xAAu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> x = cpu -> a ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> x & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> x == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_0015(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xB9u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ) + ( uint32_t ) cpu -> y ) & 0xFFFFFFu ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; cpu -> a = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0016(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x8Bu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( cpu -> dbr >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_0017(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA9u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ((unsigned int)smp[2]) ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | value ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x80u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[3]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[4]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_0018(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x89u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ SM_P_Z ) | ( ( cpu -> a & ((unsigned int)smp[3]) ) == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_0019(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA0u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ((unsigned int)smp[3]) ; cpu -> y = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_001A(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x0Cu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t result = ( uint16_t ) ( value | cpu -> a ) ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , ( uint8_t ) ( result >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( result >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ SM_P_Z ) | ( ( cpu -> a & value ) == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 8u ) ;
}

SmScpuExecResult sm_v18_body_001B(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x4Bu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( cpu -> pbr >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_001C(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA2u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ((unsigned int)smp[3]) ; cpu -> x = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_001D(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x1Cu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t result = ( uint16_t ) ( value & ~ cpu -> a ) ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , ( uint8_t ) ( result >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( result >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ SM_P_Z ) | ( ( cpu -> a & value ) == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 8u ) ;
}

SmScpuExecResult sm_v18_body_001E(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xC9u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ((unsigned int)smp[3]) ; uint16_t left = cpu -> a & 0xFFFFu ; uint16_t result = ( uint16_t ) ( left - value ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z | SM_P_C ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( ( result & 0xFFFFu ) == 0u ? SM_P_Z : 0u ) | ( left >= value ? SM_P_C : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_001F(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xC8u } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> y = ( uint16_t ) ( cpu -> y + 1u ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> y & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> y == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

