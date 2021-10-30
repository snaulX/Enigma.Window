#include "WindowModule.h"

SETMETHOD(void, SetTitle, (Window* wnd, const char* title), wnd, title)
SETMETHOD(const char*, GetTitle, (Window* wnd), wnd)
SETMETHOD(void, SetPosition, (Window* wnd, int x, int y), wnd, x, y)
SETMETHOD(void, GetPosition, (Window* wnd, int* x, int* y), wnd, x, y)
SETMETHOD(void, SetSize, (Window* wnd, int w, int h), wnd, w, h)
SETMETHOD(void, GetSize, (Window* wnd, int* w, int* h), wnd, w, h)

SETMETHOD(void, Run, (Window* wnd), wnd)
SETMETHOD(void, Update, (Window* wnd), wnd)
SETMETHOD(bool, ShouldClose, (Window* wnd), wnd)

SETMETHOD(Window*, CreateWindow, ())