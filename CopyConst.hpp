#ifndef NOVA_HEADER_CopyConst
#define NOVA_HEADER_CopyConst

namespace nova {
    template <typename To, typename From>
    struct _internal_CopyConst {
        using Type = To;
    };

    template <typename To, typename From>
    struct _internal_CopyConst<To, From const> {
        using Type = To const;
    };

    template <typename To, typename From>
    using CopyConst = typename _internal_CopyConst<To, From>::Type;
}

#endif
