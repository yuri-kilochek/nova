#ifndef NOVA_HEADER_CopyConst
#define NOVA_HEADER_CopyConst

#include "StripConst.hpp"

namespace nova {
    template <typename To, typename From>
    struct _internal_CopyConst {
        using Type = StripConst<To>;
    };

    template <typename To, typename From>
    struct _internal_CopyConst<To, From const> {
        using Type = StripConst<To> const;
    };

    template <typename To, typename From>
    using CopyConst = typename _internal_CopyConst<To, From>::Type;
}

#endif
