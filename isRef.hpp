#ifndef NOVA_INCLUDE_GUARD_IS_REF_HPP
#define NOVA_INCLUDE_GUARD_IS_REF_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename T>
        struct IsRef {
            static constexpr Bool value = false;
        };

        template <typename T>
        struct IsRef<T&> {
            static constexpr Bool value = true;
        };

        template <typename T>
        struct IsRef<T&&> {
            static constexpr Bool value = true;
        };
    }

    template <typename T>
    inline constexpr Bool isRef() {
        return internals::IsRef<T>::value;
    }
}

#endif
