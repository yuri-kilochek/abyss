#ifndef ABYSS_INCLUDE_GUARD_SYMBOL_H
#define ABYSS_INCLUDE_GUARD_SYMBOL_H

#include <abyss/detail/extern_c.h>
#include <abyss/detail/api.h>
#include <abyss/detail/align_as.h>

#include <stdint.h>
#include <string.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_symbol abyss_symbol_t;

struct abyss_symbol {
    ABYSS_DETAIL_ALIGN_AS(16)
    unsigned char bytes[16];
};

static inline
int_fast8_t abyss_symbol_compare(abyss_symbol_t a, abyss_symbol_t b) {
    int r = memcmp(a.bytes, b.bytes, 16);
    if (r < 0) { return -1; }
    if (r > 0) { return +1; }
    return 0;
}

ABYSS_DETAIL_API
size_t abyss_symbol_hash(abyss_symbol_t symbol);

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
