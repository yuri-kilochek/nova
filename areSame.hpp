#ifndef NOVA_HEADER_areSame
#define NOVA_HEADER_areSame

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename... Types>
    struct _internal_areSame;

    template <>
    struct _internal_areSame<> {
        static constexpr Bool value = true;
    };

    template <typename Type>
    struct _internal_areSame<Type> {
        static constexpr Bool value = true;
    };

    template <typename First, typename Second, typename... Rest>
    struct _internal_areSame<First, Second, Rest...> {
        static constexpr Bool value = ::std::is_same<First, Second>::value && _internal_areSame<Second, Rest...>::value;
    };

    template <typename... Types>
    inline constexpr Bool areSame() {
        return _internal_areSame<Types...>::value;
    }
}

#endif
