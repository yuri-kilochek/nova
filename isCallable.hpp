#ifndef NOVA_HEADER_isCallable
#define NOVA_HEADER_isCallable

#include "fake.hpp"
#include "Bool.hpp"
#include "areSame.hpp"

namespace nova {
    template <typename Type, typename... Args>
    struct _internal_isCallable {
        struct Yes {};
        struct No {};

        template <typename T>
        struct Box {};

        template <typename T>
        static auto test(Box<T>)
            -> decltype(fake<T>()(fake<Args>()...), Yes());
        static auto test(...)
            -> No;

        static constexpr Bool value = areSame<decltype(test(Box<Type>{})), Yes>();
    };

    template <typename Type, typename... Args>
    inline constexpr Bool isCallable() {
        return _internal_isCallable<Type, Args...>::value;
    }
}

#endif
