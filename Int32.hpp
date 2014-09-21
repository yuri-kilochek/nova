#ifndef NOVA_HEADER_INT32
#define NOVA_HEADER_INT32

#include "EnableIf.hpp"
#include "areSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using Int32 = ::std::int32_t;

    inline constexpr Int32 operator "" _i32(unsigned long long value) {
        return static_cast<Int32>(value);
    }

    template <typename MaybeInt32, EnableIf<areSame<MaybeInt32, Int32>()>...>
    inline constexpr Int32 min() {
        return ::std::numeric_limits<Int32>::min();
    }

    constexpr Int32 min_i32 = min<Int32>();

    template <typename MaybeInt32, EnableIf<areSame<MaybeInt32, Int32>()>...>
    inline constexpr Int32 max() {
        return ::std::numeric_limits<Int32>::max();
    }

    constexpr Int32 max_i32 = max<Int32>();
}

#endif
