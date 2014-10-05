#ifndef NOVA_HEADER_CopyVolatile
#define NOVA_HEADER_CopyVolatile

namespace nova {
    namespace internals_CopyVolatile {
        template <typename To, typename From>
        struct CopyVolatile {
            using Type = To;
        };

        template <typename To, typename From>
        struct CopyVolatile<To, From volatile> {
            using Type = To volatile;
        };
    }

    template <typename To, typename From>
    using CopyVolatile = typename internals_CopyVolatile::CopyVolatile<To, From>::Type;
}

#endif
