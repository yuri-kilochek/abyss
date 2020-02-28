#ifndef ABYSS_INCLUDE_GUARD_RANDOMIZER_H
#define ABYSS_INCLUDE_GUARD_RANDOMIZER_H

#include <abyss/detail/extern_c.h>
#include <abyss/error.h>
#include <abyss/allocator.h>
#include <abyss/dispatcher.h>

#include <stddef.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_randomizer abyss_randomizer_t;
typedef struct abyss_randomizer_type abyss_randomizer_type_t;

struct abyss_randomizer {
    void const *const type;
};

struct abyss_randomizer_type {
    void (*randomize)(abyss_randomizer_t *randomizer,
                      size_t byte_count, unsigned char *bytes,
                      abyss_allocator_t *allocator,
                      abyss_dispatcher_t *dispatcher,
                      void (*handler)(void *context, abyss_error_t error),
                      void *context);

    void (*interrupt)(abyss_randomizer_t *randomizer);
};

static inline
void abyss_randomizer_randomize(abyss_randomizer_t *randomizer,
                                size_t byte_count, unsigned char *bytes,
                                abyss_allocator_t *allocator,
                                abyss_dispatcher_t *dispatcher,
                                void (*handler)(void *context,
                                                abyss_error_t error),
                                void *context)
{
    typedef abyss_randomizer_type_t type_t;
    type_t const *type = (type_t const *) randomizer->type;
    type->randomize(randomizer,
                    byte_count, bytes,
                    allocator, dispatcher, handler, context);
}

static inline
void abyss_randomizer_interrupt(abyss_randomizer_t *randomizer) {
    typedef abyss_randomizer_type_t type_t;
    type_t const *type = (type_t const *) randomizer->type;
    type->interrupt(randomizer);
}

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
