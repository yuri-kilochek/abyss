#ifndef ABYSS_IMPL_INCL_SYMBOL_H
#define ABYSS_IMPL_INCL_SYMBOL_H

#include <abyss/impl/api.h>
#include <abyss/impl/align_as.h>

#include <limits.h>
#include <string.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_symbol abyss_symbol_t;

enum { ABYSS_IMPL_SYMBOL_SIZE = (128 + CHAR_BIT - 1) / CHAR_BIT };

struct abyss_symbol {
    ABYSS_IMPL_ALIGN_AS(ABYSS_IMPL_SYMBOL_SIZE)
    unsigned char bytes[ABYSS_IMPL_SYMBOL_SIZE];
};

static inline
int abyss_symbol_compare(abyss_symbol_t a, abyss_symbol_t b) {
    return memcmp(a.bytes, b.bytes, ABYSS_IMPL_SYMBOL_SIZE);
}

ABYSS_IMPL_API
size_t abyss_symbol_hash(abyss_symbol_t symbol);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
