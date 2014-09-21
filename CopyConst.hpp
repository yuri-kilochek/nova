#ifndef NOVA_HEADER_COPY_CONST
#define NOVA_HEADER_COPY_CONST

namespace nova {
    namespace internals {
        template <typename Subject, typename Bearer>
        struct CopyConst {
            using Type = Subject;
        };

        template <typename Subject, typename Bearer>
        struct CopyConst<Subject, Bearer const> {
            using Type = Subject const;
        };
    }

    template <typename Subject, typename Bearer>
    using CopyConst = typename internals::CopyConst<Subject, Bearer>::Type;
}

#endif
