#ifndef NOVA_HEADER_FLOATN
#define NOVA_HEADER_FLOATN

#include "Float32.hpp"
#include "Float64.hpp"

namespace nova {
    namespace internals {
        template <int n>
        struct FloatN;

        template <>
        struct FloatN<32> {
            using Type = Float32;
        };

        template <>
        struct FloatN<64> {
            using Type = Float64;
        };
    }

    template <int n>
    using FloatN = typename internals::FloatN<n>::Type;
}

#endif
