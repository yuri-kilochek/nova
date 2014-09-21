#ifndef NOVA_HEADER_INT64
#define NOVA_HEADER_INT64

#include "EnableIf.hpp"
#include "areSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using Int64 = ::std::int64_t;

    inline constexpr Int64 operator "" _i64(unsigned long long value) {
        return static_cast<Int64>(value);
    }

    template <typename MaybeInt64, EnableIf<areSame<MaybeInt64, Int64>()>...>
    inline constexpr Int64 min() {
        return ::std::numeric_limits<Int64>::min();
    }

    constexpr Int64 min_i64 = min<Int64>();

    template <typename MaybeInt64, EnableIf<areSame<MaybeInt64, Int64>()>...>
    inline constexpr Int64 max() {
        return ::std::numeric_limits<Int64>::max();
    }

    constexpr Int64 max_i64 = max<Int64>();
}

#endif
