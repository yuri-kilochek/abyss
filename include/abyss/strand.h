#ifndef ABYSS_IMPL_INCL_STRAND_H
#define ABYSS_IMPL_INCL_STRAND_H

#include <abyss/error.h>
#include <abyss/handler.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_strand_ops abyss_strand_ops_t;
typedef struct abyss_strand abyss_strand_t;

struct abyss_strand_ops {
    void (*post)(abyss_strand_t *self,
                 abyss_handler_t handler, abyss_error_t error);

    void (*release)(abyss_strand_t *self);
};

struct abyss_strand {
    abyss_strand_ops_t const *const ops;
};

static inline
void abyss_strand_post(abyss_strand_t *self,
                       abyss_handler_t handler, abyss_error_t error)
{ self->ops->post(self, handler, error); }

static inline
void abyss_strand_release(abyss_strand_t *self) {
    if (!self) { return; }
    self->ops->release(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
