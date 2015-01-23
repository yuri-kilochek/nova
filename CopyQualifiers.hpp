#ifndef NOVA_HEADER_CopyQualifiers
#define NOVA_HEADER_CopyQualifiers

#include "CopyRef.hpp"
#include "CopyCV.hpp"
#include "StripRef.hpp"

namespace nova {
    template <typename To, typename From>
    using CopyQualifiers = CopyRef<CopyCV<StripRef<To>, StripRef<From>>, From>;
}

#endif
