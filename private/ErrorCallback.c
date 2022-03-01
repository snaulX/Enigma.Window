#include "ErrorCallback.h"

static void(*EnigmaWindowErrorCallback)(const char*);

void EW_Error(const char* error)
{
    EnigmaWindowErrorCallback(error);
}
void EW_SetErrorCallback(void(*callback)(const char*))
{
    EnigmaWindowErrorCallback = callback;
}