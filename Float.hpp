#ifndef NOVA_HEADER_Float
#define NOVA_HEADER_Float

#include <limits>
#include <climits>

namespace nova {
    using Float = decltype(0.0);

    static_assert(::std::numeric_limits<float>::is_iec559, "float does not conform to IEC 60559/IEEE 754");
    static_assert(sizeof(float) * CHAR_BIT == 32, "float is not IEC 60559/IEEE 754 binary32.");
    using Float32 = float;

    static_assert(::std::numeric_limits<double>::is_iec559, "double does not conform to IEC 60559/IEEE 754");
    static_assert(sizeof(double) * CHAR_BIT == 64, "double is not IEC 60559/IEEE 754 binary64.");
    using Float64 = double;
}

#endif
