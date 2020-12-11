#ifndef ABYSS_DETAIL_SRC_ROUND_UP_H
#define ABYSS_DETAIL_SRC_ROUND_UP_H

#include <stddef.h>

#include <abyss/detail/always_inline.h>

///////////////////////////////////////////////////////////////////////////////

#define ABYSS_DETAIL_DEFINE_ROUND_UP(prefix, type) \
    static inline ABYSS_DETAIL_ALWAYS_INLINE \
    type abyss_detail_##prefix##round_up(type value, type step) { \
        return (value + step - 1) / step * step; \
    }

ABYSS_DETAIL_DEFINE_ROUND_UP(, int)
ABYSS_DETAIL_DEFINE_ROUND_UP(l, long)
ABYSS_DETAIL_DEFINE_ROUND_UP(ll, long long)
ABYSS_DETAIL_DEFINE_ROUND_UP(u, unsigned int)
ABYSS_DETAIL_DEFINE_ROUND_UP(ul, unsigned long)
ABYSS_DETAIL_DEFINE_ROUND_UP(ull, unsigned long long)
ABYSS_DETAIL_DEFINE_ROUND_UP(z, size_t)
ABYSS_DETAIL_DEFINE_ROUND_UP(t, ptrdiff_t)

#undef ABYSS_DETAIL_DEFINE_ROUND_UP

#define ABYSS_DETAIL_ROUND_UP(a, b) \
    _Generic(+(0 ? (a) : (b)) \
    , int: abyss_detail_round_up \
    , long: abyss_detail_lround_up \
    , long long: abyss_detail_llround_up \
    , unsigned int: abyss_detail_uround_up \
    , unsigned long: abyss_detail_ulround_up \
    , unsigned long long: abyss_detail_ullround_up \
    , default: \
        _Generic(+(0 ? (a) : (b)) \
        , size_t: abyss_detail_zround_up \
        , ptrdiff_t: abyss_detail_tround_up \
        ) \
    )(a, b)

///////////////////////////////////////////////////////////////////////////////

#endif
