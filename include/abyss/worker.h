#ifndef ABYSS_IMPL_INCL_WORKER_H
#define ABYSS_IMPL_INCL_WORKER_H

#include <abyss/task.h>
#include <abyss/handler.h>
#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_worker_type abyss_worker_type_t;
typedef struct abyss_worker abyss_worker_t;

struct abyss_worker_type {
    void (*delete_)(abyss_worker_t *self);

    void (*enqueue)(abyss_worker_t *self,
        abyss_task_t task, abyss_handler_t handler);

    void (*try_cancel)(abyss_worker_t *self);
};

struct abyss_worker {
    abyss_worker_type_t const *const type;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_worker_delete(abyss_worker_t *self) {
    if (!self) { return; }
    self->type->delete_(self);
}

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_worker_enqueue(abyss_worker_t *self,
    abyss_task_t task, abyss_handler_t handler)
{ self->type->enqueue(self, task, handler); }

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_worker_try_cancel(abyss_worker_t *self) {
    self->type->try_cancel(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
