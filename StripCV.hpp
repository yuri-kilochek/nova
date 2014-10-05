#ifndef NOVA_HEADER_StripCV
#define NOVA_HEADER_StripCV

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripCV = typename ::std::remove_cv<Type>::type;
}

#endif

