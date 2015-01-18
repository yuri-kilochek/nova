#ifndef NOVA_HEADER_EnableIf
#define NOVA_HEADER_EnableIf

#include "Bool.hpp"

namespace nova {
    template <Bool condition>
    struct _internal_EnableIf {};

    template <>
    struct _internal_EnableIf<true> {
        enum class SfinaeVictim {};
    };

    template <Bool condition>
    using EnableIf = typename _internal_EnableIf<condition>::SfinaeVictim;
}

#endif
