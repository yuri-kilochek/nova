#ifndef NOVA_HEADER_INT
#define NOVA_HEADER_INT

#include "IntN.hpp"
#include "Void.hpp"

#include <climits>

namespace nova {
    using Int = IntN<sizeof(Void*) * CHAR_BIT>;

    inline constexpr Int operator "" _i(unsigned long long value) {
        return static_cast<Int>(value);
    }

    constexpr Int min_i = min<Int>();

    constexpr Int max_i = max<Int>();
}

#endif
