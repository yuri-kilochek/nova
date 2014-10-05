#ifndef NOVA_HEADER_swap
#define NOVA_HEADER_swap

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
