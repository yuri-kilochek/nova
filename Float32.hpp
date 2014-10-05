#ifndef NOVA_HEADER_Float32
#define NOVA_HEADER_Float32

#include "EnableIf.hpp"
#include "areSame.hpp"

#include <limits>
#include <climits>
#include <cmath>

namespace nova {
    static_assert(::std::numeric_limits<float>::is_iec559, "float is not iec559.");
    static_assert(sizeof(float) * CHAR_BIT == 32, "float is not iec559 binary32.");

    using Float32 = float;

    inline constexpr Float32 operator "" _f32(long double value) {
        return static_cast<Float32>(value);
    }

    template <typename MaybeFloat32, EnableIf<areSame<MaybeFloat32, Float32>()>...>
    inline constexpr Float32 nan() {
        return ::std::numeric_limits<Float32>::quiet_NaN();
    }

    constexpr Float32 nan_f32 = nan<Float32>();

    template <typename MaybeFloat32, EnableIf<areSame<MaybeFloat32, Float32>()>...>
    inline constexpr Float32 inf() {
        return ::std::numeric_limits<Float32>::infinity();
    }

    constexpr Float32 inf_f32 = inf<Float32>();

    template <typename MaybeFloat32, EnableIf<areSame<MaybeFloat32, Float32>()>...>
    inline constexpr Float32 min() {
        return -inf_f32;
    }

    template <typename MaybeFloat32, EnableIf<areSame<MaybeFloat32, Float32>()>...>
    inline constexpr Float32 max() {
        return +inf_f32;
    }

    inline constexpr Bool isNan(Float32 x) {
        return ::std::isnan(x);
    }

    inline constexpr Float32 sign(Float32 x) {
        if (x < 0.0_f32) {
            return -1.0_f32;
        } else if (x > 0.0_f32) {
            return +1.0_f32;
        } else {
            return x;
        }
    }

    inline constexpr Float32 abs(Float32 x) {
        return ::std::abs(x);
    }

    inline constexpr Float32 mod(Float32 n, Float32 d) {
        return ::std::fmod(n, d);
    }

    inline constexpr Float32 round(Float32 x) {
        return ::std::round(x);
    }

    inline constexpr Float32 roundN(Float32 x) {
        return ::std::floor(x);
    }

    inline constexpr Float32 round0(Float32 x) {
        return ::std::trunc(x);
    }

    inline constexpr Float32 roundP(Float32 x) {
        return ::std::ceil(x);
    }

    inline constexpr Float32 min(Float32 a, Float32 b) {
        if (isNan(a) || isNan(b)) {
            return nan_f32;
        }
        return (a < b) ? a : b;
    }

    inline constexpr Float32 max(Float32 a, Float32 b) {
        if (isNan(a) || isNan(b)) {
            return nan_f32;
        }
        return (a > b) ? a : b;
    }

    inline constexpr Float32 power(Float32 x, Float32 p) {
        return ::std::pow(x, p);
    }

    inline constexpr Float32 power2(Float32 x) {
        return x * x;
    }

    inline constexpr Float32 power3(Float32 x) {
        return x * x * x;
    }

    inline constexpr Float32 root(Float32 p, Float32 x) {
        return ::std::pow(x, 1.0_f32 / p);
    }

    inline constexpr Float32 root2(Float32 x) {
        return ::std::sqrt(x);
    }

    inline constexpr Float32 root3(Float32 x) {
        return ::std::cbrt(x);
    }

    inline constexpr Float32 log(Float32 b, Float32 x) {
        return ::std::log(x) / ::std::log(b);
    }

    inline constexpr Float32 log2(Float32 x) {
        return ::std::log2(x);
    }

    inline constexpr Float32 logE(Float32 x) {
        return ::std::log(x);
    }

    inline constexpr Float32 log10(Float32 x) {
        return ::std::log10(x);
    }

    inline constexpr Float32 exp(Float32 b, Float32 x) {
        return ::std::pow(b, x);
    }

    inline constexpr Float32 exp2(Float32 x) {
        return ::std::exp2(x);
    }

    inline constexpr Float32 expE(Float32 x) {
        return ::std::exp(x);
    }

    inline constexpr Float32 exp10(Float32 x) {
        return ::std::pow(10.0_f32, x);
    }

    inline constexpr Float32 sin(Float32 a) {
        return ::std::sin(x);
    }

    inline constexpr Float32 cos(Float32 a) {
        return ::std::cos(x);
    }

    inline constexpr Float32 tan(Float32 a) {
        return ::std::tan(x);
    }

    inline constexpr Float32 arcSin(Float32 s) {
        return ::std::asin(s);
    }

    inline constexpr Float32 arcCos(Float32 c) {
        return ::std::acos(c);
    }

    inline constexpr Float32 arcTan(Float32 t) {
        return ::std::atan(t);
    }

    inline constexpr Float32 arcTan(Float32 y, Float32 x) {
        return ::std::atan2(y, x);
    }
}

#endif
