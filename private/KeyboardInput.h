#ifndef ENIGMA_WINDOW_KEYBOARDINPUT_H
#define ENIGMA_WINDOW_KEYBOARDINPUT_H
#include "base.h"
#include "WindowModule.h"
#ifdef __cplusplus
extern "C"
{
#endif
#ifndef EI_CUSTOM_KEYS
// https://www.glfw.org/docs/3.3/group__keys.html
// glfw keycodes based on USB HID Usage Tables so I use it too
typedef enum {
    EI_KEY_UNKNOWN = -1,
    EI_KEY_SPACE = 32,
    EI_KEY_APOSTROPHE = 39,
    EI_KEY_COMMA = 44,
    EI_KEY_MINUS = 45,
    EI_KEY_PERIOD = 46,
    EI_KEY_SLASH = 47,
    EI_KEY_0 = 48,
    EI_KEY_1 = 49,
    EI_KEY_2 = 50,
    EI_KEY_3 = 51,
    EI_KEY_4 = 52,
    EI_KEY_5 = 53,
    EI_KEY_6 = 54,
    EI_KEY_7 = 55,
    EI_KEY_8 = 56,
    EI_KEY_9 = 57,
    EI_KEY_SEMICOLON = 59,
    EI_KEY_EQUAL = 61,
    EI_KEY_A = 65,
    EI_KEY_B = 66,
    EI_KEY_C = 67,
    EI_KEY_D = 68,
    EI_KEY_E = 69,
    EI_KEY_F = 70,
    EI_KEY_G = 71,
    EI_KEY_H = 72,
    EI_KEY_I = 73,
    EI_KEY_J = 74,
    EI_KEY_K = 75,
    EI_KEY_L = 76,
    EI_KEY_M = 77,
    EI_KEY_N = 78,
    EI_KEY_O = 79,
    EI_KEY_P = 80,
    EI_KEY_Q = 81,
    EI_KEY_R = 82,
    EI_KEY_S = 83,
    EI_KEY_T = 84,
    EI_KEY_U = 85,
    EI_KEY_V = 86,
    EI_KEY_W = 87,
    EI_KEY_X = 88,
    EI_KEY_Y = 89,
    EI_KEY_Z = 90,
    EI_KEY_LEFT_BRACKET = 91,
    EI_KEY_BACKSLASH = 92,
    EI_KEY_RIGHT_BRACKET = 93,
    EI_KEY_ESCAPE = 256,
} EI_Key;
#endif

DECLMETHOD(bool, EI_IsKeyDown, (EW_Window*, int))
DECLMETHOD(bool, EI_IsKeyUp, (EW_Window*, int))

#ifdef __cplusplus
}
#endif
#endif //ENIGMA_WINDOW_KEYBOARDINPUT_H
