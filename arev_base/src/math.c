#include "arev/math.h"

#ifdef AREV_GCC

#define GEN_ADD(NAME, TYPE)                  \
inline                                       \
arev_Error NAME(TYPE a, TYPE b, TYPE *out) { \
    return __builtin_add_overflow(a, b, out) \
        ? AREV_ERROR_MATH_OVERFLOW           \
        : AREV_ERROR_NONE;                   \
}

#define GEN_MUL(NAME, TYPE)                  \
inline                                       \
arev_Error NAME(TYPE a, TYPE b, TYPE *out) { \
    return __builtin_mul_overflow(a, b, out) \
        ? AREV_ERROR_MATH_OVERFLOW           \
        : AREV_ERROR_NONE;                   \
}

#define GEN_SUB(NAME, TYPE)                  \
inline                                       \
arev_Error NAME(TYPE a, TYPE b, TYPE *out) { \
    return __builtin_sub_overflow(a, b, out) \
        ? AREV_ERROR_MATH_UNDERFLOW          \
        : AREV_ERROR_NONE;                   \
}

#else
#error No known checked integer operation intrinsics are available.
#endif

#define GEN_DIV(NAME, TYPE)                  \
inline                                       \
arev_Error NAME(TYPE a, TYPE b, TYPE *out) { \
    if (b == 0) {                            \
        return AREV_ERROR_MATH_DIVZERO;      \
    }                                        \
    *out = a / b;                            \
    return AREV_ERROR_NONE;                  \
}

#define GEN_MOD(NAME, TYPE)                  \
inline                                       \
arev_Error NAME(TYPE a, TYPE b, TYPE *out) { \
    if (b == 0) {                            \
        return AREV_ERROR_MATH_MODZERO;      \
    }                                        \
    *out = a % b;                            \
    return AREV_ERROR_NONE;                  \
}

GEN_ADD(arev_AddI8, int8_t)
GEN_ADD(arev_AddI16, int16_t)
GEN_ADD(arev_AddI32, int32_t)
GEN_ADD(arev_AddI64, int64_t)
GEN_ADD(arev_AddU8, uint8_t)
GEN_ADD(arev_AddU16, uint16_t)
GEN_ADD(arev_AddU32, uint32_t)
GEN_ADD(arev_AddU64, uint64_t)
GEN_ADD(arev_AddSize, size_t)

GEN_DIV(arev_DivI8, int8_t)
GEN_DIV(arev_DivI16, int16_t)
GEN_DIV(arev_DivI32, int32_t)
GEN_DIV(arev_DivI64, int64_t)
GEN_DIV(arev_DivU8, uint8_t)
GEN_DIV(arev_DivU16, uint16_t)
GEN_DIV(arev_DivU32, uint32_t)
GEN_DIV(arev_DivU64, uint64_t)
GEN_DIV(arev_DivSize, size_t)

GEN_MOD(arev_ModI8, int8_t)
GEN_MOD(arev_ModI16, int16_t)
GEN_MOD(arev_ModI32, int32_t)
GEN_MOD(arev_ModI64, int64_t)
GEN_MOD(arev_ModU8, uint8_t)
GEN_MOD(arev_ModU16, uint16_t)
GEN_MOD(arev_ModU32, uint32_t)
GEN_MOD(arev_ModU64, uint64_t)
GEN_MOD(arev_ModSize, size_t)

GEN_MUL(arev_MulI8, int8_t)
GEN_MUL(arev_MulI16, int16_t)
GEN_MUL(arev_MulI32, int32_t)
GEN_MUL(arev_MulI64, int64_t)
GEN_MUL(arev_MulU8, uint8_t)
GEN_MUL(arev_MulU16, uint16_t)
GEN_MUL(arev_MulU32, uint32_t)
GEN_MUL(arev_MulU64, uint64_t)
GEN_MUL(arev_MulSize, size_t)

GEN_SUB(arev_SubI8, int8_t)
GEN_SUB(arev_SubI16, int16_t)
GEN_SUB(arev_SubI32, int32_t)
GEN_SUB(arev_SubI64, int64_t)
GEN_SUB(arev_SubU8, uint8_t)
GEN_SUB(arev_SubU16, uint16_t)
GEN_SUB(arev_SubU32, uint32_t)
GEN_SUB(arev_SubU64, uint64_t)
GEN_SUB(arev_SubSize, size_t)

#define GEN_CAST_IX_TO_IX(NAME, TYPE_IN, TYPE_OUT, TYPE_OUT_MIN, TYPE_OUT_MAX) \
inline                                                                         \
arev_Error NAME(TYPE_IN in, TYPE_OUT *out) {                                   \
    if (in < TYPE_OUT_MIN) {                                                   \
        return AREV_ERROR_MATH_UNDERFLOW;                                      \
    }                                                                          \
    if (in > TYPE_OUT_MAX) {                                                   \
        return AREV_ERROR_MATH_OVERFLOW;                                       \
    }                                                                          \
    *out = (TYPE_OUT) in;                                                      \
    return AREV_ERROR_NONE;                                                    \
}

#define GEN_CAST_UX_TO_XX(NAME, TYPE_IN, TYPE_OUT, TYPE_OUT_MAX) \
inline                                                           \
arev_Error NAME(TYPE_IN in, TYPE_OUT *out) {                     \
    if (in > TYPE_OUT_MAX) {                                     \
        return AREV_ERROR_MATH_OVERFLOW;                         \
    }                                                            \
    *out = (TYPE_OUT) in;                                        \
    return AREV_ERROR_NONE;                                      \
}

#define GEN_CAST_IX_TO_UX(NAME, TYPE_IN, TYPE_OUT) \
inline                                             \
arev_Error NAME(TYPE_IN in, TYPE_OUT *out) {       \
    if (in < 0) {                                  \
        return AREV_ERROR_MATH_UNDERFLOW;          \
    }                                              \
    *out = (TYPE_OUT) in;                          \
    return AREV_ERROR_NONE;                        \
}

#define GEN_CAST_UNCHECKED(NAME, TYPE_IN, TYPE_OUT) \
inline                                              \
arev_Error NAME(TYPE_IN in, TYPE_OUT *out) {        \
    *out = (TYPE_OUT) in;                           \
    return AREV_ERROR_NONE;                         \
}

GEN_CAST_IX_TO_UX(arev_CastI8ToU8, int8_t, uint8_t)
GEN_CAST_IX_TO_UX(arev_CastI8ToU16, int8_t, uint16_t)
GEN_CAST_IX_TO_UX(arev_CastI8ToU32, int8_t, uint32_t)
GEN_CAST_IX_TO_UX(arev_CastI8ToU64, int8_t, uint64_t)
GEN_CAST_IX_TO_UX(arev_CastI8ToSize, int8_t, size_t)

GEN_CAST_IX_TO_IX(arev_CastI16ToI8, int16_t, int8_t, INT8_MIN, INT8_MAX)
GEN_CAST_IX_TO_UX(arev_CastI16ToU8, int16_t, uint8_t)
GEN_CAST_IX_TO_UX(arev_CastI16ToU16, int16_t, uint16_t)
GEN_CAST_IX_TO_UX(arev_CastI16ToU32, int16_t, uint32_t)
GEN_CAST_IX_TO_UX(arev_CastI16ToU64, int16_t, uint64_t)
GEN_CAST_IX_TO_UX(arev_CastI16ToSize, int16_t, size_t)

GEN_CAST_IX_TO_IX(arev_CastI32ToI8, int32_t, int8_t, INT8_MIN, INT8_MAX)
GEN_CAST_IX_TO_IX(arev_CastI32ToI16, int32_t, int16_t, INT16_MIN, INT16_MAX)
GEN_CAST_IX_TO_UX(arev_CastI32ToU8, int32_t, uint8_t)
GEN_CAST_IX_TO_UX(arev_CastI32ToU16, int32_t, uint16_t)
GEN_CAST_IX_TO_UX(arev_CastI32ToU32, int32_t, uint32_t)
GEN_CAST_IX_TO_UX(arev_CastI32ToU64, int32_t, uint64_t)
GEN_CAST_IX_TO_UX(arev_CastI32ToSize, int32_t, size_t)

GEN_CAST_IX_TO_IX(arev_CastI64ToI8, int64_t, int8_t, INT8_MIN, INT8_MAX)
GEN_CAST_IX_TO_IX(arev_CastI64ToI16, int64_t, int16_t, INT16_MIN, INT16_MAX)
GEN_CAST_IX_TO_IX(arev_CastI64ToI32, int64_t, int32_t, INT32_MIN, INT32_MAX)
GEN_CAST_IX_TO_UX(arev_CastI64ToU8, int64_t, uint8_t)
GEN_CAST_IX_TO_UX(arev_CastI64ToU16, int64_t, uint16_t)
GEN_CAST_IX_TO_UX(arev_CastI64ToU32, int64_t, uint32_t)
GEN_CAST_IX_TO_UX(arev_CastI64ToU64, int64_t, uint64_t)
GEN_CAST_IX_TO_UX(arev_CastI64ToSize, int64_t, size_t)

GEN_CAST_UX_TO_XX(arev_CastU8ToI8, uint8_t, int8_t, INT8_MAX)
#if UINT8_MAX > SIZE_MAX
GEN_CAST_UX_TO_XX(arev_CastU8ToSize, uint8_t, size_t , SIZE_MAX)
#else
GEN_CAST_UNCHECKED(arev_CastU8ToSize, uint8_t, size_t)
#endif

GEN_CAST_UX_TO_XX(arev_CastU16ToI8, uint16_t, int8_t, INT8_MAX)
GEN_CAST_UX_TO_XX(arev_CastU16ToI16, uint16_t, int16_t, INT16_MAX)
GEN_CAST_UX_TO_XX(arev_CastU16ToU8, uint16_t, uint8_t, UINT8_MAX)
#if UINT16_MAX > SIZE_MAX
GEN_CAST_UX_TO_XX(arev_CastU16ToSize, uint16_t, size_t, SIZE_MAX)
#else
GEN_CAST_UNCHECKED(arev_CastU16ToSize, uint16_t, size_t)
#endif

GEN_CAST_UX_TO_XX(arev_CastU32ToI8, uint32_t, int8_t, INT8_MAX)
GEN_CAST_UX_TO_XX(arev_CastU32ToI16, uint32_t, int16_t, INT16_MAX)
GEN_CAST_UX_TO_XX(arev_CastU32ToI32, uint32_t, int32_t, INT32_MAX)
GEN_CAST_UX_TO_XX(arev_CastU32ToU8, uint32_t, uint8_t, UINT8_MAX)
GEN_CAST_UX_TO_XX(arev_CastU32ToU16, uint32_t, uint16_t, UINT16_MAX)
#if UINT32_MAX > SIZE_MAX
GEN_CAST_UX_TO_XX(arev_CastU32ToSize, uint32_t, size_t, SIZE_MAX)
#else
GEN_CAST_UNCHECKED(arev_CastU32ToSize, uint32_t, size_t)
#endif

GEN_CAST_UX_TO_XX(arev_CastU64ToI8, uint64_t, int8_t, INT8_MAX)
GEN_CAST_UX_TO_XX(arev_CastU64ToI16, uint64_t, int16_t, INT16_MAX)
GEN_CAST_UX_TO_XX(arev_CastU64ToI32, uint64_t, int32_t, INT32_MAX)
GEN_CAST_UX_TO_XX(arev_CastU64ToI64, uint64_t, int64_t, INT64_MAX)
GEN_CAST_UX_TO_XX(arev_CastU64ToU8, uint64_t, uint8_t, UINT8_MAX)
GEN_CAST_UX_TO_XX(arev_CastU64ToU16, uint64_t, uint16_t, UINT16_MAX)
GEN_CAST_UX_TO_XX(arev_CastU64ToU32, uint64_t, uint32_t, UINT32_MAX)
#if UINT64_MAX > SIZE_MAX
GEN_CAST_UX_TO_XX(arev_CastU64ToSize, uint64_t, size_t, SIZE_MAX)
#else
GEN_CAST_UNCHECKED(arev_CastU64ToSize, uint64_t, size_t)
#endif

GEN_CAST_UX_TO_XX(arev_CastSizeToI8, size_t, int8_t, INT8_MAX)
GEN_CAST_UX_TO_XX(arev_CastSizeToI16, size_t, int16_t, INT16_MAX)
GEN_CAST_UX_TO_XX(arev_CastSizeToI32, size_t, int32_t, INT32_MAX)
GEN_CAST_UX_TO_XX(arev_CastSizeToI64, size_t, int64_t, INT64_MAX)
#if SIZE_MAX > UINT8_MAX
GEN_CAST_UX_TO_XX(arev_CastSizeToU8, size_t, uint8_t, UINT8_MAX)
#else
GEN_CAST_UNCHECKED(arev_CastSizeToU8, size_t, uint8_t)
#endif
#if SIZE_MAX > UINT16_MAX
GEN_CAST_UX_TO_XX(arev_CastSizeToU16, size_t, uint16_t, UINT16_MAX)
#else
GEN_CAST_UNCHECKED(arev_CastSizeToU16, size_t, uint16_t)
#endif
#if SIZE_MAX > UINT32_MAX
GEN_CAST_UX_TO_XX(arev_CastSizeToU32, size_t, uint32_t, UINT32_MAX)
#else
GEN_CAST_UNCHECKED(arev_CastSizeToU32, size_t, uint32_t)
#endif
#if SIZE_MAX > UINT64_MAX
GEN_CAST_UX_TO_XX(arev_CastSizeToU64, size_t, uint64_t, UINT64_MAX)
#else
GEN_CAST_UNCHECKED(arev_CastSizeToU64, size_t, uint64_t)
#endif
