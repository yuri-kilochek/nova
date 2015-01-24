#ifndef NOVA_HEADER_Float32
#define NOVA_HEADER_Float32

#include "EnableIf.hpp"
#include "areSame.hpp"
#include "Bool.hpp"

#include <limits>
#include <climits>
#include <cmath>

namespace nova {
    static_assert(::std::numeric_limits<float>::is_iec559, "float does not conform to IEC 60559.");
    static_assert(sizeof(float) * CHAR_BIT == 32, "float is not IEC 60559 binary32.");
    using Float32 = float;


    template <typename Type, EnableIf<areSame<Type, Float32>()>...>
    inline constexpr Float32 nan() {
        return ::std::numeric_limits<Float32>::quiet_NaN();
    }

    inline constexpr Bool isNan(Float32 x) {
        return ::std::isnan(x);
    }

    template <typename Type, EnableIf<areSame<Type, Float32>()>...>
    inline constexpr Float32 inf() {
        return ::std::numeric_limits<Float32>::infinity();
    }

    inline constexpr Bool isInf(Float32 x) {
        return ::std::isinf(x);
    }

    template <typename Type, EnableIf<areSame<Type, Float32>()>...>
    inline constexpr Float32 min() {
        return -::std::numeric_limits<Float32>::max();
    }

    template <typename Type, EnableIf<areSame<Type, Float32>()>...>
    inline constexpr Float32 max() {
        return +::std::numeric_limits<Float32>::max();
    }


    inline constexpr Float32 copySign(Float32 to, Float32 from) {
        return ::std::copysign(to, from);
    }

    inline constexpr Float32 abs(Float32 x) {
        return ::std::abs(x);
    }

    inline constexpr Float32 mod(Float32 n, Float32 d) {
        return ::std::fmod(n, d);
    }

    inline constexpr Float32 min(Float32 a, Float32 b) {
        return ::std::fmin(a, b);
    }

    inline constexpr Float32 max(Float32 a, Float32 b) {
        return ::std::fmax(a, b);
    }

    inline constexpr Float32 clamp(Float32 a, Float32 x, Float32 b) {
        if (x < a) {
            return a;
        }
        if (x > b) {
            return b;
        }
        return x;
    }


    inline constexpr Float32 round(Float32 x) {
        return ::std::round(x);
    }

    inline constexpr Float32 roundD(Float32 x) {
        return ::std::floor(x);
    }

    inline constexpr Float32 round0(Float32 x) {
        return ::std::trunc(x);
    }

    inline constexpr Float32 roundU(Float32 x) {
        return ::std::ceil(x);
    }


    inline constexpr Float32 power(Float32 b, Float32 p) {
        return ::std::pow(b, p);
    }

    inline constexpr Float32 power2(Float32 b) {
        return b * b;
    }

    inline constexpr Float32 power3(Float32 b) {
        return b * b * b;
    }


    inline constexpr Float32 root(Float32 b, Float32 p) {
        return ::std::pow(b, Float32{1.0} / p);
    }

    inline constexpr Float32 root2(Float32 x) {
        return ::std::sqrt(x);
    }

    inline constexpr Float32 root3(Float32 x) {
        return ::std::cbrt(x);
    }


    inline constexpr Float32 exp2(Float32 x) {
        return ::std::exp2(x);
    }

    inline constexpr Float32 exp(Float32 x) {
        return ::std::exp(x);
    }

    inline constexpr Float32 exp10(Float32 x) {
        return ::std::pow(Float32{10}, x);
    }

    inline constexpr Float32 expM1(Float32 x) {
        return ::std::expm1(x);
    }


    inline constexpr Float32 log2(Float32 x) {
        return ::std::log2(x);
    }

    inline constexpr Float32 log(Float32 x) {
        return ::std::log(x);
    }

    inline constexpr Float32 log10(Float32 x) {
        return ::std::log10(x);
    }

    inline constexpr Float32 log1P(Float32 x) {
        return ::std::log1p(x);
    }


    inline constexpr Float32 sin(Float32 x) {
        return ::std::sin(x);
    }

    inline constexpr Float32 arcSin(Float32 s) {
        return ::std::asin(s);
    }

    inline constexpr Float32 cos(Float32 x) {
        return ::std::cos(x);
    }

    inline constexpr Float32 arcCos(Float32 c) {
        return ::std::acos(c);
    }

    inline constexpr Float32 tan(Float32 x) {
        return ::std::tan(x);
    }

    inline constexpr Float32 arcTan(Float32 t) {
        return ::std::atan(t);
    }

    inline constexpr Float32 arcTan(Float32 y, Float32 x) {
        return ::std::atan2(y, x);
    }
}

#endif
