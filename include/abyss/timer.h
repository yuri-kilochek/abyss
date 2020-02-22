#ifndef ABYSS_INCLUDE_GUARD_TIMER_H
#define ABYSS_INCLUDE_GUARD_TIMER_H

#include <abyss/detail/extern_c.h>
#include <abyss/error.h>
#include <abyss/allocator.h>
#include <abyss/dispatcher.h>
#include <abyss/nanoseconds.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_time abyss_timer_t;
typedef struct abyss_timer_type abyss_timer_type_t;
typedef struct abyss_timer_provider abyss_timer_provider_t;
typedef struct abyss_timer_provider_type abyss_timer_provider_type_t;

struct abyss_timer {
    void const *const type;
};

struct abyss_timer_type {
    void (*wait)(abyss_timer_t *timer,
                 abyss_nanoseconds_t duration,
                 abyss_allocator_t *allocator,
                 abyss_dispatcher_t *dispatcher,
                 void (*handler)(void *context, abyss_error_t error),
                 void *context);

    void (*interrupt)(abyss_timer_t *timer);
};

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

struct abyss_timer_provider {
    void const *const type;
};

struct abyss_timer_provider_type {
    abyss_error_t (*acquire)(abyss_timer_provider_t *provider,
                             abyss_timer_t **timer_out,
                             abyss_dispatcher_t *dispatcher,
                             abyss_allocator_t *allocator);

    void (*release)(abyss_timer_provider_t *provider,
                    abyss_timer_t *timer,
                    abyss_allocator_t *allocator);
};

static inline
abyss_error_t abyss_timer_acquire(abyss_timer_provider_t *provider,
                                  abyss_timer_t **timer_out,
                                  abyss_allocator_t *allocator)
{
    typedef abyss_timer_provider_type_t type_t;
    type_t const *type = (type_t const *) provider->type;
    return type->acquire(provider, timer_out, allocator);
}

static inline
void abyss_timer_release(abyss_timer_provider_t *provider,
                         abyss_timer_t *timer,
                         abyss_allocator *allocator)
{
    typedef abyss_timer_provider_type_t type_t;
    type_t const *type = (type_t const *) provider->type;
    type->release(provider, timer, allocator);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
