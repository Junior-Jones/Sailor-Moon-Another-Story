#ifndef SAILOR_MOON_AUDIO_RESAMPLER_H
#define SAILOR_MOON_AUDIO_RESAMPLER_H

#include <stddef.h>
#include <stdint.h>

typedef enum SailorMoonAudioResamplerMode {
    SAILOR_MOON_AUDIO_RESAMPLER_HERMITE = 0,
    SAILOR_MOON_AUDIO_RESAMPLER_LINEAR = 1,
    SAILOR_MOON_AUDIO_RESAMPLER_NEAREST = 2
} SailorMoonAudioResamplerMode;

#define SAILOR_MOON_AUDIO_RESAMPLER_PENDING_FRAMES 16384u

typedef struct SailorMoonAudioHermiteResampler {
    double previous_left[4];
    double previous_right[4];
    double rate_ratio;
    double fraction;
    int16_t last_left;
    int16_t last_right;
    int mode;
    int16_t pending_samples[SAILOR_MOON_AUDIO_RESAMPLER_PENDING_FRAMES * 2u];
    size_t pending_frames;
} SailorMoonAudioHermiteResampler;

void sailor_moon_audio_resampler_reset(SailorMoonAudioHermiteResampler *resampler);
void sailor_moon_audio_resampler_set_rates(SailorMoonAudioHermiteResampler *resampler,
                                      double source_rate,
                                      double destination_rate);
void sailor_moon_audio_resampler_set_mode(SailorMoonAudioHermiteResampler *resampler,
                                     int mode);

/* The caller must supply enough output storage.  For the Sailor Moon: Another Story
   32,040 Hz to 48,000 Hz path, twice input_frames is always sufficient. */
size_t sailor_moon_audio_resampler_process(SailorMoonAudioHermiteResampler *resampler,
                                      const int16_t *input,
                                      size_t input_frames,
                                      int16_t *output,
                                      size_t output_capacity_frames);

#endif
