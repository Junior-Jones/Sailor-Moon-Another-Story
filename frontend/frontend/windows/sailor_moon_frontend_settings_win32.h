#ifndef SAILOR_MOON_FRONTEND_SETTINGS_WIN32_H
#define SAILOR_MOON_FRONTEND_SETTINGS_WIN32_H

#include <windows.h>
#include <stdint.h>

#include "sailor_moon_gamepad_input_win32.h"

#define SAILOR_MOON_WIN_BINDING_COUNT 12
#define SAILOR_MOON_INPUT_SOURCE_KEYBOARD 0
#define SAILOR_MOON_INPUT_SOURCE_GAMEPAD 1

typedef enum SailorMoonWinBindingAction {
    SAILOR_MOON_WIN_BIND_UP = 0, SAILOR_MOON_WIN_BIND_DOWN, SAILOR_MOON_WIN_BIND_LEFT, SAILOR_MOON_WIN_BIND_RIGHT,
    SAILOR_MOON_WIN_BIND_SNES_B, SAILOR_MOON_WIN_BIND_SNES_A, SAILOR_MOON_WIN_BIND_SNES_Y,
    SAILOR_MOON_WIN_BIND_SNES_X, SAILOR_MOON_WIN_BIND_SNES_L, SAILOR_MOON_WIN_BIND_SNES_R,
    SAILOR_MOON_WIN_BIND_START, SAILOR_MOON_WIN_BIND_SELECT
} SailorMoonWinBindingAction;

typedef struct SailorMoonFrontendSettingsWin32 {
    int integer_scale;
    int pause_on_focus_loss;
    int auto_run_on_load;
    int fullscreen_on_play;
    int show_fps_counter;
    int ntsc_frame_lock;
    int snapshot_slot;
    int input_source;
    int input_source_saved;
    int welcome_shown;
    UINT bindings[SAILOR_MOON_WIN_BINDING_COUNT];
    int gamepad_bindings[SAILOR_MOON_WIN_BINDING_COUNT];
} SailorMoonFrontendSettingsWin32;

void sailor_moon_frontend_settings_win32_defaults(SailorMoonFrontendSettingsWin32 *s);
void sailor_moon_frontend_settings_win32_classic(SailorMoonFrontendSettingsWin32 *s);
void sailor_moon_frontend_settings_win32_load(SailorMoonFrontendSettingsWin32 *s,
                                          const wchar_t *path);
int sailor_moon_frontend_settings_win32_save(const SailorMoonFrontendSettingsWin32 *s,
                                         const wchar_t *path);
uint16_t sailor_moon_frontend_settings_win32_input(
    const SailorMoonFrontendSettingsWin32 *s, UINT virtual_key);
const wchar_t *sailor_moon_frontend_settings_win32_action_name(int action);
void sailor_moon_frontend_settings_win32_key_name(UINT virtual_key,
                                               wchar_t *text, size_t capacity);
int sailor_moon_frontend_settings_win32_dialog(HWND parent, HINSTANCE instance,
                                           SailorMoonFrontendSettingsWin32 *s);
int sailor_moon_frontend_controls_win32_dialog(HWND parent, HINSTANCE instance,
                                           SailorMoonFrontendSettingsWin32 *s,
                                           SailorMoonGamepadInputWin32 *gamepad);

#endif
