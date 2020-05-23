#ifndef ABYSS_IMPL_INCL_ALLOCATOR_H
#define ABYSS_IMPL_INCL_ALLOCATOR_H

#include <abyss/error.h>

#include <stddef.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_allocator_ops abyss_allocator_ops_t;
typedef struct abyss_allocator abyss_allocator_t;

struct abyss_allocator_ops {
    void *(*allocate)(abyss_allocator_t *self,
                      size_t size, size_t alignment, abyss_error_t *error_out);
    void (*deallocate)(abyss_allocator_t *self,
                       void *ptr, size_t size, size_t alignment);
};

struct abyss_allocator {
    abyss_allocator_ops_t const *const ops;
};

static inline
void *abyss_allocator_allocate(abyss_allocator_t *self,
                               size_t size, size_t alignment,
                               abyss_error_t *error_out)
{ return self->ops->allocate(self, size, alignment, error_out); }

static inline
void abyss_allocator_deallocate(abyss_allocator_t *self,
                                void *ptr, size_t size, size_t alignment)
{ self->ops->deallocate(self, ptr, size, alignment); }

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
