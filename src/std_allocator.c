#include <abyss/std_allocator.h>

#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////

static
void *abyss_std_allocator_allocate(abyss_allocator_t *allocator,
                                   size_t size, size_t alignment,
                                   abyss_error_t *error_out)
{
    (void) allocator;

    void *ptr;
    if (!(ptr = aligned_alloc(size, alignment))) {
        *error_out = ABYSS_ERROR_OUT_OF_MEMORY;
    }
    return ptr;
}

static
void abyss_std_allocator_deallocate(abyss_allocator_t *allocator,
                                    void *ptr, size_t size, size_t alignment)
{
    (void) allocator;
    (void) size;
    (void) alignment;

    free(ptr);
}

static
abyss_allocator_t abyss_std_allocator = {
    .ops = &(abyss_allocator_ops_t const) {
        .allocate = abyss_std_allocator_allocate,
        .deallocate = abyss_std_allocator_deallocate,
    },
};

abyss_allocator_t *abyss_get_std_allocator(void) {
    return &abyss_std_allocator;
}
