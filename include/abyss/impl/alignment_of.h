#ifndef ABYSS_IMPL_INCL_IMPL_ALIGNMENT_OF_H
#define ABYSS_IMPL_INCL_IMPL_ALIGNMENT_OF_H

///////////////////////////////////////////////////////////////////////////////

#if __cplusplus
    #define ABYSS_IMPL_ALIGNMENT_OF(...) alignof(__VA_ARGS__)
#else
    #define ABYSS_IMPL_ALIGNMENT_OF(...) _Alignof(__VA_ARGS__)
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
