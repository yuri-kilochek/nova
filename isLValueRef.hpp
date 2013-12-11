#ifndef NOVA_INCLUDE_GUARD_IS_LVALUE_REF_HPP
#define NOVA_INCLUDE_GUARD_IS_LVALUE_REF_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename T>
        struct IsLValueRef {
            static constexpr Bool value = false;
        };

        template <typename T>
        struct IsLValueRef<T&> {
            static constexpr Bool value = true;
        };
    }

    template <typename T>
    inline constexpr Bool isLValueRef() {
        return internals::IsLValueRef<T>::value;
    }
}

#endif
