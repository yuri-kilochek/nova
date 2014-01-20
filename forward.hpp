#ifndef NOVA_INCLUDE_GUARD_FORWARD_HPP
#define NOVA_INCLUDE_GUARD_FORWARD_HPP

#include "StripRef.hpp"
#include "EnableIf.hpp"
#include "isLValueRef.hpp"

namespace nova {
    template <typename Arg>
    inline constexpr Arg&& forward(StripRef<Arg>& arg) {
        return static_cast<Arg&&>(arg);
    }

    template <typename Arg, EnableIf<!isLValueRef<Arg>()>...>
    inline constexpr Arg&& forward(StripRef<Arg>&& arg) {
        return static_cast<Arg&&>(arg);
    }
}

#endif
