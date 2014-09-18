#ifndef NOVA_HEADER_STRIP_CONST
#define NOVA_HEADER_STRIP_CONST

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripConst = typename ::std::remove_const<Type>::type;
}

#endif

