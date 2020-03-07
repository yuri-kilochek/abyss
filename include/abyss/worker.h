#ifndef ABYSS_INCLUDE_GUARD_WORKER_H
#define ABYSS_INCLUDE_GUARD_WORKER_H

#include <abyss/work.h>
#include <abyss/handler.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_worker abyss_worker_t;
typedef struct abyss_worker_type abyss_worker_type_t;

struct abyss_worker {
    void const *const type;
};

struct abyss_worker_type {
    void (*submit)(abyss_worker_t *worker,
                   abyss_work_t work,
                   abyss_handler_t complete_handler,
                   abyss_handler_t *cancel_handler_ptr);
};

static inline
void abyss_worker_submit(abyss_worker_t *worker,
                         abyss_work_t work,
                         abyss_handler_t complete_handler,
                         abyss_handler_t *cancel_handler_ptr)
{
    typedef abyss_worker_type_t type_t;
    type_t const *type = (type_t const *) worker->type;
    type->submit(worker, work, complete_handler, cancel_handler_ptr);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
