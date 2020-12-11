#ifndef ABYSS_DETAIL_INCLUDE_PLATFORM_H
#define ABYSS_DETAIL_INCLUDE_PLATFORM_H

#include <stddef.h>

#include <abyss/error.h>
#include <abyss/allocator.h>
#include <abyss/task.h>
#include <abyss/handler.h>
#include <abyss/strand.h>
#include <abyss/timer.h>
#include <abyss/worker.h>
#include <abyss/detail/always_inline.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_platform_type abyss_platform_type_t;
typedef struct abyss_platform abyss_platform_t;

struct abyss_platform_type {
    abyss_error_t *(*new_task)(abyss_platform_t *self,
        abyss_allocator_t *allocator,
        size_t context_size, size_t context_alignment,
        abyss_task_t **task_out);

    abyss_error_t *(*new_strand)(abyss_platform_t *self,
        abyss_allocator_t *allocator, abyss_strand_t **strand_out);

    abyss_error_t *(*new_timer)(abyss_platform_t *self,
        abyss_allocator_t *allocator, abyss_timer_t **timer_out);

    abyss_error_t *(*new_worker)(abyss_platform_t *self,
        abyss_allocator_t *allocator, abyss_worker_t **worker_out);
};

struct abyss_platform {
    abyss_platform_type_t const *const type;

    abyss_allocator_t *allocator;
};

static inline ABYSS_DETAIL_ALWAYS_INLINE
abyss_error_t *abyss_platform_new_task(abyss_platform_t *self,
    abyss_allocator_t *allocator,
    size_t context_size, size_t context_alignment,
    abyss_task_t **task_out)
{
    return self->type->new_task(self,
        allocator, context_size, context_alignment, task_out);
}

ABYSS_DETAIL_API
abyss_error_t *abyss_platform_new_handler(abyss_platform_t *self,
    abyss_allocator_t *allocator,
    size_t context_size, size_t context_alignment,
    abyss_handler_t **handler_out);

static inline ABYSS_DETAIL_ALWAYS_INLINE
abyss_error_t *abyss_platform_new_strand(abyss_platform_t *self,
    abyss_allocator_t *allocator, abyss_strand_t **strand_out)
{ return self->type->new_strand(self, allocator, strand_out); }

static inline ABYSS_DETAIL_ALWAYS_INLINE
abyss_error_t *abyss_platform_new_timer(abyss_platform_t *self,
    abyss_allocator_t *allocator, abyss_timer_t **timer_out)
{ return self->type->new_timer(self, allocator, timer_out); }

static inline ABYSS_DETAIL_ALWAYS_INLINE
abyss_error_t *abyss_platform_new_worker(abyss_platform_t *self,
    abyss_allocator_t *allocator, abyss_worker_t **worker_out)
{ return self->type->new_worker(self, allocator, worker_out); }

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
