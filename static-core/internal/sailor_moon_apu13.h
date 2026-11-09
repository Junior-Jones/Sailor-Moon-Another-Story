#ifndef SAILOR_MOON_APU13_H
#define SAILOR_MOON_APU13_H
#include "sailor_moon_scheduler.h"

enum { SM12_ARAM_BYTES = 65536u, SM12_IPL_BYTES = 64u,
       SM12_STARTUP_CYCLES = 2u };
typedef enum Sm12Phase {
    SM12_IPL, SM12_ENTRY_PENDING, SM12_ENTRY_REQUIRED, SM12_FAILED,
    SM12_STATIC_RUNNING
} Sm12Phase;

/* Offline source-derived validation only. These records never seed ARAM or
 * replace IPL instructions/acknowledgements. Immutable arrays outlive owner.
 * Ordered records may overlap when their named upload epochs justify it. */
typedef struct Sm12UploadRecord {
    uint32_t rom_offset, length;
    uint16_t destination;
} Sm12UploadRecord;
typedef struct Sm12UploadContract {
    const Sm12UploadRecord *records;
    uint32_t record_count;
    uint16_t entry;
    uint8_t fresh_data_per_byte;
} Sm12UploadContract;

typedef struct Sm12Timer {
    uint16_t prescaler;
    uint8_t target, stage, output, enabled;
} Sm12Timer;
typedef struct Sm12Ipl {
    uint16_t pc, active_pc;
    uint8_t a, x, y, sp, psw;
    uint8_t active, cycle, remaining, length, branch_taken;
    uint8_t low, high, data;
    uint64_t low_sequence, high_sequence;
} Sm12Ipl;

/* Optional16 receiver. Without it only the oscillator phase counter advances;
 * DSP data accesses fail closed. No DSP implementation or PCM is supplied. */
typedef struct Sm12DspPort {
    void *context;
    Sm08Status (*step)(void *, Sm08Bus *, uint64_t smp_cycle, uint8_t phase);
    Sm08Status (*read)(void *, uint8_t address, Sm08Value *);
    Sm08Status (*write)(void *, uint8_t address, Sm08Value);
} Sm12DspPort;

typedef struct Sm12Apu Sm12Apu;
/* Named13 receiver; no decoder is installed here. enter observes the actual
 * consumed first fetch, cycle supplies exactly one next SMP cycle event.
 * before_write runs before the underlying SMP write, not after a partial
 * protected-byte mutation. Later external/DSP writers must separately apply
 * the immutable map and cannot use an active SMP writer's exception. */
typedef struct Sm12StaticPort {
    void *context;
    Sm08Status (*enter)(void *, Sm12Apu *);
    Sm08Status (*cycle)(void *, Sm12Apu *);
    Sm08Status (*before_write)(void *, Sm12Apu *, uint16_t, Sm08Value);
} Sm12StaticPort;

struct Sm12Apu {
    Sm08Bus *bus;
    Sm09Scheduler *scheduler;
    Sm09Receivers downstream;
    Sm12DspPort dsp;
    Sm12UploadContract source;
    Sm08Value aram[SM12_ARAM_BYTES];
    Sm08Value cpu_input[4], pending_input[4], smp_output[4], aux[2];
    uint64_t write_sequence, visible_sequence[4], pending_sequence[4];
    uint64_t sampled_sequence[4], sampled_half[4], output_half[4];
    uint64_t completed_half, smp_cycles, bus_events;
    uint64_t token_sequence, data_sequence, consumed_token_sequence, consumed_data_sequence;
    uint64_t ack_token_sequence, ack_data_sequence, ack_half;
    uint64_t jump_half, entry_half;
    uint32_t record_index, record_written, uploaded_bytes, upload_epoch;
    uint16_t jump_entry, entry_pc;
    Sm08Value entry_byte;
    Sm12Timer timers[3];
    Sm12Ipl ipl;
    Sm12Phase phase;
    uint8_t pending_mask, startup_remaining, dsp_phase;
    uint8_t control, dsp_address, ipl_enabled, record_open, bound, entry_prefetched;
    uint64_t reads[4], writes[4];
    Sm12StaticPort static_owner;
};

Sm08Status sm12_apu_power_on(Sm12Apu *, Sm08Bus *, Sm09Scheduler *);
Sm08Status sm12_apu_configure_source(Sm12Apu *, Sm12UploadContract);
Sm08Status sm12_apu_bind_dsp(Sm12Apu *, Sm12DspPort);
/* Bind cold before ordinary APUIO binding, or adopt only an actual stopped
 * first-fetch witness outside scheduler advancement. No clock or fetch is
 * manufactured by adoption; unrelated sticky faults are never cleared. */
Sm08Status sm12_apu_bind_static(Sm12Apu *, Sm12StaticPort);
Sm08Device sm12_apu_device(Sm12Apu *);
/* Replaces the old missing12 SMP callback; forwards existing raster/boundary
 * contexts without delegating to the obsolete SMP receiver. */
Sm08Status sm12_apu_bind(Sm12Apu *);
/* E is completed half-units. Complete one real SMP cycle only if E+2<=target.
 * APUIO also derives the half-view from09's whole counter AND remainder.
 * At the first uploaded fetch: capture byte/PC/epoch/phase for13, execute no
 * opcode, and stop with owner13 guard rather than pad to a later target. */
Sm08Status sm12_apu_sync_half(Sm12Apu *, uint64_t target_half);
Sm08Status sm12_apu_sync_current(Sm12Apu *);
Sm08Status sm12_apu_smp_read(Sm12Apu *, uint16_t, Sm08Value *);
Sm08Status sm12_apu_smp_write(Sm12Apu *, uint16_t, Sm08Value);
/* S-CPU RESET preserves EVERYTHING in this independent owner. */
Sm08Status sm12_apu_cpu_reset(Sm12Apu *);
/* Architectural SMP reset and an explicit jump back to IPL are separate.
 * Neither is a cold ARAM clear or an S-CPU reset side effect. */
Sm08Status sm12_apu_smp_reset(Sm12Apu *);
Sm08Status sm12_apu_restart_ipl(Sm12Apu *);
#endif
