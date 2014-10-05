#ifndef NOVA_HEADER_isStateless
#define NOVA_HEADER_isStateless

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isStateless() {
        return ::std::is_empty<Type>::value;
    }
}

#endif
