#ifndef ABYSS_INCLUDE_GUARD_WORK_H
#define ABYSS_INCLUDE_GUARD_WORK_H

#include <abyss/detail/prolog.h>
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
#include <abyss/detail/epilog.h>

#endif
