#ifndef ABYSS_IMPL_INCL_MALLOC_FREE_ALLOCATOR_H
#define ABYSS_IMPL_INCL_MALLOC_FREE_ALLOCATOR_H

#include <abyss/allocator.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

ABYSS_IMPL_API
abyss_allocator_t *abyss_get_malloc_free_allocator(void);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
