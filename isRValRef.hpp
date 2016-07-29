#ifndef NOVA_HEADER_isRValRef
#define NOVA_HEADER_isRValRef

#include "Boolean.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Boolean const isRValRef = ::std::is_rvalue_reference<Type>::value;
}

#endif
