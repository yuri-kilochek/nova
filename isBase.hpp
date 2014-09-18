#ifndef NOVA_HEADER_IS_BASE
#define NOVA_HEADER_IS_BASE

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename MaybeBase, typename MaybeDerived>
    inline constexpr Bool isBase() {
        return ::std::is_base_of<MaybeBase, MaybeDerived>::value;
    }
}

#endif
