#ifndef ABYSS_IMPL_INCL_DISPATCHER_H
#define ABYSS_IMPL_INCL_DISPATCHER_H

#include <abyss/handler.h>

#include <abyss/impl/prolog.h>
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
#include <abyss/impl/epilog.h>

#endif
