#ifndef NOVA_HEADER_StripRef
#define NOVA_HEADER_StripRef

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripRef = typename ::std::remove_reference<Type>::type;
}

#endif
