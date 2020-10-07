#ifndef ABYSS_IMPL_INCL_PLATFORM_H
#define ABYSS_IMPL_INCL_PLATFORM_H

#include <abyss/error.h>
#include <abyss/allocator.h>
#include <abyss/strand.h>
#include <abyss/timer.h>
#include <abyss/worker.h>
#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_platform_ops abyss_platform_ops_t;
typedef struct abyss_platform abyss_platform_t;

struct abyss_platform_ops {
    abyss_error_t (*acquire_allocator)(abyss_platform_t *self,
        abyss_allocator_t **allocator_out);

    abyss_error_t (*acquire_strand)(abyss_platform_t *self,
        abyss_allocator_t *allocator, abyss_strand_t **strand_out);

    abyss_error_t (*acquire_timer)(abyss_platform_t *self,
        abyss_allocator_t *allocator, abyss_timer_t **timer_out);

    abyss_error_t (*acquire_worker)(abyss_platform_t *self,
        abyss_allocator_t *allocator, abyss_worker_t **worker_out);
};

struct abyss_platform {
    abyss_platform_ops_t const *const ops;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
abyss_error_t abyss_platform_acquire_allocator(abyss_platform_t *self,
    abyss_allocator_t **allocator_out)
{ return self->ops->acquire_allocator(self, allocator_out); }

static inline ABYSS_IMPL_ALWAYS_INLINE
abyss_error_t abyss_platform_acquire_strand(abyss_platform_t *self,
    abyss_allocator_t *allocator, abyss_strand_t **strand_out)
{ return self->ops->acquire_strand(self, allocator, strand_out); }

static inline ABYSS_IMPL_ALWAYS_INLINE
abyss_error_t abyss_platform_acquire_timer(abyss_platform_t *self,
    abyss_allocator_t *allocator, abyss_timer_t **timer_out)
{ return self->ops->acquire_timer(self, allocator, timer_out); }

static inline ABYSS_IMPL_ALWAYS_INLINE
abyss_error_t abyss_platform_acquire_worker(abyss_platform_t *self,
    abyss_allocator_t *allocator, abyss_worker_t **worker_out)
{ return self->ops->acquire_worker(self, allocator, worker_out); }

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
