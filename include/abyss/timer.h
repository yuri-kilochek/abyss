#ifndef ABYSS_IMPL_INCL_TIMER_H
#define ABYSS_IMPL_INCL_TIMER_H

#include <abyss/error.h>
#include <abyss/microseconds.h>
#include <abyss/callback.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_timer_ops abyss_timer_ops_t;
typedef struct abyss_timer abyss_timer_t;

struct abyss_timer_ops {
    void (*wait)(abyss_timer_t *self,
                 abyss_microseconds_t duration,
                 abyss_error_t *error_out,
                 abyss_callback_t callback);

    void (*try_cancel)(abyss_timer_t *self);

    void (*release)(abyss_timer_t *self);
};

struct abyss_timer {
    abyss_timer_ops_t const *const ops;
};

static inline
void abyss_timer_wait(abyss_timer_t *self,
                      abyss_microseconds_t duration,
                      abyss_error_t *error_out,
                      abyss_callback_t callback)
{ self->ops->wait(self, duration, error_out, callback); }

static inline
void abyss_timer_try_cancel(abyss_timer_t *self) {
    self->ops->try_cancel(self);
}

static inline
void abyss_timer_release(abyss_timer_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
