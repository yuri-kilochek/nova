#ifndef NOVA_HEADER_HASH
#define NOVA_HEADER_HASH

#include "UInt.hpp"

namespace nova {
    template <typename Type>
    UInt hash(Type const& value) = delete;
}

#endif
