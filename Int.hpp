#ifndef NOVA_HEADER_INT
#define NOVA_HEADER_INT

#include "EnableIf.hpp"
#include "isSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using Int = ::std::intptr_t;

    template <typename MaybeInt, EnableIf<isSame<MaybeInt, Int>()>...>
    inline constexpr Int min() {
        return ::std::numeric_limits<Int>::min();
    }

    template <typename MaybeInt, EnableIf<isSame<MaybeInt, Int>()>...>
    inline constexpr Int max() {
        return ::std::numeric_limits<Int>::max();
    }

    inline constexpr Int operator "" _i(unsigned long long value) {
        return static_cast<Int>(value);
    }

    constexpr Int min_i = min<Int>();

    constexpr Int max_i = max<Int>();
}

#endif
