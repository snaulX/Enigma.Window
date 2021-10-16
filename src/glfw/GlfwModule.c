#include <stdio.h>
#include "GlfwModule.h"

GlfwWindow *CreateGlfwWindow(WindowModule* module)
{
    GlfwWindow glfwWindow;
    return &glfwWindow;
}

const char* PrintSmth(Window* wnd)
{
    printf("snaulX");
}

Window* GetWindowFromGlfw(WindowModule* module)
{
    Window window;
    window.GetTitle = PrintSmth;
    return &window;
    //return GetWindowFromGlfwWindow(*CreateGlfwWindow(module));
}

WindowModule *InitEnigmaWindow()
{
    WindowModule glfwModule;
    glfwModule.CreateWindow = GetWindowFromGlfw;
    return &glfwModule;
}