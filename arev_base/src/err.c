#include <string.h>
#include "err.h"

const char *err_AsCStr(err_Num errnum) {
    switch (errnum) {
#define AREV_ERROR(CODE, NAME, DESCRIPTION) case NAME: return DESCRIPTION;
#include <arev/error.inc>
#undef AREV_ERROR
        default:
            return strerror(errnum);
    }
}
