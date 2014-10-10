#ifndef NOVA_HEADER_min_max
#define NOVA_HEADER_min_max

#include "forward.hpp"

namespace nova {
    template <typename Type>
    inline constexpr Type min(Type&& value) {
        return forward<Type>(value);
    }

    template <typename First, typename Second>
    inline constexpr auto min(First&& first, Second&& second)
        -> decltype((second < first) ? forward<Second>(second) : forward<First>(first))
    {
        return (second < first) ? forward<Second>(second) : forward<First>(first);
    }

    template <typename First, typename... Rest>
    inline constexpr auto min(First&& first, Rest&&... rest)
        -> decltype(min(forward<First>(first), min(forward<Rest>(rest)...)))
    {
        return min(forward<First>(first), min(forward<Rest>(rest)...));
    }

    template <typename Type>
    inline constexpr Type max(Type&& value) {
        return forward<Type>(value);
    }

    template <typename First, typename Second>
    inline constexpr auto max(First&& first, Second&& second)
        -> decltype((first < second) ? forward<Second>(second) : forward<First>(first))
    {
        return (first < second) ? forward<Second>(second) : forward<First>(first);
    }

    template <typename First, typename... Rest>
    inline constexpr auto max(First&& first, Rest&&... rest)
        -> decltype(max(forward<First>(first), max(forward<Rest>(rest)...)))
    {
        return max(forward<First>(first), max(forward<Rest>(rest)...));
    }
}

#endif
