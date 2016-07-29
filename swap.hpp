#ifndef NOVA_HEADER_swap
#define NOVA_HEADER_swap

#include "Void.hpp"
#include "move.hpp"

namespace nova {
    template <typename A, typename B>
    inline Void swap(A& a, B& b) {
        auto t = move(a);
        a = move(b);
        b = move(t);
    }
}

#endif
