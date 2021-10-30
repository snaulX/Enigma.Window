#include "GlfwWindow.h"

PRIVATE GLFWwindow *_Glfw_CastWindow(Window* wnd)
{
    return ((GlfwWindow*)(wnd->data))->glfwWindow;
}

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
    glfwSetWindowPos(_Glfw_CastWindow(wnd), x, y);
}
PRIVATE void Glfw_GetPosition(Window* wnd, int* x, int* y)
{
    glfwGetWindowPos(_Glfw_CastWindow(wnd), x, y);
}

PRIVATE void Glfw_Update(Window* wnd)
{
    glfwPollEvents();
}