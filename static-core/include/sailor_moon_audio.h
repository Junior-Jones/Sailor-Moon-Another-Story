#ifndef SAILOR_MOON_AUDIO_H
#define SAILOR_MOON_AUDIO_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef struct Sm16Dsp Sm16Dsp;
enum { SM16_PCM_SIGNED16_STEREO = 1u };
typedef struct Sm16PcmMetrics {
    uint32_t native_rate, channels, format, frames_available;
    uint64_t frames, known_frames, unknown_frames, overflows;
    uint64_t phase_steps, smp_cycles, pcm_hash;
    uint8_t next_phase;
} Sm16PcmMetrics;

/* Core-owned native stereo integer PCM, before any host processing.
 * No allocation, clock advancement, resampling, volume or device access.
 * stereo has at least2*capacity elements and known at leastcapacity elements;
 * buffers are disjoint and the instance quiescent. Each known byte certifies
 * both channels of that frame; unknown representatives are not audio facts.
 * Drain consumes at mostcapacity frames. Counters remain cumulative. */
uint32_t sm16_sdsp_pcm_available(const Sm16Dsp *);
uint32_t sm16_sdsp_pcm_drain(Sm16Dsp *, int16_t *stereo, uint8_t *known, uint32_t capacity);
int sm16_sdsp_pcm_metrics(const Sm16Dsp *, Sm16PcmMetrics *);
#ifdef __cplusplus
}
#endif
#endif
