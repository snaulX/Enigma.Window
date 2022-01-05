#ifndef ENIGMA_WINDOW_NATIVEWINDOW_H
#define ENIGMA_WINDOW_NATIVEWINDOW_H

#include "WindowModule.h"

#ifdef __cplusplus
extern "C"
{
#endif
typedef enum {
    NativeWindow_Win32,
    NativeWindow_X11,
    NativeWindow_Wayland,
    NativeWindow_Android,
    NativeWindow_Cocoa
} NativeWindowType;

typedef enum {
    WindowLib_Native,
    WindowLib_Sdl,
    WindowLib_Glfw,
    WindowLib_Unknown
} WindowLibType;

GETSET(Window, WindowLibType, LibType)

GETSET(Window, NativeWindowType, NativeType)

/*
 * Returns pointer to hWnd
 */
DECLMETHOD(void*, GetWin32, (Window * ))

DECLMETHOD(void*, GetX11, (Window * ))
#ifdef __cplusplus
}
#endif

#endif //ENIGMA_WINDOW_NATIVEWINDOW_H
