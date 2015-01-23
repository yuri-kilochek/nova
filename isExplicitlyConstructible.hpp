#ifndef NOVA_HEADER_isExplicitlyConstructible
#define NOVA_HEADER_isExplicitlyConstructible

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type, typename... Args>
    inline constexpr Bool isExplicitlyConstructible() {
        return ::std::is_constructible<Type, Args...>::value;
    }
}

#endif
