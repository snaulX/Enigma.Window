#ifndef ENIGMA_WINDOW_ERRORCALLBACK_H
#define ENIGMA_WINDOW_ERRORCALLBACK_H
#include "base.h"

#ifdef __cplusplus
extern "C"
{
#endif
PUBLIC void EW_Error(const char *);
PUBLIC void EW_SetErrorCallback(void(*callback)(const char *));
#ifdef __cplusplus
}
#endif

#endif //ENIGMA_WINDOW_ERRORCALLBACK_H
