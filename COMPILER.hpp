#ifndef NOVA_HEADER_COMPILER
#define NOVA_HEADER_COMPILER

#if defined(_MSC_VER)
    #define NOVA_COMPILER_MSVC
#elif defined(__GNUC__)
    #define NOVA_COMPILER_GCC
#elif defined(__clang__)
    #define NOVA_COMPILER_CLANG
#endif

#endif
