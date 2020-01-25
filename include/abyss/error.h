#ifndef ABYSS_INCLUDE_ERROR_H
#define ABYSS_INCLUDE_ERROR_H

#include <abyss/detail/api.h>

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////

typedef uint_fast16_t abyss_error;

#define ABYSS_UNKNOWN_ERROR       UINT16_C(1)
#define ABYSS_OUT_OF_MEMORY_ERROR UINT16_C(2)

ABYSS_DETAIL_API
char const *
abyss_get_error_name(abyss_error error);

///////////////////////////////////////////////////////////////////////////////

#endif
