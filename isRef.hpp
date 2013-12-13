#ifndef NOVA_INCLUDE_GUARD_IS_REF_HPP
#define NOVA_INCLUDE_GUARD_IS_REF_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename Type>
        struct IsRef {
            static constexpr Bool value = false;
        };

        template <typename Type>
        struct IsRef<Type&> {
            static constexpr Bool value = true;
        };

        template <typename Type>
        struct IsRef<Type&&> {
            static constexpr Bool value = true;
        };
    }

    template <typename Type>
    inline constexpr Bool isRef() {
        return internals::IsRef<Type>::value;
    }
}

#endif
