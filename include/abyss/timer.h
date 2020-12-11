#ifndef ABYSS_DETAIL_INCLUDE_TIMER_H
#define ABYSS_DETAIL_INCLUDE_TIMER_H

#include <abyss/error.h>
#include <abyss/microseconds.h>
#include <abyss/handler.h>
#include <abyss/detail/always_inline.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_timer_type abyss_timer_type_t;
typedef struct abyss_timer abyss_timer_t;

struct abyss_timer_type {
    void (*delete_)(abyss_timer_t *self);

    void (*wait)(abyss_timer_t *self,
        abyss_microseconds_t duration, abyss_handler_t *handler);

    void (*try_cancel)(abyss_timer_t *self);
};

struct abyss_timer {
    abyss_timer_type_t const *const type;
};

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_timer_delete(abyss_timer_t *self) {
    if (!self) { return; }
    self->type->delete_(self);
}

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_timer_wait(abyss_timer_t *self,
    abyss_microseconds_t duration, abyss_handler_t *handler)
{ self->type->wait(self, duration, handler); }

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_timer_try_cancel(abyss_timer_t *self) {
    self->type->try_cancel(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
