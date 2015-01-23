#ifndef NOVA_HEADER_DECLRET
#define NOVA_HEADER_DECLRET

#define NOVA_DECLRET(...) \
    decltype(__VA_ARGS__) { return __VA_ARGS__; }

#endif
