#ifndef NOVA_INCLUDE_GUARD_SWAP_HPP
#define NOVA_INCLUDE_GUARD_SWAP_HPP

#include "Void.hpp"
#include "move.hpp"

namespace nova {
    template <typename T>
    inline Void swap(T& a, T& b) {
        T t = move(a);
        a = move(b);
        b = move(t);
    }
}

#endif
