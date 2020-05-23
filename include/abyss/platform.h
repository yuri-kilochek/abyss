#ifndef ABYSS_IMPL_INCL_PLATFORM_H
#define ABYSS_IMPL_INCL_PLATFORM_H

#include <abyss/allocator.h>
#include <abyss/strand.h>
#include <abyss/timer.h>
#include <abyss/worker.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_platform_ops abyss_platform_ops_t;
typedef struct abyss_platform abyss_platform_t;

struct abyss_platform_ops {
    abyss_allocator_t *(*get_allocator)(abyss_platform_t *self);

    abyss_strand_t *(*create_strand)(abyss_platform_t *self,
                                     abyss_allocator_t *allocator,
                                     abyss_error_t *error_out);

    abyss_timer_t *(*create_timer)(abyss_platform_t *self,
                                   abyss_allocator_t *allocator,
                                   abyss_error_t *error_out);

    abyss_worker_t *(*create_worker)(abyss_platform_t *self,
                                     abyss_allocator_t *allocator,
                                     abyss_error_t *error_out);
};

struct abyss_platform {
    abyss_platform_ops_t const *const ops;
};

static inline
abyss_allocator_t *abyss_platform_get_allocator(abyss_platform_t *self) {
    return self->ops->get_allocator(self);
}

static inline
abyss_strand_t *abyss_platform_create_strand(abyss_platform_t *self,
                                             abyss_allocator_t *allocator,
                                             abyss_error_t *error_out)
{ return self->ops->create_strand(self, allocator, error_out); }

static inline
abyss_timer_t *abyss_platform_create_timer(abyss_platform_t *self,
                                           abyss_allocator_t *allocator,
                                           abyss_error_t *error_out)
{ return self->ops->create_timer(self, allocator, error_out); }

static inline
abyss_worker_t *abyss_platform_create_worker(abyss_platform_t *self,
                                             abyss_allocator_t *allocator,
                                             abyss_error_t *error_out)
{ return self->ops->create_worker(self, allocator, worker); }

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
