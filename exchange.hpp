#ifndef NOVA_HEADER_exchange
#define NOVA_HEADER_exchange

#include "move.hpp"
#include "forward.hpp"

namespace nova {
    template <typename Type, typename AnyType>
    inline Type exchange(Type& value, AnyType&& newValue) {
        auto oldValue = move(value);
        value = forward<AnyType>(newValue);
        return oldValue;
    }
}

#endif
