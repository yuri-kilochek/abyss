#ifndef ABYSS_DETAIL_INCLUDE_BASIC_ERROR_H
#define ABYSS_DETAIL_INCLUDE_BASIC_ERROR_H

#include <abyss/error.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

ABYSS_DETAIL_API
abyss_error_t *abyss_new_basic_error(abyss_error_semantic_t semantic);

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
