#ifndef NOVA_HEADER_MEMORY
#define NOVA_HEADER_MEMORY

#include "API.hpp"
#include "Void.hpp"
#include "UInt.hpp"
#include "ASSERT.hpp"

namespace nova {
    namespace _internal_memory {
        NOVA_API Void* allocate(UInt alignment, UInt size);
        NOVA_API Void release(Void* ptr, UInt alignment, UInt size) noexcept;
    }

    inline Void* allocateMemory(UInt alignment, UInt size, UInt count = 1) {
        NOVA_ASSERT(alignment > 0 && isExp2(alignment));
        NOVA_ASSERT(size > 0 && size >= alignment);

        if (count == 0)
            return nullptr;
        return _internal_memory::allocate(alignment, size * count);
    }

    inline Void releaseMemory(Void* ptr, UInt alignment, UInt size, UInt count = 1) noexcept {
        NOVA_ASSERT(alignment > 0 && isExp2(alignment));
        NOVA_ASSERT(size > 0 && size >= alignment);
        NOVA_ASSERT((count == 0) == !ptr);

        if (!ptr)
            return;
        _internal_memory::release(ptr, alignment, size * count);
    }
}

#endif
