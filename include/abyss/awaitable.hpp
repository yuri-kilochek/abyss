#ifndef ABYSS_DETAIL_INCLUDE_AWAITABLE_HPP
#define ABYSS_DETAIL_INCLUDE_AWAITABLE_HPP

#include <concepts>

namespace abyss {
///////////////////////////////////////////////////////////////////////////////

// Typing of awaitables depends entirely on the coroutine that evaluates
// `co_await`, so we can't really do any better here. However these are still
// useful as annotations.

template <typename Awaitable>
concept awaitable = std::destructible<Awaitable>;

template <typename Awaitable, typename Result>
concept awaitable_of = awaitable<Awaitable>;

///////////////////////////////////////////////////////////////////////////////
} // namespace abyss

#endif
