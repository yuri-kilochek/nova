#ifndef NOVA_INCLUDE_GUARD_COMPILER_HPP
#define NOVA_INCLUDE_GUARD_COMPILER_HPP

#if defined(_MSC_VER)
    #define NOVA_COMPILER_MSVC
#elif defined(__GNUC__)
    #define NOVA_COMPILER_GCC
#elif defined(__clang__)
    #define NOVA_COMPILER_CLANG
#else
    #error
#endif

#endif
