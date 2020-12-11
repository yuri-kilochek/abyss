#ifndef ABYSS_DETAIL_INCLUDE_ERROR_H
#define ABYSS_DETAIL_INCLUDE_ERROR_H

#include <limits.h>

#include <abyss/detail/always_inline.h>

#include <abyss/detail/prolog.h>
///////////////////////////////////////////////////////////////////////////////

typedef struct abyss_error_type abyss_error_type_t;
typedef struct abyss_error abyss_error_t;

typedef enum abyss_error_semantic {
    ABYSS_DETAIL_ERROR_SEMANTIC_NONE = 0,

    ABYSS_ERROR_SEMANTIC_OUT_OF_MEMORY,
    ABYSS_ERROR_SEMANTIC_IMMEDIATE_INVOCATION,
    ABYSS_ERROR_SEMANTIC_CANCELED,

    ABYSS_ERROR_SEMANTIC_UNKNOWN = INT_MAX,
} abyss_error_semantic_t;

struct abyss_error_type {
    void (*delete_)(abyss_error_t *self);
    abyss_error_semantic_t (*get_semantic)(abyss_error_t const *self);
    char const *(*get_message)(abyss_error_t const *self);
};

struct abyss_error {
    abyss_error_type_t const *const type;
};

static inline ABYSS_DETAIL_ALWAYS_INLINE
void abyss_error_delete(abyss_error_t *self) {
    if (!self) { return; }
    self->type->delete_(self);
}

static inline ABYSS_DETAIL_ALWAYS_INLINE
abyss_error_semantic_t abyss_error_get_semantic(abyss_error_t const *self) {
    return self->type->get_semantic(self);
}

static inline ABYSS_DETAIL_ALWAYS_INLINE
char const *abyss_error_get_message(abyss_error_t const *self) {
    return self->type->get_message(self);
}

///////////////////////////////////////////////////////////////////////////////
#include <abyss/detail/epilog.h>

#endif
