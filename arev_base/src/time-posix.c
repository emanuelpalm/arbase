#include <arev/math.h>
#include <arev/time.h>
#include <assert.h>
#include <errno.h>
#include <time.h>

#define TRY_MATH(STATUS) do {             \
    arev_Error __arev_error = (STATUS);   \
    switch (__arev_error) {               \
    case AREV_ERROR_NONE:                 \
        break;                            \
    case AREV_ERROR_MATH_OVERFLOW:        \
        return AREV_ERROR_TIME_OVERFLOW;  \
    case AREV_ERROR_MATH_UNDERFLOW:       \
        return AREV_ERROR_TIME_UNDERFLOW; \
    default:                              \
        return __arev_error;              \
    }                                     \
} while (0)

static_assert(
    sizeof(((struct timespec){0}).tv_sec) <= sizeof(((arev_Time){0}).ms),
    "The ms field of arev_Time is not large enough to hold all struct timespec .tv_sec values.");
static_assert(
    sizeof(((struct timespec){0}).tv_nsec) <= sizeof(((arev_Time){0}).ms),
    "The ms field of arev_Time is not large enough to hold all struct timespec .tv_nsec values.");

arev_Error arev_Now(arev_Time *out) {
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        return errno;
    }
    int64_t ms0;
    TRY_MATH(arev_MulI64(ts.tv_sec, 1000, &ms0));
    int64_t ms1;
    TRY_MATH(arev_DivI64(ts.tv_nsec, 1000000, &ms1));
    TRY_MATH(arev_AddI64(ms0, ms1, &out->ms));
    return AREV_ERROR_NONE;
}

inline
arev_Error arev_AddTime(arev_Time a, arev_Time b, arev_Time *out) {
    TRY_MATH(arev_AddI64(a.ms, b.ms, &out->ms));
    return AREV_ERROR_NONE;
}

inline
arev_Error arev_SubTime(arev_Time a, arev_Time b, arev_Time *out) {
    TRY_MATH(arev_SubI64(a.ms, b.ms, &out->ms));
    return AREV_ERROR_NONE;
}
