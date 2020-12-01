#include <abyss/malloc_free_allocator.h>

#include <stdlib.h>

#include <abyss/basic_error.h>

///////////////////////////////////////////////////////////////////////////////

static
abyss_error_t *abyss_malloc_free_allocator_allocate(
    abyss_allocator_t *self,
    size_t size, size_t alignment, void **ptr_out)
{
    (void) self;

    void *ptr = NULL;

    abyss_error_t *error = NULL;

    if (!(ptr = aligned_alloc(size, alignment))) {
        error = abyss_acquire_basic_error(ABYSS_ERROR_SEMANTIC_OUT_OF_MEMORY);
        goto out;
    }

    *ptr_out = ptr; ptr = NULL;
out:
    free(ptr);

    return error;
}

static
void abyss_malloc_free_allocator_deallocate(abyss_allocator_t *self,
    size_t size, size_t alignment, void *ptr)
{
    (void) self;
    (void) size;
    (void) alignment;

    free(ptr);
}

static
abyss_allocator_t abyss_malloc_free_allocator = {
    .type = &(abyss_allocator_type_t const) {
        .allocate = abyss_malloc_free_allocator_allocate,
        .deallocate = abyss_malloc_free_allocator_deallocate,
    },
};

abyss_allocator_t *abyss_get_malloc_free_allocator(void) {
    return &abyss_malloc_free_allocator;
}
