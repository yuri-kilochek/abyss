#ifndef ABYSS_IMPL_INCL_ERROR_H
#define ABYSS_IMPL_INCL_ERROR_H

#include <abyss/impl/api.h>

#include <stdint.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef enum abyss_error {
    ABYSS_ERROR_NONE,

    ABYSS_ERROR_UNKNOWN,
    ABYSS_ERROR_OUT_OF_MEMORY,
    ABYSS_ERROR_CANCELED,

    ABYSS_IMPL_ERROR_STRUT = INT_FAST8_MAX
} abyss_error_t;

ABYSS_IMPL_API
char const *abyss_error_get_name(abyss_error_t error);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
