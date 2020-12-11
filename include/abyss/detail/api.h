#ifndef ABYSS_DETAIL_INCLUDE_DETAIL_API_H
#define ABYSS_DETAIL_INCLUDE_DETAIL_API_H

#include <abyss/detail/os.h>

///////////////////////////////////////////////////////////////////////////////

#if ABYSS_SHARED_IMPORT && ABYSS_SHARED_EXPORT
    #error ABYSS_SHARED_IMPORT and ABYSS_SHARED_EXPORT must not be defined \
        simultaneously.
#endif

#if ABYSS_DETAIL_OS_WINDOWS
    #if ABYSS_SHARED_IMPORT
        #define ABYSS_DETAIL_API __declspec(dllimport)
    #elif ABYSS_SHARED_EXPORT
        #define ABYSS_DETAIL_API __declspec(dllexport)
    #else
        #define ABYSS_DETAIL_API 
    #endif
#else
    #if ABYSS_SHARED_EXPORT
        #define ABYSS_DETAIL_API __attribute__((visibility("default")))
    #else
        #define ABYSS_DETAIL_API
    #endif
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
