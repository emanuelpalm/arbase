#include <string.h>
#include "err.h"

const char *err_AsCStr(err_t err) {
    switch (err) {
#define AREV_ERROR(CODE, NAME, DESCRIPTION) case NAME: return DESCRIPTION;
#include <arev/error.inc>
#undef AREV_ERROR
        default:
            return strerror(err);
    }
}
