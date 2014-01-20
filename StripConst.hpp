#ifndef NOVA_INCLUDE_GUARD_STRIP_CONST_HPP
#define NOVA_INCLUDE_GUARD_STRIP_CONST_HPP

namespace nova {
    namespace internals {
        template <typename Type_>
        struct StripConst {
            using Type = Type_;
        };

        template <typename Type_>
        struct StripConst<Type_ const> {
            using Type = Type_;
        };
    }

    template <typename Type>
    using StripConst = typename internals::StripConst<Type>::Type;
}

#endif

