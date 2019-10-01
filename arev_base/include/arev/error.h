#ifndef AREV_ERROR_H
#define AREV_ERROR_H

/// Error management.
///
/// @file

#define AREV_TRY(STATUS) do {              \
    arev_Error __arev_error = (STATUS);    \
    if (__arev_error != AREV_ERROR_NONE) { \
        return __arev_error;               \
    }                                      \
} while (0)

/// An error code.
typedef int arev_Error;

/// All `arev_base` error codes.
enum {
#define AREV_ERROR(CODE, NAME, ...) AREV_ERROR_##NAME = CODE,
#include <arev/error.inc>
#undef AREV_ERROR
};

/// Looks up a C-string that contains a human-readable description of the given
/// error code.
const char *arev_ErrorAsCStr(arev_Error error);

#endif
