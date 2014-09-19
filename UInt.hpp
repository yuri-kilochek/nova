#ifndef NOVA_HEADER_UINT
#define NOVA_HEADER_UINT

#include "EnableIf.hpp"
#include "isSame.hpp"

#include <cstdint>
#include <limits>

namespace nova {
    using UInt = ::std::uintptr_t;

    template <typename MaybeUInt, EnableIf<isSame<MaybeUInt, UInt>()>...>
    inline constexpr UInt min() {
        return ::std::numeric_limits<UInt>::min();
    }

    template <typename MaybeUInt, EnableIf<isSame<MaybeUInt, UInt>()>...>
    inline constexpr UInt max() {
        return ::std::numeric_limits<UInt>::max();
    }

    inline constexpr UInt operator "" _ui(unsigned long long value) {
        return static_cast<UInt>(value);
    }

    constexpr UInt min_ui = min<UInt>();

    constexpr UInt max_ui = max<UInt>();
}

#endif
