#ifndef AREV_BASE_H
#define AREV_BASE_H

typedef enum {
#define AREV_ERROR(CODE, NAME, ...) AREV_##NAME = CODE,
#include "error.inc"
#undef AREV_ERROR
} arev_Error;

const char *arev_ErrorAsCStr(arev_Error err);

#endif
