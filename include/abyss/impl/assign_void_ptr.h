#ifndef ABYSS_IMPL_INCL_IMPL_ASSIGN_VOID_PTR_H
#define ABYSS_IMPL_INCL_IMPL_ASSIGN_VOID_PTR_H

#if __cplusplus
    #include <type_traits>
#endif

///////////////////////////////////////////////////////////////////////////////

#if __cplusplus
    #define ABYSS_IMPL_ASSIGN_VOID_PTR(ptr_out, void_ptr) \
        (*(ptr_out) = static_cast< \
            ::std::remove_reference_t<decltype(*(ptr_out))>>(void_ptr))
#else
    #define ABYSS_IMPL_ASSIGN_VOID_PTR(ptr_out, void_ptr) \
        (*(ptr_out) = (void_ptr))
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
