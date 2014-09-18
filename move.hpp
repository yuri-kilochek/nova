#ifndef NOVA_HEADER_MOVE
#define NOVA_HEADER_MOVE

#include "StripRef.hpp"

namespace nova {
    template <typename Arg>
    inline constexpr StripRef<Arg>&& move(Arg&& arg) {
        return static_cast<StripRef<Arg>&&>(arg);
    }
}

#endif
