#ifndef NOVA_HEADER_COPY_CONST
#define NOVA_HEADER_COPY_CONST

namespace nova {
    namespace internals {
        template <typename To, typename From>
        struct CopyConst {
            using Type = To;
        };

        template <typename To, typename From>
        struct CopyConst<To, From const> {
            using Type = To const;
        };
    }

    template <typename To, typename From>
    using CopyConst = typename internals::CopyConst<To, From>::Type;
}

#endif
