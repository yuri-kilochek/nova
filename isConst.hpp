#ifndef NOVA_HEADER_isConst
#define NOVA_HEADER_isConst

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isConst() {
        return ::std::is_const<Type>::value;
    }
}

#endif
