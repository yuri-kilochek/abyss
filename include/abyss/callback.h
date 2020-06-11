#ifndef ABYSS_IMPL_INCL_CALLBACK_H
#define ABYSS_IMPL_INCL_CALLBACK_H

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_callback abyss_callback_t;

struct abyss_callback {
    void (*function)(void *context);
    void *context;
};

static inline
void abyss_callback_invoke(abyss_callback_t self) {
    self.function(self.context);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
