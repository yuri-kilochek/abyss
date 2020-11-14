#ifndef ABYSS_IMPL_INCL_ALLOCATOR_H
#define ABYSS_IMPL_INCL_ALLOCATOR_H

#include <abyss/error.h>
#include <abyss/impl/always_inline.h>
#include <abyss/impl/alignment_of.h>
#include <abyss/impl/assign_void_ptr.h>

#include <stddef.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_allocator_ops abyss_allocator_ops_t;
typedef struct abyss_allocator abyss_allocator_t;

struct abyss_allocator_ops {
    abyss_error_t (*allocate)(abyss_allocator_t *self,
        size_t size, size_t alignment, void **ptr_out);

    void (*deallocate)(abyss_allocator_t *self,
        size_t size, size_t alignment, void *ptr);

    void (*release)(abyss_allocator_t *self);
};

struct abyss_allocator {
    abyss_allocator_ops_t const *const ops;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
abyss_error_t abyss_allocator_allocate(abyss_allocator_t *self,
    size_t size, size_t alignment, void **ptr_out)
{ return self->ops->allocate(self, size, alignment, ptr_out); }

#define ABYSS_ALLOCATOR_ALLOCATE(error_out, self, count, ptr_out) \
    do { \
        void *abyss_impl_allocator_allocate_void_ptr; \
        if (!(*(error_out) = abyss_allocator_allocate(self, \
                (count) * sizeof(**(ptr_out)), \
                ABYSS_IMPL_ALIGNMENT_OF(**(ptr_out)), \
                &abyss_impl_allocator_allocate_void_ptr))) \
        { \
            ABYSS_IMPL_ASSIGN_VOID_PTR( \
                ptr_out, abyss_impl_allocator_allocate_void_ptr); \
        } \
    } while (0)

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_allocator_deallocate(abyss_allocator_t *self,
    size_t size, size_t alignment, void *ptr)
{ self->ops->deallocate(self, size, alignment, ptr); }

#define ABYSS_ALLOCATOR_DEALLOCATE(self, count, ptr) \
    abyss_allocator_deallocate(self, \
        (count) * sizeof(*(ptr)), ABYSS_IMPL_ALIGNMENT_OF(*(ptr)), ptr)

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_allocator_release(abyss_allocator_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
