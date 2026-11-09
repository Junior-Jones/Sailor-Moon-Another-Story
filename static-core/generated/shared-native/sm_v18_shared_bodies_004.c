#include "sm_v18_shared.h"
SmScpuExecResult sm_v18_body_0040(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { ((unsigned int)smp[0]) , ((unsigned int)smp[1]) , ((unsigned int)smp[2]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[3]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , ((unsigned int)smp[6]) ) ;
}

SmScpuExecResult sm_v18_body_0041(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x30u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t cycles = 2u ; if ( ( cpu -> p & SM_P_N ) != 0u ) { cpu -> pc = ((unsigned int)smp[2]) ; cycles = 3u ; } else { cpu -> pc = ((unsigned int)smp[3]) ; } if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[4]) && sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , cycles ) ;
}

SmScpuExecResult sm_v18_body_0042(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x9Du , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ) + ( uint32_t ) cpu -> x ) & 0xFFFFFFu ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> a >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , ( uint8_t ) ( cpu -> a >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0043(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x6Du , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( ( cpu -> p & SM_P_D ) != 0u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_DECIMAL_MODE" ) ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t left = cpu -> a & 0xFFFFu ; uint32_t sum = ( uint32_t ) left + value + ( ( cpu -> p & SM_P_C ) != 0u ) ; uint16_t result = sum & 0xFFFFu ; cpu -> a = result ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_V | SM_P_Z | SM_P_C ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( ( ~ ( left ^ value ) & ( left ^ result ) & 0x8000u ) != 0u ? SM_P_V : 0u ) | ( result == 0u ? SM_P_Z : 0u ) | ( sum > 0xFFFFu ? SM_P_C : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_0044(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x49u , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ((unsigned int)smp[3]) ; uint16_t result = ( cpu -> a ^ value ) & 0xFFFFu ; cpu -> a = result ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_0045(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xB0u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t cycles = 2u ; if ( ( cpu -> p & SM_P_C ) != 0u ) { cpu -> pc = ((unsigned int)smp[2]) ; cycles = 3u ; } else { cpu -> pc = ((unsigned int)smp[3]) ; } if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[4]) && sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , cycles ) ;
}

SmScpuExecResult sm_v18_body_0046(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xBCu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ) + ( uint32_t ) cpu -> x ) & 0xFFFFFFu ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t result = value ; cpu -> y = result ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

SmScpuExecResult sm_v18_body_0047(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x1Au } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( cpu -> a + 1u ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> a & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> a == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_0048(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x29u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ((unsigned int)smp[2]) ; uint16_t result = ( cpu -> a & value ) & 0xFFu ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | result ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x80u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[3]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[4]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_0049(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x8Cu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ((unsigned int)smp[3]) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> y >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[4]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[5]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u ) ;
}

SmScpuExecResult sm_v18_body_004A(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xEAu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_004B(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA0u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ((unsigned int)smp[2]) ; cpu -> y = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x80u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[3]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[4]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_004C(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xEBu } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[0]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( ( cpu -> a << 8u ) | ( cpu -> a >> 8u ) ) ; uint16_t value = cpu -> a & 0xFFu ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x80u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[1]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[2]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 3u ) ;
}

SmScpuExecResult sm_v18_body_004D(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xFCu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[2]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( ! ( cpu -> x == 0x0000u || cpu -> x == 0x0002u ) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_INDEXED_CALL_DOMAIN" ) ; uint16_t saved_pc = ((unsigned int)smp[3]) ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( saved_pc >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; if ( sm_scpu_write8 ( cpu , bus , cpu -> s , ( uint8_t ) ( saved_pc >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; uint32_t pointer = ( ( uint32_t ) cpu -> pbr << 16 ) | ( uint16_t ) ( ((unsigned int)smp[4]) + cpu -> x ) ; uint8_t low , high ; if ( sm_scpu_read8 ( cpu , bus , pointer , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( ( uint32_t ) cpu -> pbr << 16 ) | ( uint16_t ) ( pointer + 1u ) , & high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t target = ( uint16_t ) ( low | ( ( uint16_t ) high << 8 ) ) ; if ( ! ( ( cpu -> x == 0x0000u && target == ((unsigned int)smp[5]) ) || ( cpu -> x == 0x0002u && target == ((unsigned int)smp[6]) ) ) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_INDEXED_CALL_TARGET" ) ; cpu -> pc = target ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[7]) && sm_scpu_context_key ( cpu ) != ((unsigned int)smp[8]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 8u ) ;
}

SmScpuExecResult sm_v18_body_004E(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x86u , ((unsigned int)smp[0]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[1]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + ((unsigned int)smp[0]) ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) cpu -> x ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , ( uint8_t ) ( cpu -> x >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = ((unsigned int)smp[2]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[3]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_004F(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xBFu , ((unsigned int)smp[0]) , ((unsigned int)smp[1]) , ((unsigned int)smp[2]) } ; if ( sm_scpu_guard_code ( cpu , bus , ((unsigned int)smp[3]) , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ((unsigned int)smp[4]) + ( uint32_t ) cpu -> x ) & 0xFFFFFFu ; uint8_t low , high ; if ( sm_scpu_read8 ( cpu , bus , address , & low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( low | ( ( uint16_t ) high << 8 ) ) ; cpu -> a = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = ((unsigned int)smp[5]) ; if ( sm_scpu_context_key ( cpu ) != ((unsigned int)smp[6]) ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 6u ) ;
}

