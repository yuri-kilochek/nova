#ifndef NOVA_INCLUDE_GUARD_STRIP_QUALIFIERS_HPP
#define NOVA_INCLUDE_GUARD_STRIP_QUALIFIERS_HPP

#include "StripConstVolatile.hpp"
#include "StripRef.hpp"

namespace nova {
    template <typename Type>
    using StripQualifiers = StripConstVolatile<StripRef<Type>>;
}

#endif
