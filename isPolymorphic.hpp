#ifndef NOVA_HEADER_isPolymorphic
#define NOVA_HEADER_isPolymorphic

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isPolymorphic() {
        return ::std::is_polymorphic<Type>::value;
    }
}

#endif
