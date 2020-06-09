#ifndef ABYSS_IMPL_INCL_STRAND_H
#define ABYSS_IMPL_INCL_STRAND_H

#include <abyss/error.h>
#include <abyss/callback.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_strand_ops abyss_strand_ops_t;
typedef struct abyss_strand abyss_strand_t;

struct abyss_strand_ops {
    void (*post)(abyss_strand_t *self,
                 abyss_callback_t callback,
                 abyss_error_t* error_out);

    void (*release)(abyss_strand_t *self);
};

struct abyss_strand {
    abyss_strand_ops_t const *const ops;
};

static inline
void abyss_strand_post(abyss_strand_t *self,
                       abyss_callback_t callback,
                       abyss_error_t* error_out)
{ self->ops->post(self, callback, error_out); }

static inline
void abyss_strand_release(abyss_strand_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
