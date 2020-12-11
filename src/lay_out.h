#ifndef ABYSS_DETAIL_SRC_LAY_OUT_H
#define ABYSS_DETAIL_SRC_LAY_OUT_H

#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////

void abyss_detail_lay_out(size_t count,
    size_t const *sizes, size_t const *alignments, size_t *restrict offsets,
    size_t *restrict total_size_out, size_t *restrict total_alignment_out);

///////////////////////////////////////////////////////////////////////////////

#endif
