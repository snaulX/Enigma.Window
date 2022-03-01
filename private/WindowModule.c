#include "WindowModule.h"

SETMETHOD(void, EW_SetTitle, (EW_Window * wnd, const char* title), wnd, title)
SETMETHOD(const char*, EW_GetTitle, (EW_Window * wnd), wnd)
SETMETHOD(void, EW_SetUserData, (EW_Window * wnd, void* userData), wnd, userData)
SETMETHOD(void*, EW_GetUserData, (EW_Window * wnd), wnd)
SETMETHOD(void, EW_SetPosition, (EW_Window * wnd, int x, int y), wnd, x, y)
SETMETHOD(void, EW_GetPosition, (EW_Window * wnd, int* x, int* y), wnd, x, y)
SETMETHOD(void, EW_SetSize, (EW_Window * wnd, int w, int h), wnd, w, h)
SETMETHOD(void, EW_GetSize, (EW_Window * wnd, int* w, int* h), wnd, w, h)
SETMETHOD(void, EW_SetMaxSize, (EW_Window * wnd, int w, int h), wnd, w, h)
SETMETHOD(void, EW_GetMaxSize, (EW_Window * wnd, int* w, int* h), wnd, w, h)
SETMETHOD(void, EW_SetMinSize, (EW_Window * wnd, int w, int h), wnd, w, h)
SETMETHOD(void, EW_GetMinSize, (EW_Window * wnd, int* w, int* h), wnd, w, h)

SETMETHOD(void, EW_Show, (EW_Window * wnd), wnd)
SETMETHOD(void, EW_Close, (EW_Window * wnd), wnd)
SETMETHOD(void, EW_Hide, (EW_Window * wnd), wnd)
SETMETHOD(void, EW_Destroy, (EW_Window * wnd), wnd)

SETMETHOD(void, EW_Run, (EW_Window * wnd), wnd)
SETMETHOD(void, EW_Update, (EW_Window * wnd), wnd)
SETMETHOD(bool, EW_ShouldClose, (EW_Window * wnd), wnd)

SETMETHOD(void, EW_SetFramebufferResizeCallback, (EW_Window * wnd, void(*callback)(EW_Window*, int, int)), wnd, callback)
SETMETHOD(void, EW_SetUpdateCallback, (EW_Window * wnd, void(*callback)(EW_Window*)), wnd, callback)

SETMETHOD(void, EW_SetOpenGL, (int majorVersion, int minorVersion), majorVersion, minorVersion)

SETMETHOD(EW_Window*, EW_CreateWindow, (const char* title, int x, int y, int w, int h, EW_WindowFlags flags), title, x, y, w, h, flags)
