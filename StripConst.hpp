#ifndef NOVA_HEADER_StripConst
#define NOVA_HEADER_StripConst

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripConst = typename ::std::remove_const<Type>::type;
}

#endif

