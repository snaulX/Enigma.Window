#include <stdio.h>
#include "WindowModule.h"

int main()
{
    WindowModule *module = InitEnigmaWindow();
    Window *wnd = module->CreateWindow(module);
    wnd->GetTitle(wnd);
}
