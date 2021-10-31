#include <stdio.h>
#include "WindowModule.h"
#include "glfw/GlfwModule.h"

int main()
{
#ifdef ENIGMA_GLFW
    Glfw_InitFunctions();
#endif // ENIGMA_GLFW
    Window *wnd = CreateWindow("snaulX window", 100, 100, 800, 600, WindowState_None);
    printf("%s\n", GetTitle(wnd));
    Run(wnd);
}
