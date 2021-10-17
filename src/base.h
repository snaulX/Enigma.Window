#ifndef ENIGMA_WINDOW_BASE_H
#define ENIGMA_WINDOW_BASE_H
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#if defined(NULL)
#undef NULL
#endif

#if defined(__cplusplus)
#define NULL 0
#else
#define NULL ((void*)0)
#endif

#define STRUCT(name) typedef struct name name; \
    struct name

#define STRUCT_EXTENDS(name, base, body) STRUCT(name) {            \
    base* _base;                                                   \
    body                                                           \
    };                                                             \
    union { base* Parent; name Child; } base##To##name##Convert;   \
    inline name Get##name##From##base(base* _base)                        \
{                                                                  \
    base##To##name##Convert.Parent = _base;                        \
    return base##To##name##Convert.Child;                          \
}                                                                  \
    inline base* Get##base##From##name(name _child)                       \
{                                                                  \
    base##To##name##Convert.Child = _child;                        \
    return base##To##name##Convert.Parent;                         \
}

#ifdef WIN32
    #define PUBLIC __declspec(dllexport)
    #define PRIVATE
#else
    #define PUBLIC __attribute__((visibility("default")))
    #define PRIVATE __attribute__((visibility("internal")))
#endif

#define METHOD(rtype, name) rtype(*name)
#define DECLMETHOD(rtype, name, params) PUBLIC METHOD(rtype, name) params; \
    PUBLIC void Set_##name(METHOD(rtype, _##name)params);

#define SETMETHOD(rtype, name, params) void Set_##name(METHOD(rtype, _##name)params) { \
name = _##name; }
#define GENPUBMETHOD(rtype, name, params) PUBLIC METHOD(rtype, name) params; \
PUBLIC inline SETMETHOD(rtype, name, params)

#endif //ENIGMA_WINDOW_BASE_H
