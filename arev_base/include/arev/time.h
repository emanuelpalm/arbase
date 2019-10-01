#ifndef AREV_TIME_H
#define AREV_TIME_H

#include <stdint.h>
#include "error.h"

struct arev_Time;

typedef struct arev_Time arev_Time;

/// Time between two instants.
struct arev_Time {
    /// Duration, in microseconds.
    int64_t us;
};

/// Gets duration since the Unix Epoch (1970-01-01 00:00:00 GMT).
arev_Error arev_Now(arev_Time *out);

arev_Error arev_AddTime(arev_Time a, arev_Time b, arev_Time *out);
arev_Error arev_SubTime(arev_Time a, arev_Time b, arev_Time *out);

#endif
