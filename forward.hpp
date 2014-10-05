#ifndef NOVA_HEADER_forward
#define NOVA_HEADER_forward

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
