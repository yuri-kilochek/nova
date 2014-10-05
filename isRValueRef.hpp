#ifndef NOVA_HEADER_isRValueRef
#define NOVA_HEADER_isRValueRef

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isRValueRef() {
        return ::std::is_rvalue_reference<Type>::value;
    }
}

#endif
