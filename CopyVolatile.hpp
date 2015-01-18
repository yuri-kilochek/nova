#ifndef NOVA_HEADER_CopyVolatile
#define NOVA_HEADER_CopyVolatile

namespace nova {
    template <typename To, typename From>
    struct _internal_CopyVolatile {
        using Type = To;
    };

    template <typename To, typename From>
    struct _internal_CopyVolatile<To, From volatile> {
        using Type = To volatile;
    };

    template <typename To, typename From>
    using CopyVolatile = typename _internal_CopyVolatile<To, From>::Type;
}

#endif
