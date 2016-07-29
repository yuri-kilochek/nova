#ifndef NOVA_HEADER_hash
#define NOVA_HEADER_hash

#include "Nat.hpp"

namespace nova {
    template <typename Type>
    Nat hash(Type const& value) = delete;
}

#endif
