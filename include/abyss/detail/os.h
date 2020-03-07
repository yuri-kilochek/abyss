#ifndef ABYSS_INCLUDE_GUARD_DETAIL_OS_H
#define ABYSS_INCLUDE_GUARD_DETAIL_OS_H

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

#if defined(_WIN32) \
 || defined(_WIN64) \
 || defined(__WIN32__) \
 || defined(__TOS_WIN__) \
 || defined(__WINDOWS__)
    #define ABYSS_DETAIL_OS_WINDOWS 1
#endif

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
