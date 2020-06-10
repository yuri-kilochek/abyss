#ifndef ABYSS_IMPL_INCL_BYTE_H
#define ABYSS_IMPL_INCL_BYTE_H

#include <abyss/impl/static_assert.h>

#include <limits.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef unsigned char abyss_byte_t;

ABYSS_IMPL_STATIC_ASSERT(sizeof(abyss_byte_t) * CHAR_BIT == 8,
                         "byte must contain exactly eight bits");

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
