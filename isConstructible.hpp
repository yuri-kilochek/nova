#ifndef NOVA_INCLUDE_GUARD_IS_CONSTRUCTIBLE_HPP
#define NOVA_INCLUDE_GUARD_IS_CONSTRUCTIBLE_HPP

#include "mock.hpp"
#include "Bool.hpp"
#include "isSameAs.hpp"

namespace nova {
    namespace internals {
        template <typename Type, typename... Args>
        class IsConstructible {
            private:
                template <typename OtherType>
                struct Holder {};

                struct Yes {};
                struct No {};

                template <typename OtherType>
                static auto test(Holder<OtherType>) -> decltype(OtherType(mock<Args>()...), Yes());
                static auto test(...) -> No;

            public:
                static constexpr Bool value = isSameAs<decltype(test(Holder<Type>())), Yes>();
        };
    }

    template <typename Type, typename... Args>
    inline constexpr Bool isConstructible() {
        return internals::IsConstructible<Type, Args...>::value;
    }
}

#endif
