#ifndef ABYSS_INCLUDE_GUARD_DISPATCHER_H
#define ABYSS_INCLUDE_GUARD_DISPATCHER_H

#include <abyss/detail/extern_c.h>
#include <abyss/handler.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_dispatcher abyss_dispatcher_t;
typedef struct abyss_dispatcher_type abyss_dispatcher_type_t;

struct abyss_dispatcher {
    void const *const type;
};

struct abyss_dispatcher_type {
    void (*submit)(abyss_dispatcher_t *dispatcher, abyss_handler_t handler);
};

static inline
void abyss_dispatcher_submit(abyss_dispatcher_t *dispatcher,
                             abyss_handler_t handler)
{ 
    typedef abyss_dispatcher_type_t type_t;
    type_t const *type = (type_t const *) dispatcher->type;
    type->submit(dispatcher, handler);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
