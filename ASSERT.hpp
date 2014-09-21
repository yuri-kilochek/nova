#ifndef NOVA_HEADER_ASSERT
#define NOVA_HEADER_ASSERT

#ifdef NOVA_DEBUG
    #define NOVA_ASSERT(...) do { /* TODO: actually implement assertion here */ } while (false)
#else
    #define NOVA_ASSERT(...) do {} while (false)
#endif

#endif
