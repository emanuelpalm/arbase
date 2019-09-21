#ifndef AREV_ERR_H
#define AREV_ERR_H

typedef enum {
#define AREV_ERROR(CODE, NAME, ...) NAME = CODE,
#include <arev/error.inc>
#undef AREV_ERROR
} err_t;

const char *err_AsCStr(err_t err);

#endif
