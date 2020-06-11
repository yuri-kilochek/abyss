#include <abyss/error.h>

#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////

char const *abyss_error_get_name(abyss_error_t error) {
    switch (error) {
    case ABYSS_ERROR_NONE:
        return "none";

    case ABYSS_ERROR_OUT_OF_MEMORY:
        return "out_of_memory";
    case ABYSS_ERROR_CANCELED:
        return "canceled";

    default:
        return "unknown";
    }
}

