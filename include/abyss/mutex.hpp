#ifndef ABYSS_DETAIL_INCLUDE_MUTEX_HPP
#define ABYSS_DETAIL_INCLUDE_MUTEX_HPP

#include <concepts>

namespace abyss {
///////////////////////////////////////////////////////////////////////////////

template <typename Mutex>
concept lockable = requires(Mutex mutex) {
    requires std::destructible<Mutex>;

    { mutex.lock() };
    { mutex.unlock() } noexcept;
};

///////////////////////////////////////////////////////////////////////////////
} // namespace abyss

#endif
