#ifndef ABYSS_IMPL_INCL_TASK_H
#define ABYSS_IMPL_INCL_TASK_H

#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_task abyss_task_t;

struct abyss_task {
    void (*function)(void *context);
    void *context;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_task_invoke(abyss_task_t self) {
    self.function(self.context);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
