#ifndef ABYSS_IMPL_INCL_HANDLER_H
#define ABYSS_IMPL_INCL_HANDLER_H

#include <abyss/error.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_handler abyss_handler_t;

struct abyss_handler {
    void (*function)(void *context, abyss_error_t error);
    void *context;
};

static inline
void abyss_handler_invoke(abyss_handler_t self, abyss_error_t error) {
    self.function(self.context, error);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
