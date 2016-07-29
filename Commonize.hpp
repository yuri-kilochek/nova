#ifndef NOVA_HEADER_Commonize
#define NOVA_HEADER_Commonize

#include <type_traits>

namespace nova {
    template <typename... Types>
    using Commonize = typename ::std::common_type<Types...>::type;
}

#endif
