#ifndef NOVA_HEADER_isVolatile
#define NOVA_HEADER_isVolatile

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isVolatile() {
        return ::std::is_volatile<Type>::value;
    }
}

#endif
