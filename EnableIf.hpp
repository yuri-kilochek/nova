#ifndef NOVA_HEADER_EnableIf
#define NOVA_HEADER_EnableIf

#include "Bool.hpp"

namespace nova {
    namespace internals_EnableIf {
        template <Bool condition>
        struct EnableIf {};

        template <>
        struct EnableIf<true> {
            enum class SfinaeVictim {};
        };
    }

    template <Bool condition>
    using EnableIf = typename internals_EnableIf::EnableIf<condition>::SfinaeVictim;
}

#endif
