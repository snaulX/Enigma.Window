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
    // Same as onKey
    // Exclusive of this will print smth every frame
    // Because key callback works only when key is changing state
    // And update callback checks key every frame
    // So when we use if (EI_IsKeyDown) else if (EI_IsKeyUp) it's will always work
    /*if (EI_IsKeyDown(wnd, EI_KEY_W))
        printf("w down\t");
    else if (EI_IsKeyUp(wnd, EI_KEY_W))
        printf("w up\t");
    if (EI_IsKeyDown(wnd, EI_KEY_ESCAPE))
        EW_Close(wnd);*/
}

void onKey(EW_Window* wnd, EI_Key key, bool isDown)
{
    if (key == EI_KEY_W)
    {
        if (isDown)
            printf("w down\t");
        else
            printf("w up\t");
    }
    else if (key == EI_KEY_ESCAPE)
    {
        EW_Close(wnd);
    }
}

int main()
{
    printf("https://github.com/wings-studio/Enigma.Window\n");
    EW_SetErrorCallback(onError);
#ifdef ENIGMA_GLFW
    Glfw_InitFunctions();
#endif // ENIGMA_GLFW
    EW_Window *wnd = EW_CreateWindow("Author: snaulX", 100, 100, 800, 600, EW_WindowState_Resizable);
    EW_SetMinSize(wnd, 320, 240);
    EW_SetFramebufferResizeCallback(wnd, onResize);
    EW_SetUpdateCallback(wnd, onUpdate);
    EI_SetKeyCallback(wnd, onKey);
    printf("%s\n", EW_GetTitle(wnd));
    EW_Run(wnd);
}
