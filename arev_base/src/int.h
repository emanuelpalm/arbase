#ifndef AREV_INT_H
#define AREV_INT_H

#include <stdint.h>
#include "err.h"

err_Num int_AddI8(int8_t a, int8_t b, int8_t *out);
err_Num int_AddI16(int16_t a, int16_t b, int16_t *out);
err_Num int_AddI32(int32_t a, int32_t b, int32_t *out);
err_Num int_AddI64(int64_t a, int64_t b, int64_t *out);
err_Num int_AddU8(uint8_t a, uint8_t b, uint8_t *out);
err_Num int_AddU16(uint16_t a, uint16_t b, uint16_t *out);
err_Num int_AddU32(uint32_t a, uint32_t b, uint32_t *out);
err_Num int_AddU64(uint64_t a, uint64_t b, uint64_t *out);

err_Num int_MulI8(int8_t a, int8_t b, int8_t *out);
err_Num int_MulI16(int16_t a, int16_t b, int16_t *out);
err_Num int_MulI32(int32_t a, int32_t b, int32_t *out);
err_Num int_MulI64(int64_t a, int64_t b, int64_t *out);
err_Num int_MulU8(uint8_t a, uint8_t b, uint8_t *out);
err_Num int_MulU16(uint16_t a, uint16_t b, uint16_t *out);
err_Num int_MulU32(uint32_t a, uint32_t b, uint32_t *out);
err_Num int_MulU64(uint64_t a, uint64_t b, uint64_t *out);

err_Num int_SubI8(int8_t a, int8_t b, int8_t *out);
err_Num int_SubI16(int16_t a, int16_t b, int16_t *out);
err_Num int_SubI32(int32_t a, int32_t b, int32_t *out);
err_Num int_SubI64(int64_t a, int64_t b, int64_t *out);
err_Num int_SubU8(uint8_t a, uint8_t b, uint8_t *out);
err_Num int_SubU16(uint16_t a, uint16_t b, uint16_t *out);
err_Num int_SubU32(uint32_t a, uint32_t b, uint32_t *out);
err_Num int_SubU64(uint64_t a, uint64_t b, uint64_t *out);

#endif
