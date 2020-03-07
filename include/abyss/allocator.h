#ifndef ABYSS_INCLUDE_GUARD_ALLOCATOR_H
#define ABYSS_INCLUDE_GUARD_ALLOCATOR_H

#include <abyss/error.h>

#include <stddef.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_allocator abyss_allocator_t;
typedef struct abyss_allocator_type abyss_allocator_type_t;

struct abyss_allocator {
    void const *const type;
};

struct abyss_allocator_type {
    abyss_error_t (*allocate)(abyss_allocator_t *allocator,
                              void **ptr_ptr, size_t size, size_t alignment);
    void (*deallocate)(abyss_allocator_t *allocator,
                       void *ptr, size_t size, size_t alignment);
};

static inline
abyss_error_t abyss_allocator_allocate(abyss_allocator_t *allocator,
                                       void **ptr_ptr,
                                       size_t size, size_t alignment)
{
    typedef abyss_allocator_type_t type_t;
    type_t const *type = (type_t const *) allocator->type;
    return type->allocate(allocator, ptr_ptr, size, alignment);
}

static inline
void abyss_allocator_deallocate(abyss_allocator_t *allocator,
                                void **ptr_ptr, size_t size, size_t alignment)
{
    if (!*ptr_ptr) { return; }
    typedef abyss_allocator_type_t type_t;
    type_t const *type = (type_t const *) allocator->type;
    type->deallocate(allocator, *ptr_ptr, size, alignment);
    *ptr_ptr = NULL;
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
