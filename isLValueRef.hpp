#ifndef NOVA_HEADER_isLValueRef
#define NOVA_HEADER_isLValueRef

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isLValueRef() {
        return ::std::is_lvalue_reference<Type>::value;
    }
}

#endif
