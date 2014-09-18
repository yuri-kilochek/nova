#ifndef NOVA_HEADER_TYPE_ID
#define NOVA_HEADER_TYPE_ID

#include "API.hpp"
#include "Bool.hpp"
#include "EnableIf.hpp"
#include "isSame.hpp"
#include "UInt.hpp"

#include <typeinfo>

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

            template <typename MaybeTypeId, EnableIf<isSame<MaybeTypeId, TypeId>()>...>
            friend UInt hash(MaybeTypeId const& typeId) {
                return typeId.typeInfoPtr->hash_code();
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

#define NOVA_TYPE_ID(...) (                                        \
    [&]{                                                           \
        try {                                                      \
            return ::nova::internals::typeId(typeid(__VA_ARGS__)); \
        } catch (::std::bad_typeid&) {                             \
            /* TODO: panic here */                                 \
        }                                                          \
    }()                                                            \
)

#endif
