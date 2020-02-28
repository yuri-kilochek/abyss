#ifndef ABYSS_INCLUDE_GUARD_TIMER_H
#define ABYSS_INCLUDE_GUARD_TIMER_H

#include <abyss/detail/extern_c.h>
#include <abyss/error.h>
#include <abyss/allocator.h>
#include <abyss/dispatcher.h>
#include <abyss/nanoseconds.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_timer abyss_timer_t;
typedef struct abyss_timer_type abyss_timer_type_t;

struct abyss_timer {
    void const *const type;

    abyss_allocator_t *const allocator;
};

struct abyss_timer_type {
    void (*release)(abyss_timer_t *timer);

    void (*wait)(abyss_timer_t *timer,
                 abyss_nanoseconds_t duration,
                 abyss_allocator_t *allocator,
                 abyss_dispatcher_t *dispatcher,
                 void (*handler)(void *context, abyss_error_t error),
                 void *context);

    void (*interrupt)(abyss_timer_t *timer);
};

static inline
void abyss_timer_release(abyss_timer_t *timer) {
    typedef abyss_timer_type_t type_t;
    type_t const *type = (type_t const *) timer->type;
    type->release(timer);
}

static inline
void abyss_timer_wait(abyss_timer_t *timer,
                      abyss_nanoseconds_t duration,
                      abyss_allocator_t *allocator,
                      abyss_dispatcher_t *dispatcher,
                      void (*handler)(void *context, abyss_error_t error),
                      void *context)
{
    typedef abyss_timer_type_t type_t;
    type_t const *type = (type_t const *) timer->type;
    type->wait(timer, duration, allocator, dispatcher, handler, context);
}

static inline
void abyss_timer_interrupt(abyss_timer_t *timer) {
    typedef abyss_timer_type_t type_t;
    type_t const *type = (type_t const *) timer->type;
    type->interrupt(timer);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
