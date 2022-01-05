#include "NativeWindow.h"

SETMETHOD(void, SetNativeType, (Window* wnd, NativeWindowType nt), wnd, nt)
SETMETHOD(NativeWindowType, GetNativeType, (Window* wnd), wnd)
SETMETHOD(void, SetLibType, (Window* wnd, WindowLibType lt), wnd, lt)
SETMETHOD(WindowLibType, GetLibType, (Window* wnd), wnd)

SETMETHOD(void*, GetWin32, (Window* wnd), wnd)
