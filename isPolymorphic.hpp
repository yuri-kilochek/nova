#ifndef NOVA_HEADER_isPolymorphic
#define NOVA_HEADER_isPolymorphic

#include "Boolean.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    static constexpr Boolean const isPolymorphic = ::std::is_polymorphic<Type>::value;
}

#endif
