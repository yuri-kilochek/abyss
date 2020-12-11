#ifndef ABYSS_DETAIL_INCLUDE_SYMBOL_H
#define ABYSS_DETAIL_INCLUDE_SYMBOL_H

#include <abyss/byte.h>
#include <abyss/detail/align_as.h>
#include <abyss/detail/always_inline.h>

#include <string.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_symbol abyss_symbol_t;

enum { ABYSS_DETAIL_SYMBOL_SIZE = 16 };

struct abyss_symbol {
    ABYSS_DETAIL_ALIGN_AS(ABYSS_DETAIL_SYMBOL_SIZE)
    abyss_byte_t bytes[ABYSS_DETAIL_SYMBOL_SIZE];
};

static inline ABYSS_DETAIL_ALWAYS_INLINE
int abyss_symbol_compare(abyss_symbol_t a, abyss_symbol_t b) {
    return memcmp(a.bytes, b.bytes, ABYSS_DETAIL_SYMBOL_SIZE);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
