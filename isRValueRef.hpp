#ifndef NOVA_HEADER_IS_RVALUE_REF
#define NOVA_HEADER_IS_RVALUE_REF

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isRValueRef() {
        return ::std::is_rvalue_reference<Type>::value;
    }
}

#endif
