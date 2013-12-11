#ifndef NOVA_INCLUDE_GUARD_MOVE_HPP
#define NOVA_INCLUDE_GUARD_MOVE_HPP

#include "UnRef.hpp"

namespace nova {
    template<typename Arg>
    inline constexpr UnRef<Arg>&& move(Arg&& arg) {
        return static_cast<UnRef<Arg>&&>(arg);
    }
}

#endif
