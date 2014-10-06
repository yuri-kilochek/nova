#ifndef NOVA_HEADER_construct_destruct
#define NOVA_HEADER_construct_destruct

#include "Void.hpp"
#include "ASSERT.hpp"
#include "forward.hpp"
#include "storageOf.hpp"

namespace nova {
    template <typename Type, typename... Args>
    inline Type* construct(Void* storage, Args&&... args) {
        NOVA_ASSERT(storage);

        return new(storage) Type(forward<Args>(args)...);
    }

    template <typename Type>
    inline Void* destruct(Type* object) noexcept {
        NOVA_ASSERT(object);

        Void* storage = storageOf(object);
        object->~Type();
        return storage;
    }
}

#endif
