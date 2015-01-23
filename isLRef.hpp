#ifndef NOVA_HEADER_isLRef
#define NOVA_HEADER_isLRef

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isLRef() {
        return ::std::is_lvalue_reference<Type>::value;
    }
}

#endif
