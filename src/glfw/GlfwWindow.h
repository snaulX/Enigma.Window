#ifndef ENIGMA_WINDOW_GLFWWINDOW_H
#define ENIGMA_WINDOW_GLFWWINDOW_H
#include "WindowModule.h"

STRUCT_EXTENDS(GlfwWindow, Window,
    METHOD(void, Init)(GlfwWindow*);
)

#endif //ENIGMA_WINDOW_GLFWWINDOW_H
