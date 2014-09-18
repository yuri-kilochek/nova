#ifndef NOVA_HEADER_SWAP
#define NOVA_HEADER_SWAP

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
