#ifndef AREV_LOOP_H
#define AREV_LOOP_H

/// Event loop management.
///
/// @file

#include <stdnoreturn.h>

/// Starts event loop.
///
/// Note that this function never returns. It will run until the application
/// exits, if it is at all possible to exit applications on the target system.
noreturn
void arev_Loop();

#endif
