#ifndef NOVA_HEADER_Float64
#define NOVA_HEADER_Float64

#include "EnableIf.hpp"
#include "areSame.hpp"
#include "Bool.hpp"

#include <limits>
#include <climits>
#include <cmath>

namespace nova {
    static_assert(::std::numeric_limits<double>::is_iec559, "float does not conform to IEC 60559.");
    static_assert(sizeof(double) * CHAR_BIT == 64, "float is not IEC 60559 binary64.");
    using Float64 = double;


    template <typename Type, EnableIf<areSame<Type, Float64>()>...>
    inline constexpr Float64 nan() {
        return ::std::numeric_limits<Float64>::quiet_NaN();
    }

    inline constexpr Bool isNan(Float64 x) {
        return ::std::isnan(x);
    }

    template <typename Type, EnableIf<areSame<Type, Float64>()>...>
    inline constexpr Float64 inf() {
        return ::std::numeric_limits<Float64>::infinity();
    }

    inline constexpr Bool isInf(Float64 x) {
        return ::std::isinf(x);
    }

    template <typename Type, EnableIf<areSame<Type, Float64>()>...>
    inline constexpr Float64 min() {
        return -::std::numeric_limits<Float64>::max();
    }

    template <typename Type, EnableIf<areSame<Type, Float64>()>...>
    inline constexpr Float64 max() {
        return +::std::numeric_limits<Float64>::max();
    }


    inline constexpr Float64 copySign(Float64 to, Float64 from) {
        return ::std::copysign(to, from);
    }

    inline constexpr Float64 abs(Float64 x) {
        return ::std::abs(x);
    }

    inline constexpr Float64 mod(Float64 n, Float64 d) {
        return ::std::fmod(n, d);
    }

    inline constexpr Float64 min(Float64 a, Float64 b) {
        return ::std::fmin(a, b);
    }

    inline constexpr Float64 max(Float64 a, Float64 b) {
        return ::std::fmax(a, b);
    }

    inline constexpr Float64 clamp(Float64 a, Float64 x, Float64 b) {
        if (x < a) {
            return a;
        }
        if (x > b) {
            return b;
        }
        return x;
    }


    inline constexpr Float64 round(Float64 x) {
        return ::std::round(x);
    }

    inline constexpr Float64 roundD(Float64 x) {
        return ::std::floor(x);
    }

    inline constexpr Float64 round0(Float64 x) {
        return ::std::trunc(x);
    }

    inline constexpr Float64 roundU(Float64 x) {
        return ::std::ceil(x);
    }


    inline constexpr Float64 power(Float64 b, Float64 p) {
        return ::std::pow(b, p);
    }

    inline constexpr Float64 power2(Float64 b) {
        return b * b;
    }

    inline constexpr Float64 power3(Float64 b) {
        return b * b * b;
    }


    inline constexpr Float64 root(Float64 b, Float64 p) {
        return ::std::pow(b, Float64{1.0} / p);
    }

    inline constexpr Float64 root2(Float64 x) {
        return ::std::sqrt(x);
    }

    inline constexpr Float64 root3(Float64 x) {
        return ::std::cbrt(x);
    }


    inline constexpr Float64 exp2(Float64 x) {
        return ::std::exp2(x);
    }

    inline constexpr Float64 exp(Float64 x) {
        return ::std::exp(x);
    }

    inline constexpr Float64 exp10(Float64 x) {
        return ::std::pow(Float64{10}, x);
    }

    inline constexpr Float64 expM1(Float64 x) {
        return ::std::expm1(x);
    }


    inline constexpr Float64 log2(Float64 x) {
        return ::std::log2(x);
    }

    inline constexpr Float64 log(Float64 x) {
        return ::std::log(x);
    }

    inline constexpr Float64 log10(Float64 x) {
        return ::std::log10(x);
    }

    inline constexpr Float64 log1P(Float64 x) {
        return ::std::log1p(x);
    }


    inline constexpr Float64 sin(Float64 x) {
        return ::std::sin(x);
    }

    inline constexpr Float64 arcSin(Float64 s) {
        return ::std::asin(s);
    }

    inline constexpr Float64 cos(Float64 x) {
        return ::std::cos(x);
    }

    inline constexpr Float64 arcCos(Float64 c) {
        return ::std::acos(c);
    }

    inline constexpr Float64 tan(Float64 x) {
        return ::std::tan(x);
    }

    inline constexpr Float64 arcTan(Float64 t) {
        return ::std::atan(t);
    }

    inline constexpr Float64 arcTan(Float64 y, Float64 x) {
        return ::std::atan2(y, x);
    }
}

#endif
