#ifndef NOVA_HEADER_UINT8
#define NOVA_HEADER_UINT8

#include "EnableIf.hpp"
#include "areSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using UInt8 = ::std::uint8_t;

    inline constexpr UInt8 operator "" _ui8(unsigned long long value) {
        return static_cast<UInt8>(value);
    }

    template <typename MaybeUInt8, EnableIf<areSame<MaybeUInt8, UInt8>()>...>
    inline constexpr UInt8 min() {
        return ::std::numeric_limits<UInt8>::min();
    }

    template <typename MaybeUInt8, EnableIf<areSame<MaybeUInt8, UInt8>()>...>
    inline constexpr UInt8 max() {
        return ::std::numeric_limits<UInt8>::max();
    }

    constexpr UInt8 max_ui8 = max<UInt8>();
}

#endif
