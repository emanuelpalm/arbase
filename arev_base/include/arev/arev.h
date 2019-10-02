#ifndef AREV_AREV_H
#define AREV_AREV_H

#include "error.h"
#include "net/tcp.h"
#include "time.h"

struct arev_t;
struct arev_Options;
struct arev_Task;

typedef struct arev_t arev_t;
typedef struct arev_Options arev_Options;
typedef struct arev_Task arev_Task;

typedef arev_Error (*arev_OnStarted)(arev_t *);
typedef arev_Error (*arev_OnStopping)(arev_t *);
typedef arev_Error (*arev_OnTask)(arev_t *, arev_Task *);

struct arev_Options {
    arev_OnStarted on_started;
    arev_OnStopping on_stopping;
    void *context;
};

struct arev_Task {
    arev_Instant baseline;
    arev_Instant deadline;
    arev_Duration interval;
    arev_OnTask on_triggered;
    void *context;
};

arev_Error arev_Start(arev_Options *options);

arev_Error arev_OpenTCPListener(arev_t *a, arev_TCPListenerOptions *options);
arev_Error arev_OpenTCPSocket(arev_t *a, arev_TCPSocketOptions *options);
arev_Error arev_ScheduleTask(arev_t *a, arev_Task *task);
arev_Error arev_Stop(arev_t *a);

#endif
