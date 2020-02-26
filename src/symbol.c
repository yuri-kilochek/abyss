#include <abyss/symbol.h>

#include <limits.h>

///////////////////////////////////////////////////////////////////////////////

size_t abyss_symbol_hash(abyss_symbol_t symbol) {
    size_t hash = symbol.bytes[0];
    for (size_t i = 1; i < sizeof(symbol.bytes); ++i) {
        hash = hash << CHAR_BIT
             | hash >> CHAR_BIT * (sizeof(hash) - 1); // rotate left
        hash ^= symbol.bytes[i];
    }
    return hash;
}
