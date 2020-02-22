#ifndef ABYSS_INCLUDE_GUARD_STD_ALLOCATOR_H
#define ABYSS_INCLUDE_GUARD_STD_ALLOCATOR_H

#include <abyss/detail/extern_c.h>
#include <abyss/detail/api.h>
#include <abyss/allocator.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

ABYSS_DETAIL_API
abyss_allocator_t *abyss_get_std_allocator(void);

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
