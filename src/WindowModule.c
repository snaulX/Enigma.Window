#include "WindowModule.h"

PUBLIC SETMETHOD(void, SetTitle, (Window*, const char*))
PUBLIC SETMETHOD(const char*, GetTitle, (Window*))
PUBLIC SETMETHOD(void, SetPosition, (Window*, int, int))
PUBLIC SETMETHOD(void, GetPosition, (Window*, int*, int*))
PUBLIC SETMETHOD(void, SetSize, (Window*, int, int))
PUBLIC SETMETHOD(void, GetSize, (Window*, int*, int*))

PUBLIC SETMETHOD(void, Run, (Window*))
PUBLIC SETMETHOD(void, Update, (Window*))
PUBLIC SETMETHOD(bool, ShouldClose, (Window*))

PUBLIC SETMETHOD(Window*, CreateWindow, ())