#ifndef NOVA_HEADER_BYTE
#define NOVA_HEADER_BYTE

#include "UInt8.hpp"

namespace nova {
    using Byte = UInt8;

    inline constexpr Byte operator "" _b(unsigned long long value) {
        return static_cast<Byte>(value);
    }

    constexpr Byte min_b = min_ui8;

    constexpr Byte max_b = max_ui8;
}

#endif
