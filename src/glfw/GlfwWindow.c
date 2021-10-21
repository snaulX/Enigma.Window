#include "GlfwWindow.h"

PRIVATE GlfwWindow *_Glfw__CastWindow(Window* wnd)
{
    return (GlfwWindow*)(wnd->data);
}

PRIVATE const char* Glfw__GetTitle(Window* wnd)
{
    return _Glfw__CastWindow(wnd)->test;
}

PRIVATE void Glfw__SetTitle(Window* wnd, const char* title)
{
    _Glfw__CastWindow(wnd)->test = title;
}