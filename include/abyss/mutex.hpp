#ifndef ABYSS_DETAIL_INCLUDE_MUTEX_HPP
#define ABYSS_DETAIL_INCLUDE_MUTEX_HPP

#include <abyss/lockable.hpp>

#include <utility>
#include <type_traits>
#include <concepts>
#include <memory>

namespace abyss {
///////////////////////////////////////////////////////////////////////////////

namespace detail::mutex {
///////////////////////////////////////////////////////////////////////////////

template <typename Mutex>
struct impl {
    static constexpr
    bool nothrow_construct = false;

    template <typename... Args>
    void construct(void*& state, Args&&... args) {
        state = new Mutex(std::forward<Args>(args)...);
    };

    static
    auto to_ptr(void*& state)
    noexcept
    -> Mutex*
    { return static_cast<Mutex*>(state); }

    static
    void destroy(void*& state)
    noexcept
    { delete to_ptr(state); }
};

template <typename Mutex>
requires sizeof(Mutex) <= sizeof(void*)
      && alignof(Mutex) <= alignof(void*)
struct impl<Mutex> {
    static constexpr
    bool nothrow_construct = std::is_nothrow_constructible_v<Mutex, Args...>;

    template <typename... Args>
    void construct(void*& state, Args&&... args)
    noexcept(nothrow_construct)
    { std::construct_at(to_ptr(state), std::forward<Args>(args)...); };

    static
    auto to_ptr(void*& state)
    noexcept
    -> Mutex*
    { return reinterpret_cast<Mutex*>(&state); }

    static
    void destroy(void*& state)
    noexcept
    { std::destroy_at(to_ptr(state)); }
};

template <typename Mutex>
struct impl<Mutex&> {
    static constexpr
    bool nothrow_construct = true;

    void construct(void*& state, Mutex& mutex)
    noexcept
    { state = std::addressof(mutex); };

    static
    auto to_ptr(void*& state)
    noexcept
    -> Mutex*
    { return static_cast<Mutex*>(state); }

    static
    void destroy(void*& state)
    noexcept
    {}
};

struct operations {
    void (&destroy)(void*& state);
    
    void (&lock)(void*& state);
    
    void (&unlock)(void*& state)
    noexcept;
};

template <typename Mutex>
constexpr
operations operations_for = {
    .destroy = impl<Mutex>::destroy,
    
    .lock = [](void*& state) {
        impl<Mutex>::to_ptr(state)->lock();
    },

    .lock = [](void*& state)
    noexcept
    { impl<Mutex>::to_ptr(state)->unlock(); },
};

///////////////////////////////////////////////////////////////////////////////
} // namespace detail::mutex

class mutex {
public:
    template <lockable Mutex, typename... Args>
    requires std::constructible_from<Mutex, Args...>
    explicit
    mutex(std::in_place_type_t<Mutex>, Args&&... args)
    noexcept(detail::mutex::impl<Mutex>::nothrow_construct)
    : operations_(detail::mutex::operations_for<Mutex>>)
    {
        detail::mutex::impl<Mutex>::
            construct(state_, std::forward<Args>(args)...);
    }

    template <lockable Mutex, typename... Args>
    mutex(std::reference_wrapper<Mutex> ref)
    noexcept
    : operations_(detail::mutex::operations_for<Mutex&>>)
    { detail::mutex::impl<Mutex&>::construct(state_, ref.get()); }
    
    mutex(mutex&& other)
    = delete;

    ~mutex() {
        operations_.destroy(state_);
    }

    void lock() {
        operations_.lock(state_);
    }

    void unlock()
    noexcept
    { operations_->unlock(state_); }

private:
    detail::mutex::operations const& operations_;
    void* state_;
};

///////////////////////////////////////////////////////////////////////////////
} // namespace abyss

#endif
