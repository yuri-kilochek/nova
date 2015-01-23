#ifndef NOVA_HEADER_CopyRef
#define NOVA_HEADER_CopyRef

#include "StripRef.hpp"

namespace nova {
    template <typename To, typename From>
    struct _internal_CopyRef {
        using Type = StripRef<To>;
    };

    template <typename To, typename From>
    struct _internal_CopyRef<To, From&> {
        using Type = StripRef<To>&;
    };

    template <typename To, typename From>
    struct _internal_CopyRef<To, From&&> {
        using Type = StripRef<To>&&;
    };

    template <typename To, typename From>
    using CopyRef = typename _internal_CopyRef<To, From>::Type;
}

#endif
