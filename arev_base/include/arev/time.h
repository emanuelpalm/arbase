#ifndef AREV_TIME_H
#define AREV_TIME_H

#include <stdint.h>
#include "error.h"

/// A duration that will never end.
#define AREV_DURATION_FOREVER ((arev_Duration){.us = INT64_MIN})

/// A point in time that will never occur.
#define AREV_INSTANT_NEVER ((arev_Instant){.us = INT64_MIN})

struct arev_Duration;
struct arev_Instant;

typedef struct arev_Duration arev_Duration;
typedef struct arev_Instant arev_Instant;

/// Time relative to some arbitrary point in time.
struct arev_Duration {
    /// Duration, in microseconds.
    int64_t us;
};

/// Time elapsed since the Unix Epoch (1970-01-01 00:00:00 GMT).
struct arev_Instant {
    /// Time elapsed, in microseconds.
    int64_t us;
};

/// Gets current time, with at least millisecond precision.
arev_Error arev_Now(arev_Instant *out);

#endif
