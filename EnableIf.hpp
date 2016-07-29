#ifndef NOVA_HEADER_EnableIf
#define NOVA_HEADER_EnableIf

#include "Boolean.hpp"

namespace nova {
    template <Boolean condition>
    struct _internal_EnableIf {};

    template <>
    struct _internal_EnableIf<true> {
        enum class SfinaeVictim {};
    };

    template <Boolean condition>
    using EnableIf = typename _internal_EnableIf<condition>::SfinaeVictim;
}

#endif
