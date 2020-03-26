#ifndef AREV_TIME_H
#define AREV_TIME_H

#include <stdint.h>
#include "error.h"

/// A duration that will never end.
#define AREV_FOREVER ((arev_Duration){.s = INT64_MAX})

/// A point in time that will never occur.
#define AREV_NEVER ((arev_Instant){.s = INT64_MAX})

struct arev_Duration;
struct arev_Instant;

typedef struct arev_Duration arev_Duration;
typedef struct arev_Instant arev_Instant;

/// Time relative to some arbitrary point in time.
struct arev_Duration {
    /// Duration, in seconds. May be negative.
    int64_t s;

    // Nanosecond adjustment. Must be in range [0,999999999]
    int64_t ns;
};

/// Time elapsed since the Unix Epoch (1970-01-01 00:00:00 GMT).
struct arev_Instant {
    /// Time elapsed, in seconds. Must be zero or positive.
    int64_t s;

    /// Nonsecond adjustment. Must be in range [0,999999999]
    int64_t ns;
};

/// Gets current time, with at least millisecond precision.
arev_Error arev_Now(arev_Instant *out);

/// Adds duration to duration.
arev_Error arev_AddDuration(arev_Duration duration, arev_Duration *out);

/// Adds duration to instant.
arev_Error arev_AddDurationToInstant(arev_Duration duration, arev_Instant *out);

/// Subtracts duration from duration.
arev_Error arev_SubDuration(arev_Duration duration, arev_Duration *out);

/// Subtracts duration from instant.
arev_Error arev_SubDurationFromInstant(arev_Duration duration, arev_Instant *out);

#endif
