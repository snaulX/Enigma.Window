#include "KeyboardInput.h"

SETMETHOD(bool, EI_IsKeyDown, (EW_Window* wnd, int keycode), wnd, keycode)
SETMETHOD(bool, EI_IsKeyPress, (EW_Window* wnd, int keycode), wnd, keycode)
SETMETHOD(bool, EI_IsKeyUp, (EW_Window* wnd, int keycode), wnd, keycode)