#ifndef NOVA_HEADER_STRIP_CONST_VOLATILE
#define NOVA_HEADER_STRIP_CONST_VOLATILE

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripConstVolatile = typename ::std::remove_cv<Type>::type;
}

#endif

