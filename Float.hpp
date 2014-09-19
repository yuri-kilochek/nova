#ifndef NOVA_HEADER_FLOAT
#define NOVA_HEADER_FLOAT

#include "Float32.hpp"
#include "Float64.hpp"

namespace nova {
    using Float = Float64;

    inline constexpr Float operator "" _f(long double value) {
        return static_cast<Float>(value);
    }

    constexpr Float min_f = min<Float>();

    constexpr Float max_f = max<Float>();

    constexpr Float nan_f = nan<Float>();
}

#endif
