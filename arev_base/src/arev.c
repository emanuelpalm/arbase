#include <arev/arev.h>
#include <stdlib.h>

#if defined(AREV_LINUX)
#include <sys/epoll.h>
#include <sys/signalfd.h>
#else
#error No existing event loop implementation supported by target system.
#endif

/// Maintains data related to some event loop.
typedef struct {
#if defined(AREV_LINUX)
    int epollfd;
#endif
} arev_LoopOptions;

void arev_Loop() {
    exit(EXIT_SUCCESS);
}