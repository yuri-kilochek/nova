#ifndef NOVA_INCLUDE_GUARD_IS_CONSTRUCTIBLE_HPP
#define NOVA_INCLUDE_GUARD_IS_CONSTRUCTIBLE_HPP

#include "mock.hpp"
#include "Void.hpp"
#include "Bool.hpp"
#include "isSameAs.hpp"

namespace nova {
    namespace internals {
        template <typename Type, typename... Args>
        class IsConstructible {
            private:
                struct Yes {};
                struct No {};

                template <typename OtherType>
                static auto test(OtherType*) -> decltype(OtherType(mock<Args>()...), Yes());
                static auto test(Void*) -> No;

            public:
                static constexpr Bool value = isSameAs<decltype(test(mock<Type*>())), Yes>();
        };
    }

    template <typename Type, typename... Args>
    inline constexpr Bool isConstructible() {
        return internals::IsConstructible<Type, Args...>::value;
    }
}

#endif
