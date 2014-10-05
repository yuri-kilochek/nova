#ifndef NOVA_HEADER_CopyCV
#define NOVA_HEADER_CopyCV

#include "CopyVolatile.hpp"
#include "CopyConst.hpp"

namespace nova {
    template <typename To, typename From>
    using CopyCV = CopyVolatile<CopyConst<To, From>, From>;
}

#endif
