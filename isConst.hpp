#ifndef NOVA_HEADER_isConst
#define NOVA_HEADER_isConst

#include "Boolean.hpp"
#include "StripRef.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    static constexpr Boolean const isConst = ::std::is_const<StripRef<Type>>::value;
}

#endif
