#ifndef AREV_INT_H
#define AREV_INT_H

/// Safe integer operations.
///
/// More specifically, all functions defined in this file are guaranteed to
/// never cause undefined behavior. That being said, no guarantees are given
/// about the state of out variables if these functions return any other result
/// than ERROR_NONE.
///
/// @file

#include <stddef.h>
#include <stdint.h>
#include "err.h"

err_t int_AddI8(int8_t a, int8_t b, int8_t *out);
err_t int_AddI16(int16_t a, int16_t b, int16_t *out);
err_t int_AddI32(int32_t a, int32_t b, int32_t *out);
err_t int_AddI64(int64_t a, int64_t b, int64_t *out);
err_t int_AddU8(uint8_t a, uint8_t b, uint8_t *out);
err_t int_AddU16(uint16_t a, uint16_t b, uint16_t *out);
err_t int_AddU32(uint32_t a, uint32_t b, uint32_t *out);
err_t int_AddU64(uint64_t a, uint64_t b, uint64_t *out);
err_t int_AddSize(size_t a, size_t b, size_t *out);

err_t int_DivI8(int8_t a, int8_t b, int8_t *out);
err_t int_DivI16(int16_t a, int16_t b, int16_t *out);
err_t int_DivI32(int32_t a, int32_t b, int32_t *out);
err_t int_DivI64(int64_t a, int64_t b, int64_t *out);
err_t int_DivU8(uint8_t a, uint8_t b, uint8_t *out);
err_t int_DivU16(uint16_t a, uint16_t b, uint16_t *out);
err_t int_DivU32(uint32_t a, uint32_t b, uint32_t *out);
err_t int_DivU64(uint64_t a, uint64_t b, uint64_t *out);
err_t int_DivSize(size_t a, size_t b, size_t *out);

err_t int_ModI8(int8_t a, int8_t b, int8_t *out);
err_t int_ModI16(int16_t a, int16_t b, int16_t *out);
err_t int_ModI32(int32_t a, int32_t b, int32_t *out);
err_t int_ModI64(int64_t a, int64_t b, int64_t *out);
err_t int_ModU8(uint8_t a, uint8_t b, uint8_t *out);
err_t int_ModU16(uint16_t a, uint16_t b, uint16_t *out);
err_t int_ModU32(uint32_t a, uint32_t b, uint32_t *out);
err_t int_ModU64(uint64_t a, uint64_t b, uint64_t *out);
err_t int_ModSize(size_t a, size_t b, size_t *out);

err_t int_MulI8(int8_t a, int8_t b, int8_t *out);
err_t int_MulI16(int16_t a, int16_t b, int16_t *out);
err_t int_MulI32(int32_t a, int32_t b, int32_t *out);
err_t int_MulI64(int64_t a, int64_t b, int64_t *out);
err_t int_MulU8(uint8_t a, uint8_t b, uint8_t *out);
err_t int_MulU16(uint16_t a, uint16_t b, uint16_t *out);
err_t int_MulU32(uint32_t a, uint32_t b, uint32_t *out);
err_t int_MulU64(uint64_t a, uint64_t b, uint64_t *out);
err_t int_MulSize(size_t a, size_t b, size_t *out);

err_t int_SubI8(int8_t a, int8_t b, int8_t *out);
err_t int_SubI16(int16_t a, int16_t b, int16_t *out);
err_t int_SubI32(int32_t a, int32_t b, int32_t *out);
err_t int_SubI64(int64_t a, int64_t b, int64_t *out);
err_t int_SubU8(uint8_t a, uint8_t b, uint8_t *out);
err_t int_SubU16(uint16_t a, uint16_t b, uint16_t *out);
err_t int_SubU32(uint32_t a, uint32_t b, uint32_t *out);
err_t int_SubU64(uint64_t a, uint64_t b, uint64_t *out);
err_t int_SubSize(size_t a, size_t b, size_t *out);

err_t int_CastI8ToU8(int8_t in, uint8_t *out);
err_t int_CastI8ToU16(int8_t in, uint16_t *out);
err_t int_CastI8ToU32(int8_t in, uint32_t *out);
err_t int_CastI8ToU64(int8_t in, uint64_t *out);
err_t int_CastI8ToSize(int8_t in, size_t *out);

err_t int_CastI16ToI8(int16_t in, int8_t *out);
err_t int_CastI16ToU8(int16_t in, uint8_t *out);
err_t int_CastI16ToU16(int16_t in, uint16_t *out);
err_t int_CastI16ToU32(int16_t in, uint32_t *out);
err_t int_CastI16ToU64(int16_t in, uint64_t *out);
err_t int_CastI16ToSize(int16_t in, size_t *out);

err_t int_CastI32ToI8(int32_t in, int8_t *out);
err_t int_CastI32ToI16(int32_t in, int16_t *out);
err_t int_CastI32ToU8(int32_t in, uint8_t *out);
err_t int_CastI32ToU16(int32_t in, uint16_t *out);
err_t int_CastI32ToU32(int32_t in, uint32_t *out);
err_t int_CastI32ToU64(int32_t in, uint64_t *out);
err_t int_CastI32ToSize(int32_t in, size_t *out);

err_t int_CastI64ToI8(int64_t in, int8_t *out);
err_t int_CastI64ToI16(int64_t in, int16_t *out);
err_t int_CastI64ToI32(int64_t in, int32_t *out);
err_t int_CastI64ToU8(int64_t in, uint8_t *out);
err_t int_CastI64ToU16(int64_t in, uint16_t *out);
err_t int_CastI64ToU32(int64_t in, uint32_t *out);
err_t int_CastI64ToU64(int64_t in, uint64_t *out);
err_t int_CastI64ToSize(int64_t in, size_t *out);

err_t int_CastU8ToI8(uint8_t in, int8_t *out);
err_t int_CastU8ToSize(uint8_t in, size_t *out);

err_t int_CastU16ToI8(uint16_t in, int8_t *out);
err_t int_CastU16ToI16(uint16_t in, int16_t *out);
err_t int_CastU16ToU8(uint16_t in, uint8_t *out);
err_t int_CastU16ToSize(uint16_t in, size_t *out);

err_t int_CastU32ToI8(uint32_t in, int8_t *out);
err_t int_CastU32ToI16(uint32_t in, int16_t *out);
err_t int_CastU32ToI32(uint32_t in, int32_t *out);
err_t int_CastU32ToU8(uint32_t in, uint8_t *out);
err_t int_CastU32ToU16(uint32_t in, uint16_t *out);
err_t int_CastU32ToSize(uint32_t in, size_t *out);

err_t int_CastU64ToI8(uint64_t in, int8_t *out);
err_t int_CastU64ToI16(uint64_t in, int16_t *out);
err_t int_CastU64ToI32(uint64_t in, int32_t *out);
err_t int_CastU64ToI64(uint64_t in, int64_t *out);
err_t int_CastU64ToU8(uint64_t in, uint8_t *out);
err_t int_CastU64ToU16(uint64_t in, uint16_t *out);
err_t int_CastU64ToU32(uint64_t in, uint32_t *out);
err_t int_CastU64ToSize(uint64_t in, size_t *out);

err_t int_CastSizeToI8(size_t in, int8_t *out);
err_t int_CastSizeToI16(size_t in, int16_t *out);
err_t int_CastSizeToI32(size_t in, int32_t *out);
err_t int_CastSizeToI64(size_t in, int64_t *out);
err_t int_CastSizeToU8(size_t in, uint8_t *out);
err_t int_CastSizeToU16(size_t in, uint16_t *out);
err_t int_CastSizeToU32(size_t in, uint32_t *out);
err_t int_CastSizeToU64(size_t in, uint64_t *out);

#endif
