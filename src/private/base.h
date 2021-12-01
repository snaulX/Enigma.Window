#ifndef ENIGMA_WINDOW_BASE_H
#define ENIGMA_WINDOW_BASE_H
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#if defined(NULL)
#undef NULL
#endif

#if defined(__cplusplus)
#define NULL 0
#else
#define NULL ((void*)0)
#endif

#if !defined(nullptr)
#define nullptr ((void*)0)
#endif

typedef unsigned int uint;

inline bool CheckBitsAny(int v, int bits)
{
    return (v & bits) != 0;
}

#define STRUCT(name) typedef struct name name; \
    struct name

#define STRUCT_EXTENDS(name, base, body) STRUCT(name) {            \
    base* _base;                                                   \
    body                                                           \
    };                                                             \
    union base##To##name##Convert { base* Parent; name Child; };   \
    inline name Get##name##From##base(base* _base)                        \
{                                                                  \
    union base##To##name##Convert _##base##To##name##Convert;      \
    _##base##To##name##Convert.Parent = _base;                        \
    return _##base##To##name##Convert.Child;                          \
}                                                                  \
    inline base* Get##base##From##name(name _child)                       \
{                                                                  \
    union base##To##name##Convert _##base##To##name##Convert;      \
    _##base##To##name##Convert.Child = _child;                        \
    return _##base##To##name##Convert.Parent;                         \
}

#ifdef WIN32
    #define PUBLIC __declspec(dllexport)
    #define PRIVATE
#else
    #define PUBLIC __attribute__((visibility("default")))
    #define PRIVATE __attribute__((visibility("internal")))
#endif

#define METHOD(rtype, name) rtype(*name)
#define DECLMETHOD(rtype, name, params) static METHOD(rtype, _##name) params; \
    PUBLIC rtype name params;                                                 \
    PUBLIC void Set_##name(METHOD(rtype, __##name)params);

#define SETMETHOD(rtype, name, params, ...) PUBLIC void Set_##name(METHOD(rtype, __##name)params) { \
_##name = __##name; }                                                                       \
PUBLIC rtype name params { return _##name (__VA_ARGS__);  }

#define GETSET(ptype, type, name) DECLMETHOD(void, Set##name, (ptype*, type)) \
DECLMETHOD(type, Get##name, (ptype*))

#define LOGE(msg) printf("Error: %s", msg)

#endif //ENIGMA_WINDOW_BASE_H
