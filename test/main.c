#include <stdio.h>
#include "EnigmaWindow.h"
#include "EnigmaInput.h"
#include "GlfwModule.h"

void onError(const char* error)
{
    printf("Enigma.Window error: %s", error);
}

void onResize(EW_Window* wnd, int w, int h)
{
    printf("Width: %i\nHeight: %i\n", w, h);
}

void onUpdate(EW_Window* wnd)
{
    if (EI_IsKeyPress(wnd, EI_KEY_W))
        printf("W was pressed!\n");
}

int main()
{
    EW_SetErrorCallback(onError);
#ifdef ENIGMA_GLFW
    Glfw_InitFunctions();
#endif // ENIGMA_GLFW
    EW_Window *wnd = EW_CreateWindow("snaulX window", 100, 100, 800, 600, EW_WindowState_Resizable);
    EW_SetMinSize(wnd, 320, 240);
    EW_SetFramebufferResizeCallback(wnd, onResize);
    EW_SetUpdateCallback(wnd, onUpdate);
    printf("%s\n", EW_GetTitle(wnd));
    EW_Run(wnd);
}
