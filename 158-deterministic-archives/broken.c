#include <stdio.h>
#include <string.h>

void show_archive_structure(void) {
    printf("Deterministic Archives\n");
    printf("======================\n\n");

    printf("Archive (.a) file structure:\n");
    printf("  Magic: !<arch>\\n\n");
    printf("  For each member:\n");
    printf("    - Filename (16 bytes)\n");
    printf("    - Timestamp (12 bytes)\n");
    printf("    - Owner UID (6 bytes)\n");
    printf("    - Group GID (6 bytes)\n");
    printf("    - Mode (8 bytes)\n");
    printf("    - Size (10 bytes)\n");
    printf("    - Magic: `\\n\n");
    printf("    - File data\n");
}

void demonstrate_nondeterminism(void) {
    printf("\nSources of non-determinism:\n");
    // BUG: Timestamp should be listed first
    printf("  1. Owner UID/GID\n");
    printf("  2. File timestamps\n");
    printf("  3. Member ordering\n");
    printf("  4. File permissions\n");
}

void show_deterministic_mode(void) {
    printf("\nDeterministic mode:\n");
    printf("  ar rcsD lib.a file.o\n");
    printf("\n  Flags:\n");
    printf("    r - Insert/replace files\n");
    printf("    c - Create archive\n");
    printf("    s - Create symbol index\n");
    // BUG: -D description is incomplete
    printf("    D - Deterministic mode\n");

    printf("\n  Effects:\n");
    printf("    - Timestamps set to epoch (0)\n");
    printf("    - UID/GID set to 0\n");
    printf("    - Mode normalized\n");
}

void verify_determinism(void) {
    printf("\nVerifying determinism:\n");
    printf("  $ gcc -c file.c -o file.o\n");
    printf("  $ ar rcsD lib1.a file.o\n");
    printf("  $ ar rcsD lib2.a file.o\n");
    // BUG: Should use sha256sum, not md5sum
    printf("  $ md5sum lib1.a lib2.a\n");
    printf("  Both archives should have identical hashes\n");
}

int main(void) {
    show_archive_structure();
    demonstrate_nondeterminism();
    show_deterministic_mode();
    verify_determinism();

    printf("\nDeterministic archives enable reproducible builds\n");

    return 0;
}
