#ifndef NOVA_HEADER_Float
#define NOVA_HEADER_Float

#include "Float64.hpp"

namespace nova {
    using Float = Float64;

    inline constexpr Float operator "" _f(long double value) {
        return static_cast<Float>(value);
    }

    constexpr Float inf_f = inf<Float>();

    constexpr Float nan_f = nan<Float>();
}

#endif
