#ifndef ABYSS_INCLUDE_GUARD_VERSION_H
#define ABYSS_INCLUDE_GUARD_VERSION_H

#include <abyss/detail/extern_c.h>

#include <stdint.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef uint_least32_t abyss_version_t;

#define ABYSS_VERSION_COMPOSE(major, minor, patch) \
    (((major) & UINT32_C(0xFFF)) << UINT32_C(20) | \
     ((minor) & UINT32_C(0x3FF)) << UINT32_C(10) | \
     ((patch) & UINT32_C(0x3FF)))

#define ABYSS_VERSION_GET_MAJOR(version) \
    (((version) >> UINT32_C(20)) & UINT32_C(0xFFF))

#define ABYSS_VERSION_GET_MINOR(version) \
    (((version) >> UINT32_C(10)) & UINT32_C(0x3FF))

#define ABYSS_VERSION_GET_PATCH(version) \
    ((version) & UINT32_C(0x3FF))

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
