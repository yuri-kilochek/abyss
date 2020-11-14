#ifndef ABYSS_IMPL_INCL_TASK_H
#define ABYSS_IMPL_INCL_TASK_H

#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_task_ops abyss_task_ops_t;
typedef struct abyss_task abyss_task_t;

struct abyss_task_ops {
    void (*release)(abyss_task_t *self);
};

struct abyss_task {
    abyss_task_ops_t const *const ops;

    void (*execute)(abyss_task_t* task);
    void *context;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_task_execute(abyss_task_t *self) {
    self->execute(self);
}

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_task_release(abyss_task_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
