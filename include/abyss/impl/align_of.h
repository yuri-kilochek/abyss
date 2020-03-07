#ifndef ABYSS_IMPL_INCL_ALIGN_OF_H
#define ABYSS_IMPL_INCL_ALIGN_OF_H

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

#if __cplusplus
    #define ABYSS_IMPL_ALIGN_OF(...) alignof(__VA_ARGS__)
#else
    #define ABYSS_IMPL_ALIGN_OF(...) _Alignof(__VA_ARGS__)
#endif

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
