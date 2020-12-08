#include <abyss/basic_error.h>

///////////////////////////////////////////////////////////////////////////////

static
abyss_error_type_t const abyss_basic_error_type;

typedef struct abyss_basic_error abyss_basic_error_t;

struct abyss_basic_error {
    abyss_error_t base;
    char const *message;
};

static
abyss_basic_error_t abyss_basic_errors[] = {
    [ABYSS_ERROR_SEMANTIC_OUT_OF_MEMORY - 1] = {
        .base.type = &abyss_basic_error_type,
        .message = "out of memory",
    },
    [ABYSS_ERROR_SEMANTIC_IMMEDIATE_INVOCATION - 1] = {
        .base.type = &abyss_basic_error_type,
        .message = "immediate invocation",
    },
    [ABYSS_ERROR_SEMANTIC_CANCELED - 1] = {
        .base.type = &abyss_basic_error_type,
        .message = "canceled",
    },
};

static
void abyss_basic_error_delete(abyss_error_t *base)
{
    (void) base;
}

static
abyss_error_semantic_t abyss_basic_error_get_semantic(
    abyss_error_t const *base)
{
    abyss_basic_error_t const *self = (void *) base;
    return (self - abyss_basic_errors) + 1;
}

static
char const *abyss_basic_error_get_message(abyss_error_t const *base) {
    abyss_basic_error_t const *self = (void *) base;
    return self->message;
}

static
abyss_error_type_t const abyss_basic_error_type = {
    .delete_ = abyss_basic_error_delete,
    .get_semantic = abyss_basic_error_get_semantic,
    .get_message = abyss_basic_error_get_message,
};

abyss_error_t *abyss_new_basic_error(abyss_error_semantic_t semantic) {
    return &abyss_basic_errors[semantic - 1].base;
}

