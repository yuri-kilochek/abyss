#include <abyss/stdlib_allocator.h>

#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////

static
abyss_error
abyss_stdlib_allocate(void *allocator,
                      size_t size, size_t alignment, void **pointer_out)
{
    (void)allocator;

    if (size == 0) {
        *pointer_out = NULL;
        return 0;
    }

    void *pointer;
    if (!(pointer = aligned_alloc(size, alignment))) {
        return ABYSS_OUT_OF_MEMORY_ERROR;
    }
    *pointer_out = pointer;
    return 0;
}

static
void
abyss_stdlib_deallocate(void *allocator,
                        size_t size, size_t alignment, void *pointer)
{
    (void)allocator;
    (void)size;
    (void)alignment;

    free(pointer);
}

static
abyss_allocator abyss_stdlib_allocator = {
    .type = &(abyss_allocator_type) {
        .allocate = abyss_stdlib_allocate,
        .deallocate = abyss_stdlib_deallocate,
    },
};

abyss_allocator *
abyss_get_stdlib_allocator(void) {
    return &abyss_stdlib_allocator;
}
