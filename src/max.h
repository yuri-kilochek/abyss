#ifndef ABYSS_DETAIL_SRC_MAX_H
#define ABYSS_DETAIL_SRC_MAX_H

#include <stddef.h>

#include <abyss/detail/always_inline.h>

///////////////////////////////////////////////////////////////////////////////

#define ABYSS_DETAIL_DEFINE_MAX(prefix, type) \
    static inline ABYSS_DETAIL_ALWAYS_INLINE \
    type abyss_detail_##prefix##max(type x, type y) { \
        return (x > y) ? x : y; \
    }

ABYSS_DETAIL_DEFINE_MAX(, int)
ABYSS_DETAIL_DEFINE_MAX(l, long)
ABYSS_DETAIL_DEFINE_MAX(ll, long long)
ABYSS_DETAIL_DEFINE_MAX(u, unsigned int)
ABYSS_DETAIL_DEFINE_MAX(ul, unsigned long)
ABYSS_DETAIL_DEFINE_MAX(ull, unsigned long long)
ABYSS_DETAIL_DEFINE_MAX(z, size_t)
ABYSS_DETAIL_DEFINE_MAX(t, ptrdiff_t)

#undef ABYSS_DETAIL_DEFINE_MAX

#define ABYSS_DETAIL_MAX(a, b) \
    _Generic(+(0 ? (a) : (b)) \
    , int: abyss_detail_max \
    , long: abyss_detail_lmax \
    , long long: abyss_detail_llmax \
    , unsigned int: abyss_detail_umax \
    , unsigned long: abyss_detail_ulmax \
    , unsigned long long: abyss_detail_ullmax \
    , default: \
        _Generic(+(0 ? (a) : (b)) \
        , size_t: abyss_detail_zmax \
        , ptrdiff_t: abyss_detail_tmax \
        ) \
    )(a, b)

///////////////////////////////////////////////////////////////////////////////

#endif
