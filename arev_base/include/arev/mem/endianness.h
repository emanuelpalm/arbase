#ifndef AREV_MEM_ENDIANNESS_H
#define AREV_MEM_ENDIANNESS_H

#ifdef AREV_GCC

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define AREV_INTO_BE16(X) __builtin_bswap16 (X)
#define AREV_INTO_BE32(X) __builtin_bswap32 (X)
#define AREV_INTO_BE64(X) __builtin_bswap64 (X)
#define AREV_INTO_LE16(X) (X)
#define AREV_INTO_LE32(X) (X)
#define AREV_INTO_LE64(X) (X)
#define AREV_FROM_BE16(X) __builtin_bswap16 (X)
#define AREV_FROM_BE32(X) __builtin_bswap32 (X)
#define AREV_FROM_BE64(X) __builtin_bswap64 (X)
#define AREV_FROM_LE16(X) (X)
#define AREV_FROM_LE32(X) (X)
#define AREV_FROM_LE64(X) (X)
# else
#define AREV_INTO_BE16(X) (X)
#define AREV_INTO_BE32(X) (X)
#define AREV_INTO_BE64(X) (X)
#define AREV_INTO_LE16(X) __builtin_bswap16 (X)
#define AREV_INTO_LE32(X) __builtin_bswap_32 (X)
#define AREV_INTO_LE64(X) __builtin_bswap_64 (X)
#define AREV_FROM_BE16(X) (X)
#define AREV_FROM_BE32(X) (X)
#define AREV_FROM_BE64(X) (X)
#define AREV_FROM_LE16(X) __builtin_bswap16 (X)
#define AREV_FROM_LE32(X) __builtin_bswap_32 (X)
#define AREV_FROM_LE64(X) __builtin_bswap_64 (X)
#endif

#else
#error No supported endianess conversion implementations.
#endif

#endif
