#ifndef NOVA_HEADER_ARE_SAME
#define NOVA_HEADER_ARE_SAME

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    namespace internals {
        template <typename... Types>
        struct AreSame;

        template <>
        struct AreSame<> {
            static constexpr Bool value = true;
        };

        template <typename Type>
        struct AreSame<Type> {
            static constexpr Bool value = true;
        };

        template <typename First, typename Second, typename... Rest>
        struct AreSame<First, Second, Rest...> {
            static constexpr Bool value = ::std::is_same<First, Second>::value && AreSame<Second, Rest...>::value;
        };
    }

    template <typename... Types>
    inline constexpr Bool areSame() {
        return internals::AreSame<Types...>::value;
    }
}

#endif
