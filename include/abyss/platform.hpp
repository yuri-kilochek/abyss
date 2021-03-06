#ifndef ABYSS_DETAIL_INCLUDE_PLATFORM_HPP
#define ABYSS_DETAIL_INCLUDE_PLATFORM_HPP

#include <abyss/mutex.hpp>
#include <abyss/timer.hpp>
#include <abyss/worker_pool.hpp>

#include <concepts>

namespace abyss {
///////////////////////////////////////////////////////////////////////////////

template <typename Platform>
concept platform = requires(Platform platform) {
    requires std::copy_constructible<Platform>;

    { platform.make_mutex() } -> mutex;
    { platform.make_timer() } -> timer;
    { platform.make_worker_pool() } -> worker_pool;
};

///////////////////////////////////////////////////////////////////////////////
} // namespace abyss

#endif
