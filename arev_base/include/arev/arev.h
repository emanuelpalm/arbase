#ifndef AREV_AREV_H
#define AREV_AREV_H

#include "error.h"
#include "net/tcp.h"
#include "time.h"

struct arev_t;
struct arev_Activity;
struct arev_Options;

typedef struct arev_t arev_t;
typedef struct arev_Activity arev_Activity;
typedef struct arev_Options arev_Options;

typedef arev_Error (*arev_OnStarted)(arev_t *);
typedef arev_Error (*arev_OnStopping)(arev_t *);
typedef arev_Error (*arev_OnTriggered)(arev_t *, arev_Activity *);

struct arev_Activity {
    arev_Instant baseline;
    arev_Instant deadline;
    arev_Duration interval;
    arev_OnTriggered on_triggered;
    void *context;
};

struct arev_Options {
    arev_OnStarted on_started;
    arev_OnStopping on_stopping;
    void *context;
};

arev_Error arev_Start(arev_Options *options);

arev_Error arev_OpenTCPListener(arev_t *a, arev_TCPListenerOptions *options);
arev_Error arev_OpenTCPSocket(arev_t *a, arev_TCPSocketOptions *options);
arev_Error arev_Schedule(arev_t *a, arev_Activity *activity);
arev_Error arev_Stop(arev_t *a);

#endif
