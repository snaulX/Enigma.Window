#include "GlfwWindow.h"

PRIVATE void Glfw_SetUserData(Window* wnd, void* userData)
{
    glfwSetWindowUserPointer(Glfw_CastWindow(wnd), userData);
    Base_SetUserData(wnd, userData);
}
PRIVATE void* Glfw_GetUserData(Window* wnd)
{
    return Base_GetUserData(wnd);
    //return glfwGetWindowUserPointer(Glfw_CastWindow(wnd));
}
PRIVATE const char* Glfw_GetTitle(Window* wnd)
{
    return ((GlfwWindow*)(wnd->wndData))->title;
}
PRIVATE void Glfw_SetTitle(Window* wnd, const char* title)
{
    GlfwWindow *gwnd = (GlfwWindow*)(wnd->wndData);
    gwnd->title = title;
    glfwSetWindowTitle(gwnd->glfwWindow, title);
}

PRIVATE void Glfw_SetPosition(Window* wnd, int x, int y)
{
    glfwSetWindowPos(Glfw_CastWindow(wnd), x, y);
}
PRIVATE void Glfw_GetPosition(Window* wnd, int* x, int* y)
{
    glfwGetWindowPos(Glfw_CastWindow(wnd), x, y);
}

PRIVATE void Glfw_Update(Window* wnd)
{
    glfwPollEvents();
}

PRIVATE void Glfw_Show(Window* wnd)
{
    //CreateSwapchain();

    glfwShowWindow(Glfw_CastWindow(wnd));
}

PRIVATE void* Glfw_GetWin32(Window* wnd)
{
#ifdef GLFW_EXPOSE_NATIVE_WIN32
    return glfwGetWin32Window(Glfw_CastWindow(wnd));
#else
    EW_Error("You cannot get hWnd not on Win32 platform");
    return NULL;
#endif
}