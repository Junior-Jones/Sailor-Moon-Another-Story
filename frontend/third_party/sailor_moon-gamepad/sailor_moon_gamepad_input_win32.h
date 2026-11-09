#ifndef SAILOR_MOON_GAMEPAD_INPUT_WIN32_H
#define SAILOR_MOON_GAMEPAD_INPUT_WIN32_H

#include <stddef.h>
#include <stdint.h>
#include <windows.h>

#include <SDL3/SDL_gamepad.h>

#define SAILOR_MOON_GAMEPAD_BINDING_COUNT 12

typedef enum SailorMoonGamepadControl {
    SAILOR_MOON_GAMEPAD_DPAD_UP = 1,
    SAILOR_MOON_GAMEPAD_DPAD_DOWN,
    SAILOR_MOON_GAMEPAD_DPAD_LEFT,
    SAILOR_MOON_GAMEPAD_DPAD_RIGHT,
    SAILOR_MOON_GAMEPAD_LEFT_STICK_UP,
    SAILOR_MOON_GAMEPAD_LEFT_STICK_DOWN,
    SAILOR_MOON_GAMEPAD_LEFT_STICK_LEFT,
    SAILOR_MOON_GAMEPAD_LEFT_STICK_RIGHT,
    SAILOR_MOON_GAMEPAD_FACE_SOUTH,
    SAILOR_MOON_GAMEPAD_FACE_EAST,
    SAILOR_MOON_GAMEPAD_FACE_WEST,
    SAILOR_MOON_GAMEPAD_FACE_NORTH,
    SAILOR_MOON_GAMEPAD_LEFT_SHOULDER,
    SAILOR_MOON_GAMEPAD_RIGHT_SHOULDER,
    SAILOR_MOON_GAMEPAD_LEFT_TRIGGER,
    SAILOR_MOON_GAMEPAD_RIGHT_TRIGGER,
    SAILOR_MOON_GAMEPAD_START,
    SAILOR_MOON_GAMEPAD_BACK,
    SAILOR_MOON_GAMEPAD_LEFT_STICK_BUTTON,
    SAILOR_MOON_GAMEPAD_RIGHT_STICK_BUTTON,
    SAILOR_MOON_GAMEPAD_CONTROL_LAST = SAILOR_MOON_GAMEPAD_RIGHT_STICK_BUTTON
} SailorMoonGamepadControl;

typedef struct SailorMoonGamepadInputWin32 {
    SDL_Gamepad *handle;
    int initialized;
    int startup_gamepad_found;
    unsigned refresh_countdown;
    wchar_t name[160];
} SailorMoonGamepadInputWin32;

int sailor_moon_gamepad_win32_initialize(SailorMoonGamepadInputWin32 *input,
                                     const wchar_t *mapping_path);
void sailor_moon_gamepad_win32_shutdown(SailorMoonGamepadInputWin32 *input);
uint16_t sailor_moon_gamepad_win32_poll(
    SailorMoonGamepadInputWin32 *input,
    const int bindings[SAILOR_MOON_GAMEPAD_BINDING_COUNT]);
int sailor_moon_gamepad_win32_connected(const SailorMoonGamepadInputWin32 *input);
const wchar_t *sailor_moon_gamepad_win32_name(const SailorMoonGamepadInputWin32 *input);
void sailor_moon_gamepad_win32_default_bindings(
    int bindings[SAILOR_MOON_GAMEPAD_BINDING_COUNT]);
const wchar_t *sailor_moon_gamepad_win32_control_name(int control);
int sailor_moon_gamepad_win32_capture_control(SailorMoonGamepadInputWin32 *input);
void sailor_moon_gamepad_win32_control_display_name(
    const SailorMoonGamepadInputWin32 *input, int control,
    wchar_t *text, size_t capacity);

#endif
