#ifndef NOVA_INCLUDE_GUARD_FORWARD_HPP
#define NOVA_INCLUDE_GUARD_FORWARD_HPP

#include "UnRef.hpp"
#include "EnableIf.hpp"
#include "isLValueRef.hpp"

namespace nova {
    template<typename Arg>
    inline constexpr Arg&& forward(UnRef<Arg>& arg) {
        return static_cast<Arg&&>(arg);
    }

    template<typename Arg, EnableIf<!isLValueRef<Arg>()>...>
    inline constexpr Arg&& forward(UnRef<Arg>&& arg) {
        return static_cast<Arg&&>(arg);
    }
}

#endif
