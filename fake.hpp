#ifndef NOVA_HEADER_FAKE
#define NOVA_HEADER_FAKE

namespace nova {
    template <typename Type>
    constexpr Type&& fake(); // Not defined intentionally. Should only appear in unevaluated context.
}

#endif
