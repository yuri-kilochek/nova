#ifndef NOVA_HEADER_MemoryOrder
#define NOVA_HEADER_MemoryOrder

namespace nova {
    enum class MemoryOrder {
        NONE = 0b00,
        ACQUIRE = 0b01,
        RELEASE = 0b10,
        FULL = ACQUIRE | RELEASE,
    };
}

#endif
