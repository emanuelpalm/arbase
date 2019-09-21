#ifndef AREV_INT_H
#define AREV_INT_H

/// Safe integer operations.
///
/// By safe, it is implied that use of these functions must never cause
/// undefined behavior.
///
/// @file

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
err_t int_MulI8(int8_t a, int8_t b, int8_t *out);
err_t int_MulI16(int16_t a, int16_t b, int16_t *out);
err_t int_MulI32(int32_t a, int32_t b, int32_t *out);
err_t int_MulI64(int64_t a, int64_t b, int64_t *out);
err_t int_MulU8(uint8_t a, uint8_t b, uint8_t *out);
err_t int_MulU16(uint16_t a, uint16_t b, uint16_t *out);
err_t int_MulU32(uint32_t a, uint32_t b, uint32_t *out);
err_t int_MulU64(uint64_t a, uint64_t b, uint64_t *out);
err_t int_SubI8(int8_t a, int8_t b, int8_t *out);
err_t int_SubI16(int16_t a, int16_t b, int16_t *out);
err_t int_SubI32(int32_t a, int32_t b, int32_t *out);
err_t int_SubI64(int64_t a, int64_t b, int64_t *out);
err_t int_SubU8(uint8_t a, uint8_t b, uint8_t *out);
err_t int_SubU16(uint16_t a, uint16_t b, uint16_t *out);
err_t int_SubU32(uint32_t a, uint32_t b, uint32_t *out);
err_t int_SubU64(uint64_t a, uint64_t b, uint64_t *out);

err_t int_CastI8ToU8(int8_t in, uint8_t *out);
err_t int_CastI8ToU16(int8_t in, uint16_t *out);
err_t int_CastI8ToU32(int8_t in, uint32_t *out);
err_t int_CastI8ToU64(int8_t in, uint64_t *out);
err_t int_CastI16ToI8(int16_t in, int8_t *out);
err_t int_CastI16ToU8(int16_t in, uint8_t *out);
err_t int_CastI16ToU16(int16_t in, uint16_t *out);
err_t int_CastI16ToU32(int16_t in, uint32_t *out);
err_t int_CastI16ToU64(int16_t in, uint64_t *out);
err_t int_CastI32ToI8(int32_t in, int8_t *out);
err_t int_CastI32ToI16(int32_t in, int16_t *out);
err_t int_CastI32ToU8(int32_t in, uint8_t *out);
err_t int_CastI32ToU16(int32_t in, uint16_t *out);
err_t int_CastI32ToU32(int32_t in, uint32_t *out);
err_t int_CastI32ToU64(int32_t in, uint64_t *out);
err_t int_CastI64ToI8(int64_t in, int8_t *out);
err_t int_CastI64ToI16(int64_t in, int16_t *out);
err_t int_CastI64ToI32(int64_t in, int32_t *out);
err_t int_CastI64ToU8(int64_t in, uint8_t *out);
err_t int_CastI64ToU16(int64_t in, uint16_t *out);
err_t int_CastI64ToU32(int64_t in, uint32_t *out);
err_t int_CastI64ToU64(int64_t in, uint64_t *out);
err_t int_CastU8ToI8(uint8_t in, int8_t *out);
err_t int_CastU16ToI8(uint16_t in, int8_t *out);
err_t int_CastU16ToI16(uint16_t in, int16_t *out);
err_t int_CastU16ToU8(uint16_t in, uint8_t *out);
err_t int_CastU32ToI8(uint32_t in, int8_t *out);
err_t int_CastU32ToI16(uint32_t in, int16_t *out);
err_t int_CastU32ToI32(uint32_t in, int32_t *out);
err_t int_CastU32ToU8(uint32_t in, uint8_t *out);
err_t int_CastU32ToU16(uint32_t in, uint16_t *out);
err_t int_CastU64ToI8(uint64_t in, int8_t *out);
err_t int_CastU64ToI16(uint64_t in, int16_t *out);
err_t int_CastU64ToI32(uint64_t in, int32_t *out);
err_t int_CastU64ToI64(uint64_t in, int64_t *out);
err_t int_CastU64ToU8(uint64_t in, uint8_t *out);
err_t int_CastU64ToU16(uint64_t in, uint16_t *out);
err_t int_CastU64ToU32(uint64_t in, uint32_t *out);

#endif
