#ifndef NOVA_HEADER_Float
#define NOVA_HEADER_Float

#include <limits>

namespace nova {
    using Float = double;

    static_assert(::std::numeric_limits<float>::is_iec559, "float is not iec559.");
    static_assert(sizeof(float) == 4, "float is not iec559 binary32.");
    using Float32 = float;

    static_assert(::std::numeric_limits<double>::is_iec559, "double is not iec559.");
    static_assert(sizeof(double) == 8, "double is not iec559 binary64.");
    using Float64 = double;
}

#endif
