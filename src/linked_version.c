#include <abyss/version.h>

#include <abyss/included_version.h>

///////////////////////////////////////////////////////////////////////////////

abyss_version_t abyss_get_linked_version(void) {
    return ABYSS_INCLUDED_VERSION;
}