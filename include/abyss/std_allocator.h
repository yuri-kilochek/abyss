#ifndef ABYSS_INCLUDE_GUARD_STD_ALLOCATOR_H
#define ABYSS_INCLUDE_GUARD_STD_ALLOCATOR_H

#include <abyss/detail/api.h>
#include <abyss/allocator.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

ABYSS_DETAIL_API
abyss_allocator_t *abyss_get_std_allocator(void);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
