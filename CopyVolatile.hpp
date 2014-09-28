#ifndef NOVA_HEADER_COPY_VOLATILE
#define NOVA_HEADER_COPY_VOLATILE

namespace nova {
    namespace internals {
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
    using CopyVolatile = typename internals::CopyVolatile<To, From>::Type;
}

#endif
