#ifndef ABYSS_DETAIL_INCLUDE_DETAIL_ALIGN_AS_H
#define ABYSS_DETAIL_INCLUDE_DETAIL_ALIGN_AS_H

///////////////////////////////////////////////////////////////////////////////

#if __cplusplus
    #define ABYSS_DETAIL_ALIGN_AS(...) alignas(__VA_ARGS__)
#else
    #define ABYSS_DETAIL_ALIGN_AS(...) _Alignas(__VA_ARGS__)
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
