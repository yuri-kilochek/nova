#ifndef NOVA_HEADER_isImplicitlyConstructible
#define NOVA_HEADER_isImplicitlyConstructible

#include "Void.hpp"
#include "fake.hpp"
#include "Bool.hpp"
#include "areSame.hpp"

namespace nova {
    template <typename Type, typename... Args>
    struct _internal_isImplicitlyConstructible {
        struct Yes {};
        struct No {};

        template <typename T>
        struct Box {};

        template <typename T>
        static Void expect(T) {}

        template <typename T>
        static auto test(Box<T>)
            -> decltype(expect<T>({fake<Args>()...}), Yes());
        static auto test(...)
            -> No;

        static constexpr Bool value = areSame<decltype(test(Box<Type>{})), Yes>();
    };

    template <typename Type, typename... Args>
    inline constexpr Bool isImplicitlyConstructible() {
        return _internal_isImplicitlyConstructible<Type, Args...>::value;
    }
}

#endif
