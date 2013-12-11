#ifndef NOVA_INCLUDE_GUARD_EXCHANGE_HPP
#define NOVA_INCLUDE_GUARD_EXCHANGE_HPP

#include "move.hpp"
#include "forward.hpp"

namespace nova {
    template <typename Value, typename NewValue>
    inline Value exchange(Value& value, NewValue&& newValue) {
        Value oldValue = move(value);
        value = forward<NewValue>(newValue);
        return oldValue;
    }
}

#endif
