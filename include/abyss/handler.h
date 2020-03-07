#ifndef ABYSS_INCLUDE_GUARD_HANDLER_H
#define ABYSS_INCLUDE_GUARD_HANDLER_H

#include <abyss/allocator.h>
#include <abyss/error.h>

#include <stddef.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_handler abyss_handler_t;

struct abyss_handler {
    abyss_allocator_t *allocator;
    void (*function)(void* context, abyss_error_t error);
    void *context;
};

#define ABYSS_NULL_HANDLER (abyss_handler_t) {0}

static inline
void abyss_handler_invoke(abyss_handler_t *handler_ptr, abyss_error_t error) {
    if (!handler_ptr->function) { return; }
    handler_ptr->function(handler_ptr->context, error);
    *handler_ptr = ABYSS_NULL_HANDLER;
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
