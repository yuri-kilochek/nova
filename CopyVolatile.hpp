#ifndef NOVA_HEADER_CopyVolatile
#define NOVA_HEADER_CopyVolatile

namespace nova {
    namespace _internal_CopyVolatile {
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
    using CopyVolatile = typename _internal_CopyVolatile::CopyVolatile<To, From>::Type;
}

#endif
