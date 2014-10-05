#ifndef NOVA_HEADER_StripQualifiers
#define NOVA_HEADER_StripQualifiers

#include "StripCV.hpp"
#include "StripRef.hpp"

namespace nova {
    template <typename Type>
    using StripQualifiers = StripCV<StripRef<Type>>;
}

#endif
