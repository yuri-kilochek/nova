#ifndef NOVA_INCLUDE_GUARD_API_HPP
#define NOVA_INCLUDE_GUARD_API_HPP

#include "COMPILER.hpp"

#if !defined(NOVA_BUILD_STATIC)
    #if !defined(NOVA_BUILD_DYNAMIC_EXPORT) && !defined(NOVA_BUILD_DYNAMIC_IMPORT)
        #define NOVA_BUILD_STATIC
    #endif
#endif

#if defined(NOVA_COMPILER_MSVC)
    #if defined(NOVA_BUILD_STATIC)
        #define NOVA_API
    #elif defined(NOVA_BUILD_DYNAMIC_EXPORT)
        #define NOVA_API __declspec(dllexport)
    #elif defined(NOVA_BUILD_DYNAMIC_IMPORT)
        #define NOVA_API __declspec(dllimport)
    #endif
#elif defined(NOVA_COMPILER_GCC) // should be built with '-fvisibility=hidden'
    #if defined(NOVA_BUILD_STATIC)
        #define NOVA_API
    #elif defined(NOVA_BUILD_DYNAMIC_IMPORT)
        #define NOVA_API __attribute__((visibility("default")))
    #elif defined(NOVA_BUILD_DYNAMIC_EXPORT)
        #define NOVA_API __attribute__((visibility("default")))
    #endif
#elif defined(NOVA_COMPILER_CLANG) // should be built with '-fvisibility=hidden'
    #if defined(NOVA_BUILD_STATIC)
        #define NOVA_API
    #elif defined(NOVA_BUILD_DYNAMIC_EXPORT)
        #define NOVA_API __attribute__((visibility("default")))
    #elif defined(NOVA_BUILD_DYNAMIC_IMPORT)
        #define NOVA_API __attribute__((visibility("default")))
    #endif
#endif

#endif
