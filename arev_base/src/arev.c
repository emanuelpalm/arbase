#include <arev/arev.h>
#include <stdlib.h>

#if defined(AREV_LINUX)
#include <sys/epoll.h>
#include <sys/signalfd.h>
#else
#error No existing event loop implementation supported by target system.
#endif

/// Maintains data related to some event loop.
struct arev_EventLoop {
#if defined(AREV_LINUX)
    int epollfd;
#endif
};

arev_Error arev_StartEventLoop(arev_Options *options) {
    return AREV_ERROR_NONE; // TODO: Implement.
}

arev_Error arev_ScheduleEventAt(arev_EventLoop *loop, arev_Time instant, void *context) {
    return AREV_ERROR_NONE; // TODO: Implement.
}

arev_Error arev_ScheduleEventIn(arev_EventLoop *loop, arev_Time duration, void *context) {
    return AREV_ERROR_NONE; // TODO: Implement.
}

arev_Error arev_StopEventLoop(arev_EventLoop *loop) {
    return AREV_ERROR_NONE; // TODO: Implement.
}