#ifndef ENIGMA_WINDOW_GLFWWINDOW_H
#define ENIGMA_WINDOW_GLFWWINDOW_H
#include "EnigmaWindow.h"

#ifdef __cplusplus
extern "C"
{
#endif
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
#ifdef __cplusplus
}
#endif

#endif //ENIGMA_WINDOW_GLFWWINDOW_H
