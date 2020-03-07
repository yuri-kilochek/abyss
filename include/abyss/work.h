#ifndef ABYSS_IMPL_INCL_WORK_H
#define ABYSS_IMPL_INCL_WORK_H

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_work abyss_work_t;

struct abyss_work {
    void (*function)(void* context);
    void *context;
};

static inline
void abyss_work_do(abyss_work_t work) {
    work.function(work.context);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
