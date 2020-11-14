#ifndef ABYSS_IMPL_INCL_SRC_MAX_H
#define ABYSS_IMPL_INCL_SRC_MAX_H

#include <stddef.h>

#include <abyss/impl/always_inline.h>

///////////////////////////////////////////////////////////////////////////////

#define ABYSS_IMPL_DEFINE_MAX(prefix, type) \
    static inline ABYSS_IMPL_ALWAYS_INLINE \
    type abyss_impl_##prefix##max(type x, type y) { \
        return (x > y) ? x : y; \
    }

ABYSS_IMPL_DEFINE_MAX(, int)
ABYSS_IMPL_DEFINE_MAX(l, long)
ABYSS_IMPL_DEFINE_MAX(ll, long long)
ABYSS_IMPL_DEFINE_MAX(u, unsigned int)
ABYSS_IMPL_DEFINE_MAX(ul, unsigned long)
ABYSS_IMPL_DEFINE_MAX(ull, unsigned long long)
ABYSS_IMPL_DEFINE_MAX(z, size_t)
ABYSS_IMPL_DEFINE_MAX(t, ptrdiff_t)

#undef ABYSS_IMPL_DEFINE_MAX

#define ABYSS_IMPL_MAX(a, b) \
    _Generic(+(0 ? (a) : (b)) \
    , int: abyss_impl_max \
    , long: abyss_impl_lmax \
    , long long: abyss_impl_llmax \
    , unsigned int: abyss_impl_umax \
    , unsigned long: abyss_impl_ulmax \
    , unsigned long long: abyss_impl_ullmax \
    , default: \
        _Generic(+(0 ? (a) : (b)) \
        , size_t: abyss_impl_zmax \
        , ptrdiff_t: abyss_impl_tmax \
        ) \
    )(a, b)

///////////////////////////////////////////////////////////////////////////////

#endif
