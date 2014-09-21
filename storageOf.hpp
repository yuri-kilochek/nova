#ifndef NOVA_HEADER_STORAGE_OF
#define NOVA_HEADER_STORAGE_OF

#include "EnableIf.hpp"
#include "isPolymorphic.hpp"
#include "CopyCV.hpp"
#include "Void.hpp"

namespace nova {
    template <typename Type, EnableIf<isPolymorphic<Type>()>...>
    inline auto storageOf(Type* object) {
        return dynamic_cast<CopyCV<Void, Type>*>(object);
    }

    template <typename Type, EnableIf<!isPolymorphic<Type>()>...>
    inline auto storageOf(Type* object) {
        return static_cast<CopyCV<Void, Type>*>(object);
    }
}

#endif
