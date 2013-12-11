#ifndef NOVA_INCLUDE_GUARD_ENABLE_IF_HPP
#define NOVA_INCLUDE_GUARD_ENABLE_IF_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <Bool condition>
        struct EnableIf {};

        template <>
        struct EnableIf<true> {
            enum class SfinaeSubject {};
        };
    }

    template <Bool condition>
    using EnableIf = typename internals::EnableIf<condition>::SfinaeSubject;
}

#endif
