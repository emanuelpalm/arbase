#ifndef AREV_MEM_WRITER_H
#define AREV_MEM_WRITER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// A writable sequences of bytes (octets).
typedef struct {
    /// Current writer offset.
    uint8_t *offset;

    /// Pointer to first byte after writer memory.
    const uint8_t *end;
} arev_Writer;

/// Initializes `writer` from given `data` pointer and byte length.
void arev_InitWriter(arev_Writer *writer, uint8_t *data, size_t len);

bool arev_WriteI8(arev_Writer *writer, int8_t value);
bool arev_WriteI16BE(arev_Writer *writer, int16_t value);
bool arev_WriteI32BE(arev_Writer *writer, int32_t value);
bool arev_WriteI64BE(arev_Writer *writer, int64_t value);
bool arev_WriteI16LE(arev_Writer *writer, int16_t value);
bool arev_WriteI32LE(arev_Writer *writer, int32_t value);
bool arev_WriteI64LE(arev_Writer *writer, int64_t value);
bool arev_WriteU8(arev_Writer *writer, uint8_t value);
bool arev_WriteU16BE(arev_Writer *writer, uint16_t value);
bool arev_WriteU32BE(arev_Writer *writer, uint32_t value);
bool arev_WriteU64BE(arev_Writer *writer, uint64_t value);
bool arev_WriteU16LE(arev_Writer *writer, uint16_t value);
bool arev_WriteU32LE(arev_Writer *writer, uint32_t value);
bool arev_WriteU64LE(arev_Writer *writer, uint64_t value);

#endif
