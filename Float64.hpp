#ifndef NOVA_HEADER_FLOAT64
#define NOVA_HEADER_FLOAT64

#include "EnableIf.hpp"
#include "areSame.hpp"

#include <limits>
#include <climits>
#include <cmath>

namespace nova {
    static_assert(::std::numeric_limits<double>::is_iec559, "double is not iec559.");
    static_assert(sizeof(double) * CHAR_BIT == 64, "double is not iec559 binary64.");

    using Float64 = double;

    inline constexpr Float64 operator "" _f64(long double value) {
        return static_cast<Float64>(value);
    }

    template <typename MaybeFloat64, EnableIf<areSame<MaybeFloat64, Float64>()>...>
    inline constexpr Float64 nan() {
        return ::std::numeric_limits<Float64>::quiet_NaN();
    }

    constexpr Float64 nan_f64 = nan<Float64>();

    template <typename MaybeFloat64, EnableIf<areSame<MaybeFloat64, Float64>()>...>
    inline constexpr Float64 inf() {
        return ::std::numeric_limits<Float64>::infinity();
    }

    constexpr Float64 inf_f64 = inf<Float64>();

    template <typename MaybeFloat64, EnableIf<areSame<MaybeFloat64, Float64>()>...>
    inline constexpr Float64 min() {
        return -inf_f64;
    }

    template <typename MaybeFloat64, EnableIf<areSame<MaybeFloat64, Float64>()>...>
    inline constexpr Float64 max() {
        return +inf_f64;
    }

    inline constexpr Bool isNan(Float64 x) {
        return ::std::isnan(x);
    }

    inline constexpr Float64 sign(Float64 x) {
        if (x < 0.0_f64) {
            return -1.0_f64;
        } else if (x > 0.0_f64) {
            return +1.0_f64;
        } else {
            return x;
        }
    }

    inline constexpr Float64 abs(Float64 x) {
        return ::std::abs(x);
    }

    inline constexpr Float64 mod(Float64 n, Float64 d) {
        return ::std::fmod(n, d);
    }

    inline constexpr Float64 round(Float64 x) {
        return ::std::round(x);
    }

    inline constexpr Float64 roundN(Float64 x) {
        return ::std::floor(x);
    }

    inline constexpr Float64 round0(Float64 x) {
        return ::std::trunc(x);
    }

    inline constexpr Float64 roundP(Float64 x) {
        return ::std::ceil(x);
    }

    inline constexpr Float64 min(Float64 a, Float64 b) {
        if (isNan(a) || isNan(b)) {
            return nan_f64;
        }
        return (a < b) ? a : b;
    }

    inline constexpr Float64 max(Float64 a, Float64 b) {
        if (isNan(a) || isNan(b)) {
            return nan_f64;
        }
        return (a > b) ? a : b;
    }

    inline constexpr Float64 power(Float64 x, Float64 p) {
        return ::std::pow(x, p);
    }

    inline constexpr Float64 power2(Float64 x) {
        return x * x;
    }

    inline constexpr Float64 power3(Float64 x) {
        return x * x * x;
    }

    inline constexpr Float64 root(Float64 p, Float64 x) {
        return ::std::pow(x, 1.0_f32 / p);
    }

    inline constexpr Float64 root2(Float64 x) {
        return ::std::sqrt(x);
    }

    inline constexpr Float64 root3(Float64 x) {
        return ::std::cbrt(x);
    }

    inline constexpr Float64 log(Float64 b, Float64 x) {
        return ::std::log(x) / ::std::log(b);
    }

    inline constexpr Float64 log2(Float64 x) {
        return ::std::log2(x);
    }

    inline constexpr Float64 logE(Float64 x) {
        return ::std::log(x);
    }

    inline constexpr Float64 log10(Float64 x) {
        return ::std::log10(x);
    }

    inline constexpr Float64 exp(Float64 b, Float64 x) {
        return ::std::pow(b, x);
    }

    inline constexpr Float64 exp2(Float64 x) {
        return ::std::exp2(x);
    }

    inline constexpr Float64 expE(Float64 x) {
        return ::std::exp(x);
    }

    inline constexpr Float64 exp10(Float64 x) {
        return ::std::pow(10.0_f32, x);
    }

    inline constexpr Float64 sin(Float64 a) {
        return ::std::sin(x);
    }

    inline constexpr Float64 cos(Float64 a) {
        return ::std::cos(x);
    }

    inline constexpr Float64 tan(Float64 a) {
        return ::std::tan(x);
    }

    inline constexpr Float64 arcSin(Float64 s) {
        return ::std::asin(s);
    }

    inline constexpr Float64 arcCos(Float64 c) {
        return ::std::acos(c);
    }

    inline constexpr Float64 arcTan(Float64 t) {
        return ::std::atan(t);
    }

    inline constexpr Float64 arcTan(Float64 y, Float64 x) {
        return ::std::atan2(y, x);
    }
}

#endif
