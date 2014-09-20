#ifndef NOVA_HEADER_IS_STATELESS
#define NOVA_HEADER_IS_STATELESS

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isStateless() {
        return ::std::is_empty<Type>::value;
    }
}

#endif
