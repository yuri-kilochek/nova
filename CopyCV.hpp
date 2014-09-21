#ifndef NOVA_HEADER_COPY_CV
#define NOVA_HEADER_COPY_CV

#include "CopyVolatile.hpp"
#include "CopyConst.hpp"

namespace nova {
    template <typename Subject, typename Bearer>
    using CopyCV = CopyVolatile<CopyConst<Subject, Bearer>, Bearer>;
}

#endif
