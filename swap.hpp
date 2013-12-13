#ifndef NOVA_INCLUDE_GUARD_SWAP_HPP
#define NOVA_INCLUDE_GUARD_SWAP_HPP

#include "Void.hpp"
#include "move.hpp"

namespace nova {
    template <typename Value>
    inline Void swap(Value& a, Value& b) {
        Value t = move(a);
        a = move(b);
        b = move(t);
    }
}

#endif
