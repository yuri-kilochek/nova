#ifndef NOVA_HEADER_INT8
#define NOVA_HEADER_INT8

#include "EnableIf.hpp"
#include "isSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using Int8 = ::std::int8_t;

    template <typename MaybeInt8, EnableIf<isSame<MaybeInt8, Int8>()>...>
    inline constexpr Int8 min() {
        return ::std::numeric_limits<Int8>::min();
    }

    template <typename MaybeInt8, EnableIf<isSame<MaybeInt8, Int8>()>...>
    inline constexpr Int8 max() {
        return ::std::numeric_limits<Int8>::max();
    }

    inline constexpr Int8 operator "" _i8(unsigned long long value) {
        return static_cast<Int8>(value);
    }

    constexpr Int8 min_i8 = min<Int8>();

    constexpr Int8 max_i8 = max<Int8>();
}

#endif
