#ifndef ENIGMA_WINDOW_GLFWWINDOW_H
#define ENIGMA_WINDOW_GLFWWINDOW_H
#include "WindowModule.h"

STRUCT_EXTENDS(GlfwWindow, Window,
               const char* test;
)

PRIVATE const char* Glfw__GetTitle(Window*);
PRIVATE void Glfw__SetTitle(Window*, const char*);

#endif //ENIGMA_WINDOW_GLFWWINDOW_H
