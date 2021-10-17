#ifndef WINDOW_MODULE_ENIGMA_WINDOW_H
#define WINDOW_MODULE_ENIGMA_WINDOW_H
#include "base.h"

STRUCT(Window)
{
    void* handle;
};

DECLMETHOD(void, SetTitle, (Window*, const char*))
DECLMETHOD(const char*, GetTitle, (Window*))
DECLMETHOD(void, SetPosition, (Window*, int, int))
DECLMETHOD(void, GetPosition, (Window*, int*, int*))
DECLMETHOD(void, SetSize, (Window*, int, int))
DECLMETHOD(void, GetSize, (Window*, int*, int*))

DECLMETHOD(void, Run, (Window*))
DECLMETHOD(void, Update, (Window*))
DECLMETHOD(bool, ShouldClose, (Window*))

DECLMETHOD(Window*, CreateWindow, ())

#endif //WINDOW_MODULE_ENIGMA_WINDOW_H
