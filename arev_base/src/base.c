#include <arev/base.h>
#include "err.h"

inline
const char *arev_ErrorAsCStr(const arev_Error err) {
    return err_AsCStr((err_t) err);
}
