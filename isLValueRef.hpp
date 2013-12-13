#ifndef NOVA_INCLUDE_GUARD_IS_LVALUE_REF_HPP
#define NOVA_INCLUDE_GUARD_IS_LVALUE_REF_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename Type>
        struct IsLValueRef {
            static constexpr Bool value = false;
        };

        template <typename Type>
        struct IsLValueRef<Type&> {
            static constexpr Bool value = true;
        };
    }

    template <typename Type>
    inline constexpr Bool isLValueRef() {
        return internals::IsLValueRef<Type>::value;
    }
}

#endif
