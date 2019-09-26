#include <arev/mem/endianness.h>
#include <arev/mem/writer.h>
#include <string.h>

inline
void arev_InitWriter(arev_Writer *reader, uint8_t *data, size_t len) {
    reader->offset = data;
    reader->end = &data[len];
}

#define GEN_WRITE(NAME, TYPE, SWAP)                     \
inline                                                  \
bool NAME(arev_Writer *writer, TYPE value) {            \
    if (writer->offset + sizeof(TYPE) <= writer->end) { \
        ((TYPE *) writer->offset)[0] = SWAP(value);     \
        writer->offset = &writer->offset[sizeof(TYPE)]; \
        return true;                                    \
    }                                                   \
    return false;                                       \
}

GEN_WRITE(arev_WriteI8, int8_t, )
GEN_WRITE(arev_WriteI16BE, int16_t, AREV_INTO_BE16)
GEN_WRITE(arev_WriteI32BE, int32_t, AREV_INTO_BE32)
GEN_WRITE(arev_WriteI64BE, int64_t, AREV_INTO_BE64)
GEN_WRITE(arev_WriteI16LE, int16_t, AREV_INTO_LE16)
GEN_WRITE(arev_WriteI32LE, int32_t, AREV_INTO_LE32)
GEN_WRITE(arev_WriteI64LE, int64_t, AREV_INTO_LE64)
GEN_WRITE(arev_WriteU8, uint8_t, )
GEN_WRITE(arev_WriteU16BE, uint16_t, AREV_INTO_BE16)
GEN_WRITE(arev_WriteU32BE, uint32_t, AREV_INTO_BE32)
GEN_WRITE(arev_WriteU64BE, uint64_t, AREV_INTO_BE64)
GEN_WRITE(arev_WriteU16LE, uint16_t, AREV_INTO_LE16)
GEN_WRITE(arev_WriteU32LE, uint32_t, AREV_INTO_LE32)
GEN_WRITE(arev_WriteU64LE, uint64_t, AREV_INTO_LE64)
