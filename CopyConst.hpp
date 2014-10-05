#ifndef NOVA_HEADER_CopyConst
#define NOVA_HEADER_CopyConst

namespace nova {
    namespace internals_CopyConst {
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
    using CopyConst = typename internals_CopyConst::CopyConst<To, From>::Type;
}

#endif
