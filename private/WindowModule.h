#ifndef WINDOW_MODULE_ENIGMA_WINDOW_H
#define WINDOW_MODULE_ENIGMA_WINDOW_H
#include "base.h"

#ifdef __cplusplus
extern "C"
{
#endif
typedef enum {
    EW_WindowState_None = 0,
    EW_WindowState_Fullscreen = 1 << 0,
    EW_WindowState_FullscreenDesktop = 1 << 1,
    EW_WindowState_Borderless = 1 << 2,
    EW_WindowState_Resizable = 1 << 3,
    EW_WindowState_Maximized = 1 << 4,
} EW_WindowFlags;

STRUCT(EW_Window) {
    void* wndData;
    void* userData;
};

DECLMETHOD(void, EW_SetTitle, (EW_Window *, const char*))
DECLMETHOD(const char*, EW_GetTitle, (EW_Window *))
//GETSET(EW_Window, const char*, Title)
DECLMETHOD(void, EW_SetUserData, (EW_Window *, void*))
DECLMETHOD(void*, EW_GetUserData, (EW_Window *))
//GETSET(EW_Window, void*, UserData)

DECLMETHOD(void, EW_SetPosition, (EW_Window *, int, int))
DECLMETHOD(void, EW_GetPosition, (EW_Window *, int*, int*))
DECLMETHOD(void, EW_SetSize, (EW_Window *, int, int))
DECLMETHOD(void, EW_GetSize, (EW_Window *, int*, int*))
DECLMETHOD(void, EW_SetMaxSize, (EW_Window *, int, int))
DECLMETHOD(void, EW_GetMaxSize, (EW_Window *, int*, int*))
DECLMETHOD(void, EW_SetMinSize, (EW_Window *, int, int))
DECLMETHOD(void, EW_GetMinSize, (EW_Window *, int*, int*))

DECLMETHOD(void, EW_Show, (EW_Window *))
DECLMETHOD(void, EW_Close, (EW_Window *))
DECLMETHOD(void, EW_Hide, (EW_Window *))
DECLMETHOD(void, EW_Destroy, (EW_Window *))
DECLMETHOD(void, EW_Run, (EW_Window *))
DECLMETHOD(void, EW_Update, (EW_Window *))
DECLMETHOD(bool, EW_ShouldClose, (EW_Window *))

DECLMETHOD(void, EW_SetFramebufferResizeCallback, (EW_Window *, void(*)(EW_Window *, int, int)))
DECLMETHOD(void, EW_SetUpdateCallback, (EW_Window *, void(*)(EW_Window *)))

DECLMETHOD(void, EW_SetOpenGL, (int, int))

DECLMETHOD(EW_Window*, EW_CreateWindow, (const char* title, int x, int y, int w, int h, EW_WindowFlags flags))

PUBLIC inline void Base_Run(EW_Window *wnd) {
    while (!EW_ShouldClose(wnd)) {
        EW_Update(wnd);
    }
}
PUBLIC inline void Base_SetUserData(EW_Window* wnd, void* userData) {
    wnd->userData = userData;
}
PUBLIC inline void* Base_GetUserData(EW_Window* wnd) {
    return wnd->userData;
}

#ifdef __cplusplus
}
#endif

#endif //WINDOW_MODULE_ENIGMA_WINDOW_H
