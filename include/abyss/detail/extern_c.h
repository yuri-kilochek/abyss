#ifndef ABYSS_INCLUDE_GUARD_DETAIL_EXTERN_C_H
#define ABYSS_INCLUDE_GUARD_DETAIL_EXTERN_C_H

///////////////////////////////////////////////////////////////////////////////

#if __cplusplus
    #define ABYSS_DETAIL_EXTERN_C_BEGIN extern "C" {
    #define ABYSS_DETAIL_EXTERN_C_END   }
#else
    #define ABYSS_DETAIL_EXTERN_C_BEGIN
    #define ABYSS_DETAIL_EXTERN_C_END
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
