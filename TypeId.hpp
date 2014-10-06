#ifndef NOVA_HEADER_TypeId
#define NOVA_HEADER_TypeId

#include "API.hpp"
#include "Bool.hpp"
#include "UInt.hpp"
#include "hash.hpp"

#include <typeinfo>

namespace nova {
    class NOVA_API TypeId final {
    public:
        TypeId(::std::type_info const& typeInfo)
            : typeInfoPtr(&typeInfo)
        {}

        friend Bool operator==(TypeId const& a, TypeId const& b) {
            return *a.typeInfoPtr == *b.typeInfoPtr;
        }

        friend Bool operator!=(TypeId const& a, TypeId const& b) {
            return *a.typeInfoPtr != *b.typeInfoPtr;
        }

        friend Bool operator<(TypeId const& a, TypeId const& b) {
            return (*a.typeInfoPtr).before(*b.typeInfoPtr);
        }

        friend Bool operator<=(TypeId const& a, TypeId const& b) {
            return !(a > b);
        }

        friend Bool operator>(TypeId const& a, TypeId const& b) {
            return (*b.typeInfoPtr).before(*a.typeInfoPtr);
        }

        friend Bool operator>=(TypeId const& a, TypeId const& b) {
            return !(a < b);
        }

        friend UInt hash(TypeId const& typeId) {
            return (*typeId.typeInfoPtr).hash_code();
        }

    private:
        ::std::type_info const* typeInfoPtr;
    };
}

#endif
