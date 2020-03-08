#ifndef ABYSS_IMPL_INCL_STRAND_H
#define ABYSS_IMPL_INCL_STRAND_H

#include <abyss/dispatcher.h>
#include <abyss/allocator.h>

#include <stddef.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_strand abyss_strand_t;
typedef struct abyss_strand_type abyss_strand_type_t;

struct abyss_strand {
    union {
        void const *const type;
        abyss_dispatcher_t base_dispatcher;
    };
    abyss_allocator_t *const allocator;
    abyss_dispatcher_t *const dispatcher;
};

struct abyss_strand_type {
    abyss_dispatcher_type_t base_dispatcher;

    void (*release)(abyss_strand_t *strand);
};

static inline
void abyss_strand_release(abyss_strand_t *strand) {
    if (!strand) { return; }
    typedef abyss_strand_type_t type_t;
    type_t const *type = (type_t const *) strand->type;
    type->release(strand);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
