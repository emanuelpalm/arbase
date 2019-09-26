#ifndef AREV_AREV_H
#define AREV_AREV_H

#include <arev/error.h>
#include <arev/net/tcp.h>

struct arev_EventLoop;
struct arev_Options;

typedef struct arev_EventLoop arev_EventLoop;
typedef struct arev_Options arev_Options;

typedef arev_Error (*arev_OnEventLoopStarted)(arev_EventLoop *);
typedef arev_Error (*arev_OnEventLoopStopping)(arev_EventLoop *);

struct arev_Options {
    arev_OnEventLoopStarted on_started;
    arev_OnEventLoopStopping on_stopping;
    void *context;
};

arev_Error arev_StartEventLoop(arev_Options *options);
arev_Error arev_StopEventLoop(arev_EventLoop *loop);

arev_Error arev_OpenTCPListener(arev_EventLoop *loop, arev_TCPListenerOptions *options);
arev_Error arev_OpenTCPSocket(arev_EventLoop *loop, arev_TCPSocketOptions *options);

#endif
