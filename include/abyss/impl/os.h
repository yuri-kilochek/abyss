#ifndef ABYSS_IMPL_INCL_IMPL_OS_H
#define ABYSS_IMPL_INCL_IMPL_OS_H

///////////////////////////////////////////////////////////////////////////////

#if defined(_WIN32) \
 || defined(_WIN64) \
 || defined(__WIN32__) \
 || defined(__TOS_WIN__) \
 || defined(__WINDOWS__)
    #define ABYSS_IMPL_OS_WINDOWS 1
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
