#ifndef ENIGMA_WINDOW_BASE_H
#define ENIGMA_WINDOW_BASE_H
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#define STRUCT(name) typedef struct name name; \
    struct name

#define STRUCT_EXTENDS(name, base, body) STRUCT(name) {            \
    base* _base;                                                   \
    body                                                           \
    };                                                             \
    union { base* Parent; name Child; } base##To##name##Convert;   \
    name Get##name##From##base(base* _base)                        \
{                                                                  \
    base##To##name##Convert.Parent = _base;                        \
    return base##To##name##Convert.Child;                          \
}                                                                  \
    base* Get##base##From##name(name _child)                        \
{                                                                  \
    base##To##name##Convert.Child = _child;                        \
    return base##To##name##Convert.Parent;                          \
}



#define METHOD(rtype, name) rtype(*name)

#endif //ENIGMA_WINDOW_BASE_H
