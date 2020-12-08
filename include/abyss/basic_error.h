#ifndef ABYSS_IMPL_INCL_BASIC_ERROR_H
#define ABYSS_IMPL_INCL_BASIC_ERROR_H

#include <abyss/error.h>

#include <abyss/impl/prolog.h>
///////////////////////////////////////////////////////////////////////////////

ABYSS_IMPL_API
abyss_error_t *abyss_new_basic_error(abyss_error_semantic_t semantic);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/impl/epilog.h>

#endif
