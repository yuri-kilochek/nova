#ifndef NOVA_HEADER_STORAGE_OF
#define NOVA_HEADER_STORAGE_OF

#include "EnableIf.hpp"
#include "isPolymorphic.hpp"
#include "ASSERT.hpp"
#include "CopyCV.hpp"
#include "Void.hpp"

namespace nova {
    template <typename Type, EnableIf<isPolymorphic<Type>()>...>
    inline auto storageOf(Type* object) {
        NOVA_ASSERT(object);
        return dynamic_cast<CopyCV<Void, Type>*>(object);
    }

    template <typename Type, EnableIf<!isPolymorphic<Type>()>...>
    inline auto storageOf(Type* object) {
        NOVA_ASSERT(object);
        return static_cast<CopyCV<Void, Type>*>(object);
    }
}

#endif
