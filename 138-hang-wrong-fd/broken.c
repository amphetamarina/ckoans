#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    const char *filename = "/tmp/koan138.txt";
    char buffer[64];

    // Create and write to file
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open for write");
        return 1;
    }

    const char *msg = "File descriptor test\n";
    write(fd, msg, strlen(msg));
    close(fd);

    // Open for reading
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open for read");
        return 1;
    }

    printf("File opened, reading data...\n");

    // BUG: Reading from stdin (fd 0) instead of the file (fd)
    // This will hang waiting for terminal input
    ssize_t n = read(0, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        close(fd);
        unlink(filename);
        return 1;
    }

    buffer[n] = '\0';
    printf("Read: %s", buffer);

    close(fd);
    unlink(filename);

    return 0;
}
