#ifndef NOVA_HEADER_UINT16
#define NOVA_HEADER_UINT16

#include "EnableIf.hpp"
#include "isSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using UInt16 = ::std::uint16_t;

    inline constexpr UInt16 operator "" _ui16(unsigned long long value) {
        return static_cast<UInt16>(value);
    }

    template <typename MaybeUInt16, EnableIf<isSame<MaybeUInt16, UInt16>()>...>
    inline constexpr UInt16 min() {
        return ::std::numeric_limits<UInt16>::min();
    }

    template <typename MaybeUInt16, EnableIf<isSame<MaybeUInt16, UInt16>()>...>
    inline constexpr UInt16 max() {
        return ::std::numeric_limits<UInt16>::max();
    }

    constexpr UInt16 max_ui16 = max<UInt16>();
}

#endif
