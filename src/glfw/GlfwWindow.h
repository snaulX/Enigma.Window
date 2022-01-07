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
    int maxWidth, maxHeight, minWidth, minHeight;
    void(*framebufferResizeCallback)(Window*, int, int);
    void(*updateCallback)(Window*);
};

PRIVATE inline GLFWwindow *Glfw_CastWindow(Window* wnd)
{
    return ((GlfwWindow*)(wnd->wndData))->glfwWindow;
}

// Exclusively for glfw
PUBLIC void Glfw_MakeContextCurrent(Window*);

PRIVATE void Glfw_SetUserData(Window*, void*);
PRIVATE void* Glfw_GetUserData(Window*);
PRIVATE const char* Glfw_GetTitle(Window*);
PRIVATE void Glfw_SetTitle(Window*, const char*);
PRIVATE void Glfw_SetPosition(Window*, int, int);
PRIVATE void Glfw_GetPosition(Window*, int*, int*);
PRIVATE void Glfw_SetSize(Window*, int, int);
PRIVATE void Glfw_GetSize(Window*, int*, int*);
PRIVATE void Glfw_SetMaxSize(Window*, int, int);
PRIVATE void Glfw_GetMaxSize(Window*, int*, int*);
PRIVATE void Glfw_SetMinSize(Window*, int, int);
PRIVATE void Glfw_GetMinSize(Window*, int*, int*);
PRIVATE void Glfw_Close(Window*);
PRIVATE void Glfw_Update(Window*);
PRIVATE bool Glfw_ShouldClose(Window*);
PRIVATE void Glfw_Show(Window*);
PRIVATE void Glfw_Hide(Window*);
PRIVATE void Glfw_SetFramebufferResizeCallback(Window*, void(*)(Window*, int, int));
PRIVATE void Glfw_SetUpdateCallback(Window*, void(*)(Window*));
PRIVATE void* Glfw_GetWin32(Window*);

#endif //ENIGMA_WINDOW_GLFWWINDOW_H
