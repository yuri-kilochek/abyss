#ifndef ABYSS_DETAIL_INCLUDE_HANDLER_H
#define ABYSS_DETAIL_INCLUDE_HANDLER_H

#include <abyss/error.h>
#include <abyss/strand.h>
#include <abyss/detail/always_inline.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_handler abyss_handler_t;

struct abyss_handler {
    abyss_task_t *task;
    abyss_strand_t *strand;
    abyss_error_t *error;
    void (*function)(abyss_handler_t *handler);
    void *context;
};

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_handler_delete(abyss_handler_t *self) {
    if (!self) { return; }
    abyss_task_delete(self->task);
}

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_handler_enqueue(abyss_handler_t *self) {
    abyss_strand_enqueue(self->strand, self->task);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
