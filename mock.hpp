#ifndef NOVA_INCLUDE_GUARD_MOCK_HPP
#define NOVA_INCLUDE_GUARD_MOCK_HPP

namespace nova {
    template <typename Value>
    inline constexpr Value&& mock(); // Not defined intentionally. Should only appear in unevaluated context.
}

#endif
