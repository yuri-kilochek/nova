#ifndef NOVA_HEADER_isBaseOf
#define NOVA_HEADER_isBaseOf

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename MaybeBase, typename MaybeDerived>
    inline constexpr Bool isBaseOf() {
        return ::std::is_base_of<MaybeBase, MaybeDerived>::value;
    }
}

#endif
