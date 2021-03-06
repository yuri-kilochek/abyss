#ifndef ABYSS_DETAIL_INCLUDE_WORKER_POOL_HPP
#define ABYSS_DETAIL_INCLUDE_WORKER_POOL_HPP

#include <abyss/awaitable.hpp>

#include <concepts>

namespace abyss {
///////////////////////////////////////////////////////////////////////////////

namespace detail::worker_pool {
///////////////////////////////////////////////////////////////////////////////

struct dummy_result {
    dummy_result()
    = delete;

    dummy_result(dummy_result&&)
    = default;

    dummy_result(dummy_result const&)
    = delete;

    auto operator=(dummy_result&&)
    = delete;

    auto operator=(dummy_result const&)
    = delete;
};

struct dummy_work {
    dummy_result()
    = delete;

    dummy_result(dummy_result&&)
    = delete;

    dummy_result(dummy_result const&)
    = delete;

    auto operator=(dummy_result&&)
    = delete;

    auto operator=(dummy_result const&)
    = delete;

    auto operator()()
    -> dummy_result;
};

///////////////////////////////////////////////////////////////////////////////
} // namespace detail::worker_pool

template <typename Pool>
concept worker_pool = requires(
    Pool pool,
    detail::worker_pool::dummy_work& work)
{
    requires std::destructible<Pool>;

    { pool.execute(work) }
    -> awaitable_of<detail::worker_pool::dummy_result>;

    { pool.cancel() };
};

///////////////////////////////////////////////////////////////////////////////
} // namespace abyss

#endif
