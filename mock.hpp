#ifndef NOVA_HEADER_MOCK
#define NOVA_HEADER_MOCK

namespace nova {
    template <typename Value>
    inline constexpr Value&& mock(); // Not defined intentionally. Should only appear in unevaluated context.
}

#endif
