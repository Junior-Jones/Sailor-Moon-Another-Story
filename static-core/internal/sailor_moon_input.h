#ifndef SAILOR_MOON_INPUT_H
#define SAILOR_MOON_INPUT_H
#include "sailor_moon_scheduler.h"

enum { SM15_STANDARD_PAD_MASK = 0xfff0u };
typedef struct Sm15Word { uint16_t value, known_mask; } Sm15Word;
/* Caller explicitly supplies physical presence and native reports. No default
 * attachment, host key mapping or guessed live report is inferred from ROM.
 * Only standard pads are admitted. Absent ports/unconnected Data2 read0 per
 * Anomie1157. Report bits15..4 are B,Y,Select,Start,U,D,L,R,A,X,L,R; low4 are
 * the standard-pad signature, forced known0 by this hardware owner. */
typedef struct Sm15Physical {
    Sm15Word report[2];
    uint8_t present[2];
} Sm15Physical;

typedef struct Sm15Input {
    Sm08Bus *bus;
    Sm09Scheduler *scheduler;
    Sm15Physical physical;
    Sm15Word serial_shift[2], auto_result[4];
    Sm08Value sampled_serial[4];
    uint8_t cpu_strobe, auto_strobe, effective_strobe, bound;
    uint64_t serial_reads[2], autojoy_samples, report_sequence;
    uint64_t last_phase_clock;
    uint8_t last_phase;
} Sm15Input;

Sm08Status sm15_input_power_on(Sm15Input *, Sm08Bus *, Sm09Scheduler *, const Sm15Physical *);
Sm08Status sm15_input_bind(Sm15Input *);
/*09 abort/reset ordering precedes this guest-latch reset. External reports,
 * presence and report sequence survive; SRAM and absolute time are untouched. */
Sm08Status sm15_input_cpu_reset(Sm15Input *);
/* Physical-only setters. While effective latch is high, the hardware serial
 * latch follows live reports; after release it remains frozen. Connection
 * changes do not synthesize a new latch edge. No opposite-direction filter. */
Sm08Status sm15_input_set_report(Sm15Input *, unsigned port, Sm15Word);
Sm08Status sm15_input_set_present(Sm15Input *, unsigned port, uint8_t present);
Sm08Status sm15_input_result(const Sm15Input *, unsigned index, Sm15Word *);
Sm08Device sm15_input_device(Sm15Input *);
Sm09AutoJoyPort sm15_input_autojoy_port(Sm15Input *);
#endif
