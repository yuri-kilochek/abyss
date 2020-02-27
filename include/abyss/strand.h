#ifndef ABYSS_INCLUDE_GUARD_STRAND_H
#define ABYSS_INCLUDE_GUARD_STRAND_H

#include <abyss/detail/extern_c.h>
#include <abyss/error.h>
#include <abyss/allocator.h>
#include <abyss/dispatcher.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_strand abyss_strand_t;
typedef struct abyss_strand_type abyss_strand_type_t;
typedef struct abyss_strand_factory abyss_strand_factory_t;
typedef struct abyss_strand_factory_type abyss_strand_factory_type_t;

struct abyss_strand {
    union {
        abyss_dispatcher_t base;
        void const *const type;
    };
    abyss_allocator_t *const allocator;
    abyss_dispatcher_t *const dispatcher;
};

struct abyss_strand_type {
    abyss_dispatcher_type_t base;

    void (*release)(abyss_strand_t *strand);
};

static inline
void abyss_strand_release(abyss_strand_t *strand) {
    typedef abyss_strand_type_t type_t;
    type_t const *type = (type_t const *) strand->type;
    type->release(strand);
}

struct abyss_strand_factory {
    void const *const type;
};

struct abyss_strand_factory_type {
    abyss_error_t (*create)(abyss_strand_factory_t *factory,
                            abyss_allocator_t *allocator,
                            abyss_dispatcher_t *dispatcher,
                            abyss_strand_t **strand_out);
};

static inline
abyss_error_t abyss_strand_create(abyss_strand_factory_t *factory,
                                  abyss_allocator_t *allocator,
                                  abyss_dispatcher_t *dispatcher,
                                  abyss_strand_t **strand_out)
{
    typedef abyss_strand_factory_type_t type_t;
    type_t const *type = (type_t const *) factory->type;
    return type->create(factory, allocator, dispatcher, strand_out);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
