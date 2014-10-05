#ifndef NOVA_HEADER_isConstructible
#define NOVA_HEADER_isConstructible

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type, typename... Args>
    inline constexpr Bool isConstructible() {
        return ::std::is_constructible<Type, Args...>::value;
    }
}

#endif
