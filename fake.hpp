#ifndef NOVA_HEADER_fake
#define NOVA_HEADER_fake

namespace nova {
    template <typename Type>
    constexpr Type&& fake(); // Not defined intentionally. Should only appear in unevaluated context.
}

#endif
