#ifndef NOVA_HEADER_UINT64
#define NOVA_HEADER_UINT64

#include "EnableIf.hpp"
#include "isSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using UInt64 = ::std::uint64_t;

    template <typename MaybeUInt64, EnableIf<isSame<MaybeUInt64, UInt64>()>...>
    inline constexpr UInt64 min() {
        return ::std::numeric_limits<UInt64>::min();
    }

    template <typename MaybeUInt64, EnableIf<isSame<MaybeUInt64, UInt64>()>...>
    inline constexpr UInt64 max() {
        return ::std::numeric_limits<UInt64>::max();
    }

    inline constexpr UInt64 operator "" _ui64(unsigned long long value) {
        return static_cast<UInt64>(value);
    }

    constexpr UInt64 max_ui64 = max<UInt64>();
}

#endif
