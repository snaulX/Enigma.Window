#ifndef ENIGMA_WINDOW_GLFWMODULE_H
#define ENIGMA_WINDOW_GLFWMODULE_H
#define ENIGMA_GLFW
#include "WindowModule.h"
#include "GlfwWindow.h"

GlfwWindow *CreateGlfwWindow(WindowModule* module);
Window* GetWindowFromGlfw(WindowModule* module);

#endif //ENIGMA_WINDOW_GLFWMODULE_H
