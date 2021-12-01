#ifndef WINDOW_MODULE_ENIGMA_WINDOW_H
#define WINDOW_MODULE_ENIGMA_WINDOW_H
#include "base.h"

typedef enum {
    WindowState_None = 0,
    WindowState_Fullscreen = 1 << 0,
    WindowState_FullscreenDesktop = 1 << 1,
    WindowState_Borderless = 1 << 2,
    WindowState_Resizable = 1 << 3,
    WindowState_Maximized = 1 << 4,
} WindowFlags;


STRUCT(Window)
{
    void* data;
};

//DECLMETHOD(void, SetTitle, (Window*, const char*))
//DECLMETHOD(const char*, GetTitle, (Window*))
GETSET(Window, const char*, Title)
DECLMETHOD(void, SetPosition, (Window*, int, int))
DECLMETHOD(void, GetPosition, (Window*, int*, int*))
DECLMETHOD(void, SetSize, (Window*, int, int))
DECLMETHOD(void, GetSize, (Window*, int*, int*))

DECLMETHOD(void, Show, ())
DECLMETHOD(void, Close, ())
DECLMETHOD(void, Hide, ())
DECLMETHOD(void, Destroy, ())

DECLMETHOD(void, Run, (Window*))
DECLMETHOD(void, Update, (Window*))
DECLMETHOD(bool, ShouldClose, (Window*))

DECLMETHOD(Window*, CreateWindow, (const char* title, int x, int y, int w, int h, WindowFlags flags))

PUBLIC inline void Base_Run(Window* wnd)
{
    while (!ShouldClose(wnd))
    {
        Update(wnd);
    }
}

#endif //WINDOW_MODULE_ENIGMA_WINDOW_H
