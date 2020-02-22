#include <abyss/std_allocator.h>

#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////

static
abyss_error_t abyss_std_allocator_allocate(abyss_allocator_t *allocator,
                                           void **ptr_out,
                                           size_t size, size_t alignment)
{
    (void)allocator;

    if (size == 0) {
        *ptr_out = NULL;
        return ABYSS_ERROR_NONE;
    }

    void *ptr;
    if ((ptr = aligned_alloc(size, alignment))) {
        *ptr_out = ptr;
        return ABYSS_ERROR_NONE;
    }

    return ABYSS_ERROR_OUT_OF_MEMORY;
}

static
void abyss_std_allocator_deallocate(abyss_allocator_t *allocator,
                                    void *ptr, size_t size, size_t alignment)
{
    (void)allocator;
    (void)size;
    (void)alignment;

    free(ptr);
}

static
abyss_allocator_t abyss_std_allocator = {
    .type = &(abyss_allocator_type_t const) {
        .allocate = abyss_std_allocator_allocate,
        .deallocate = abyss_std_allocator_deallocate,
    },
};

abyss_allocator_t *abyss_get_std_allocator(void) {
    return &abyss_std_allocator;
}
