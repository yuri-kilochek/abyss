#ifndef ABYSS_INCLUDE_GUARD_WORKER_H
#define ABYSS_INCLUDE_GUARD_WORKER_H

#include <abyss/detail/extern_c.h>
#include <abyss/error.h>
#include <abyss/allocator.h>
#include <abyss/dispatcher.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_worker abyss_worker_t;
typedef struct abyss_worker_type abyss_worker_type_t;

struct abyss_worker {
    void const *const type;
};

struct abyss_worker_type {
    void (*work)(abyss_worker_t *worker,
                 void (*work)(void *context), void *work_context,
                 abyss_allocator_t *allocator,
                 abyss_dispatcher_t *dispatcher,
                 void (*handler)(void *context, abyss_error_t error),
                 void *context);
};

static inline
void abyss_worker_work(abyss_worker_t *worker,
                       void (*work)(void *context), void *work_context,
                       abyss_allocator_t *allocator,
                       abyss_dispatcher_t *dispatcher,
                       void (*handler)(void *context, abyss_error_t error),
                       void *context)
{ 
    typedef abyss_worker_type_t type_t;
    type_t const *type = (type_t const *) worker->type;
    type->work(worker,
               work, work_context, allocator, dispatcher, handler, context);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
