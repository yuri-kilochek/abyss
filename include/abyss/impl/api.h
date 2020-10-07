#ifndef ABYSS_IMPL_INCL_IMPL_API_H
#define ABYSS_IMPL_INCL_IMPL_API_H

#include <abyss/impl/os.h>

///////////////////////////////////////////////////////////////////////////////

#if ABYSS_SHARED_IMPORT && ABYSS_SHARED_EXPORT
    #error ABYSS_SHARED_IMPORT and ABYSS_SHARED_EXPORT must not be defined \
        simultaneously.
#endif

#if ABYSS_IMPL_OS_WINDOWS
    #if ABYSS_SHARED_IMPORT
        #define ABYSS_IMPL_API __declspec(dllimport)
    #elif ABYSS_SHARED_EXPORT
        #define ABYSS_IMPL_API __declspec(dllexport)
    #else
        #define ABYSS_IMPL_API 
    #endif
#else
    #if ABYSS_SHARED_EXPORT
        #define ABYSS_IMPL_API __attribute__((visibility("default")))
    #else
        #define ABYSS_IMPL_API
    #endif
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
