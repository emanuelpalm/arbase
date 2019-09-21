#ifndef AREV_ERROR
#define AREV_ERROR(CODE, NAME, DESCRIPTION)
#endif

AREV_ERROR(0, ERROR_NONE, "No error")

// Integer errors.
AREV_ERROR(-256, ERROR_INT_DIVZERO, "Division by zero")
AREV_ERROR(-257, ERROR_INT_OVERFLOW, "Integer overflow")
AREV_ERROR(-258, ERROR_INT_UNDERFLOW, "Integer underflow")
