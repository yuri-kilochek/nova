#ifndef NOVA_INCLUDE_GUARD_IS_RVALUE_REF_HPP
#define NOVA_INCLUDE_GUARD_IS_RVALUE_REF_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename T>
        struct IsRValueRef {
            static constexpr Bool value = false;
        };

        template <typename T>
        struct IsRValueRef<T&&> {
            static constexpr Bool value = true;
        };
    }

    template <typename T>
    inline constexpr Bool isRValueRef() {
        return internals::IsRValueRef<T>::value;
    }
}

#endif
