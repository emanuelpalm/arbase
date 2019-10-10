#include <stdio.h>
#include <stdlib.h>

int main() {
#ifndef NDEBUG
    puts(
        "Arev Test\n"
        "  Compiler: " AREV_COMPILER_ID "\n"
        "  System:   " AREV_SYSTEM_NAME " " AREV_SYSTEM_VERSION);
#endif
    return EXIT_SUCCESS;
}
