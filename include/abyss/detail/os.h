#ifndef ABYSS_INCLUDE_GUARD_DETAIL_OS_H
#define ABYSS_INCLUDE_GUARD_DETAIL_OS_H

///////////////////////////////////////////////////////////////////////////////

#if defined(_WIN32) \
 || defined(_WIN64) \
 || defined(__WIN32__) \
 || defined(__TOS_WIN__) \
 || defined(__WINDOWS__)
    #define ABYSS_DETAIL_OS_WINDOWS 1
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
