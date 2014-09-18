#ifndef NOVA_HEADER_SBYTE
#define NOVA_HEADER_SBYTE

#include "Int8.hpp"

namespace nova {
    using SByte = Int8;

    inline constexpr SByte operator "" _sb(unsigned long long value) {
        return static_cast<SByte>(value);
    }

    constexpr Byte min_sb = min_i8;

    constexpr Byte max_sb = max_i8;
}

#endif
