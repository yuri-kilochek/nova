#ifndef NOVA_HEADER_SWAP
#define NOVA_HEADER_SWAP

#include "Void.hpp"
#include "move.hpp"

namespace nova {
    template <typename Type>
    inline Void swap(Type& a, Type& b) {
        auto t = move(a);
        a = move(b);
        b = move(t);
    }
}

#endif
