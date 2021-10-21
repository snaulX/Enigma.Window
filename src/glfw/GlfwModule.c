#include "GlfwModule.h"

PRIVATE Window* Glfw__CreateWindow()
{
    GlfwWindow *glfwWindow = malloc(sizeof(GlfwWindow));
    glfwWindow->test = "";
    Window *wnd = malloc(sizeof(Window));
    wnd->data = glfwWindow;
    return wnd;
}

PUBLIC void Glfw__InitFunctions()
{
    Set_CreateWindow(Glfw__CreateWindow);
    Set_GetTitle(Glfw__GetTitle);
    Set_SetTitle(Glfw__SetTitle);
}