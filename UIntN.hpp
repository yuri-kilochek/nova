#ifndef NOVA_HEADER_UINTN
#define NOVA_HEADER_UINTN

#include "UInt8.hpp"
#include "UInt16.hpp"
#include "UInt32.hpp"
#include "UInt64.hpp"

namespace nova {
    namespace internals {
        template <int n>
        struct UIntN;

        template <>
        struct UIntN<8> {
            using Type = UInt8;
        };

        template <>
        struct UIntN<16> {
            using Type = UInt16;
        };

        template <>
        struct UIntN<32> {
            using Type = UInt32;
        };

        template <>
        struct UIntN<64> {
            using Type = UInt64;
        };
    }

    template <int n>
    using UIntN = typename internals::UIntN<n>::Type;
}

#endif
