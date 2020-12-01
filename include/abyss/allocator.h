#ifndef ABYSS_IMPL_INCL_ALLOCATOR_H
#define ABYSS_IMPL_INCL_ALLOCATOR_H

#include <abyss/error.h>
#include <abyss/impl/always_inline.h>

#include <stddef.h>

#include <abyss/impl/prolog.h>
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

static inline ABYSS_IMPL_ALWAYS_INLINE
abyss_error_t *abyss_allocator_allocate(abyss_allocator_t *self,
    size_t size, size_t alignment, void **ptr_out)
{ return self->type->allocate(self, size, alignment, ptr_out); }

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_allocator_deallocate(abyss_allocator_t *self,
    size_t size, size_t alignment, void *ptr)
{ self->type->deallocate(self, size, alignment, ptr); }

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
