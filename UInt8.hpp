#ifndef NOVA_HEADER_UINT8
#define NOVA_HEADER_UINT8

#include "EnableIf.hpp"
#include "isSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using UInt8 = ::std::uint8_t;

    template <typename MaybeUInt8, EnableIf<isSame<MaybeUInt8, UInt8>()>...>
    inline constexpr UInt8 min() {
        return ::std::numeric_limits<UInt8>::min();
    }

    template <typename MaybeUInt8, EnableIf<isSame<MaybeUInt8, UInt8>()>...>
    inline constexpr UInt8 max() {
        return ::std::numeric_limits<UInt8>::max();
    }

    inline constexpr UInt8 operator "" _ui8(unsigned long long value) {
        return static_cast<UInt8>(value);
    }

    constexpr UInt8 min_ui8 = min<UInt8>();

    constexpr UInt8 max_ui8 = max<UInt8>();
}

#endif
