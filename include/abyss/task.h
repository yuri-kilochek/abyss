#ifndef ABYSS_DETAIL_INCLUDE_TASK_H
#define ABYSS_DETAIL_INCLUDE_TASK_H

#include <abyss/detail/always_inline.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_task_type abyss_task_type_t;
typedef struct abyss_task abyss_task_t;

struct abyss_task_type {
    void (*delete_)(abyss_task_t *self);
};

struct abyss_task {
    abyss_task_type_t const *const type;

    void (*function)(abyss_task_t* task);
    void *context;
};

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_task_delete(abyss_task_t *self) {
    if (!self) { return; }
    self->type->delete_(self);
}

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_task_execute(abyss_task_t *self) {
    self->function(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
