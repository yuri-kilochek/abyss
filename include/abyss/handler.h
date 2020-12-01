#ifndef ABYSS_IMPL_INCL_HANDLER_H
#define ABYSS_IMPL_INCL_HANDLER_H

#include <abyss/error.h>
#include <abyss/strand.h>
#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_handler abyss_handler_t;

struct abyss_handler {
    abyss_task_t *task;
    abyss_strand_t *strand;
    abyss_error_t *error;
    void (*execute)(abyss_handler_t *handler);
    void *context;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_handler_release(abyss_handler_t *self) {
    if (!self) { return; }
    abyss_task_release(self->task);
}

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_handler_enqueue(abyss_handler_t *self) {
    abyss_strand_enqueue(self->strand, self->task);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
