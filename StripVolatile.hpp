#ifndef NOVA_HEADER_StripVolatile
#define NOVA_HEADER_StripVolatile

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripVolatile = typename ::std::remove_volatile<Type>::type;
}

#endif
