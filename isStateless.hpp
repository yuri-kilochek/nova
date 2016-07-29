#ifndef NOVA_HEADER_isStateless
#define NOVA_HEADER_isStateless

#include "Boolean.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    static constexpr Boolean const isStateless = ::std::is_empty<Type>::value;
}

#endif
