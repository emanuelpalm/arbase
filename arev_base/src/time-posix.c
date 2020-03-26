#include <arev/time.h>
#include <assert.h>
#include <errno.h>
#include <time.h>

static_assert(
    sizeof(((struct timespec) {0}).tv_sec) <= sizeof(((arev_Instant) {0}).s),
    "The assumption that struct timespec .tv_sec type fits in arev_Instant .s does not hold.");
static_assert(
    sizeof(((struct timespec) {0}).tv_nsec) <= sizeof(((arev_Instant) {0}).ns),
    "The assumption that struct timespec .tv_nsec type fits in arev_Instant .ns does not hold.");

inline
arev_Error arev_Now(arev_Instant *out) {
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        return errno;
    }
    out->s = ts.tv_sec;
    out->ns = ts.tv_nsec;
    return AREV_ERROR_NONE;
}
