#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    printf("=== Errno Pathway Demo ===\n\n");

    // Try to open a file that doesn't exist
    printf("Attempting to open non-existent file...\n");
    int fd = open("/nonexistent/path/file.txt", O_RDONLY);

    // BUG: Checking errno before checking if call failed
    if (errno == ENOENT) {
        printf("File not found (but we didn't check return value!)\n");
    }

    // BUG: Should check fd == -1 FIRST
    if (fd == -1) {
        printf("open() failed with return value: %d\n", fd);
        printf("Error code (errno): %d\n", errno);
        printf("Error message: %s\n", strerror(errno));

        // Could also use perror:
        perror("  perror output");
    }

    printf("\n");

    // Try to open with invalid flags
    printf("Attempting open with invalid flags...\n");
    // BUG: Not capturing return value
    open("/tmp/test", -1);  // Invalid flags

    // BUG: Checking errno without checking if call failed
    printf("errno after call: %d (%s)\n", errno, strerror(errno));

    printf("\n");

    // Demonstrate correct usage
    printf("Correct errno usage:\n");
    fd = open("/nonexistent", O_RDONLY);
    if (fd == -1) {
        // Now errno is meaningful
        if (errno == ENOENT) {
            printf("  Correctly detected: File does not exist\n");
        }
    } else {
        close(fd);
    }

    printf("\nKey lesson: Always check return value before checking errno!\n");

    return 0;
}
