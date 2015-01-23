#ifndef NOVA_HEADER_CopyVolatile
#define NOVA_HEADER_CopyVolatile

#include "StripVolatile.hpp"

namespace nova {
    template <typename To, typename From>
    struct _internal_CopyVolatile {
        using Type = StripVolatile<To>;
    };

    template <typename To, typename From>
    struct _internal_CopyVolatile<To, From volatile> {
        using Type = StripVolatile<To> volatile;
    };

    template <typename To, typename From>
    using CopyVolatile = typename _internal_CopyVolatile<To, From>::Type;
}

#endif
