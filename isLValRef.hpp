#ifndef NOVA_HEADER_isLValRef
#define NOVA_HEADER_isLValRef

#include "Boolean.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Boolean const isLValRef = ::std::is_lvalue_reference<Type>::value;
}

#endif
