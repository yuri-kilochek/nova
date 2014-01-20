#ifndef NOVA_INCLUDE_GUARD_STRIP_CONST_VOLATILE_HPP
#define NOVA_INCLUDE_GUARD_STRIP_CONST_VOLATILE_HPP

#include "StripVolatile.hpp"
#include "StripConst.hpp"

namespace nova {
    template <typename Type>
    using StripConstVolatile = StripVolatile<StripConst<Type>>;
}

#endif

