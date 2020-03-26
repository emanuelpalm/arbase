#include <arev/math.h>
#include <arev/time.h>

#define NS_MAX 1000000000
#define NS_MIN 0

inline
arev_Error arev_AddDuration(const arev_Duration duration, arev_Duration *out) {
    AREV_TRY(arev_AddI64(duration.s, out->s, &out->s));
    int64_t ns = duration.ns + out->ns;
    if (ns >= NS_MAX) {
        AREV_TRY(arev_AddI64(1, out->s, &out->s));
    }
    out->ns = ns - NS_MAX;
    return AREV_ERROR_NONE;
}

inline
arev_Error arev_AddDurationToInstant(const arev_Duration duration, arev_Instant *out) {
    AREV_TRY(arev_AddI64(duration.s, out->s, &out->s));
    int64_t ns = duration.ns + out->ns;
    if (ns >= NS_MAX) {
        AREV_TRY(arev_AddI64(1, out->s, &out->s));
    }
    out->ns = ns - NS_MAX;
    return AREV_ERROR_NONE;
}

inline
arev_Error arev_SubDuration(const arev_Duration duration, arev_Duration *out) {
    AREV_TRY(arev_SubI64(duration.s, out->s, &out->s));
    int64_t ns = duration.ns - out->ns;
    if (ns < NS_MIN) {
        AREV_TRY(arev_AddI64(1, out->s, &out->s));
    }
    out->ns = ns + NS_MAX;
    return AREV_ERROR_NONE;
}

inline
arev_Error arev_SubDurationFromInstant(const arev_Duration duration, arev_Instant *out) {
    AREV_TRY(arev_SubI64(duration.s, out->s, &out->s));
    int64_t ns = duration.ns - out->ns;
    if (ns < NS_MIN) {
        AREV_TRY(arev_AddI64(1, out->s, &out->s));
    }
    out->ns = ns + NS_MAX;
    return AREV_ERROR_NONE;
}
