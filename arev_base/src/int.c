#include "int.h"

#ifdef AREV_GCC
#define GEN_ADD(NAME, TYPE)                      \
    inline                                       \
    err_Num NAME(TYPE a, TYPE b, TYPE *out) {    \
        return __builtin_add_overflow(a, b, out) \
            ? ERROR_INT_OVERFLOW                 \
            : ERROR_NONE;                        \
    }
#define GEN_MUL(NAME, TYPE)                      \
    inline                                       \
    err_Num NAME(TYPE a, TYPE b, TYPE *out) {    \
        return __builtin_mul_overflow(a, b, out) \
            ? ERROR_INT_OVERFLOW                 \
            : ERROR_NONE;                        \
    }
#define GEN_SUB(NAME, TYPE)                      \
    inline                                       \
    err_Num NAME(TYPE a, TYPE b, TYPE *out) {    \
        return __builtin_sub_overflow(a, b, out) \
            ? ERROR_INT_UNDERFLOW                \
            : ERROR_NONE;                        \
    }
#else
#error No known checked integer operation intrinsics are available.
#endif

GEN_ADD(int_AddI8, int8_t)
GEN_ADD(int_AddI16,int16_t)
GEN_ADD(int_AddI32,int32_t)
GEN_ADD(int_AddI64,int64_t)
GEN_ADD(int_AddU8,uint8_t)
GEN_ADD(int_AddU16,uint16_t)
GEN_ADD(int_AddU32,uint32_t)
GEN_ADD(int_AddU64,uint64_t)

GEN_MUL(int_MulI8, int8_t)
GEN_MUL(int_MulI16, int16_t)
GEN_MUL(int_MulI32, int32_t)
GEN_MUL(int_MulI64, int64_t)
GEN_MUL(int_MulU8, uint8_t)
GEN_MUL(int_MulU16, uint16_t)
GEN_MUL(int_MulU32, uint32_t)
GEN_MUL(int_MulU64, uint64_t)

GEN_SUB(int_SubI8, int8_t)
GEN_SUB(int_SubI16, int16_t)
GEN_SUB(int_SubI32, int32_t)
GEN_SUB(int_SubI64, int64_t)
GEN_SUB(int_SubU8, uint8_t)
GEN_SUB(int_SubU16, uint16_t)
GEN_SUB(int_SubU32, uint32_t)
GEN_SUB(int_SubU64, uint64_t)
