#include <arev/mem/endianness.h>
#include <arev/mem/reader.h>
#include <string.h>

inline
void arev_InitReader(arev_Reader *reader, const uint8_t *data, size_t len) {
    reader->offset = data;
    reader->end = &data[len];
}

inline
void arev_InitReaderFromCStr(arev_Reader *reader, const char *c_str) {
    arev_InitReader(reader, (uint8_t *) c_str, strlen(c_str));
}

#define GEN_WRITE(NAME, TYPE, SWAP)                      \
inline                                                  \
bool NAME(arev_Reader *reader, TYPE *out) {             \
    if (reader->offset + sizeof(TYPE) <= reader->end) { \
        *out = SWAP(((TYPE *) reader->offset)[0]);      \
        reader->offset = &reader->offset[sizeof(TYPE)]; \
        return true;                                    \
    }                                                   \
    return false;                                       \
}

GEN_WRITE(arev_ReadI8, int8_t, )
GEN_WRITE(arev_ReadI16BE, int16_t, AREV_FROM_BE16)
GEN_WRITE(arev_ReadI32BE, int32_t, AREV_FROM_BE32)
GEN_WRITE(arev_ReadI64BE, int64_t, AREV_FROM_BE64)
GEN_WRITE(arev_ReadI16LE, int16_t, AREV_FROM_LE16)
GEN_WRITE(arev_ReadI32LE, int32_t, AREV_FROM_LE32)
GEN_WRITE(arev_ReadI64LE, int64_t, AREV_FROM_LE64)
GEN_WRITE(arev_ReadU8, uint8_t, )
GEN_WRITE(arev_ReadU16BE, uint16_t, AREV_FROM_BE16)
GEN_WRITE(arev_ReadU32BE, uint32_t, AREV_FROM_BE32)
GEN_WRITE(arev_ReadU64BE, uint64_t, AREV_FROM_BE64)
GEN_WRITE(arev_ReadU16LE, uint16_t, AREV_FROM_LE16)
GEN_WRITE(arev_ReadU32LE, uint32_t, AREV_FROM_LE32)
GEN_WRITE(arev_ReadU64LE, uint64_t, AREV_FROM_LE64)
