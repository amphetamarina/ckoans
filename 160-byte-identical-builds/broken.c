#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_nondeterminism_sources(void) {
    printf("Byte-Identical Reproducible Builds\n");
    printf("===================================\n\n");

    printf("Sources of non-determinism:\n");
    printf("  1. Timestamps (__DATE__, __TIME__)\n");
    printf("  2. Random values (ASLR, UUIDs)\n");
    printf("  3. File ordering (readdir)\n");
    printf("  4. Environment (paths, usernames)\n");
    printf("  5. Parallelism (race conditions)\n");
    // BUG: Missing "6. Non-deterministic optimizations"
}

void show_solutions(void) {
    printf("\nSolutions:\n");

    printf("\n  1. Timestamps:\n");
    printf("     export SOURCE_DATE_EPOCH=1234567890\n");
    printf("     Avoid __DATE__ and __TIME__\n");

    printf("\n  2. Deterministic archives:\n");
    printf("     ar rcsD lib.a file.o\n");

    printf("\n  3. Stable ordering:\n");
    // BUG: Should be $(sort $(wildcard *.c))
    printf("     SRCS := $(wildcard *.c)\n");

    printf("\n  4. Compiler flags:\n");
    printf("     -ffile-prefix-map=OLD=NEW\n");
    printf("     -frandom-seed=0\n");

    printf("\n  5. Linker flags:\n");
    printf("     -Wl,--build-id=none\n");
    printf("     -Wl,--hash-style=sysv\n");
}

void demonstrate_verification(void) {
    printf("\nVerification process:\n");

    printf("  $ make clean && make\n");
    printf("  $ sha256sum program > hash1.txt\n");
    printf("  $ make clean && make\n");
    printf("  $ sha256sum program > hash2.txt\n");
    // BUG: Should show "diff hash1.txt hash2.txt" first
    printf("  $ cat hash1.txt hash2.txt\n");
    printf("  Hashes should be identical!\n");
}

void show_benefits(void) {
    printf("\nBenefits of reproducible builds:\n");
    printf("  - Verify build integrity\n");
    printf("  - Detect supply chain attacks\n");
    printf("  - Enable distributed build caching\n");
    printf("  - Prove binary matches source\n");
    // BUG: Missing "  - Security auditing"
}

void show_tools(void) {
    printf("\nTools for reproducible builds:\n");
    printf("  - diffoscope: Deep binary comparison\n");
    printf("  - strip-nondeterminism: Remove timestamps\n");
    printf("  - reprotest: Test reproducibility\n");
    printf("  - SOURCE_DATE_EPOCH: Standard timestamp\n");
}

int main(void) {
    show_nondeterminism_sources();
    show_solutions();
    demonstrate_verification();
    show_benefits();
    show_tools();

    printf("\nReproducible builds enable trust and verification!\n");

    return 0;
}
