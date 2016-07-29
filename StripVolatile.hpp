#ifndef NOVA_HEADER_StripVolatile
#define NOVA_HEADER_StripVolatile

#include "WithRefOf.hpp"
#include "StripRef.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripVolatile = WithRefOf<typename ::std::remove_volatile<StripRef<Type>>::type, Type>;
}

#endif

