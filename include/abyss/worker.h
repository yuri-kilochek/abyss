#ifndef ABYSS_IMPL_INCL_WORKER_H
#define ABYSS_IMPL_INCL_WORKER_H

#include <abyss/work.h>
#include <abyss/handler.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_worker_ops abyss_worker_ops_t;
typedef struct abyss_worker abyss_worker_t;

struct abyss_worker_ops {
    void (*submit)(abyss_worker_t *self,
                   abyss_work_t work,
                   abyss_handler_t handler);

    void (*cancel)(abyss_worker_t *self);

    void (*release)(abyss_worker_t *self);
};

struct abyss_worker {
    abyss_worker_ops_t const *const ops;
};

static inline
void abyss_worker_submit(abyss_worker_t *self,
                         abyss_work_t work,
                         abyss_handler_t handler)
{ self->ops->submit(self, work, handler); }

static inline
void abyss_worker_cancel(abyss_worker_t *self) {
    if (!self) { return; }
    self->ops->cancel(self);
}

static inline
void abyss_worker_release(abyss_worker_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
