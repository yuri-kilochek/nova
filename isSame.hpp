#ifndef NOVA_INCLUDE_GUARD_IS_SAME_HPP
#define NOVA_INCLUDE_GUARD_IS_SAME_HPP

#include "Bool.hpp"

namespace nova {
    namespace internals {
        template <typename TypeA, typename TypeB>
        struct IsSame {
            static constexpr Bool value = false;
        };

        template <typename Type>
        struct IsSame<Type, Type> {
            static constexpr Bool value = true;
        };
    }

    template <typename TypeA, typename TypeB>
    inline constexpr Bool isSame() {
        return internals::IsSame<TypeA, TypeB>::value;
    }
}

#endif
