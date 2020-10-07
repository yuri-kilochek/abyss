#ifndef ABYSS_IMPL_INCL_SYMBOL_H
#define ABYSS_IMPL_INCL_SYMBOL_H

#include <abyss/byte.h>
#include <abyss/impl/align_as.h>
#include <abyss/impl/always_inline.h>

#include <string.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_symbol abyss_symbol_t;

enum { ABYSS_IMPL_SYMBOL_SIZE = 16 };

struct abyss_symbol {
    ABYSS_IMPL_ALIGN_AS(ABYSS_IMPL_SYMBOL_SIZE)
    abyss_byte_t bytes[ABYSS_IMPL_SYMBOL_SIZE];
};

static inline ABYSS_IMPL_ALWAYS_INLINE
int abyss_symbol_compare(abyss_symbol_t a, abyss_symbol_t b) {
    return memcmp(a.bytes, b.bytes, ABYSS_IMPL_SYMBOL_SIZE);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
