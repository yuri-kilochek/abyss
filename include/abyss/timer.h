#ifndef ABYSS_INCLUDE_GUARD_TIMER_H
#define ABYSS_INCLUDE_GUARD_TIMER_H

#include <abyss/detail/extern_c.h>
#include <abyss/nanoseconds.h>
#include <abyss/handler.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_timer abyss_timer_t;
typedef struct abyss_timer_type abyss_timer_type_t;

struct abyss_timer {
    void const *const type;
};

struct abyss_timer_type {
    void (*wait)(abyss_timer_t *timer,
                 abyss_nanoseconds_t duration,
                 abyss_handler_t complete_handler,
                 abyss_handler_t *cancel_handler_ptr);
};

static inline
void abyss_timer_wait(abyss_timer_t *timer,
                      abyss_nanoseconds_t duration,
                      abyss_handler_t complete_handler,
                      abyss_handler_t *cancel_handler_ptr)
{
    typedef abyss_timer_type_t type_t;
    type_t const *type = (type_t const *) timer->type;
    type->wait(timer, duration, complete_handler, cancel_handler_ptr);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
