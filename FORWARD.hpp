#ifndef NOVA_HEADER_FORWARD
#define NOVA_HEADER_FORWARD

#include "StripRef.hpp"
#include "EnableIf.hpp"
#include "isLValueRef.hpp"

namespace nova {
    template <typename Arg>
    inline constexpr Arg&& _internal_FORWARD(StripRef<Arg>& arg) {
        return static_cast<Arg&&>(arg);
    }

    template <typename Arg, EnableIf<!isLValueRef<Arg>()>...>
    inline constexpr Arg&& _internal_FORWARD(StripRef<Arg>&& arg) {
        return static_cast<Arg&&>(arg);
    }
}

#define NOVA_FORWARD(arg) \
    ::nova::_internal_FORWARD<decltype(arg)>(arg)

#endif
