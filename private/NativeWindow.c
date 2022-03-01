#include "NativeWindow.h"

SETMETHOD(EW_NativeWindowType, EW_GetNativeType, (EW_Window* wnd), wnd)
SETMETHOD(EW_WindowLibType, EW_GetLibType, (EW_Window* wnd), wnd)

SETMETHOD(void*, EW_GetWin32, (EW_Window* wnd), wnd)
