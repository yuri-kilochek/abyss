#ifndef ABYSS_IMPL_INCL_TASK_H
#define ABYSS_IMPL_INCL_TASK_H

#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_task_type abyss_task_type_t;
typedef struct abyss_task abyss_task_t;

struct abyss_task_type {
    void (*delete_)(abyss_task_t *self);
};

struct abyss_task {
    abyss_task_type_t const *const type;

    void (*execute)(abyss_task_t* task);
    void *context;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_task_delete(abyss_task_t *self) {
    if (!self) { return; }
    self->type->delete_(self);
}

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_task_execute(abyss_task_t *self) {
    self->execute(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
