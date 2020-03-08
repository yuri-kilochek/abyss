#ifndef ABYSS_IMPL_INCL_WORK_H
#define ABYSS_IMPL_INCL_WORK_H

#include <stddef.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_work abyss_work_t;

struct abyss_work {
    void (*function)(void* context);
    void *context;
};

#define ABYSS_NULL_WORK (abyss_work_t) {NULL}

static inline
void abyss_work_do(abyss_work_t work) {
    if (!work.function) { return; }
    work.function(work.context);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
