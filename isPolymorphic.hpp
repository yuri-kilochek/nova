#ifndef NOVA_HEADER_IS_POLYMORPHIC
#define NOVA_HEADER_IS_POLYMORPHIC

#include "Bool.hpp"

#include <type_traits>

namespace nova {
    template <typename Type>
    inline constexpr Bool isPolymorphic() {
        return ::std::is_polymorphic<Type>::value;
    }
}

#endif
