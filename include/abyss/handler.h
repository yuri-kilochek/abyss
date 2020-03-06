#ifndef ABYSS_INCLUDE_GUARD_HANDLER_H
#define ABYSS_INCLUDE_GUARD_HANDLER_H

#include <abyss/detail/extern_c.h>
#include <abyss/allocator.h>
#include <abyss/error.h>

#include <stddef.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_handler abyss_handler_t;

struct abyss_handler {
    abyss_allocator_t *allocator;
    void (*function)(void* context, abyss_error_t error);
    void *context;
};

static inline
void abyss_handler_invoke(abyss_handler_t *handler_ptr, abyss_error_t error) {
    if (!handler_ptr->function) { return; }
    handler_ptr->function(handler_ptr->context, error);
    handler_ptr->function = NULL;
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
