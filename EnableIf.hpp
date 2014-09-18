#ifndef NOVA_HEADER_ENABLE_IF
#define NOVA_HEADER_ENABLE_IF

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <Bool condition>
        struct EnableIf {};

        template <>
        struct EnableIf<true> {
            enum class SfinaeVictim {};
        };
    }

    template <Bool condition>
    using EnableIf = typename internals::EnableIf<condition>::SfinaeVictim;
}

#endif
