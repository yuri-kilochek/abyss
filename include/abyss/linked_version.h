#ifndef ABYSS_INCLUDE_GUARD_LINKED_VERSION_H
#define ABYSS_INCLUDE_GUARD_LINKED_VERSION_H

#include <abyss/detail/extern_c.h>
#include <abyss/detail/api.h>
#include <abyss/version.h>

ABYSS_DETAIL_EXTERN_C_BEGIN
///////////////////////////////////////////////////////////////////////////////

ABYSS_DETAIL_API
abyss_version_t abyss_get_linked_version(void);

///////////////////////////////////////////////////////////////////////////////
ABYSS_DETAIL_EXTERN_C_END

#endif
