#ifndef ENIGMA_WINDOW_GLFWMODULE_H
#define ENIGMA_WINDOW_GLFWMODULE_H
#include <stdlib.h>
#include <stdio.h>
#include "EnigmaWindow.h"
#ifdef __cplusplus
extern "C"
{
#endif

PUBLIC void Glfw_InitFunctions();

// Exclusively for Enigma.Glfw
PUBLIC void Glfw_MakeContextCurrent(EW_Window*);

#ifdef __cplusplus
}
#endif
#endif //ENIGMA_WINDOW_GLFWMODULE_H
