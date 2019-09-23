#ifndef AREV_MATH_H
#define AREV_MATH_H

/// Safe integer operations.
///
/// More specifically, all functions defined in this file are guaranteed to
/// never cause undefined behavior. That being said, no guarantees are given
/// about the state of out variables if these functions return any other
/// results than ERROR_NONE.
///
/// @file

#include <stddef.h>
#include <stdint.h>
#include "error.h"

arev_Error arev_AddI8(int8_t a, int8_t b, int8_t *out);
arev_Error arev_AddI16(int16_t a, int16_t b, int16_t *out);
arev_Error arev_AddI32(int32_t a, int32_t b, int32_t *out);
arev_Error arev_AddI64(int64_t a, int64_t b, int64_t *out);
arev_Error arev_AddU8(uint8_t a, uint8_t b, uint8_t *out);
arev_Error arev_AddU16(uint16_t a, uint16_t b, uint16_t *out);
arev_Error arev_AddU32(uint32_t a, uint32_t b, uint32_t *out);
arev_Error arev_AddU64(uint64_t a, uint64_t b, uint64_t *out);
arev_Error arev_AddSize(size_t a, size_t b, size_t *out);

arev_Error arev_DivI8(int8_t a, int8_t b, int8_t *out);
arev_Error arev_DivI16(int16_t a, int16_t b, int16_t *out);
arev_Error arev_DivI32(int32_t a, int32_t b, int32_t *out);
arev_Error arev_DivI64(int64_t a, int64_t b, int64_t *out);
arev_Error arev_DivU8(uint8_t a, uint8_t b, uint8_t *out);
arev_Error arev_DivU16(uint16_t a, uint16_t b, uint16_t *out);
arev_Error arev_DivU32(uint32_t a, uint32_t b, uint32_t *out);
arev_Error arev_DivU64(uint64_t a, uint64_t b, uint64_t *out);
arev_Error arev_DivSize(size_t a, size_t b, size_t *out);

arev_Error arev_ModI8(int8_t a, int8_t b, int8_t *out);
arev_Error arev_ModI16(int16_t a, int16_t b, int16_t *out);
arev_Error arev_ModI32(int32_t a, int32_t b, int32_t *out);
arev_Error arev_ModI64(int64_t a, int64_t b, int64_t *out);
arev_Error arev_ModU8(uint8_t a, uint8_t b, uint8_t *out);
arev_Error arev_ModU16(uint16_t a, uint16_t b, uint16_t *out);
arev_Error arev_ModU32(uint32_t a, uint32_t b, uint32_t *out);
arev_Error arev_ModU64(uint64_t a, uint64_t b, uint64_t *out);
arev_Error arev_ModSize(size_t a, size_t b, size_t *out);

arev_Error arev_MulI8(int8_t a, int8_t b, int8_t *out);
arev_Error arev_MulI16(int16_t a, int16_t b, int16_t *out);
arev_Error arev_MulI32(int32_t a, int32_t b, int32_t *out);
arev_Error arev_MulI64(int64_t a, int64_t b, int64_t *out);
arev_Error arev_MulU8(uint8_t a, uint8_t b, uint8_t *out);
arev_Error arev_MulU16(uint16_t a, uint16_t b, uint16_t *out);
arev_Error arev_MulU32(uint32_t a, uint32_t b, uint32_t *out);
arev_Error arev_MulU64(uint64_t a, uint64_t b, uint64_t *out);
arev_Error arev_MulSize(size_t a, size_t b, size_t *out);

arev_Error arev_SubI8(int8_t a, int8_t b, int8_t *out);
arev_Error arev_SubI16(int16_t a, int16_t b, int16_t *out);
arev_Error arev_SubI32(int32_t a, int32_t b, int32_t *out);
arev_Error arev_SubI64(int64_t a, int64_t b, int64_t *out);
arev_Error arev_SubU8(uint8_t a, uint8_t b, uint8_t *out);
arev_Error arev_SubU16(uint16_t a, uint16_t b, uint16_t *out);
arev_Error arev_SubU32(uint32_t a, uint32_t b, uint32_t *out);
arev_Error arev_SubU64(uint64_t a, uint64_t b, uint64_t *out);
arev_Error arev_SubSize(size_t a, size_t b, size_t *out);

arev_Error arev_CastI8ToU8(int8_t in, uint8_t *out);
arev_Error arev_CastI8ToU16(int8_t in, uint16_t *out);
arev_Error arev_CastI8ToU32(int8_t in, uint32_t *out);
arev_Error arev_CastI8ToU64(int8_t in, uint64_t *out);
arev_Error arev_CastI8ToSize(int8_t in, size_t *out);

arev_Error arev_CastI16ToI8(int16_t in, int8_t *out);
arev_Error arev_CastI16ToU8(int16_t in, uint8_t *out);
arev_Error arev_CastI16ToU16(int16_t in, uint16_t *out);
arev_Error arev_CastI16ToU32(int16_t in, uint32_t *out);
arev_Error arev_CastI16ToU64(int16_t in, uint64_t *out);
arev_Error arev_CastI16ToSize(int16_t in, size_t *out);

arev_Error arev_CastI32ToI8(int32_t in, int8_t *out);
arev_Error arev_CastI32ToI16(int32_t in, int16_t *out);
arev_Error arev_CastI32ToU8(int32_t in, uint8_t *out);
arev_Error arev_CastI32ToU16(int32_t in, uint16_t *out);
arev_Error arev_CastI32ToU32(int32_t in, uint32_t *out);
arev_Error arev_CastI32ToU64(int32_t in, uint64_t *out);
arev_Error arev_CastI32ToSize(int32_t in, size_t *out);

arev_Error arev_CastI64ToI8(int64_t in, int8_t *out);
arev_Error arev_CastI64ToI16(int64_t in, int16_t *out);
arev_Error arev_CastI64ToI32(int64_t in, int32_t *out);
arev_Error arev_CastI64ToU8(int64_t in, uint8_t *out);
arev_Error arev_CastI64ToU16(int64_t in, uint16_t *out);
arev_Error arev_CastI64ToU32(int64_t in, uint32_t *out);
arev_Error arev_CastI64ToU64(int64_t in, uint64_t *out);
arev_Error arev_CastI64ToSize(int64_t in, size_t *out);

arev_Error arev_CastU8ToI8(uint8_t in, int8_t *out);
arev_Error arev_CastU8ToSize(uint8_t in, size_t *out);

arev_Error arev_CastU16ToI8(uint16_t in, int8_t *out);
arev_Error arev_CastU16ToI16(uint16_t in, int16_t *out);
arev_Error arev_CastU16ToU8(uint16_t in, uint8_t *out);
arev_Error arev_CastU16ToSize(uint16_t in, size_t *out);

arev_Error arev_CastU32ToI8(uint32_t in, int8_t *out);
arev_Error arev_CastU32ToI16(uint32_t in, int16_t *out);
arev_Error arev_CastU32ToI32(uint32_t in, int32_t *out);
arev_Error arev_CastU32ToU8(uint32_t in, uint8_t *out);
arev_Error arev_CastU32ToU16(uint32_t in, uint16_t *out);
arev_Error arev_CastU32ToSize(uint32_t in, size_t *out);

arev_Error arev_CastU64ToI8(uint64_t in, int8_t *out);
arev_Error arev_CastU64ToI16(uint64_t in, int16_t *out);
arev_Error arev_CastU64ToI32(uint64_t in, int32_t *out);
arev_Error arev_CastU64ToI64(uint64_t in, int64_t *out);
arev_Error arev_CastU64ToU8(uint64_t in, uint8_t *out);
arev_Error arev_CastU64ToU16(uint64_t in, uint16_t *out);
arev_Error arev_CastU64ToU32(uint64_t in, uint32_t *out);
arev_Error arev_CastU64ToSize(uint64_t in, size_t *out);

arev_Error arev_CastSizeToI8(size_t in, int8_t *out);
arev_Error arev_CastSizeToI16(size_t in, int16_t *out);
arev_Error arev_CastSizeToI32(size_t in, int32_t *out);
arev_Error arev_CastSizeToI64(size_t in, int64_t *out);
arev_Error arev_CastSizeToU8(size_t in, uint8_t *out);
arev_Error arev_CastSizeToU16(size_t in, uint16_t *out);
arev_Error arev_CastSizeToU32(size_t in, uint32_t *out);
arev_Error arev_CastSizeToU64(size_t in, uint64_t *out);

#endif
