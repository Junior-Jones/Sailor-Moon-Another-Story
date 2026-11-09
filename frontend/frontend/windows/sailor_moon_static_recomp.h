#ifndef SAILOR_MOON_STATIC_RECOMP_FRONTEND_H
#define SAILOR_MOON_STATIC_RECOMP_FRONTEND_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SAILOR_MOON_RECOMP_ROM_SIZE 4194304u
#define SAILOR_MOON_RECOMP_FRAME_WIDTH 256u
#define SAILOR_MOON_RECOMP_FRAME_HEIGHT 224u
#define SAILOR_MOON_RECOMP_AUDIO_SAMPLE_RATE 32000u
#define SAILOR_MOON_RECOMP_HOST_AUDIO_SAMPLE_RATE 32000u
#define SAILOR_MOON_RECOMP_AUDIO_CHANNELS 2u
#define SAILOR_MOON_RECOMP_PRESENTATION_FPS_NUMERATOR 39375000u
#define SAILOR_MOON_RECOMP_PRESENTATION_FPS_DENOMINATOR 655171u

enum SailorMoonRecompInput {
    SAILOR_MOON_INPUT_B = 0x8000u, SAILOR_MOON_INPUT_Y = 0x4000u,
    SAILOR_MOON_INPUT_SELECT = 0x2000u, SAILOR_MOON_INPUT_START = 0x1000u,
    SAILOR_MOON_INPUT_UP = 0x0800u, SAILOR_MOON_INPUT_DOWN = 0x0400u,
    SAILOR_MOON_INPUT_LEFT = 0x0200u, SAILOR_MOON_INPUT_RIGHT = 0x0100u,
    SAILOR_MOON_INPUT_A = 0x0080u, SAILOR_MOON_INPUT_X = 0x0040u,
    SAILOR_MOON_INPUT_L = 0x0020u, SAILOR_MOON_INPUT_R = 0x0010u
};

typedef struct SailorMoonRecomp SailorMoonRecomp;
typedef void (*SailorMoonRecompAudioProgressCallback)(
    SailorMoonRecomp *instance, void *opaque);
typedef struct SailorMoonRecompFrameResult {
    uint8_t route_continued;
    uint8_t frame_rendered;
    uint16_t input_mask;
    uint32_t start_frame;
    uint32_t end_frame;
    char renderer_error[192];
} SailorMoonRecompFrameResult;

int sailor_moon_recomp_create(SailorMoonRecomp **out_instance,
                         const uint8_t *rom, size_t rom_size,
                         char *error, size_t error_capacity);
void sailor_moon_recomp_destroy(SailorMoonRecomp *instance);
int sailor_moon_recomp_reset(SailorMoonRecomp *instance,
                        char *error, size_t error_capacity);
int sailor_moon_recomp_advance(SailorMoonRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count,
                          SailorMoonRecompFrameResult *result);
int sailor_moon_recomp_advance_streamed(
    SailorMoonRecomp *instance, uint16_t input_mask, uint32_t frame_count,
    SailorMoonRecompAudioProgressCallback audio_progress, void *opaque,
    SailorMoonRecompFrameResult *result);
const uint32_t *sailor_moon_recomp_frame_bgra(const SailorMoonRecomp *instance);
uint32_t sailor_moon_recomp_frame_width(const SailorMoonRecomp *instance);
uint32_t sailor_moon_recomp_current_frame(const SailorMoonRecomp *instance);
uint64_t sailor_moon_recomp_instruction_count(const SailorMoonRecomp *instance);
int sailor_moon_recomp_failed(const SailorMoonRecomp *instance);
const char *sailor_moon_recomp_last_error(const SailorMoonRecomp *instance);
size_t sailor_moon_recomp_audio_available(const SailorMoonRecomp *instance);
size_t sailor_moon_recomp_audio_read(SailorMoonRecomp *instance,
                                int16_t *interleaved_stereo,
                                size_t frame_capacity);
size_t sailor_moon_recomp_audio_discard(SailorMoonRecomp *instance);
int sailor_moon_recomp_audio_overflowed(const SailorMoonRecomp *instance);
uint64_t sailor_moon_recomp_audio_dropped_frames(
    const SailorMoonRecomp *instance);
void sailor_moon_recomp_audio_clear_overflow(SailorMoonRecomp *instance);

int sailor_moon_recomp_snapshot_save(const SailorMoonRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity);
int sailor_moon_recomp_snapshot_load(SailorMoonRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity);
int sailor_moon_recomp_sram_copy(const SailorMoonRecomp *instance,
                            void *destination, size_t capacity);
int sailor_moon_recomp_sram_load(SailorMoonRecomp *instance,
                            const void *source, size_t size,
                            char *error, size_t error_capacity);
int sailor_moon_recomp_sram_dirty(const SailorMoonRecomp *instance);
void sailor_moon_recomp_sram_mark_clean(SailorMoonRecomp *instance);

#ifdef __cplusplus
}
#endif
#endif
