#ifndef NOVA_HEADER_WithRefOf
#define NOVA_HEADER_WithRefOf

#include "StripRef.hpp"

namespace nova {
    template <typename Target, typename Origin>
    struct _internal_WithRefOf {
        using Type = StripRef<Target>;
    };

    template <typename Target, typename Origin>
    struct _internal_WithRefOf<Target, Origin&> {
        using Type = StripRef<Target>&;
    };

    template <typename Target, typename Origin>
    struct _internal_WithRefOf<Target, Origin&&> {
        using Type = StripRef<Target>&&;
    };

    template <typename Target, typename Origin>
    using WithRefOf = typename _internal_WithRefOf<Target, Origin>::Type;
}

#endif
