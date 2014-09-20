#ifndef NOVA_HEADER_STRIP_QUALIFIERS
#define NOVA_HEADER_STRIP_QUALIFIERS

#include "StripCV.hpp"
#include "StripRef.hpp"

namespace nova {
    template <typename Type>
    using StripQualifiers = StripCV<StripRef<Type>>;
}

#endif
