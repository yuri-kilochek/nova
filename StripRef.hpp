#ifndef NOVA_HEADER_STRIP_REF
#define NOVA_HEADER_STRIP_REF

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripRef = typename ::std::remove_reference<Type>::type;
}

#endif
