#ifndef NOVA_HEADER_Decay
#define NOVA_HEADER_Decay

#include <type_traits>

namespace nova {
    template <typename Type>
    using Decay = typename ::std::decay<Type>::type;
}

#endif
