#include "GlfwWindow.h"

PRIVATE const char* Glfw__GetTitle(Window* wnd)
{
    return GetGlfwWindowFromWindow(wnd).test;
}

PRIVATE void Glfw__SetTitle(Window* wnd, const char* title)
{
    GlfwWindow glfwWindow = GetGlfwWindowFromWindow(wnd);
    glfwWindow.test = title;
    wnd = GetWindowFromGlfwWindow(glfwWindow);
}