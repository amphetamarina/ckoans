#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void) {
    const char *dir = "/tmp/koan135_test";
    const char *file = "/tmp/koan135_test/data.txt";

    // Create directory
    if (mkdir(dir, 0755) < 0) {
        // BUG: Not checking if error is EEXIST (directory already exists)
        // This is recoverable, but we treat it as fatal
        perror("mkdir failed");
        return 1;
    }

    // Try to write to file
    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open failed");
        rmdir(dir);
        return 1;
    }

    const char *msg = "Error analysis complete\n";
    if (write(fd, msg, strlen(msg)) < 0) {
        perror("write failed");
        close(fd);
        unlink(file);
        rmdir(dir);
        return 1;
    }

    close(fd);

    // Read it back
    fd = open(file, O_RDONLY);
    if (fd < 0) {
        perror("open for read failed");
        unlink(file);
        rmdir(dir);
        return 1;
    }

    char buffer[128];
    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Success: %s", buffer);
    }

    close(fd);
    unlink(file);
    rmdir(dir);

    return 0;
}
