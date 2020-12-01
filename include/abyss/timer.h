#ifndef ABYSS_IMPL_INCL_TIMER_H
#define ABYSS_IMPL_INCL_TIMER_H

#include <abyss/error.h>
#include <abyss/microseconds.h>
#include <abyss/handler.h>
#include <abyss/impl/always_inline.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_timer_type abyss_timer_type_t;
typedef struct abyss_timer abyss_timer_t;

struct abyss_timer_type {
    void (*release)(abyss_timer_t *self);

    void (*wait)(abyss_timer_t *self,
        abyss_microseconds_t duration, abyss_handler_t handler);

    void (*try_cancel)(abyss_timer_t *self);
};

struct abyss_timer {
    abyss_timer_type_t const *const type;
};

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_timer_release(abyss_timer_t *self) {
    if (!self) { return; }
    self->type->release(self);
}

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_timer_wait(abyss_timer_t *self,
    abyss_microseconds_t duration, abyss_handler_t handler)
{ self->type->wait(self, duration, handler); }

static inline ABYSS_IMPL_ALWAYS_INLINE
void abyss_timer_try_cancel(abyss_timer_t *self) {
    self->type->try_cancel(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
