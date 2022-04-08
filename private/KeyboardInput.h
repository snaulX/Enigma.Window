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
// This fact also gives full compatibility with glfw keys: GLFW_KEY_*

typedef enum {
    EI_KEY_UNKNOWN = -1,
    EI_KEY_SPACE = 32,
    EI_KEY_APOSTROPHE = 39, /* ` */
    EI_KEY_COMMA = 44, /* , */
    EI_KEY_MINUS = 45, /* - */
    EI_KEY_PERIOD = 46, /* . */
    EI_KEY_SLASH = 47, /* / */
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
    EI_KEY_SEMICOLON = 59, /* ; */
    EI_KEY_EQUAL = 61, /* = */
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
    EI_KEY_LEFT_BRACKET = 91, /* [ */
    EI_KEY_BACKSLASH = 92, /* \ */
    EI_KEY_RIGHT_BRACKET = 93, /* ] */
    EI_KEY_GRAVE_ACCENT = 96, /* ` */
    EI_KEY_WORLD_1 = 161, /* non-US #1 */
    EI_KEY_WORLD_2 = 162, /* non-US #2 */
    EI_KEY_ESCAPE = 256,
    EI_KEY_ENTER = 257,
    EI_KEY_TAB = 258,
    EI_KEY_BACKSPACE = 259,
    EI_KEY_INSERT = 260,
    EI_KEY_DELETE = 261,
    EI_KEY_RIGHT = 262,
    EI_KEY_LEFT = 263,
    EI_KEY_DOWN = 264,
    EI_KEY_UP = 265,
    EI_KEY_PAGE_UP = 266,
    EI_KEY_PAGE_DOWN = 267,
    EI_KEY_HOME = 268,
    EI_KEY_END = 269,
    EI_KEY_CAPS_LOCK = 280,
    EI_KEY_SCROLL_LOCK = 281,
    EI_KEY_NUM_LOCK = 282,
    EI_KEY_PRINT_SCREEN = 283,
    EI_KEY_PAUSE = 284,
    EI_KEY_F1 = 290,
    EI_KEY_F2 = 291,
    EI_KEY_F3 = 292,
    EI_KEY_F4 = 293,
    EI_KEY_F5 = 294,
    EI_KEY_F6 = 295,
    EI_KEY_F7 = 296,
    EI_KEY_F8 = 297,
    EI_KEY_F9 = 298,
    EI_KEY_F10 = 299,
    EI_KEY_F11 = 300,
    EI_KEY_F12 = 301,
    EI_KEY_F13 = 302,
    EI_KEY_F14 = 303,
    EI_KEY_F15 = 304,
    EI_KEY_F16 = 305,
    EI_KEY_F17 = 306,
    EI_KEY_F18 = 307,
    EI_KEY_F19 = 308,
    EI_KEY_F20 = 309,
    EI_KEY_F21 = 310,
    EI_KEY_F22 = 311,
    EI_KEY_F23 = 312,
    EI_KEY_F24 = 313,
    EI_KEY_F25 = 314,
    EI_KEY_KP_0 = 320,
    EI_KEY_KP_1 = 321,
    EI_KEY_KP_2 = 322,
    EI_KEY_KP_3 = 323,
    EI_KEY_KP_4 = 324,
    EI_KEY_KP_5 = 325,
    EI_KEY_KP_6 = 326,
    EI_KEY_KP_7 = 327,
    EI_KEY_KP_8 = 328,
    EI_KEY_KP_9 = 329,
    EI_KEY_KP_DECIMAL = 330,
    EI_KEY_KP_DIVIDE = 331,
    EI_KEY_KP_MULTIPLY = 332,
    EI_KEY_KP_SUBTRACT = 333,
    EI_KEY_KP_ADD = 334,
    EI_KEY_KP_ENTER = 335,
    EI_KEY_KP_EQUAL = 336,
    EI_KEY_LEFT_SHIFT = 340,
    EI_KEY_LEFT_CONTROL = 341,
    EI_KEY_LEFT_ALT = 342,
    EI_KEY_LEFT_SUPER = 343,
    EI_KEY_RIGHT_SHIFT = 344,
    EI_KEY_RIGHT_CONTROL = 345,
    EI_KEY_RIGHT_ALT = 346,
    EI_KEY_RIGHT_SUPER = 347,
    EI_KEY_MENU = 348,
} EI_Key;
#endif // not EI_CUSTOM_KEYS

DECLMETHOD(bool, EI_IsKeyDown, (EW_Window*, int))
DECLMETHOD(bool, EI_IsKeyUp, (EW_Window*, int))

DECLMETHOD(void, EI_SetKeyCallback, (EW_Window*, void(*)(EW_Window*, int, bool)))

#ifdef __cplusplus
}
#endif
#endif //ENIGMA_WINDOW_KEYBOARDINPUT_H
