#ifndef NOVA_HEADER_STRIP_QUALIFIERS
#define NOVA_HEADER_STRIP_QUALIFIERS

#include "StripConstVolatile.hpp"
#include "StripRef.hpp"

namespace nova {
    template <typename Type>
    using StripQualifiers = StripConstVolatile<StripRef<Type>>;
}

#endif
