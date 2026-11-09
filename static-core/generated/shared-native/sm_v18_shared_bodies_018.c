#include "sm_v18_shared.h"
SmScpuExecResult sm_v18_body_0180(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x74u , 0x2Bu } ; if ( sm_scpu_guard_code ( cpu , bus , 0x81E9ECu , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + 0x2Bu + cpu -> x ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( 0u >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = 0xE9EEu ; if ( sm_scpu_context_key ( cpu ) != 0x040F4F72u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 4u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0181(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x94u , 0x66u } ; if ( sm_scpu_guard_code ( cpu , bus , 0x81D4B7u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> d + 0x66u + cpu -> x ) ; if ( sm_scpu_write8 ( cpu , bus , address , ( uint8_t ) ( cpu -> y >> 0u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , ( uint8_t ) ( cpu -> y >> 8u ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> pc = 0xD4B9u ; if ( sm_scpu_context_key ( cpu ) != 0x040EA5C8u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0182(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA3u , 0x01u } ; if ( sm_scpu_guard_code ( cpu , bus , 0x80FDABu , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( uint16_t ) ( cpu -> s + 0x01u ) ; uint8_t data_low , data_high ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; cpu -> a = value ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> a & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> a == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = 0xFDADu ; if ( sm_scpu_context_key ( cpu ) != 0x0407ED69u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u ) ;
}

SmScpuExecResult sm_v18_body_0183(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xB0u , 0x0Eu } ; if ( sm_scpu_guard_code ( cpu , bus , 0x81C7EFu , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t cycles = 2u ; if ( ( cpu -> p & SM_P_C ) != 0u ) { cpu -> pc = 0xC7FFu ; cycles = 3u ; } else { cpu -> pc = 0xC7F1u ; } if ( sm_scpu_context_key ( cpu ) != 0x040E3F8Au ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , cycles ) ;
}

SmScpuExecResult sm_v18_body_0184(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x50u , 0x2Du } ; if ( sm_scpu_guard_code ( cpu , bus , 0xDE00C7u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t cycles = 2u ; if ( ( cpu -> p & SM_P_V ) == 0u ) { cpu -> pc = 0x00F6u ; cycles = 3u ; } else { cpu -> pc = 0x00C9u ; } if ( sm_scpu_context_key ( cpu ) != 0x06F0064Au && sm_scpu_context_key ( cpu ) != 0x06F007B2u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , cycles ) ;
}

SmScpuExecResult sm_v18_body_0185(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xD7u , 0xFDu } ; if ( sm_scpu_guard_code ( cpu , bus , 0x80F42Eu , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t pointer = ( uint16_t ) ( cpu -> d + 0xFDu ) ; uint8_t pointer_low , pointer_high , pointer_bank ; if ( sm_scpu_read8 ( cpu , bus , pointer , & pointer_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 1u ) & 0xFFFFu , & pointer_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 2u ) & 0xFFFFu , & pointer_bank ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) pointer_bank << 16 ) | ( ( uint32_t ) pointer_high << 8 ) | pointer_low ; address = ( address + cpu -> y ) & 0xFFFFFFu ; uint8_t data_low , data_high ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t result = ( cpu -> a - value ) & 0xFFFFu ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z | SM_P_C ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) | ( cpu -> a >= value ? SM_P_C : 0u ) ) ; cpu -> pc = 0xF430u ; if ( sm_scpu_context_key ( cpu ) != 0x0407A181u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 7u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0186(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x17u , 0x14u } ; if ( sm_scpu_guard_code ( cpu , bus , 0xA7864Fu , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t pointer = ( uint16_t ) ( cpu -> d + 0x14u ) ; uint8_t pointer_low , pointer_high , pointer_bank ; if ( sm_scpu_read8 ( cpu , bus , pointer , & pointer_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 1u ) & 0xFFFFu , & pointer_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 2u ) & 0xFFFFu , & pointer_bank ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) pointer_bank << 16 ) | ( ( uint32_t ) pointer_high << 8 ) | pointer_low ; address = ( address + cpu -> y ) & 0xFFFFFFu ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t result = ( cpu -> a | value ) & 0xFFFFu ; cpu -> a = result ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = 0x8651u ; if ( sm_scpu_context_key ( cpu ) != 0x053C3288u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 7u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0187(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xD7u , 0x10u } ; if ( sm_scpu_guard_code ( cpu , bus , 0x80EE81u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t pointer = ( uint16_t ) ( cpu -> d + 0x10u ) ; uint8_t pointer_low , pointer_high , pointer_bank ; if ( sm_scpu_read8 ( cpu , bus , pointer , & pointer_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 1u ) & 0xFFFFu , & pointer_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 2u ) & 0xFFFFu , & pointer_bank ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) pointer_bank << 16 ) | ( ( uint32_t ) pointer_high << 8 ) | pointer_low ; address = ( address + cpu -> y ) & 0xFFFFFFu ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint8_t data_high ; if ( sm_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & data_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = ( uint16_t ) ( data_low | ( ( uint16_t ) data_high << 8 ) ) ; uint16_t result = ( uint16_t ) ( cpu -> a - value ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z | SM_P_C ) ) | ( ( result & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) | ( cpu -> a >= value ? SM_P_C : 0u ) ) ; cpu -> pc = 0xEE83u ; if ( sm_scpu_context_key ( cpu ) != 0x04077418u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 7u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0188(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x12u , 0x10u } ; if ( sm_scpu_guard_code ( cpu , bus , 0xA8AF95u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t pointer = ( uint16_t ) ( cpu -> d + 0x10u ) ; uint8_t pointer_low , pointer_high ; if ( sm_scpu_read8 ( cpu , bus , pointer , & pointer_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( sm_scpu_read8 ( cpu , bus , ( pointer + 1u ) & 0xFFFFu , & pointer_high ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint32_t address = ( ( uint32_t ) cpu -> dbr << 16 ) | ( ( uint32_t ) pointer_high << 8 ) | pointer_low ; uint8_t data_low ; if ( sm_scpu_read8 ( cpu , bus , address , & data_low ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t value = data_low ; uint16_t result = ( cpu -> a | value ) & 0xFFu ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | result ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x80u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = 0xAF97u ; if ( sm_scpu_context_key ( cpu ) != 0x05457CBAu ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 5u + ( ( cpu -> d & 0xFFu ) != 0u ) ) ;
}

SmScpuExecResult sm_v18_body_0189(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x3Au } ; if ( sm_scpu_guard_code ( cpu , bus , 0x80FDF9u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( cpu -> a - 1u ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> a & 0x8000u ) != 0u ? SM_P_N : 0u ) | ( cpu -> a == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = 0xFDFAu ; if ( sm_scpu_context_key ( cpu ) != 0x0407EFD1u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_018A(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x9Au } ; if ( sm_scpu_guard_code ( cpu , bus , 0x00FF88u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> s = cpu -> x ; cpu -> pc = 0xFF89u ; if ( sm_scpu_context_key ( cpu ) != 0x0007FC48u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_018B(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xA8u } ; if ( sm_scpu_guard_code ( cpu , bus , 0x809CC4u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; cpu -> y = ( uint8_t ) cpu -> a ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( cpu -> y & 0x80u ) != 0u ? SM_P_N : 0u ) | ( cpu -> y == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = 0x9CC5u ; if ( sm_scpu_context_key ( cpu ) != 0x0404E62Bu ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_018C(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xFBu } ; if ( sm_scpu_guard_code ( cpu , bus , 0x00FF82u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( ( cpu -> p & SM_P_C ) != 0u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_XCE_CARRY_DOMAIN" ) ; cpu -> e = 0u ; cpu -> p = ( uint8_t ) ( cpu -> p & ~ SM_P_C ) ; cpu -> pc = 0xFF83u ; if ( sm_scpu_context_key ( cpu ) != 0x0007FC1Au ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_018D(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0xFBu } ; if ( sm_scpu_guard_code ( cpu , bus , 0x00FF82u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; if ( ( cpu -> p & SM_P_C ) != 0u ) return sm_scpu_stop ( cpu , bus , "UNPROVED_XCE_CARRY_DOMAIN" ) ; cpu -> e = 0u ; cpu -> p = ( uint8_t ) ( cpu -> p | SM_P_C ) ; cpu -> pc = 0xFF83u ; if ( sm_scpu_context_key ( cpu ) != 0x0007FC1Bu ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_018E(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x2Au } ; if ( sm_scpu_guard_code ( cpu , bus , 0xDE00B8u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t left = cpu -> a & 0xFFu ; uint16_t value = ( uint16_t ) ( ( ( left << 1u ) | ( ( cpu -> p & SM_P_C ) != 0u ) ) & 0xFFu ) ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | value ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ SM_P_C ) | ( ( left & 0x80u ) != 0u ? SM_P_C : 0u ) ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( value & 0x80u ) != 0u ? SM_P_N : 0u ) | ( value == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = 0x00B9u ; if ( sm_scpu_context_key ( cpu ) != 0x06F005CAu ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

SmScpuExecResult sm_v18_body_018F(SmScpuState *cpu, const SmScpuBus *bus, const uint32_t *smp) {
    (void)smp;
    const uint8_t source_bytes [ ] = { 0x8Au } ; if ( sm_scpu_guard_code ( cpu , bus , 0xA8DF90u , source_bytes , sizeof ( source_bytes ) ) != SM_SCPU_EXECUTED ) return SM_SCPU_STOPPED ; uint16_t result = cpu -> x & 0xFFu ; cpu -> a = ( uint16_t ) ( ( cpu -> a & 0xFF00u ) | result ) ; cpu -> p = ( uint8_t ) ( ( cpu -> p & ~ ( SM_P_N | SM_P_Z ) ) | ( ( result & 0x80u ) != 0u ? SM_P_N : 0u ) | ( result == 0u ? SM_P_Z : 0u ) ) ; cpu -> pc = 0xDF91u ; if ( sm_scpu_context_key ( cpu ) != 0x0546FC8Au ) return sm_scpu_stop ( cpu , bus , "UNPROVED_SUCCESSOR_CONTEXT" ) ; return sm_scpu_finish ( cpu , bus , 2u ) ;
}

