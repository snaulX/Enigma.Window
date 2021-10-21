#include <stdio.h>
#include "WindowModule.h"
#include "glfw/GlfwModule.h"

int main()
{
    Glfw__InitFunctions();
    Window *wnd = CreateWindow();
    SetTitle(wnd, "snaulX");
    printf("%s\n", GetTitle(wnd));
    Window* new_wnd = CreateWindow();
    printf("%s\n", GetTitle(wnd));
    SetTitle(new_wnd, "lolus");
    printf("%s\n", GetTitle(wnd));
    printf("%s\n", GetTitle(new_wnd));
}
