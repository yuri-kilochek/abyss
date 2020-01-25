#ifndef ABYSS_INCLUDE_ALLOCATOR_H
#define ABYSS_INCLUDE_ALLOCATOR_H

#include <abyss/error.h>

#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_allocator_type {
    abyss_error
    (*const allocate)(void *allocator,
                      size_t size, size_t alignment,
                      void **pointer_out);

    void
    (*const deallocate)(void *allocator,
                        size_t size, size_t alignment, void *pointer);
} abyss_allocator_type;

typedef struct abyss_allocator {
    abyss_allocator_type *const type;
} abyss_allocator;

static inline
abyss_error
abyss_allocate(abyss_allocator *allocator,
               size_t size, size_t alignment, void **pointer_out)
{ return allocator->type->allocate(allocator, size, alignment, pointer_out); }

static inline
void
abyss_deallocate(abyss_allocator *allocator,
                 size_t size, size_t alignment, void *pointer)
{ return allocator->type->deallocate(allocator, size, alignment, pointer); }

///////////////////////////////////////////////////////////////////////////////

#endif
