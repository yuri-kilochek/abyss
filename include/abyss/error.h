#ifndef ABYSS_INCLUDE_GUARD_ERROR_H
#define ABYSS_INCLUDE_GUARD_ERROR_H

#include <abyss/detail/api.h>

#include <stdint.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef enum abyss_error {
    ABYSS_ERROR_NONE,
    #define ABYSS_ERROR_NONE ABYSS_ERROR_NONE

    ABYSS_ERROR_UNKNOWN,
    #define ABYSS_ERROR_UNKNOWN ABYSS_ERROR_UNKNOWN

    ABYSS_ERROR_CANCELLED,
    #define ABYSS_ERROR_CANCELLED ABYSS_ERROR_CANCELLED

    ABYSS_ERROR_OUT_OF_MEMORY,
    #define ABYSS_ERROR_OUT_OF_MEMORY ABYSS_ERROR_OUT_OF_MEMORY

    ABYSS_DETAIL_ERROR_STRUT = INT_FAST8_MAX
} abyss_error_t;

ABYSS_DETAIL_API
char const *abyss_error_get_name(abyss_error_t error);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
