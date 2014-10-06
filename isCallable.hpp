#ifndef NOVA_HEADER_isCallable
#define NOVA_HEADER_isCallable

#include "fake.hpp"
#include "Bool.hpp"
#include "isSame.hpp"

namespace nova {
    namespace internals_isCallable {
        template <typename Type, typename... Args>
        class IsCallable {
        private:
            template <typename OtherType>
            struct Holder {};

            struct Yes {};
            struct No {};

            template <typename OtherType>
            static auto test(Holder<OtherType>) -> decltype(fake<OtherType>()(fake<Args>()...), Yes());
            static auto test(...) -> No;

        public:
            static constexpr Bool value = isSame<decltype(test(Holder<Type>())), Yes>();
        };
    }

    template <typename Type, typename... Args>
    inline constexpr Bool isCallable() {
        return internals_isCallable::IsCallable<Type, Args...>::value;
    }
}

#endif
