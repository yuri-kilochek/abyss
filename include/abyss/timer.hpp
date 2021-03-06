#ifndef ABYSS_DETAIL_INCLUDE_TIMER_HPP
#define ABYSS_DETAIL_INCLUDE_TIMER_HPP

#include <abyss/awaitable.hpp>

#include <concepts>
#include <chrono>

namespace abyss {
///////////////////////////////////////////////////////////////////////////////

template <typename Timer>
concept timer = requires(Timer timer, std::chrono::microseconds duration) {
    requires std::destructible<Timer>;

    { timer.wait(duration) }
    -> awaitable;

    { timer.cancel() };
};

///////////////////////////////////////////////////////////////////////////////
} // namespace abyss

#endif
