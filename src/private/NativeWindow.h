#ifndef ENIGMA_WINDOW_NATIVEWINDOW_H
#define ENIGMA_WINDOW_NATIVEWINDOW_H

#include "WindowModule.h"

#ifdef __cplusplus
extern "C"
{
#endif
typedef enum {
    EW_NativeWindow_Win32,
    EW_NativeWindow_X11,
    EW_NativeWindow_Wayland,
    EW_NativeWindow_Android,
    EW_NativeWindow_Cocoa
} EW_NativeWindowType;

typedef enum {
    EW_WindowLib_Native,
    EW_WindowLib_Sdl,
    EW_WindowLib_Glfw,
    EW_WindowLib_Unknown
} EW_WindowLibType;

DECLMETHOD(EW_WindowLibType, EW_GetLibType, (EW_Window*))
DECLMETHOD(EW_NativeWindowType, EW_GetNativeType, (EW_Window*))

/*
 * Returns pointer to hWnd
 */
DECLMETHOD(void*, EW_GetWin32, (EW_Window * ))

DECLMETHOD(void*, EW_GetX11, (EW_Window * ))
#ifdef __cplusplus
}
#endif

#endif //ENIGMA_WINDOW_NATIVEWINDOW_H
