#ifndef AREV_MEM_READER_H
#define AREV_MEM_READER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// A readable sequences of bytes (octets).
typedef struct {
    /// Current reader offset.
    const uint8_t *offset;

    /// Pointer to first byte after reader memory.
    const uint8_t *end;
} arev_Reader;

/// Initializes `reader` from given `data` pointer and byte length.
void arev_InitReader(arev_Reader *reader, const uint8_t *data, size_t len);

/// Initializes `reader` from given C-string pointer.
void arev_InitReaderFromCStr(arev_Reader *reader, const char *c_str);

bool arev_ReadI8(arev_Reader *reader, int8_t *out);
bool arev_ReadI16BE(arev_Reader *reader, int16_t *out);
bool arev_ReadI32BE(arev_Reader *reader, int32_t *out);
bool arev_ReadI64BE(arev_Reader *reader, int64_t *out);
bool arev_ReadI16LE(arev_Reader *reader, int16_t *out);
bool arev_ReadI32LE(arev_Reader *reader, int32_t *out);
bool arev_ReadI64LE(arev_Reader *reader, int64_t *out);
bool arev_ReadU8(arev_Reader *reader, uint8_t *out);
bool arev_ReadU16BE(arev_Reader *reader, uint16_t *out);
bool arev_ReadU32BE(arev_Reader *reader, uint32_t *out);
bool arev_ReadU64BE(arev_Reader *reader, uint64_t *out);
bool arev_ReadU16LE(arev_Reader *reader, uint16_t *out);
bool arev_ReadU32LE(arev_Reader *reader, uint32_t *out);
bool arev_ReadU64LE(arev_Reader *reader, uint64_t *out);

#endif
