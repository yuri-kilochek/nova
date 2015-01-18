#ifndef NOVA_HEADER_isCallable
#define NOVA_HEADER_isCallable

#include "fake.hpp"
#include "Bool.hpp"
#include "areSame.hpp"

namespace nova {
    template <typename MaybeCallable, typename... Args>
    struct _internal_isCallable {
        struct Yes {};
        struct No {};

        template <typename OtherMaybeCallable, typename... OtherArgs>
        struct Box {};

        template <typename OtherMaybeCallable, typename... OtherArgs>
        static auto test(Box<OtherMaybeCallable, OtherArgs>)
            -> decltype(fake<OtherMaybeCallable>()(fake<OtherArgs>()...), Yes());
        static auto test(...)
            -> No;

        static constexpr Bool value = areSame<decltype(test(Box<MaybeCallable, Args...>())), Yes>();
    };

    template <typename MaybeCallable, typename... Args>
    inline constexpr Bool isCallable() {
        return _internal_isCallable<MaybeCallable, Args...>::value;
    }
}

#endif
