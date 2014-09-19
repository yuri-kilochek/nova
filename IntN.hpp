#ifndef NOVA_HEADER_INTN
#define NOVA_HEADER_INTN

#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Int64.hpp"

namespace nova {
    namespace internals {
        template <int n>
        struct IntN;

        template <>
        struct IntN<8> {
            using Type = Int8;
        };

        template <>
        struct IntN<16> {
            using Type = Int16;
        };

        template <>
        struct IntN<32> {
            using Type = Int32;
        };

        template <>
        struct IntN<64> {
            using Type = Int64;
        };
    }

    template <int n>
    using IntN = typename internals::IntN<n>::Type;
}

#endif