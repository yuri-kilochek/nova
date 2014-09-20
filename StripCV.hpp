#ifndef NOVA_HEADER_STRIP_CV
#define NOVA_HEADER_STRIP_CV

#include <type_traits>

namespace nova {
    template <typename Type>
    using StripCV = typename ::std::remove_cv<Type>::type;
}

#endif

