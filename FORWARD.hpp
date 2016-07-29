#ifndef NOVA_HEADER_FORWARD
#define NOVA_HEADER_FORWARD

#include "StripRef.hpp"
#include "EnableIf.hpp"
#include "isLValRef.hpp"

namespace nova {
    template <typename Arg>
    inline constexpr Arg&& _internal_FORWARD(StripRef<Arg>& arg) {
        return static_cast<Arg&&>(arg);
    }

    template <typename Arg, EnableIf<!isLValRef<Arg>>...>
    inline constexpr Arg&& _internal_FORWARD(StripRef<Arg>&& arg) {
        return static_cast<Arg&&>(arg);
    }
}

#define NOVA_FORWARD(arg) \
    ::nova::_internal_PASS<decltype(arg)>(arg)

#endif
