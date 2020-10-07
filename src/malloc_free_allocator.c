#include <abyss/malloc_free_allocator.h>

#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////

static
abyss_error_t abyss_malloc_free_allocator_allocate(
    abyss_allocator_t *allocator,
    size_t size, size_t alignment, void **ptr_out)
{
    (void) allocator;

    void *ptr = NULL;

    abyss_error_t error = ABYSS_ERROR_NONE;

    if (!(ptr = aligned_alloc(size, alignment))) {
        error = ABYSS_ERROR_OUT_OF_MEMORY;
        goto out;
    }

    *ptr_out = ptr; ptr = NULL;
out:
    free(ptr);

    return error;
}

static
void abyss_malloc_free_allocator_deallocate(abyss_allocator_t *allocator,
    size_t size, size_t alignment, void *ptr)
{
    (void) allocator;
    (void) size;
    (void) alignment;

    free(ptr);
}

static
void abyss_malloc_free_allocator_release(abyss_allocator_t *allocator) {
    (void) allocator;
}

static
abyss_allocator_t abyss_malloc_free_allocator = {
    .ops = &(abyss_allocator_ops_t const) {
        .allocate = abyss_malloc_free_allocator_allocate,
        .deallocate = abyss_malloc_free_allocator_deallocate,
        .release = abyss_malloc_free_allocator_release,
    },
};

abyss_allocator_t *abyss_acquire_malloc_free_allocator(void) {
    return &abyss_malloc_free_allocator;
}
