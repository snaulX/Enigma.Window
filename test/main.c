#include <stdio.h>
#include "WindowModule.h"
#include "glfw/GlfwModule.h"

int main()
{
    Glfw__InitFunctions();
    Window *wnd = CreateWindow();
    SetTitle(wnd, "snaulX");
    //Window* new_wnd = CreateWindow();
    //SetTitle(new_wnd, "lolus");
    printf(GetTitle(wnd));
}
