#ifndef ENIGMA_WINDOW_GLFWINPUT_H
#define ENIGMA_WINDOW_GLFWINPUT_H
#include "EnigmaInput.h"
#ifdef __cplusplus
extern "C"
{
#endif

PRIVATE bool Glfw_IsKeyDown(EW_Window*, int);
PRIVATE bool Glfw_IsKeyUp(EW_Window*, int);

PRIVATE void Glfw_SetKeyCallback(EW_Window*, void(*)(EW_Window*, int, bool));

#ifdef __cplusplus
}
#endif
#endif //ENIGMA_WINDOW_GLFWINPUT_H
