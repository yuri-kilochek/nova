#ifndef NOVA_HEADER_COPY_VOLATILE
#define NOVA_HEADER_COPY_VOLATILE

namespace nova {
    namespace internals {
        template <typename Subject, typename Bearer>
        struct CopyVolatile {
            using Type = Subject;
        };

        template <typename Subject, typename Bearer>
        struct CopyVolatile<Subject, Bearer volatile> {
            using Type = Subject volatile;
        };
    }

    template <typename Subject, typename Bearer>
    using CopyVolatile = typename internals::CopyVolatile<Subject, Bearer>::Type;
}

#endif
