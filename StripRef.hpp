#ifndef NOVA_INCLUDE_GUARD_STRIP_REF_HPP
#define NOVA_INCLUDE_GUARD_STRIP_REF_HPP

namespace nova {
    namespace internals {
        template <typename Type_>
        struct StripRef {
            using Type = Type_;
        };

        template <typename Type_>
        struct StripRef<Type_&> {
            using Type = Type_;
        };

        template <typename Type_>
        struct StripRef<Type_&&> {
            using Type = Type_;
        };
    }

    template <typename Type>
    using StripRef = typename internals::StripRef<Type>::Type;
}

#endif
