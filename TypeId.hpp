#ifndef NOVA_HEADER_TYPE_ID
#define NOVA_HEADER_TYPE_ID

#include "API.hpp"
#include "Bool.hpp"
#include "EnableIf.hpp"
#include "areSame.hpp"
#include "UInt.hpp"

#include <typeinfo>

namespace nova {
    class NOVA_API TypeId final {
        public:
            template <typename Type>
            friend TypeId typeId() {
                return {typeid(Type)};
            };

            template <typename Type>
            friend TypeId typeId(Type const& object) {
                return {typeid(object)};
            };

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

            template <typename MaybeTypeId, EnableIf<areSame<MaybeTypeId, TypeId>()>...>
            friend UInt hash(MaybeTypeId const& typeId) {
                return (*typeId.typeInfoPtr).hash_code();
            }

        private:
            ::std::type_info const* typeInfoPtr;

            TypeId(::std::type_info const& typeInfo)
                : typeInfoPtr(&typeInfo)
            {}
    };
}

#endif
