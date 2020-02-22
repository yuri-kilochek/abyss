#ifndef ABYSS_INCLUDE_GUARD_DISPATCHER_H
#define ABYSS_INCLUDE_GUARD_DISPATCHER_H

#include <abyss/detail/extern_c.h>
#include <abyss/error.h>
#include <abyss/allocator.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_dispatcher abyss_dispatcher_t;
typedef struct abyss_dispatcher_type abyss_dispatcher_type_t;

struct abyss_dispatcher {
    void const *const type;
};

struct abyss_dispatcher_type {
    void (*dispatch)(abyss_dispatcher_t *dispatcher,
                     abyss_allocator_t *allocator,
                     void (*handler)(void *context, abyss_error_t error),
                     void *context);
};

static inline
void abyss_dispatcher_dispatch(abyss_dispatcher_t *dispatcher,
                               abyss_allocator_t *allocator,
                               void (*handler)(void *context,
                                               abyss_error_t error),
                               void *context)
{ 
    typedef abyss_dispatcher_type_t type_t;
    type_t const *type = (type_t const *) dispatcher->type;
    type->dispatch(dispatcher, allocator, handler, context);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
