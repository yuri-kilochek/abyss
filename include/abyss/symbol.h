#ifndef ABYSS_IMPL_INCL_SYMBOL_H
#define ABYSS_IMPL_INCL_SYMBOL_H

#include <abyss/impl/api.h>
#include <abyss/impl/align_as.h>

#include <stdint.h>
#include <string.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_symbol abyss_symbol_t;

enum { ABYSS_IMPL_SYMBOL_SIZE = 16 };

struct abyss_symbol {
    ABYSS_IMPL_ALIGN_AS(ABYSS_IMPL_SYMBOL_SIZE)
    unsigned char bytes[ABYSS_IMPL_SYMBOL_SIZE];
};

static inline
int_fast8_t abyss_symbol_compare(abyss_symbol_t a, abyss_symbol_t b) {
    int r = memcmp(a.bytes, b.bytes, ABYSS_IMPL_SYMBOL_SIZE);
    if (r < 0) { return -1; }
    if (r > 0) { return +1; }
    return 0;
}

ABYSS_IMPL_API
size_t abyss_symbol_hash(abyss_symbol_t symbol);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
