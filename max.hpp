#ifndef NOVA_HEADER_max
#define NOVA_HEADER_max

#include "forward.hpp"
#include "EnableIf.hpp"

namespace nova {
    template <typename First, typename Second>
    inline constexpr auto max(First&& first, Second&& second)
        -> decltype((first < second) ? forward<Second>(second) : forward<First>(first))
    {
        return (first < second) ? forward<Second>(second) : forward<First>(first);
    }

    template <typename First, typename... Rest, EnableIf<(sizeof...(Rest) >= 2)>...>
    inline constexpr auto max(First&& first, Rest&&... rest)
        -> decltype(max(forward<First>(first), max(forward<Rest>(rest)...)))
    {
        return max(forward<First>(first), max(forward<Rest>(rest)...));
    }
}

#endif
