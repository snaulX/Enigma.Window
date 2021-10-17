#include "GlfwModule.h"

Window* Glfw__CreateWindow()
{
    GlfwWindow glfwWindow;
    glfwWindow.test = "snaulX";
    return GetWindowFromGlfwWindow(glfwWindow);
}

PUBLIC void Glfw__InitFunctions()
{
    Set_CreateWindow(Glfw__CreateWindow);
    Set_GetTitle(Glfw__GetTitle);
    Set_SetTitle(Glfw__SetTitle);
}