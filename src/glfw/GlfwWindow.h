#ifndef ENIGMA_WINDOW_GLFWWINDOW_H
#define ENIGMA_WINDOW_GLFWWINDOW_H
#include "WindowModule.h"

STRUCT(GlfwWindow)
{
    const char* test;
};

PRIVATE GlfwWindow *_Glfw__CastWindow(Window*);
PRIVATE const char* Glfw__GetTitle(Window*);
PRIVATE void Glfw__SetTitle(Window*, const char*);

#endif //ENIGMA_WINDOW_GLFWWINDOW_H
