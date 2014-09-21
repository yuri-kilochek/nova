#ifndef NOVA_HEADER_INT16
#define NOVA_HEADER_INT16

#include "EnableIf.hpp"
#include "areSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using Int16 = ::std::int16_t;

    inline constexpr Int16 operator "" _i16(unsigned long long value) {
        return static_cast<Int16>(value);
    }

    template <typename MaybeInt16, EnableIf<areSame<MaybeInt16, Int16>()>...>
    inline constexpr Int16 min() {
        return ::std::numeric_limits<Int16>::min();
    }

    constexpr Int16 min_i16 = min<Int16>();

    template <typename MaybeInt16, EnableIf<areSame<MaybeInt16, Int16>()>...>
    inline constexpr Int16 max() {
        return ::std::numeric_limits<Int16>::max();
    }

    constexpr Int16 max_i16 = max<Int16>();
}

#endif
