#ifndef NOVA_INCLUDE_GUARD_TYPE_ID_HPP
#define NOVA_INCLUDE_GUARD_TYPE_ID_HPP

#include <typeinfo>

#include "API.hpp"
#include "Bool.hpp"
#include "UInt.hpp"

namespace nova {
    class TypeId;

    namespace internals {
        constexpr TypeId typeId(::std::type_info const& typeInfo);
    }

    class NOVA_API TypeId final {
        friend constexpr TypeId internals::typeId(::std::type_info const& typeInfo);
        public:
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
                return (UInt)typeId.typeInfoPtr->hash_code();
            }

        private:
            ::std::type_info const* typeInfoPtr;

            constexpr TypeId(::std::type_info const& typeInfo)
                : typeInfoPtr(&typeInfo)
            {}
    };

    namespace internals {
        inline constexpr TypeId typeId(::std::type_info const& typeInfo) {
            return {typeInfo};
        }
    }
}

#define typeid(...) (                                               \
    [&]{                                                            \
        try {                                                       \
            return ::nova::internals::typeId(typeid(__VA_ARGS__));  \
        } catch (::std::bad_typeid&) {                              \
            /* TODO: panic here */                                  \
        }                                                           \
    }()                                                             \
)

#endif
