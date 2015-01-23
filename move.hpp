#ifndef NOVA_HEADER_move
#define NOVA_HEADER_move

#include "StripRef.hpp"

namespace nova {
    template <typename Type>
    inline constexpr StripRef<Type>&& move(Type&& value) {
        return static_cast<StripRef<Type>&&>(value);
    }
}

#endif
