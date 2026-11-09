#ifndef SAILOR_MOON_CORE_H
#define SAILOR_MOON_CORE_H
#include <stddef.h>
#include <stdint.h>
#include "sailor_moon_audio.h"
#ifdef __cplusplus
extern "C" {
#endif

enum { SM_CORE_ROM_BYTES=4194304u, SM_CORE_SRAM_BYTES=9296u,
       SM_CORE_WIDTH=256u, SM_CORE_HEIGHT=224u,
       SM_CORE_PIXELS=57344u, SM_CORE_FRAME_KNOWN_BYTES=7168u,
       SM_CORE_OPTIONS_VERSION=2u };
typedef enum SmCoreColdStorageProfile {
    SM_CORE_STRICT_UNKNOWN=0,
    SM_CORE_DETERMINISTIC_ZERO_STORAGE_V1=1,
    SM_CORE_DETERMINISTIC_ZERO_STORAGE_APUIO_V1=2
} SmCoreColdStorageProfile;
typedef struct SmCore SmCore;
typedef enum SmCoreStatus {
    SM_CORE_OK=0, SM_CORE_ARGUMENT, SM_CORE_BAD_ROM, SM_CORE_UNKNOWN,
    SM_CORE_GUARD, SM_CORE_STORAGE, SM_CORE_LATE_SRAM_LOAD, SM_CORE_SRAM_OVERFLOW,
    SM_CORE_BAD_SAVE, SM_CORE_PPU_ABSENT, SM_CORE_APUIO_ABSENT,
    SM_CORE_DMA_ABSENT, SM_CORE_INPUT_ABSENT, SM_CORE_CLOCK_ABSENT,
    SM_CORE_IO_ABSENT, SM_CORE_REGISTER, SM_CORE_ALLOCATION
} SmCoreStatus;
typedef enum SmCoreRunResult {
    SM_CORE_FRAME_READY, SM_CORE_TARGET_REACHED, SM_CORE_BUDGET,
    SM_CORE_STOPPED, SM_CORE_BAD_ARGUMENT
} SmCoreRunResult;
typedef struct SmCorePad { uint16_t value, known_mask; uint8_t present; } SmCorePad;
/* Required immutable options. Values of unforced CPU registers are explicit
 * functional representatives, never measured board/reset facts. The separate
 * explicit cold-storage profile is a reproducibility contract, not ROM writes
 * or universal physical power-on values. Report order B,Y,Select,Start,U,D,L,R,A,X,L,R
 * in bits15..4; attachment is separate from an unpressed report. */
typedef struct SmCoreOptions {
    uint32_t version;
    uint32_t cold_storage_profile;
    char name[32];
    uint16_t cpu_a,cpu_x,cpu_y,cpu_s,cpu_d;
    uint8_t cpu_pbr,cpu_dbr,cpu_p,cpu_e;
    uint8_t external_pin_value,external_pin_known_mask;
    SmCorePad pads[2];
} SmCoreOptions;
void sm_core_options_functional_neutral_v1(SmCoreOptions *);
/* Same neutral CPU/pins/pads, with complete zero+known WRAM/VRAM/CGRAM/OAM/
 * ARAM cold images. Does not seed SRAM, registers, latches, DSP or timing.
 * Hardware RESET preserves images; cold restart reapplies the named profile. */
void sm_core_options_deterministic_zero_storage_v1(SmCoreOptions *);
/* Profile2 adds all four input and four output directional APUIO cold values
 * zero+known. Explicit functional convention, not a physical reset claim.
 * No write/ACK/sequence is synthesized; actual writes replace the latches. */
void sm_core_options_deterministic_zero_storage_apuio_v1(SmCoreOptions *);
typedef struct SmCoreTiming {
    uint32_t master_numerator,master_denominator;
    uint32_t presentation_numerator,presentation_denominator;
    uint32_t smp_hz,pcm_hz,smp_ratio_numerator,smp_ratio_denominator;
    uint16_t normal_line,short_line,field_lines,width,height;
    uint32_t reset_release_master_clocks;
} SmCoreTiming;
typedef struct SmCoreDiagnostic {
    SmCoreStatus status;
    uint32_t cold_storage_profile,options_version;
    uint32_t failure_owner,failure_address,scpu_address,scpu_context;
    uint8_t failure_value,failure_known_mask;
    char failure_reason[128];
    uint64_t master_clock,completed_fields,cpu_cycles,scpu_instructions;
    uint64_t smp_target,smp_cycles,completed_half,apu_bus_events,published_sequence;
    uint32_t smp_remainder,upload_epoch,uploaded_bytes;
    uint64_t raster_deliveries,dma_completed_bytes;
    uint16_t scpu_a,scpu_x,scpu_y,scpu_s,scpu_d,scanline,hclock,dot;
    uint16_t smp_pc,smp_active_pc,smp_return_depth;
    uint8_t scpu_p,scpu_e,scpu_pbr,scpu_dbr,scpu_stopped;
    uint8_t apu_phase,smp_active,smp_cycle_index,dsp_phase;
    uint8_t dma_channel,hdma_enable,dma_servicing,ppu_mode,ppu_mode_known;
    uint8_t ppu_blank,ppu_brightness,ppu_main,ppu_main_known;
    uint8_t active_voice_mask,active_voice_known_mask;
    uint32_t render_status,render_dependency,render_address;
    uint16_t render_x,render_y,render_mask,render_known_mask;
    Sm16PcmMetrics pcm;
} SmCoreDiagnostic;

/* Owns a durable private exact-ROM copy, validates identity before vectors,
 * decodes optional complete portable SRAM before first guest access. No IO. */
SmCore *sm_core_create(const uint8_t *,size_t,const uint8_t *,size_t,
                       const SmCoreOptions *,SmCoreStatus *);
void sm_core_destroy(SmCore *);
SmCoreStatus sm_core_hardware_reset(SmCore *);
/* Frontend Reset: transactional fresh cold machine with live battery data and
 * current physical reports, unlike retained-state SNES hardware RESET. */
SmCoreStatus sm_core_cold_restart(SmCore *);
SmCoreStatus sm_core_set_pad(SmCore *,unsigned,uint16_t,uint16_t);
SmCoreStatus sm_core_set_present(SmCore *,unsigned,uint8_t);
/* Progress callback is synchronous/observational except it may drain PCM.
 * It must not reenter advancement/reset/load/input. No host timing authority. */
typedef void (*SmCoreAudioProgress)(SmCore *,void *);
SmCoreRunResult sm_core_run_to_frame(SmCore *,uint64_t instruction_budget,
    uint64_t master_budget,uint64_t *steps,SmCoreAudioProgress,void *);
/* Target is a minimum natural master boundary: the last real static step may
 * cross it. Diagnostics report the actual clock; no padding/truncation occurs. */
SmCoreRunResult sm_core_run_until_master(SmCore *,uint64_t target,
    uint64_t instruction_budget,uint64_t *steps,SmCoreAudioProgress,void *);
int sm_core_copy_frame(const SmCore *,uint16_t *,uint32_t,uint8_t *,uint32_t,
                       uint16_t *,uint16_t *,uint64_t *);
uint32_t sm_core_pcm_available(const SmCore *);
uint32_t sm_core_pcm_drain(SmCore *,int16_t *,uint8_t *,uint32_t);
int sm_core_pcm_metrics(const SmCore *,Sm16PcmMetrics *);
int sm_core_timing(SmCoreTiming *);
int sm_core_diagnostic(const SmCore *,SmCoreDiagnostic *);
SmCoreStatus sm_core_encode_sram(const SmCore *,uint8_t *,size_t,uint64_t *);
int sm_core_ack_sram(SmCore *,uint64_t);
/* Native-ABI pointer-free, exact ROM/options/build-bound snapshots. Load is
 * transactional, with no reset/bind/time advancement; host queues are cleared
 * by the caller only after success. Guest pending PCM is serialized state. */
size_t sm_core_snapshot_size(const SmCore *);
int sm_core_snapshot_save(const SmCore *,void *,size_t);
int sm_core_snapshot_load(SmCore *,const void *,size_t);
int sm_core_build_identity(uint8_t output[32]);
#ifdef __cplusplus
}
#endif
#endif
