#ifndef NOVA_HEADER_memory
#define NOVA_HEADER_memory

#include "API.hpp"
#include "Void.hpp"
#include "UInt.hpp"

namespace nova {
    namespace memory {
        NOVA_API Void* allocate(UInt alignment, UInt size);
        NOVA_API Void release(UInt alignment, UInt size, Void* ptr) noexcept;
    }
}

#endif
