#ifndef NOVA_HEADER_COPY_CV
#define NOVA_HEADER_COPY_CV

#include "CopyVolatile.hpp"
#include "CopyConst.hpp"

namespace nova {
    template <typename To, typename From>
    using CopyCV = CopyVolatile<CopyConst<To, From>, From>;
}

#endif
