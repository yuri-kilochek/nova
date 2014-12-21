#ifndef NOVA_HEADER_EnableIf
#define NOVA_HEADER_EnableIf

#include "Bool.hpp"

namespace nova {
    namespace _internal_EnableIf {
        template <Bool condition>
        struct EnableIf {};

        template <>
        struct EnableIf<true> {
            enum class SfinaeVictim {};
        };
    }

    template <Bool condition>
    using EnableIf = typename _internal_EnableIf::EnableIf<condition>::SfinaeVictim;
}

#endif
