#ifndef NOVA_HEADER_StripConst
#define NOVA_HEADER_StripConst

#include "WithRefOf.hpp"
#include "StripRef.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripConst = WithRefOf<typename ::std::remove_const<StripRef<Type>>::type, Type>;
}

#endif

