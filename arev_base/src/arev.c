#include <arev/arev.h>
#include <stdbool.h>
#include <string.h>

#if defined(AREV_LINUX)
#include <sys/epoll.h>
#include <sys/signalfd.h>
#else
#error No existing event loop implementation supported by target system.
#endif

struct arev_t {
    arev_Options options;
    bool is_stopped;
#if defined(AREV_LINUX)
    int epollfd;
#endif
};

arev_Error arev_Start(arev_Options *options) {
    arev_t a;
    memset(&a, 0, sizeof(arev_t));
    memcpy(&a.options, options, sizeof(arev_Options));

    // TODO: Setup.

    if (a.options.on_started != NULL) {
        AREV_TRY(a.options.on_started(&a));
    }
    while (!a.is_stopped) {
        // TODO: Loop until no events can happen, explicitly stopped, or an interrupt is received.
    }
    return AREV_ERROR_NONE;
}

arev_Error arev_Schedule(arev_t *a, arev_ScheduledEvent *event) {
    (void) a;
    (void) event;
    return AREV_ERROR_NONE; // TODO: Implement.
}

inline
arev_Error arev_SetOnStoppingCallback(arev_t *a, arev_OnStopping on_stopping) {
    a->options.on_stopping = on_stopping;
    return AREV_ERROR_NONE;
}

inline
arev_Error arev_Stop(arev_t *a) {
    a->is_stopped = true;
    return AREV_ERROR_NONE;
}