#include <abyss/error.h>

#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////

char const *abyss_error_get_name(abyss_error_t error) {
    switch (error) {
    case ABYSS_ERROR_NONE:
        return "none";
    case ABYSS_ERROR_UNKNOWN:
        return "unknown";
    case ABYSS_ERROR_INTERRUPTED:
        return "interrupted";
    case ABYSS_ERROR_OUT_OF_MEMORY:
        return "out of memory";
    case ABYSS_DETAIL_ERROR_STRUT:
        break;
    }
    return NULL;
}
