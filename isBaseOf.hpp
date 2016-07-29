#ifndef NOVA_HEADER_isBaseOf
#define NOVA_HEADER_isBaseOf

#include "Boolean.hpp"

#include <type_traits>

namespace nova {
    template <typename MaybeBase, typename MaybeDerived>
    static constexpr Boolean const isBaseOf = ::std::is_base_of<MaybeBase, MaybeDerived>::value;
}

#endif
