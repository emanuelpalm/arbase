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
    sizeof(((struct timespec){0}).tv_sec) <= sizeof(((arev_Instant){0}).us),
    "The assumption that struct timespec .tv_sec type fits in arev_Instant .us does not hold.");
static_assert(
    sizeof(((struct timespec){0}).tv_nsec) <= sizeof(((arev_Instant){0}).us),
    "The assumption that struct timespec .tv_nsec type fits in arev_Instant .us does not hold.");

arev_Error arev_Now(arev_Instant *out) {
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        return errno;
    }
    int64_t us0;
    TRY_MATH(arev_MulI64(ts.tv_sec, 1000000, &us0));
    int64_t us1;
    TRY_MATH(arev_DivI64(ts.tv_nsec, 1000, &us1));
    TRY_MATH(arev_AddI64(us0, us1, &out->us));
    return AREV_ERROR_NONE;
}
