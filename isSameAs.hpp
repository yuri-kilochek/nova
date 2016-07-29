#ifndef NOVA_HEADER_isSameAs
#define NOVA_HEADER_isSameAs

#include "Boolean.hpp"

#include <type_traits>

namespace nova {
    template <typename A, typename B>
    static constexpr Boolean const isSameAs = ::std::is_same<A, B>::value;
}

#endif
