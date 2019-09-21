#include "int.h"

#ifdef AREV_GCC

#define GEN_ADD(NAME, TYPE)                  \
inline                                       \
err_t NAME(TYPE a, TYPE b, TYPE *out) {      \
    return __builtin_add_overflow(a, b, out) \
        ? ERROR_INT_OVERFLOW                 \
        : ERROR_NONE;                        \
}

#define GEN_MUL(NAME, TYPE)                  \
inline                                       \
err_t NAME(TYPE a, TYPE b, TYPE *out) {      \
    return __builtin_mul_overflow(a, b, out) \
        ? ERROR_INT_OVERFLOW                 \
        : ERROR_NONE;                        \
}

#define GEN_SUB(NAME, TYPE)                  \
inline                                       \
err_t NAME(TYPE a, TYPE b, TYPE *out) {      \
    return __builtin_sub_overflow(a, b, out) \
        ? ERROR_INT_UNDERFLOW                \
        : ERROR_NONE;                        \
}

#else
#error No known checked integer operation intrinsics are available.
#endif

#define GEN_DIV(NAME, TYPE)                  \
inline                                       \
err_t NAME(TYPE a, TYPE b, TYPE *out) {      \
    if (b == 0) {                            \
        return ERROR_INT_DIVZERO;            \
    }                                        \
    *out = a / b;                            \
    return ERROR_NONE;                       \
}

#define GEN_MOD(NAME, TYPE)                  \
inline                                       \
err_t NAME(TYPE a, TYPE b, TYPE *out) {      \
    if (b == 0) {                            \
        return ERROR_INT_MODZERO;            \
    }                                        \
    *out = a % b;                            \
    return ERROR_NONE;                       \
}

GEN_ADD(int_AddI8, int8_t)
GEN_ADD(int_AddI16, int16_t)
GEN_ADD(int_AddI32, int32_t)
GEN_ADD(int_AddI64, int64_t)
GEN_ADD(int_AddU8, uint8_t)
GEN_ADD(int_AddU16, uint16_t)
GEN_ADD(int_AddU32, uint32_t)
GEN_ADD(int_AddU64, uint64_t)
GEN_ADD(int_AddSize, size_t)

GEN_DIV(int_DivI8, int8_t)
GEN_DIV(int_DivI16, int16_t)
GEN_DIV(int_DivI32, int32_t)
GEN_DIV(int_DivI64, int64_t)
GEN_DIV(int_DivU8, uint8_t)
GEN_DIV(int_DivU16, uint16_t)
GEN_DIV(int_DivU32, uint32_t)
GEN_DIV(int_DivU64, uint64_t)
GEN_DIV(int_DivSize, size_t)

GEN_MOD(int_ModI8, int8_t)
GEN_MOD(int_ModI16, int16_t)
GEN_MOD(int_ModI32, int32_t)
GEN_MOD(int_ModI64, int64_t)
GEN_MOD(int_ModU8, uint8_t)
GEN_MOD(int_ModU16, uint16_t)
GEN_MOD(int_ModU32, uint32_t)
GEN_MOD(int_ModU64, uint64_t)
GEN_MOD(int_ModSize, size_t)

GEN_MUL(int_MulI8, int8_t)
GEN_MUL(int_MulI16, int16_t)
GEN_MUL(int_MulI32, int32_t)
GEN_MUL(int_MulI64, int64_t)
GEN_MUL(int_MulU8, uint8_t)
GEN_MUL(int_MulU16, uint16_t)
GEN_MUL(int_MulU32, uint32_t)
GEN_MUL(int_MulU64, uint64_t)
GEN_MUL(int_MulSize, size_t)

GEN_SUB(int_SubI8, int8_t)
GEN_SUB(int_SubI16, int16_t)
GEN_SUB(int_SubI32, int32_t)
GEN_SUB(int_SubI64, int64_t)
GEN_SUB(int_SubU8, uint8_t)
GEN_SUB(int_SubU16, uint16_t)
GEN_SUB(int_SubU32, uint32_t)
GEN_SUB(int_SubU64, uint64_t)
GEN_SUB(int_SubSize, size_t)

#define GEN_CAST_IX_TO_IX(NAME, TYPE_IN, TYPE_OUT, TYPE_OUT_MIN, TYPE_OUT_MAX) \
inline                                                                         \
err_t NAME(TYPE_IN in, TYPE_OUT *out) {                                        \
    if (in < TYPE_OUT_MIN) {                                                   \
        return ERROR_INT_UNDERFLOW;                                            \
    }                                                                          \
    if (in > TYPE_OUT_MAX) {                                                   \
        return ERROR_INT_OVERFLOW;                                             \
    }                                                                          \
    *out = (TYPE_OUT) in;                                                      \
    return ERROR_NONE;                                                         \
}

#define GEN_CAST_UX_TO_XX(NAME, TYPE_IN, TYPE_OUT, TYPE_OUT_MAX) \
inline                                                           \
err_t NAME(TYPE_IN in, TYPE_OUT *out) {                          \
    if (in > TYPE_OUT_MAX) {                                     \
        return ERROR_INT_OVERFLOW;                               \
    }                                                            \
    *out = (TYPE_OUT) in;                                        \
    return ERROR_NONE;                                           \
}

#define GEN_CAST_IX_TO_UX(NAME, TYPE_IN, TYPE_OUT) \
inline                                             \
err_t NAME(TYPE_IN in, TYPE_OUT *out) {            \
    if (in < 0) {                                  \
        return ERROR_INT_UNDERFLOW;                \
    }                                              \
    *out = (TYPE_OUT) in;                          \
    return ERROR_NONE;                             \
}

#define GEN_CAST_UNCHECKED(NAME, TYPE_IN, TYPE_OUT) \
inline                                              \
err_t NAME(TYPE_IN in, TYPE_OUT *out) {             \
    *out = (TYPE_OUT) in;                           \
    return ERROR_NONE;                              \
}

GEN_CAST_IX_TO_UX(int_CastI8ToU8, int8_t, uint8_t)
GEN_CAST_IX_TO_UX(int_CastI8ToU16, int8_t, uint16_t)
GEN_CAST_IX_TO_UX(int_CastI8ToU32, int8_t, uint32_t)
GEN_CAST_IX_TO_UX(int_CastI8ToU64, int8_t, uint64_t)
GEN_CAST_IX_TO_UX(int_CastI8ToSize, int8_t, size_t)

GEN_CAST_IX_TO_IX(int_CastI16ToI8, int16_t, int8_t, INT8_MIN, INT8_MAX)
GEN_CAST_IX_TO_UX(int_CastI16ToU8, int16_t, uint8_t)
GEN_CAST_IX_TO_UX(int_CastI16ToU16, int16_t, uint16_t)
GEN_CAST_IX_TO_UX(int_CastI16ToU32, int16_t, uint32_t)
GEN_CAST_IX_TO_UX(int_CastI16ToU64, int16_t, uint64_t)
GEN_CAST_IX_TO_UX(int_CastI16ToSize, int16_t, size_t)

GEN_CAST_IX_TO_IX(int_CastI32ToI8, int32_t, int8_t, INT8_MIN, INT8_MAX)
GEN_CAST_IX_TO_IX(int_CastI32ToI16, int32_t, int16_t, INT16_MIN, INT16_MAX)
GEN_CAST_IX_TO_UX(int_CastI32ToU8, int32_t, uint8_t)
GEN_CAST_IX_TO_UX(int_CastI32ToU16, int32_t, uint16_t)
GEN_CAST_IX_TO_UX(int_CastI32ToU32, int32_t, uint32_t)
GEN_CAST_IX_TO_UX(int_CastI32ToU64, int32_t, uint64_t)
GEN_CAST_IX_TO_UX(int_CastI32ToSize, int32_t, size_t)

GEN_CAST_IX_TO_IX(int_CastI64ToI8, int64_t, int8_t, INT8_MIN, INT8_MAX)
GEN_CAST_IX_TO_IX(int_CastI64ToI16, int64_t, int16_t, INT16_MIN, INT16_MAX)
GEN_CAST_IX_TO_IX(int_CastI64ToI32, int64_t, int32_t, INT32_MIN, INT32_MAX)
GEN_CAST_IX_TO_UX(int_CastI64ToU8, int64_t, uint8_t)
GEN_CAST_IX_TO_UX(int_CastI64ToU16, int64_t, uint16_t)
GEN_CAST_IX_TO_UX(int_CastI64ToU32, int64_t, uint32_t)
GEN_CAST_IX_TO_UX(int_CastI64ToU64, int64_t, uint64_t)
GEN_CAST_IX_TO_UX(int_CastI64ToSize, int64_t, size_t)

GEN_CAST_UX_TO_XX(int_CastU8ToI8, uint8_t, int8_t, INT8_MAX)
#if UINT8_MAX > SIZE_MAX
GEN_CAST_UX_TO_XX(int_CastU8ToSize, uint8_t, size_t , SIZE_MAX)
#else
GEN_CAST_UNCHECKED(int_CastU8ToSize, uint8_t, size_t)
#endif

GEN_CAST_UX_TO_XX(int_CastU16ToI8, uint16_t, int8_t, INT8_MAX)
GEN_CAST_UX_TO_XX(int_CastU16ToI16, uint16_t, int16_t, INT16_MAX)
GEN_CAST_UX_TO_XX(int_CastU16ToU8, uint16_t, uint8_t, UINT8_MAX)
#if UINT16_MAX > SIZE_MAX
GEN_CAST_UX_TO_XX(int_CastU16ToSize, uint16_t, size_t, SIZE_MAX)
#else
GEN_CAST_UNCHECKED(int_CastU16ToSize, uint16_t, size_t)
#endif

GEN_CAST_UX_TO_XX(int_CastU32ToI8, uint32_t, int8_t, INT8_MAX)
GEN_CAST_UX_TO_XX(int_CastU32ToI16, uint32_t, int16_t, INT16_MAX)
GEN_CAST_UX_TO_XX(int_CastU32ToI32, uint32_t, int32_t, INT32_MAX)
GEN_CAST_UX_TO_XX(int_CastU32ToU8, uint32_t, uint8_t, UINT8_MAX)
GEN_CAST_UX_TO_XX(int_CastU32ToU16, uint32_t, uint16_t, UINT16_MAX)
#if UINT32_MAX > SIZE_MAX
GEN_CAST_UX_TO_XX(int_CastU32ToSize, uint32_t, size_t, SIZE_MAX)
#else
GEN_CAST_UNCHECKED(int_CastU32ToSize, uint32_t, size_t)
#endif

GEN_CAST_UX_TO_XX(int_CastU64ToI8, uint64_t, int8_t, INT8_MAX)
GEN_CAST_UX_TO_XX(int_CastU64ToI16, uint64_t, int16_t, INT16_MAX)
GEN_CAST_UX_TO_XX(int_CastU64ToI32, uint64_t, int32_t, INT32_MAX)
GEN_CAST_UX_TO_XX(int_CastU64ToI64, uint64_t, int64_t, INT64_MAX)
GEN_CAST_UX_TO_XX(int_CastU64ToU8, uint64_t, uint8_t, UINT8_MAX)
GEN_CAST_UX_TO_XX(int_CastU64ToU16, uint64_t, uint16_t, UINT16_MAX)
GEN_CAST_UX_TO_XX(int_CastU64ToU32, uint64_t, uint32_t, UINT32_MAX)
#if UINT64_MAX > SIZE_MAX
GEN_CAST_UX_TO_XX(int_CastU64ToSize, uint64_t, size_t, SIZE_MAX)
#else
GEN_CAST_UNCHECKED(int_CastU64ToSize, uint64_t, size_t)
#endif

GEN_CAST_UX_TO_XX(int_CastSizeToI8, size_t, int8_t, INT8_MAX)
GEN_CAST_UX_TO_XX(int_CastSizeToI16, size_t, int16_t, INT16_MAX)
GEN_CAST_UX_TO_XX(int_CastSizeToI32, size_t, int32_t, INT32_MAX)
GEN_CAST_UX_TO_XX(int_CastSizeToI64, size_t, int64_t, INT64_MAX)
#if SIZE_MAX > UINT8_MAX
GEN_CAST_UX_TO_XX(int_CastSizeToU8, size_t, uint8_t, UINT8_MAX)
#else
GEN_CAST_UNCHECKED(int_CastSizeToU8, size_t, uint8_t)
#endif
#if SIZE_MAX > UINT16_MAX
GEN_CAST_UX_TO_XX(int_CastSizeToU16, size_t, uint16_t, UINT16_MAX)
#else
GEN_CAST_UNCHECKED(int_CastSizeToU16, size_t, uint16_t)
#endif
#if SIZE_MAX > UINT32_MAX
GEN_CAST_UX_TO_XX(int_CastSizeToU32, size_t, uint32_t, UINT32_MAX)
#else
GEN_CAST_UNCHECKED(int_CastSizeToU32, size_t, uint32_t)
#endif
#if SIZE_MAX > UINT64_MAX
GEN_CAST_UX_TO_XX(int_CastSizeToU64, size_t, uint64_t, UINT64_MAX)
#else
GEN_CAST_UNCHECKED(int_CastSizeToU64, size_t, uint64_t)
#endif
