#ifndef NOVA_HEADER_UInt
#define NOVA_HEADER_UInt

#include "UIntN.hpp"
#include "Void.hpp"

#include <climits>

namespace nova {
    using UInt = UIntN<sizeof(Void*) * CHAR_BIT>;

    inline constexpr UInt operator "" _ui(unsigned long long value) {
        return static_cast<UInt>(value);
    }

    constexpr UInt max_ui = max<UInt>();
}

#endif
