#ifndef ENIGMA_WINDOW_GLFWWINDOW_H
#define ENIGMA_WINDOW_GLFWWINDOW_H

#ifdef WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#endif

#include "EnigmaWindow.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

STRUCT(GlfwWindow)
{
    GLFWwindow *glfwWindow;
    const char* title;
};

PRIVATE inline GLFWwindow *Glfw_CastWindow(Window* wnd)
{
    return ((GlfwWindow*)(wnd->wndData))->glfwWindow;
}

PRIVATE void Glfw_SetUserData(Window*, void*);
PRIVATE void* Glfw_GetUserData(Window*);
PRIVATE const char* Glfw_GetTitle(Window*);
PRIVATE void Glfw_SetTitle(Window*, const char*);
PRIVATE void Glfw_SetPosition(Window*, int, int);
PRIVATE void Glfw_GetPosition(Window*, int*, int*);
PRIVATE void Glfw_Update(Window*);
PRIVATE void Glfw_Show(Window*);
PRIVATE void* Glfw_GetWin32(Window*);

#endif //ENIGMA_WINDOW_GLFWWINDOW_H
