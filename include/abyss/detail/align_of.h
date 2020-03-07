#ifndef ABYSS_INCLUDE_GUARD_ALIGN_OF_H
#define ABYSS_INCLUDE_GUARD_ALIGN_OF_H

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

#if __cplusplus
    #define ABYSS_DETAIL_ALIGN_OF(...) alignof(__VA_ARGS__)
#else
    #define ABYSS_DETAIL_ALIGN_OF(...) _Alignof(__VA_ARGS__)
#endif

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
