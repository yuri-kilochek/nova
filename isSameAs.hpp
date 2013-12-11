#ifndef NOVA_INCLUDE_GUARD_IS_SAME_AS_HPP
#define NOVA_INCLUDE_GUARD_IS_SAME_AS_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename A, typename B>
        struct IsSameAs {
            static constexpr Bool value = false;
        };

        template <typename T>
        struct IsSameAs<T, T> {
            static constexpr Bool value = true;
        };
    }

    template <typename A, typename B>
    inline constexpr Bool isSameAs() {
        return internals::IsSameAs<A, B>::value;
    }
}

#endif
