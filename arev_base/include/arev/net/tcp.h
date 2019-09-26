#ifndef AREV_NET_TCP_H
#define AREV_NET_TCP_H

#include <arev/error.h>
#include <arev/net/host.h>
#include <stddef.h>

struct arev_TCPListener;
struct arev_TCPListenerOptions;
struct arev_TCPSocket;
struct arev_TCPSocketOptions;

typedef struct arev_TCPListener arev_TCPListener;
typedef struct arev_TCPListenerOptions arev_TCPListenerOptions;
typedef struct arev_TCPSocket arev_TCPSocket;
typedef struct arev_TCPSocketOptions arev_TCPSocketOptions;

typedef arev_Error (*arev_OnTCPListenerOpened)(arev_TCPListener *);
typedef arev_Error (*arev_OnTCPListenerClosing)(arev_TCPListener *);
typedef arev_Error (*arev_OnTCPListenerError)(arev_TCPListener *, arev_TCPSocket *, arev_Error);
typedef arev_Error (*arev_OnTCPListenerConnection)(arev_TCPListener *, arev_TCPSocket *);

typedef arev_Error (*arev_OnTCPSocketOpened)(arev_TCPSocket *);
typedef arev_Error (*arev_OnTCPSocketClosing)(arev_TCPSocket *);
typedef arev_Error (*arev_OnTCPSocketError)(arev_TCPSocket *, arev_Error);
typedef arev_Error (*arev_OnTCPSocketReadable)(arev_TCPSocket *, size_t);
typedef arev_Error (*arev_OnTCPSocketWritable)(arev_TCPSocket *, size_t);

struct arev_TCPListenerOptions {
    arev_Host interface;
    arev_OnTCPListenerOpened on_opened;
    arev_OnTCPListenerClosing on_closing;
    arev_OnTCPListenerError on_error;
    arev_OnTCPListenerConnection on_connection;
    void *context;
};

struct arev_TCPSocketOptions {
    arev_Host host;
    arev_OnTCPSocketOpened on_opened;
    arev_OnTCPSocketClosing on_closing;
    arev_OnTCPSocketError on_error;
    arev_OnTCPSocketReadable on_readable;
    arev_OnTCPSocketWritable on_writable;
    void *context;
};

arev_Error arev_GetTCPListenerContext(arev_TCPListener *listener, void **out);
arev_Error arev_GetTCPListenerInterface(arev_TCPListener *listener, arev_Host **out);
arev_Error arev_CloseTCPListener(arev_TCPListener *listener);
arev_Error arev_SetTCPListenerOpenedCallback(arev_TCPListener *listener, arev_OnTCPListenerOpened callback);
arev_Error arev_SetTCPListenerClosingCallback(arev_TCPListener *listener, arev_OnTCPListenerClosing callback);
arev_Error arev_SetTCPListenerErrorCallback(arev_TCPListener *listener, arev_OnTCPListenerError callback);
arev_Error arev_SetTCPListenerConnectionCallback(arev_TCPListener *listener, arev_OnTCPListenerConnection callback);
arev_Error arev_SetTCPListenerContext(arev_TCPListener *listener, void *context);

arev_Error arev_GetTCPSocketContext(arev_TCPSocket *socket, void **out);
arev_Error arev_GetTCPSocketHost(arev_TCPSocket *socket, arev_Host **out);
arev_Error arev_GetTCPSocketListener(arev_TCPSocket *socket, arev_TCPListener **out);
arev_Error arev_CloseTCPSocket(arev_TCPSocket *socket);
arev_Error arev_SetTCPSocketOpenedCallback(arev_TCPSocket *socket, arev_OnTCPSocketOpened callback);
arev_Error arev_SetTCPSocketClosingCallback(arev_TCPSocket *socket, arev_OnTCPSocketClosing callback);
arev_Error arev_SetTCPSocketErrorCallback(arev_TCPSocket *socket, arev_OnTCPSocketError callback);
arev_Error arev_SetTCPSocketReadableCallback(arev_TCPSocket *socket, arev_OnTCPSocketReadable callback);
arev_Error arev_SetTCPSocketWritableCallback(arev_TCPSocket *socket, arev_OnTCPSocketWritable callback);
arev_Error arev_SetTCPSocketContext(arev_TCPSocket *socket, void *context);

#endif
