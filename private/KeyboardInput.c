#include "KeyboardInput.h"

SETMETHOD(bool, EI_IsKeyDown, (EW_Window* wnd, int keycode), wnd, keycode)
SETMETHOD(bool, EI_IsKeyUp, (EW_Window* wnd, int keycode), wnd, keycode)

SETMETHOD(void, EI_SetKeyCallback, (EW_Window* wnd, void(*callback)(EW_Window*, int, bool)), wnd, callback)