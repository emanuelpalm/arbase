#include <arev/error.h>
#include <string.h>

const char *arev_ErrorAsCStr(arev_Error error) {
    switch (error) {
#define AREV_ERROR(CODE, NAME, DESCRIPTION, ...) \
    case AREV_ERROR_##NAME: return DESCRIPTION;
#include <arev/error.inc>
#undef AREV_ERROR
        default:
            return strerror(error);
    }
}
