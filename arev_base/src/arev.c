#include <arev/arev.h>
#include <stdlib.h>

#if defined(AREV_LINUX)
#include <sys/epoll.h>
#include <sys/signalfd.h>
#else
#error No existing event loop implementation supported by target system.
#endif

struct arev_t {
#if defined(AREV_LINUX)
    int epollfd;
#endif
};

arev_Error arev_Start(arev_Options *options) {
    (void) options;
    return AREV_ERROR_NONE; // TODO: Implement.
}

arev_Error arev_Schedule(arev_t *a, arev_Activity *activity) {
    (void) a;
    (void) activity;
    return AREV_ERROR_NONE; // TODO: Implement.
}

arev_Error arev_Stop(arev_t *a) {
    (void) a;
    return AREV_ERROR_NONE; // TODO: Implement.
}