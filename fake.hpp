#ifndef NOVA_HEADER_FAKE
#define NOVA_HEADER_FAKE

namespace nova {
    template <typename Value>
    inline constexpr Value&& fake(); // Not defined intentionally. Should only appear in unevaluated context.
}

#endif
