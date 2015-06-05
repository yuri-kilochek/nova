#ifndef NOVA_HEADER_TypeId
#define NOVA_HEADER_TypeId

#include "API.hpp"
#include "Bool.hpp"
#include "UInt.hpp"
#include "hash.hpp"

#include <typeinfo>

namespace nova {
    struct TypeId;

    namespace _internal_TypeId {
        struct Default {};

        TypeId make(::std::type_info const& typeInfo);
    }
    
    struct NOVA_API TypeId final {
        TypeId()
            : TypeId{typeid(_internal_TypeId::Default)}
        {}

        friend TypeId _internal_TypeId::make(::std::type_info const& typeInfo);

        friend Bool operator==(TypeId const& a, TypeId const& b) {
            return *a.typeInfo == *b.typeInfo;
        }

        friend Bool operator!=(TypeId const& a, TypeId const& b) {
            return *a.typeInfo != *b.typeInfo;
        }

        friend Bool operator<(TypeId const& a, TypeId const& b) {
            return a.typeInfo->before(*b.typeInfo);
        }

        friend Bool operator<=(TypeId const& a, TypeId const& b) {
            return !(a > b);
        }

        friend Bool operator>(TypeId const& a, TypeId const& b) {
            return b.typeInfo->before(*a.typeInfo);
        }

        friend Bool operator>=(TypeId const& a, TypeId const& b) {
            return !(a < b);
        }

        friend UInt hash(TypeId const& typeId) {
            return typeId.typeInfo->hash_code();
        }

    private:
        ::std::type_info const* typeInfo;

        TypeId(::std::type_info const& typeInfo)
            : typeInfo{&typeInfo}
        {}
    };

    namespace _internal_TypeId {
        inline TypeId make(::std::type_info const& typeInfo) {
            return {typeInfo};
        }
    }
}

#define NOVA_TYPE_ID(...) ( \
    [&]{ \
        try { \
            return ::nova::_internal_TypeId::make(typeid(__VA_ARGS__)); \
        } catch (::std::bad_typeid&) { \
            return ::nova::TypeId{}; \
        } \
    }() \
)

#endif
