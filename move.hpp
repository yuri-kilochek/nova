#ifndef NOVA_INCLUDE_GUARD_MOVE_HPP
#define NOVA_INCLUDE_GUARD_MOVE_HPP

#include "StripRef.hpp"

namespace nova {
    template <typename Arg>
    inline constexpr StripRef<Arg>&& move(Arg&& arg) {
        return static_cast<StripRef<Arg>&&>(arg);
    }
}

#endif
