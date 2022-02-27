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
    void(*framebufferResizeCallback)(EW_Window*, int, int);
    void(*updateCallback)(EW_Window*);
};

PRIVATE inline GLFWwindow *Glfw_CastWindow(EW_Window* wnd)
{
    return ((GlfwWindow*)(wnd->wndData))->glfwWindow;
}

// Exclusively for glfw
PUBLIC void Glfw_MakeContextCurrent(EW_Window*);

PRIVATE void Glfw_SetUserData(EW_Window*, void*);
PRIVATE void* Glfw_GetUserData(EW_Window*);
PRIVATE const char* Glfw_GetTitle(EW_Window*);
PRIVATE void Glfw_SetTitle(EW_Window*, const char*);
PRIVATE void Glfw_SetPosition(EW_Window*, int, int);
PRIVATE void Glfw_GetPosition(EW_Window*, int*, int*);
PRIVATE void Glfw_SetSize(EW_Window*, int, int);
PRIVATE void Glfw_GetSize(EW_Window*, int*, int*);
PRIVATE void Glfw_SetMaxSize(EW_Window*, int, int);
PRIVATE void Glfw_GetMaxSize(EW_Window*, int*, int*);
PRIVATE void Glfw_SetMinSize(EW_Window*, int, int);
PRIVATE void Glfw_GetMinSize(EW_Window*, int*, int*);
PRIVATE void Glfw_Close(EW_Window*);
PRIVATE void Glfw_Update(EW_Window*);
PRIVATE bool Glfw_ShouldClose(EW_Window*);
PRIVATE void Glfw_Show(EW_Window*);
PRIVATE void Glfw_Hide(EW_Window*);
PRIVATE void Glfw_SetFramebufferResizeCallback(EW_Window*, void(*)(EW_Window*, int, int));
PRIVATE void Glfw_SetUpdateCallback(EW_Window*, void(*)(EW_Window*));
PRIVATE void* Glfw_GetWin32(EW_Window*);
PRIVATE EW_WindowLibType Glfw_GetLibType(EW_Window*);

#endif //ENIGMA_WINDOW_GLFWWINDOW_H
