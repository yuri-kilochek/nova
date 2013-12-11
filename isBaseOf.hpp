#ifndef NOVA_INCLUDE_GUARD_IS_BASE_OF_HPP
#define NOVA_INCLUDE_GUARD_IS_BASE_OF_HPP

#include "Bool.hpp"
#include "isSameAs.hpp"

namespace nova {
    namespace internals {
        template <typename PotentialBase, typename PotentialDerived>
        class IsBaseOf {
            private:
                struct Host {
                    operator PotentialBase*() const;
                    operator PotentialDerived*();
                };

                struct Dummy {};

                struct Yes {};
                struct No {};

                template <typename T>
                static Yes test(PotentialDerived*, T);
                static No test(PotentialBase*, Dummy);

            public:
                static constexpr Bool value = isSameAs<decltype(test(Host(), Dummy())), Yes>();
        };
    }

    template <typename PotentialBase, typename PotentialDerived>
    inline constexpr Bool isBaseOf() {
        return internals::IsBaseOf<PotentialBase, PotentialDerived>::value;
    }
}

#endif
