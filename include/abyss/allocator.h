#ifndef ABYSS_DETAIL_INCLUDE_ALLOCATOR_H
#define ABYSS_DETAIL_INCLUDE_ALLOCATOR_H

#include <abyss/error.h>
#include <abyss/detail/always_inline.h>

#include <stddef.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_allocator_type abyss_allocator_type_t;
typedef struct abyss_allocator abyss_allocator_t;

struct abyss_allocator_type {
    abyss_error_t *(*allocate)(abyss_allocator_t *self,
        size_t size, size_t alignment, void **ptr_out);

    void (*deallocate)(abyss_allocator_t *self,
        size_t size, size_t alignment, void *ptr);
};

struct abyss_allocator {
    abyss_allocator_type_t const *const type;
};

static inline ABYSS_DETAIL_ALWAYS_INLINE
abyss_error_t *abyss_allocator_allocate(abyss_allocator_t *self,
    size_t size, size_t alignment, void **ptr_out)
{ return self->type->allocate(self, size, alignment, ptr_out); }

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_allocator_deallocate(abyss_allocator_t *self,
    size_t size, size_t alignment, void *ptr)
{ self->type->deallocate(self, size, alignment, ptr); }

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
