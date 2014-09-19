#ifndef NOVA_HEADER_MIN_MAX
#define NOVA_HEADER_MIN_MAX

#include "forward.hpp"

namespace nova {
    template <typename Value>
    inline constexpr Value min(Value&& value) {
        return forward<Value>(value);
    }

    template <typename First, typename Second>
    inline constexpr auto min(First&& first, Second&& second) {
        return (second < first) ? forward<Second>(second) : forward<First>(first);
    }

    template <typename First, typename... Rest>
    inline constexpr auto min(First&& first, Rest&&... rest) {
        return min(forward<First>(first), min(forward<Rest>(rest)...));
    }

    template <typename Value>
    inline constexpr Value max(Value&& value) {
        return forward<Value>(value);
    }

    template <typename First, typename Second>
    inline constexpr auto max(First&& first, Second&& second) {
        return (first < second) ? forward<Second>(second) : forward<First>(first);
    }

    template <typename First, typename... Rest>
    inline constexpr auto max(First&& first, Rest&&... rest) {
        return max(forward<First>(first), max(forward<Rest>(rest)...));
    }
}

#endif
