#include "GlfwWindow.h"

PRIVATE void Glfw_SetUserData(Window* wnd, void* userData)
{
    glfwSetWindowUserPointer(Glfw_CastWindow(wnd), userData);
    //Base_SetUserData(wnd, userData);
}
PRIVATE void* Glfw_GetUserData(Window* wnd)
{
    //return Base_GetUserData(wnd);
    return glfwGetWindowUserPointer(Glfw_CastWindow(wnd));
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

PRIVATE void Glfw_SetSize(Window* wnd, int w, int h)
{
    glfwSetWindowSize(Glfw_CastWindow(wnd), w, h);
}
PRIVATE void Glfw_GetSize(Window* wnd, int* w, int* h)
{
    glfwGetWindowSize(Glfw_CastWindow(wnd), w, h);
}

PRIVATE void Glfw_SetMaxSize(Window* wnd, int w, int h)
{
    GlfwWindow *gwnd = wnd->wndData;
    gwnd->maxWidth = w;
    gwnd->maxHeight = h;
    glfwSetWindowSizeLimits(gwnd->glfwWindow, gwnd->minWidth, gwnd->minHeight, w, h);
}
PRIVATE void Glfw_GetMaxSize(Window* wnd, int* w, int* h)
{
    GlfwWindow *gwnd = wnd->wndData;
    *w = gwnd->maxWidth;
    *h = gwnd->maxHeight;
}

PRIVATE void Glfw_SetMinSize(Window* wnd, int w, int h)
{
    GlfwWindow *gwnd = wnd->wndData;
    gwnd->minWidth = w;
    gwnd->minHeight = h;
    glfwSetWindowSizeLimits(gwnd->glfwWindow, w, h, gwnd->maxWidth, gwnd->maxHeight);
}
PRIVATE void Glfw_GetMinSize(Window* wnd, int* w, int* h)
{
    GlfwWindow *gwnd = wnd->wndData;
    *w = gwnd->minWidth;
    *h = gwnd->minHeight;
}

PRIVATE void Glfw_Close(Window* wnd)
{
    glfwSetWindowShouldClose(Glfw_CastWindow(wnd), GLFW_TRUE);
}
PRIVATE void Glfw_Update(Window* wnd)
{
    glfwPollEvents();
}
PRIVATE bool Glfw_ShouldClose(Window* wnd)
{
    return glfwWindowShouldClose(Glfw_CastWindow(wnd));
}
PRIVATE void Glfw_Show(Window* wnd)
{
    //CreateSwapchain();

    glfwShowWindow(Glfw_CastWindow(wnd));
}
PRIVATE void Glfw_Hide(Window* wnd)
{
    glfwHideWindow(Glfw_CastWindow(wnd));
}

PRIVATE void Native_FramebufferResizeCallback(GLFWwindow* glfwWindow, int w, int h)
{
    Window* wnd = glfwGetWindowUserPointer(glfwWindow);
    ((GlfwWindow*)wnd->wndData)->framebufferResizeCallback(wnd, w, h);
}
PRIVATE void Glfw_SetFramebufferResizeCallback(Window* wnd, void(*callback)(Window*, int, int))
{
    ((GlfwWindow*)wnd->wndData)->framebufferResizeCallback = callback;
    glfwSetFramebufferSizeCallback(Glfw_CastWindow(wnd), Native_FramebufferResizeCallback);
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