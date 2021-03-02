#ifndef ABYSS_DETAIL_INCLUDE_LOCKABLE_HPP
#define ABYSS_DETAIL_INCLUDE_LOCKABLE_HPP

namespace abyss {
///////////////////////////////////////////////////////////////////////////////

template <typename Lockable>
concept lockable = requires(Lockable lockable) {
    { mutex.lock() };
    { mutex.unlock() } noexcept;
};

///////////////////////////////////////////////////////////////////////////////
} // namespace abyss

#endif
