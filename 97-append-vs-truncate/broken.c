#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void append_log(const char *filename, const char *message) {
    // BUG: Using O_TRUNC instead of O_APPEND - destroys previous content
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    write(fd, message, strlen(message));
    write(fd, "\n", 1);
    close(fd);
}

int main(void) {
    const char *logfile = "/tmp/test_log.txt";

    // Remove any existing log
    unlink(logfile);

    // Append multiple entries
    append_log(logfile, "Entry 1: Application started");
    append_log(logfile, "Entry 2: Configuration loaded");
    append_log(logfile, "Entry 3: Database connected");
    append_log(logfile, "Entry 4: Server listening on port 8080");
    append_log(logfile, "Entry 5: Ready to accept requests");

    // Read back and display the log
    int fd = open(logfile, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Log contents:\n");
    char buffer[256];
    ssize_t n;
    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, n);
    }

    close(fd);
    unlink(logfile);

    return 0;
}
