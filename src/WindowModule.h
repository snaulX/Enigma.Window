#ifndef WINDOW_MODULE_ENIGMA_WINDOW_H
#define WINDOW_MODULE_ENIGMA_WINDOW_H
#include "base.h"

STRUCT(Window)
{
    METHOD(void, SetTitle)(Window*, const char*);
    METHOD(const char*, GetTitle)(Window*);
    METHOD(void, SetPosition)(Window*, int, int);
    METHOD(void, GetPosition)(Window*, int*, int*);
    METHOD(void, SetSize)(Window*, int, int);
    METHOD(void, GetSize)(Window*, int*, int*);

    METHOD(void, Run)(Window*);
    METHOD(void, Update)(Window*);
    METHOD(bool, ShouldClose)(Window*);
};

STRUCT(WindowModule)
{
    METHOD(Window*, CreateWindow)(WindowModule*);
};

WindowModule *InitEnigmaWindow();

#endif //WINDOW_MODULE_ENIGMA_WINDOW_H
