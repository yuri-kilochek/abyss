#include "lay_out.h"

#include "round_up.h"
#include "max.h"

///////////////////////////////////////////////////////////////////////////////

void abyss_impl_lay_out(size_t count,
    size_t const *sizes, size_t const *alignments, size_t *restrict offsets,
    size_t *restrict total_size_out, size_t *restrict total_alignment_out)
{
    size_t total_size = 0;
    size_t total_alignment = 0;
    for (size_t i = 0; i < count; ++i) {
        size_t alignment = alignments[i];
        size_t offset = ABYSS_IMPL_ROUND_UP(total_size, alignment);
        offsets[i] = offset;
        total_size = offset + sizes[i];
        total_alignment = ABYSS_IMPL_MAX(total_alignment, alignment);
    }
    *total_size_out = total_size;
    *total_alignment_out = total_alignment;
}
