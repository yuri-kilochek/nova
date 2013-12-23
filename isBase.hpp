#ifndef NOVA_INCLUDE_GUARD_IS_BASE_HPP
#define NOVA_INCLUDE_GUARD_IS_BASE_HPP

#include "Bool.hpp"
#include "isSame.hpp"

namespace nova {
    namespace internals {
        template <typename MaybeBase, typename MaybeDerived>
        class IsBase {
            private:
                struct Host {
                    operator MaybeBase*() const;
                    operator MaybeDerived*();
                };

                struct Dummy {};

                struct Yes {};
                struct No {};

                template <typename T>
                static Yes test(MaybeDerived*, T);
                static No test(MaybeBase*, Dummy);

            public:
                static constexpr Bool value = isSame<decltype(test(Host(), Dummy())), Yes>();
        };
    }

    template <typename MaybeBase, typename MaybeDerived>
    inline constexpr Bool isBase() {
        return internals::IsBase<MaybeBase, MaybeDerived>::value;
    }
}

#endif
