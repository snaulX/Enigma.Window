#include "GlfwWindow.h"

PRIVATE const char* Glfw_GetTitle(Window* wnd)
{
    return ((GlfwWindow*)(wnd->data))->title;
}
PRIVATE void Glfw_SetTitle(Window* wnd, const char* title)
{
    GlfwWindow *gwnd = (GlfwWindow*)(wnd->data);
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