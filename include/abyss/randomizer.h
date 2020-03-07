#ifndef ABYSS_INCLUDE_GUARD_RANDOMIZER_H
#define ABYSS_INCLUDE_GUARD_RANDOMIZER_H

#include <abyss/handler.h>

#include <stddef.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_randomizer abyss_randomizer_t;
typedef struct abyss_randomizer_type abyss_randomizer_type_t;

struct abyss_randomizer {
    void const *const type;
};

struct abyss_randomizer_type {
    void (*get_bytes)(abyss_randomizer_t *randomizer,
                      size_t byte_count, unsigned char *bytes,
                      abyss_handler_t complete_handler,
                      abyss_handler_t *cancel_handler_ptr);
};

static inline
void abyss_randomizer_get_bytes(abyss_randomizer_t *randomizer,
                                size_t byte_count, unsigned char *bytes,
                                abyss_handler_t complete_handler,
                                abyss_handler_t *cancel_handler_ptr)
{
    typedef abyss_randomizer_type_t type_t;
    type_t const *type = (type_t const *) randomizer->type;
    type->get_bytes(randomizer,
                    byte_count, bytes,
                    complete_handler, cancel_handler_ptr);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
