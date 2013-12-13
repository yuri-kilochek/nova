#ifndef NOVA_INCLUDE_GUARD_IS_RVALUE_REF_HPP
#define NOVA_INCLUDE_GUARD_IS_RVALUE_REF_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename Type>
        struct IsRValueRef {
            static constexpr Bool value = false;
        };

        template <typename Type>
        struct IsRValueRef<Type&&> {
            static constexpr Bool value = true;
        };
    }

    template <typename Type>
    inline constexpr Bool isRValueRef() {
        return internals::IsRValueRef<Type>::value;
    }
}

#endif
