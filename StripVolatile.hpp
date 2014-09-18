#ifndef NOVA_HEADER_STRIP_VOLATILE
#define NOVA_HEADER_STRIP_VOLATILE

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripVolatile = typename ::std::remove_volatile<Type>::type;
}

#endif
