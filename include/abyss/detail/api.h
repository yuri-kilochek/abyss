#ifndef ABYSS_INCLUDE_DETAIL_API_H
#define ABYSS_INCLUDE_DETAIL_API_H

#include <abyss/detail/os.h>

///////////////////////////////////////////////////////////////////////////////

#if ABYSS_DETAIL_USE_DYNAMIC && ABYSS_DETAIL_BUILD_DYNAMIC
    #error ABYSS_DETAIL_USE_DYNAMIC and ABYSS_DETAIL_BUILD_DYNAMIC must not \
        be defined simultaneously.
#endif
#if ABYSS_DETAIL_WINDOWS
    #if ABYSS_DETAIL_USE_DYNAMIC
        #define ABYSS_DETAIL_API_VISIBILITY __declspec(dllimport)
    #elif ABYSS_DETAIL_BUILD_DYNAMIC
        #define ABYSS_DETAIL_API_VISIBILITY __declspec(dllexport)
    #else
        #define ABYSS_DETAIL_API_VISIBILITY 
    #endif
#else
    #if ABYSS_DETAIL_BUILD_DYNAMIC
        #define ABYSS_DETAIL_API_VISIBILITY \
            __attribute__((visibility("default")))
    #else
        #define ABYSS_DETAIL_API_VISIBILITY 
    #endif
#endif

#if __cplusplus
    #define ABYSS_DETAIL_API_LANGUAGE_LINKAGE extern "C"
#else
    #define ABYSS_DETAIL_API_LANGUAGE_LINKAGE
#endif

#define ABYSS_DETAIL_API \
    ABYSS_DETAIL_API_VISIBILITY \
    ABYSS_DETAIL_API_LANGUAGE_LINKAGE

///////////////////////////////////////////////////////////////////////////////

#endif
