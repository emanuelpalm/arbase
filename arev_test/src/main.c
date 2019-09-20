#include <stdio.h>
#include <stdlib.h>

int main() {
#ifndef NDEBUG
    puts("Arev Test");
    puts("  Compiler: " AREV_COMPILER_ID);
    puts("  System:   " AREV_SYSTEM_NAME " " AREV_SYSTEM_VERSION);
#endif
    return EXIT_SUCCESS;
}