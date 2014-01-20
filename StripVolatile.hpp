#ifndef NOVA_INCLUDE_GUARD_STRIP_VOLATILE_HPP
#define NOVA_INCLUDE_GUARD_STRIP_VOLATILE_HPP

namespace nova {
    namespace internals {
        template <typename Type_>
        struct StripVolatile {
            using Type = Type_;
        };

        template <typename Type_>
        struct StripVolatile<Type_ volatile> {
            using Type = Type_;
        };
    }

    template <typename Type>
    using StripVolatile = typename internals::StripVolatile<Type>::Type;
}

#endif
