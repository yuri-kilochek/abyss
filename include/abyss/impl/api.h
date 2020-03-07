#ifndef ABYSS_INCLUDE_GUARD_IMPL_API_H
#define ABYSS_INCLUDE_GUARD_IMPL_API_H

#include <abyss/impl/os.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

#if ABYSS_IMPL_USE_DYNAMIC && ABYSS_IMPL_BUILD_DYNAMIC
    #error ABYSS_IMPL_USE_DYNAMIC and ABYSS_IMPL_BUILD_DYNAMIC must not \
        be defined simultaneously.
#endif

#if ABYSS_IMPL_OS_WINDOWS
    #if ABYSS_IMPL_USE_DYNAMIC
        #define ABYSS_IMPL_API __declspec(dllimport)
    #elif ABYSS_IMPL_BUILD_DYNAMIC
        #define ABYSS_IMPL_API __declspec(dllexport)
    #else
        #define ABYSS_IMPL_API 
    #endif
#else
    #if ABYSS_IMPL_BUILD_DYNAMIC
        #define ABYSS_IMPL_API __attribute__((visibility("default")))
    #else
        #define ABYSS_IMPL_API
    #endif
#endif

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
