#include <abyss/error.h>

#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////

char const *
abyss_get_error_name(abyss_error error) {
    switch (error) {
    case 0:
        return "0";
    case ABYSS_UNKNOWN_ERROR:
        return "unknown";
    defualt:
        return NULL;
    }
}
