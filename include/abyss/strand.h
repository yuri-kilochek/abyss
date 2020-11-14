#ifndef ABYSS_IMPL_INCL_STRAND_H
#define ABYSS_IMPL_INCL_STRAND_H

#include <abyss/task.h>
#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_strand_ops abyss_strand_ops_t;
typedef struct abyss_strand abyss_strand_t;

struct abyss_strand_ops {
    void (*enqueue)(abyss_strand_t *self, abyss_task_t *task);
    void (*release)(abyss_strand_t *self);
};

struct abyss_strand {
    abyss_strand_ops_t const *const ops;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_strand_enqueue(abyss_strand_t *self, abyss_task_t *task) {
    self->ops->enqueue(self, task);
}

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_strand_release(abyss_strand_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
