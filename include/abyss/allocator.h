#ifndef ABYSS_INCLUDE_GUARD_ALLOCATOR_H
#define ABYSS_INCLUDE_GUARD_ALLOCATOR_H

#include <abyss/detail/extern_c.h>
#include <abyss/error.h>

#include <stddef.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_allocator abyss_allocator_t;
typedef struct abyss_allocator_type abyss_allocator_type_t;

struct abyss_allocator {
    void const *const type;
};

struct abyss_allocator_type {
    abyss_error_t (*allocate)(abyss_allocator_t *allocator,
                              size_t size, size_t alignment, void **ptr_out);

    void (*deallocate)(abyss_allocator_t *allocator,
                       void *ptr, size_t size, size_t alignment);
};

static inline
abyss_error_t abyss_allocator_allocate(abyss_allocator_t *allocator,
                                       size_t size, size_t alignment,
                                       void **ptr_out)
{
    typedef abyss_allocator_type_t type_t;
    type_t const *type = (type_t const *) allocator->type;
    return type->allocate(allocator, size, alignment, ptr_out);
}

static inline
void abyss_allocator_deallocate(abyss_allocator_t *allocator,
                                void *ptr, size_t size, size_t alignment)
{
    typedef abyss_allocator_type_t type_t;
    type_t const *type = (type_t const *) allocator->type;
    type->deallocate(allocator, ptr, size, alignment);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif