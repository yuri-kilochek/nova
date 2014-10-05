#ifndef NOVA_HEADER_isRef
#define NOVA_HEADER_isRef

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isRef() {
        return ::std::is_reference<Type>::value;
    }
}

#endif
