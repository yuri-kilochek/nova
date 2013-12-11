#ifndef NOVA_INCLUDE_GUARD_UN_CONST_HPP
#define NOVA_INCLUDE_GUARD_UN_CONST_HPP

namespace nova {
    namespace internals {
        template <typename Type_>
        struct UnConst {
            using Type = Type_;
        };

        template <typename Type_>
        struct UnConst<Type_ const> {
            using Type = Type_;
        };
    }

    template <typename Type>
    using UnConst = typename internals::UnConst<Type>::Type;
}

#endif
