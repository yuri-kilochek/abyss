#ifndef ABYSS_IMPL_INCL_TIMER_H
#define ABYSS_IMPL_INCL_TIMER_H

#include <abyss/nanoseconds.h>
#include <abyss/handler.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_timer_ops abyss_timer_ops_t;
typedef struct abyss_timer abyss_timer_t;

struct abyss_timer_ops {
    void (*wait)(abyss_timer_t *self,
                 abyss_nanoseconds_t duration,
                 abyss_handler_t handler);

    void (*cancel)(abyss_timer_t *self);

    void (*release)(abyss_timer_t *self);
};

struct abyss_timer {
    abyss_timer_ops_t const *const ops;
};

static inline
void abyss_timer_wait(abyss_timer_t *self,
                      abyss_nanoseconds_t duration,
                      abyss_handler_t handler)
{ self->ops->wait(self, duration, handler); }

static inline
void abyss_timer_cancel(abyss_timer_t *self) {
    if (!self) { return; }
    self->ops->cancel(self);
}

static inline
void abyss_timer_release(abyss_timer_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
