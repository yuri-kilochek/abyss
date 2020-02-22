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
typedef struct abyss_strand_provider abyss_strand_provider_t;
typedef struct abyss_strand_provider_type abyss_strand_provider_type_t;

struct abyss_strand {
    union {
        abyss_dispatcher_t base;
        void const *const type;
    };
    abyss_dispatcher_t *dispatcher;
};

struct abyss_strand_type {
    abyss_dispatcher_type_t base;
};

struct abyss_strand_provider {
    void const *const type;
};

struct abyss_strand_provider_type {
    abyss_error_t (*acquire)(abyss_strand_provider_t *provider,
                             abyss_strand_t **strand_out,
                             abyss_dispatcher_t *dispatcher,
                             abyss_allocator_t *allocator);

    void (*release)(abyss_strand_provider_t *provider,
                    abyss_strand_t *strand,
                    abyss_allocator_t *allocator);
};

static inline
abyss_error_t abyss_strand_acquire(abyss_strand_provider_t *provider,
                                   abyss_strand_t **strand_out,
                                   abyss_dispatcher_t *dispatcher,
                                   abyss_allocator_t *allocator)
{
    typedef abyss_strand_provider_type_t type_t;
    type_t const *type = (type_t const *) provider->type;
    return type->acquire(provider, strand_out, dispatcher, allocator);
}

static inline
void abyss_strand_release(abyss_strand_provider_t *provider,
                          abyss_strand_t *strand,
                          abyss_allocator_t *allocator)
{
    typedef abyss_strand_provider_type_t type_t;
    type_t const *type = (type_t const *) provider->type;
    type->release(provider, strand, allocator);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
