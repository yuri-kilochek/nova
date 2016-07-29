#ifndef NOVA_HEADER_isVolatile
#define NOVA_HEADER_isVolatile

#include "Boolean.hpp"
#include "StripRef.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    static constexpr Boolean const isVolatile = ::std::is_volatile<StripRef<Type>>::value;
}

#endif
