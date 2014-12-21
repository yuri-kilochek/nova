#ifndef NOVA_HEADER_FloatN
#define NOVA_HEADER_FloatN

#include "Float32.hpp"
#include "Float64.hpp"

namespace nova {
    namespace _internal_FloatN {
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
    using FloatN = typename _internal_FloatN::FloatN<n>::Type;
}

#endif
