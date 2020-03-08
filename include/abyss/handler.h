#ifndef ABYSS_IMPL_INCL_HANDLER_H
#define ABYSS_IMPL_INCL_HANDLER_H

#include <abyss/allocator.h>
#include <abyss/error.h>

#include <stddef.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_handler abyss_handler_t;

struct abyss_handler {
    void (*function)(void* context, abyss_error_t error);
    void *context;
    abyss_allocator_t *allocator;
};

#define ABYSS_NULL_HANDLER (abyss_handler_t) {NULL}

static inline
void abyss_handler_invoke(abyss_handler_t handler, abyss_error_t error) {
    if (!handler.function) { return; }
    handler.function(handler.context, error);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
