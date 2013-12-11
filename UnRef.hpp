#ifndef NOVA_INCLUDE_GUARD_UN_REF_HPP
#define NOVA_INCLUDE_GUARD_UN_REF_HPP

namespace nova {
    namespace internals {
        template <typename Type_>
        struct UnRef {
            using Type = Type_;
        };

        template <typename Type_>
        struct UnRef<Type_&> {
            using Type = Type_;
        };

        template <typename Type_>
        struct UnRef<Type_&&> {
            using Type = Type_;
        };
    }

    template <typename Type>
    using UnRef = typename internals::UnRef<Type>::Type;
}

#endif
