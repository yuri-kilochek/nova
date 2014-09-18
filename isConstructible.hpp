#ifndef NOVA_HEADER_IS_CONSTRUCTIBLE
#define NOVA_HEADER_IS_CONSTRUCTIBLE

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type, typename... Args>
    inline constexpr Bool isConstructible() {
        return ::std::is_constructible<Type, Args...>::value;
    }
}

#endif
