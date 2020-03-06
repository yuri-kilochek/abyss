#ifndef ABYSS_INCLUDE_GUARD_WORK_H
#define ABYSS_INCLUDE_GUARD_WORK_H

#include <abyss/detail/extern_c.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
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
ABYSS_DETAIL_EXTERN_C_END

#endif
