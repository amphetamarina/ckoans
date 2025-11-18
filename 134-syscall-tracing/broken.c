#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    char buffer[64];
    int fd;

    // Create a test file
    fd = open("/tmp/koan134.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open write");
        return 1;
    }
    write(fd, "Hello, strace!\n", 15);
    close(fd);

    // BUG: Opening for write, but trying to read
    fd = open("/tmp/koan134.txt", O_WRONLY);
    if (fd < 0) {
        perror("open read");
        return 1;
    }

    memset(buffer, 0, sizeof(buffer));
    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    // BUG: This will print nothing because read fails silently (n=0 or error)
    printf("Read %zd bytes: %s", n, buffer);

    close(fd);
    unlink("/tmp/koan134.txt");
    return 0;
}
