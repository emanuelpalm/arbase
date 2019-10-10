/// Error codes.
///
/// This files lists all possible AREV errors and their codes. All codes are
/// negative, except for the no error type, in order to ensure that there is no
/// overlap with standard C error codes.
///
/// @file

#ifndef AREV_ERROR
#define AREV_ERROR(CODE, NAME, DESCRIPTION)
#endif

AREV_ERROR(0, NONE, "No error")

// Math errors.
AREV_ERROR(-256, MATH_DIVZERO, "Division by zero")
AREV_ERROR(-257, MATH_MODZERO, "Modulus by zero")
AREV_ERROR(-258, MATH_OVERFLOW, "Arithmetic overflow")
AREV_ERROR(-259, MATH_UNDERFLOW, "Arithmetic underflow")

// Time errors.
AREV_ERROR(-512, TIME_OVERFLOW, "Temporal overflow")
AREV_ERROR(-513, TIME_UNDERFLOW, "Temporal underflow")
