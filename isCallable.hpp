#ifndef NOVA_HEADER_IS_CALLABLE
#define NOVA_HEADER_IS_CALLABLE

#include "mock.hpp"
#include "Bool.hpp"
#include "isSame.hpp"

namespace nova {
    namespace internals {
        template <typename Type, typename... Args>
        class IsCallable {
            private:
                template <typename OtherType>
                struct Holder {};

                struct Yes {};
                struct No {};

                template <typename OtherType>
                static auto test(Holder<OtherType>) -> decltype(mock<OtherType>()(mock<Args>()...), Yes());
                static auto test(...) -> No;

            public:
                static constexpr Bool value = isSame<decltype(test(Holder<Type>())), Yes>();
        };
    }

    template <typename Type, typename... Args>
    inline constexpr Bool isCallable() {
        return internals::IsCallable<Type, Args...>::value;
    }
}

#endif
