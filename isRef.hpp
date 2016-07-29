#ifndef NOVA_HEADER_isRef
#define NOVA_HEADER_isRef

#include "Boolean.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    static constexpr Boolean const isRef = ::std::is_reference<Type>::value;
}

#endif
