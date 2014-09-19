#ifndef NOVA_HEADER_INT16
#define NOVA_HEADER_INT16

#include "EnableIf.hpp"
#include "isSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using Int16 = ::std::int16_t;

    template <typename MaybeInt16, EnableIf<isSame<MaybeInt16, Int16>()>...>
    inline constexpr Int16 min() {
        return ::std::numeric_limits<Int16>::min();
    }

    template <typename MaybeInt16, EnableIf<isSame<MaybeInt16, Int16>()>...>
    inline constexpr Int16 max() {
        return ::std::numeric_limits<Int16>::max();
    }

    inline constexpr Int16 operator "" _i16(unsigned long long value) {
        return static_cast<Int16>(value);
    }

    constexpr Int16 min_i16 = min<Int16>();

    constexpr Int16 max_i16 = max<Int16>();
}

#endif
