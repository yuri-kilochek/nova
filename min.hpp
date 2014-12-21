#ifndef NOVA_HEADER_min
#define NOVA_HEADER_min

#include "forward.hpp"
#include "EnableIf.hpp"

namespace nova {
    template <typename First, typename Second>
    inline constexpr auto min(First&& first, Second&& second)
        -> decltype((second < first) ? forward<Second>(second) : forward<First>(first))
    {
        return (second < first) ? forward<Second>(second) : forward<First>(first);
    }

    template <typename First, typename... Rest, EnableIf<(sizeof...(Rest) >= 2)>...>
    inline constexpr auto min(First&& first, Rest&&... rest)
        -> decltype(min(forward<First>(first), min(forward<Rest>(rest)...)))
    {
        return min(forward<First>(first), min(forward<Rest>(rest)...));
    }
}

#endif
