#ifndef NOVA_HEADER_API
#define NOVA_HEADER_API

#include "COMPILER.hpp"

#if defined(NOVA_BUILD_IMPORT) && defined(NOVA_BUILD_EXPORT)
    #error "You cannot import and export simultaneously."
#endif

#if defined(NOVA_COMPILER_MSVC)
    #if defined(NOVA_BUILD_EXPORT)
        #define NOVA_API __declspec(dllexport)
    #elif defined(NOVA_BUILD_IMPORT)
        #define NOVA_API __declspec(dllimport)
    #endif
#elif defined(NOVA_COMPILER_GCC) // should be built with '-fvisibility=hidden'
    #if defined(NOVA_BUILD_IMPORT) || defined(NOVA_BUILD_EXPORT)
        #define NOVA_API __attribute__((visibility("default")))
    #endif
#elif defined(NOVA_COMPILER_CLANG) // should be built with '-fvisibility=hidden'
    #if defined(NOVA_BUILD_IMPORT) || defined(NOVA_BUILD_EXPORT)
        #define NOVA_API __attribute__((visibility("default")))
    #endif
#else
    #if defined(NOVA_BUILD_IMPORT) || defined(NOVA_BUILD_EXPORT)
        #error "Dynamic linking not implemented for this compiler."
    #endif
#endif

#ifndef NOVA_API
    #define NOVA_API
#endif

#endif
