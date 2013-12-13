#ifndef NOVA_INCLUDE_GUARD_IS_SAME_AS_HPP
#define NOVA_INCLUDE_GUARD_IS_SAME_AS_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename TypeA, typename TypeB>
        struct IsSameAs {
            static constexpr Bool value = false;
        };

        template <typename Type>
        struct IsSameAs<Type, Type> {
            static constexpr Bool value = true;
        };
    }

    template <typename TypeA, typename TypeB>
    inline constexpr Bool isSameAs() {
        return internals::IsSameAs<TypeA, TypeB>::value;
    }
}

#endif
