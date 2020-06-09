#ifndef ABYSS_IMPL_INCL_WORKER_H
#define ABYSS_IMPL_INCL_WORKER_H

#include <abyss/error.h>
#include <abyss/callback.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_worker_ops abyss_worker_ops_t;
typedef struct abyss_worker abyss_worker_t;

struct abyss_worker_ops {
    void (*post)(abyss_worker_t *self,
                 abyss_callback_t task,
                 abyss_error_t *error_out,
                 abyss_callback_t callback);

    void (*try_cancel)(abyss_worker_t *self);

    void (*release)(abyss_worker_t *self);
};

struct abyss_worker {
    abyss_worker_ops_t const *const ops;
};

static inline
void abyss_worker_post(abyss_worker_t *self,
                       abyss_callback_t task,
                       abyss_error_t *error_out,
                       abyss_callback_t callback)
{ self->ops->post(self, task, error_out, callback); }

static inline
void abyss_worker_try_cancel(abyss_worker_t *self) {
    self->ops->try_cancel(self);
}

static inline
void abyss_worker_release(abyss_worker_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
