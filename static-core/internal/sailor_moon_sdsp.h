#ifndef SAILOR_MOON_SDSP_H
#define SAILOR_MOON_SDSP_H
#include "sailor_moon_apu13.h"
#include "../include/sailor_moon_audio.h"

enum { SM16_VOICES = 8u, SM16_REGISTERS = 128u, SM16_PHASES = 32u,
       SM16_NATIVE_HZ = 32000u, SM16_PCM_CAPACITY = 4096u };
typedef struct Sm16Scalar { int32_t value; uint8_t known; } Sm16Scalar;
typedef struct Sm16Address { uint16_t value; uint8_t known; } Sm16Address;
typedef enum Sm16Envelope { SM16_RELEASE, SM16_ATTACK, SM16_DECAY, SM16_SUSTAIN } Sm16Envelope;

typedef struct Sm16Voice {
    Sm16Scalar decoded[12], envelope, hidden_envelope, output;
    Sm16Address brr_address;
    uint16_t interpolation;
    uint8_t interpolation_known, decode_position, brr_offset;
    uint8_t key_delay, key_delay_known, mode, mode_known;
    Sm08Value envx, looped;
} Sm16Voice;

struct Sm16Dsp {
    Sm12Apu *apu;
    Sm08Bus *bus;
    Sm08Value registers[SM16_REGISTERS];
    Sm16Voice voice[SM16_VOICES];
    Sm08Value flags, kon_pending, kon_latch, koff_latch;
    Sm08Value pmon, noise_enable, echo_enable, directory, source;
    Sm08Value adsr1, brr_header, brr_data, endx_latch, outx_latch, envx_latch;
    Sm16Address directory_address, next_brr, echo_pointer;
    Sm16Scalar voice_output, dry[2], echo_input[2], fir[2];
    Sm16Scalar echo_history[8][2];
    Sm08Value echo_page, echo_write_disable;
    uint16_t pitch, rate_counter, noise_lfsr, echo_offset, echo_length;
    uint8_t pitch_known, noise_known, echo_offset_known, echo_length_known;
    uint8_t phase, alternating_sample, history_index, bound;
    uint32_t zero_delay_samples;
    int16_t pcm[SM16_PCM_CAPACITY * 2u];
    uint8_t pcm_known[SM16_PCM_CAPACITY];
    uint32_t pcm_read, pcm_write, pcm_count;
    uint64_t phase_steps, frames, known_frames, unknown_frames, overflows;
    uint64_t register_reads, register_writes, aram_reads, aram_writes, last_smp_cycle;
    uint64_t pcm_hash;
};

/* Cold state uses primary-forced internal FLG/reset/release/counter/noise;
 * raw unforced registers and retained sample/echo histories remain tagged.
 * ARAM is the actual12 backing storage, never a reconstructed-image seed. */
Sm08Status sm16_sdsp_power_on(Sm16Dsp *, Sm12Apu *);
Sm08Status sm16_sdsp_bind(Sm16Dsp *);
Sm12DspPort sm16_sdsp_port(Sm16Dsp *);
/* Raw reads return tags, including unknown data discarded by actual13 dummy
 * reads. The semantic consumer owns strict control/value-knownness failure. */
Sm08Status sm16_sdsp_read(Sm16Dsp *, uint8_t address, Sm08Value *);
Sm08Status sm16_sdsp_write(Sm16Dsp *, uint8_t address, Sm08Value);
Sm08Status sm16_sdsp_step(Sm16Dsp *, uint64_t smp_cycle, uint8_t phase);
/* Physical DSP ARAM, with separate external-writer protection. No SMP MMIO
 * action or active-SPC writer exception is granted by this byte/word API. */
Sm08Status sm16_sdsp_aram_write_word(Sm16Dsp *, Sm16Address, Sm16Scalar);
/* Consuming bounded native S16 stereo drain; no host processing/clocking.
 * Overflow increments a counter then faults owner16 before overwriting FIFO. */
uint32_t sm16_sdsp_pcm_available(const Sm16Dsp *);
uint32_t sm16_sdsp_pcm_drain(Sm16Dsp *, int16_t *stereo, uint8_t *known, uint32_t capacity);
#endif
