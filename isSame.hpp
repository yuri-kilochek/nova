#ifndef NOVA_HEADER_IS_SAME
#define NOVA_HEADER_IS_SAME

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename TypeA, typename TypeB>
    inline constexpr Bool isSame() {
        return ::std::is_same<TypeA, TypeB>::value;
    }
}

#endif
