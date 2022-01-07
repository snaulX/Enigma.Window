#include "WindowModule.h"

SETMETHOD(void, SetTitle, (Window* wnd, const char* title), wnd, title)
SETMETHOD(const char*, GetTitle, (Window* wnd), wnd)
SETMETHOD(void, SetUserData, (Window* wnd, void* userData), wnd, userData)
SETMETHOD(void*, GetUserData, (Window* wnd), wnd)
SETMETHOD(void, SetPosition, (Window* wnd, int x, int y), wnd, x, y)
SETMETHOD(void, GetPosition, (Window* wnd, int* x, int* y), wnd, x, y)
SETMETHOD(void, SetSize, (Window* wnd, int w, int h), wnd, w, h)
SETMETHOD(void, GetSize, (Window* wnd, int* w, int* h), wnd, w, h)
SETMETHOD(void, SetMaxSize, (Window* wnd, int w, int h), wnd, w, h)
SETMETHOD(void, GetMaxSize, (Window* wnd, int* w, int* h), wnd, w, h)
SETMETHOD(void, SetMinSize, (Window* wnd, int w, int h), wnd, w, h)
SETMETHOD(void, GetMinSize, (Window* wnd, int* w, int* h), wnd, w, h)

SETMETHOD(void, Show, ())
SETMETHOD(void, Close, ())
SETMETHOD(void, Hide, ())
SETMETHOD(void, Destroy, ())

SETMETHOD(void, Run, (Window* wnd), wnd)
SETMETHOD(void, Update, (Window* wnd), wnd)
SETMETHOD(bool, ShouldClose, (Window* wnd), wnd)

SETMETHOD(void, SetFramebufferResizeCallback, (Window* wnd, void(*callback)(Window*, int, int)), wnd, callback)
SETMETHOD(void, SetUpdateCallback, (Window* wnd, void(*callback)(Window*)), wnd, callback)

SETMETHOD(void, SetOpenGL, (int majorVersion, int minorVersion), majorVersion, minorVersion)

SETMETHOD(Window*, CreateWindow, (const char* title, int x, int y, int w, int h, WindowFlags flags), title, x, y, w, h, flags)
