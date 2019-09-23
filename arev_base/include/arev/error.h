#ifndef AREV_ERROR_H
#define AREV_ERROR_H

/// Error management.
///
/// @file

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
