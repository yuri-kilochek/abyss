#ifndef ABYSS_IMPL_INCL_STRAND_H
#define ABYSS_IMPL_INCL_STRAND_H

#include <abyss/task.h>
#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_strand_type abyss_strand_type_t;
typedef struct abyss_strand abyss_strand_t;

struct abyss_strand_type {
    void (*delete_)(abyss_strand_t *self);
    void (*enqueue)(abyss_strand_t *self, abyss_task_t *task);
};

struct abyss_strand {
    abyss_strand_type_t const *const type;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_strand_delete(abyss_strand_t *self) {
    if (!self) { return; }
    self->type->delete_(self);
}

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_strand_enqueue(abyss_strand_t *self, abyss_task_t *task) {
    self->type->enqueue(self, task);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
