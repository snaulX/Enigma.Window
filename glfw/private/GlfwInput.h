#ifndef ENIGMA_WINDOW_GLFWINPUT_H
#define ENIGMA_WINDOW_GLFWINPUT_H
#include "EnigmaInput.h"
#ifdef __cplusplus
extern "C"
{
#endif

bool Glfw_IsKeyDown(EW_Window*, int);
bool Glfw_IsKeyPress(EW_Window*, int);
bool Glfw_IsKeyUp(EW_Window*, int);

#ifdef __cplusplus
}
#endif
#endif //ENIGMA_WINDOW_GLFWINPUT_H
