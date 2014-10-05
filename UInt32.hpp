#ifndef NOVA_HEADER_UInt32
#define NOVA_HEADER_UInt32

#include "EnableIf.hpp"
#include "areSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using UInt32 = ::std::uint32_t;

    inline constexpr UInt32 operator "" _ui32(unsigned long long value) {
        return static_cast<UInt32>(value);
    }

    template <typename MaybeUInt32, EnableIf<areSame<MaybeUInt32, UInt32>()>...>
    inline constexpr UInt32 min() {
        return ::std::numeric_limits<UInt32>::min();
    }

    template <typename MaybeUInt32, EnableIf<areSame<MaybeUInt32, UInt32>()>...>
    inline constexpr UInt32 max() {
        return ::std::numeric_limits<UInt32>::max();
    }

    constexpr UInt32 max_ui32 = max<UInt32>();
}

#endif
