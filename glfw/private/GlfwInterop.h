#ifndef ENIGMA_WINDOW_GLFWINTEROP_H
#define ENIGMA_WINDOW_GLFWINTEROP_H

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

#endif // ENIGMA_WINDOW_GLFWINTEROP_H
