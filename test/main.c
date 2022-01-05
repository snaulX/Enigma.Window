#include <stdio.h>
#include "EnigmaWindow.h"
#include "glfw/GlfwModule.h"

void onError(const char* error)
{
    printf("Enigma.Window error: %s", error);
}

int main()
{
    EW_SetErrorCallback(onError);
#ifdef ENIGMA_GLFW
    Glfw_InitFunctions();
#endif // ENIGMA_GLFW
#ifdef CreateWindow
    #undef CreateWindow
#endif
    Window *wnd = CreateWindow("snaulX window", 100, 100, 800, 600, WindowState_None);
    printf("%s\n", GetTitle(wnd));
    Run(wnd);
}
