#ifndef NOVA_HEADER_EXCHANGE
#define NOVA_HEADER_EXCHANGE

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
