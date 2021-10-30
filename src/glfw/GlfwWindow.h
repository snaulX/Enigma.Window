#ifndef ENIGMA_WINDOW_GLFWWINDOW_H
#define ENIGMA_WINDOW_GLFWWINDOW_H
#include "WindowModule.h"
#include "GLFW/glfw3.h"

STRUCT(GlfwWindow)
{
    GLFWwindow *glfwWindow;
    const char* title;
};

PRIVATE GLFWwindow *_Glfw_CastWindow(Window*);
PRIVATE const char* Glfw_GetTitle(Window*);
PRIVATE void Glfw_SetTitle(Window*, const char*);
PRIVATE void Glfw_SetPosition(Window*, int, int);
PRIVATE void Glfw_GetPosition(Window*, int*, int*);
PRIVATE void Glfw_Update(Window*);

#endif //ENIGMA_WINDOW_GLFWWINDOW_H
