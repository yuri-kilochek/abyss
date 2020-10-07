#include <abyss/error.h>

#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////

char const *abyss_error_get_description(abyss_error_t error) {
    switch (error) {
    case ABYSS_ERROR_NONE:
        return "none";

    case ABYSS_ERROR_OUT_OF_MEMORY:
        return "out of memory";
    case ABYSS_ERROR_IMMEDIATE_INVOCATION:
        return "immediate invocation";
    case ABYSS_ERROR_CANCELED:
        return "canceled";

    default:
        return "unknown";
    }
}

