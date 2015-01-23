#ifndef NOVA_HEADER_isRRef
#define NOVA_HEADER_isRRef

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isRRef() {
        return ::std::is_rvalue_reference<Type>::value;
    }
}

#endif
