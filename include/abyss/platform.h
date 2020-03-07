#ifndef ABYSS_IMPL_INCL_PLATFORM_H
#define ABYSS_IMPL_INCL_PLATFORM_H

#include <abyss/allocator.h>
#include <abyss/dispatcher.h>
#include <abyss/worker.h>
#include <abyss/randomizer.h>
#include <abyss/strand.h>
#include <abyss/timer.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_platform abyss_platform_t;
typedef struct abyss_platform_type abyss_platform_type_t;

struct abyss_platform {
    void const *const type;

    abyss_allocator_t *const allocator;
    abyss_dispatcher_t *const dispatcher;
    abyss_worker_t *const worker;
    abyss_timer_t *const timer;
    abyss_randomizer_t *const randomizer;
};

struct abyss_platform_type {
    abyss_error_t (*create_strand)(abyss_platform_t *platform,
                                   abyss_strand_t **strand_out,
                                   abyss_allocator_t *allocator,
                                   abyss_dispatcher_t *dispatcher);
};

static inline
abyss_error_t abyss_platform_create_strand(abyss_platform_t *platform,
                                           abyss_strand_t **strand_out,
                                           abyss_allocator_t *allocator,
                                           abyss_dispatcher_t *dispatcher)
{
    typedef abyss_platform_type_t type_t;
    type_t const *type = (type_t const *) platform->type;
    return type->create_strand(platform, strand_out, allocator, dispatcher);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
