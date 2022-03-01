#include "GlfwInterop.h"
#include "GlfwWindow.h"

PUBLIC void Glfw_MakeContextCurrent(EW_Window* wnd)
{
    glfwMakeContextCurrent(Glfw_CastWindow(wnd));
}

PRIVATE void Glfw_SetUserData(EW_Window* wnd, void* userData)
{
    glfwSetWindowUserPointer(Glfw_CastWindow(wnd), userData);
    //Base_SetUserData(wnd, userData);
}
PRIVATE void* Glfw_GetUserData(EW_Window* wnd)
{
    //return Base_GetUserData(wnd);
    return glfwGetWindowUserPointer(Glfw_CastWindow(wnd));
}
PRIVATE const char* Glfw_GetTitle(EW_Window* wnd)
{
    return ((GlfwWindow*)(wnd->wndData))->title;
}
PRIVATE void Glfw_SetTitle(EW_Window* wnd, const char* title)
{
    GlfwWindow *gwnd = (GlfwWindow*)(wnd->wndData);
    gwnd->title = title;
    glfwSetWindowTitle(gwnd->glfwWindow, title);
}

PRIVATE void Glfw_SetPosition(EW_Window* wnd, int x, int y)
{
    glfwSetWindowPos(Glfw_CastWindow(wnd), x, y);
}
PRIVATE void Glfw_GetPosition(EW_Window* wnd, int* x, int* y)
{
    glfwGetWindowPos(Glfw_CastWindow(wnd), x, y);
}

PRIVATE void Glfw_SetSize(EW_Window* wnd, int w, int h)
{
    glfwSetWindowSize(Glfw_CastWindow(wnd), w, h);
}
PRIVATE void Glfw_GetSize(EW_Window* wnd, int* w, int* h)
{
    glfwGetWindowSize(Glfw_CastWindow(wnd), w, h);
}

PRIVATE void Glfw_SetMaxSize(EW_Window* wnd, int w, int h)
{
    GlfwWindow *gwnd = wnd->wndData;
    gwnd->maxWidth = w;
    gwnd->maxHeight = h;
    glfwSetWindowSizeLimits(gwnd->glfwWindow, gwnd->minWidth, gwnd->minHeight, w, h);
}
PRIVATE void Glfw_GetMaxSize(EW_Window* wnd, int* w, int* h)
{
    GlfwWindow *gwnd = wnd->wndData;
    *w = gwnd->maxWidth;
    *h = gwnd->maxHeight;
}

PRIVATE void Glfw_SetMinSize(EW_Window* wnd, int w, int h)
{
    GlfwWindow *gwnd = wnd->wndData;
    gwnd->minWidth = w;
    gwnd->minHeight = h;
    glfwSetWindowSizeLimits(gwnd->glfwWindow, w, h, gwnd->maxWidth, gwnd->maxHeight);
}
PRIVATE void Glfw_GetMinSize(EW_Window* wnd, int* w, int* h)
{
    GlfwWindow *gwnd = wnd->wndData;
    *w = gwnd->minWidth;
    *h = gwnd->minHeight;
}

PRIVATE void Glfw_Close(EW_Window* wnd)
{
    glfwSetWindowShouldClose(Glfw_CastWindow(wnd), GLFW_TRUE);
}
PRIVATE void Glfw_Update(EW_Window* wnd)
{
    glfwPollEvents();
	void(*updateFunc)(EW_Window*) = ((GlfwWindow*)wnd->wndData)->updateCallback;
    if (updateFunc)
		updateFunc(wnd);
}
PRIVATE bool Glfw_ShouldClose(EW_Window* wnd)
{
    return glfwWindowShouldClose(Glfw_CastWindow(wnd));
}
PRIVATE void Glfw_Show(EW_Window* wnd)
{
    //CreateSwapchain();

    glfwShowWindow(Glfw_CastWindow(wnd));
}
PRIVATE void Glfw_Hide(EW_Window* wnd)
{
    glfwHideWindow(Glfw_CastWindow(wnd));
}

PRIVATE void Native_FramebufferResizeCallback(GLFWwindow* glfwWindow, int w, int h)
{
    EW_Window* wnd = glfwGetWindowUserPointer(glfwWindow);
    void(*callback)(EW_Window*, int, int) = ((GlfwWindow*)wnd->wndData)->framebufferResizeCallback;
	if (callback)
		callback(wnd, w, h);
}
PRIVATE void Glfw_SetFramebufferResizeCallback(EW_Window* wnd, void(*callback)(EW_Window*, int, int))
{
    ((GlfwWindow*)wnd->wndData)->framebufferResizeCallback = callback;
    glfwSetFramebufferSizeCallback(Glfw_CastWindow(wnd), Native_FramebufferResizeCallback);
}

PRIVATE void Glfw_SetUpdateCallback(EW_Window* wnd, void(*callback)(EW_Window*))
{
    ((GlfwWindow*)wnd->wndData)->updateCallback = callback;
}

PRIVATE void* Glfw_GetWin32(EW_Window* wnd)
{
#ifdef GLFW_EXPOSE_NATIVE_WIN32
    return glfwGetWin32Window(Glfw_CastWindow(wnd));
#else
    EW_Error("You cannot get hWnd not on Win32 platform");
    return nullptr;
#endif
}

PRIVATE EW_WindowLibType Glfw_GetLibType(EW_Window* wnd)
{
    if (Glfw_CastWindow(wnd))
        return EW_WindowLib_Glfw;
    else
        return EW_WindowLib_Unknown;
}
