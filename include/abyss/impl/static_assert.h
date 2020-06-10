#ifndef ABYSS_IMPL_INCL_IMPL_STATIC_ASSERT_H
#define ABYSS_IMPL_INCL_IMPL_STATIC_ASSERT_H

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

#if __cplusplus
    #define ABYSS_IMPL_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
#else
    #define ABYSS_IMPL_STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)
#endif

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
