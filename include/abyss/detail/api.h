#ifndef ABYSS_INCLUDE_GUARD_DETAIL_API_H
#define ABYSS_INCLUDE_GUARD_DETAIL_API_H

#include <abyss/detail/os.h>

///////////////////////////////////////////////////////////////////////////////

#if ABYSS_DETAIL_USE_DYNAMIC && ABYSS_DETAIL_BUILD_DYNAMIC
    #error ABYSS_DETAIL_USE_DYNAMIC and ABYSS_DETAIL_BUILD_DYNAMIC must not \
        be defined simultaneously.
#endif

#if ABYSS_DETAIL_OS_WINDOWS
    #if ABYSS_DETAIL_USE_DYNAMIC
        #define ABYSS_DETAIL_API __declspec(dllimport)
    #elif ABYSS_DETAIL_BUILD_DYNAMIC
        #define ABYSS_DETAIL_API __declspec(dllexport)
    #else
        #define ABYSS_DETAIL_API 
    #endif
#else
    #if ABYSS_DETAIL_BUILD_DYNAMIC
        #define ABYSS_DETAIL_API __attribute__((visibility("default")))
    #else
        #define ABYSS_DETAIL_API
    #endif
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
