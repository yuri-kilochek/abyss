#ifndef ABYSS_IMPL_INCL_SRC_ROUND_UP_H
#define ABYSS_IMPL_INCL_SRC_ROUND_UP_H

#include <stddef.h>

#include <abyss/impl/always_inline.h>

///////////////////////////////////////////////////////////////////////////////

#define ABYSS_IMPL_DEFINE_ROUND_UP(prefix, type) \
    static inline ABYSS_IMPL_ALWAYS_INLINE \
    type abyss_impl_##prefix##round_up(type value, type step) { \
        return (value + step - 1) / step * step; \
    }

ABYSS_IMPL_DEFINE_ROUND_UP(, int)
ABYSS_IMPL_DEFINE_ROUND_UP(l, long)
ABYSS_IMPL_DEFINE_ROUND_UP(ll, long long)
ABYSS_IMPL_DEFINE_ROUND_UP(u, unsigned int)
ABYSS_IMPL_DEFINE_ROUND_UP(ul, unsigned long)
ABYSS_IMPL_DEFINE_ROUND_UP(ull, unsigned long long)
ABYSS_IMPL_DEFINE_ROUND_UP(z, size_t)
ABYSS_IMPL_DEFINE_ROUND_UP(t, ptrdiff_t)

#undef ABYSS_IMPL_DEFINE_ROUND_UP

#define ABYSS_IMPL_ROUND_UP(a, b) \
    _Generic(+(0 ? (a) : (b)) \
    , int: abyss_impl_round_up \
    , long: abyss_impl_lround_up \
    , long long: abyss_impl_llround_up \
    , unsigned int: abyss_impl_uround_up \
    , unsigned long: abyss_impl_ulround_up \
    , unsigned long long: abyss_impl_ullround_up \
    , default: \
        _Generic(+(0 ? (a) : (b)) \
        , size_t: abyss_impl_zround_up \
        , ptrdiff_t: abyss_impl_tround_up \
        ) \
    )(a, b)

///////////////////////////////////////////////////////////////////////////////

#endif
