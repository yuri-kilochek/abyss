#ifndef ABYSS_DETAIL_INCLUDE_MALLOC_FREE_ALLOCATOR_H
#define ABYSS_DETAIL_INCLUDE_MALLOC_FREE_ALLOCATOR_H

#include <abyss/allocator.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

ABYSS_DETAIL_API
abyss_allocator_t *abyss_get_malloc_free_allocator(void);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
