#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void write_log(const char *filename, const char *message) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    write(fd, message, strlen(message));
    write(fd, "\n", 1);

    // BUG: Missing close(fd) - file descriptor leak
}

int read_first_line(const char *filename, char *buffer, size_t size) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    ssize_t n = read(fd, buffer, size - 1);
    if (n > 0) {
        buffer[n] = '\0';
        // Find first newline and truncate there
        char *newline = strchr(buffer, '\n');
        if (newline) *newline = '\0';
    }

    // BUG: Missing close(fd) - file descriptor leak
    return n;
}

int main(void) {
    const char *logfile = "/tmp/test.log";

    // Create a fresh log file
    int fd = open(logfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd >= 0) {
        close(fd);  // This one is correct
    }

    // Write multiple log entries
    for (int i = 1; i <= 5; i++) {
        char msg[64];
        snprintf(msg, sizeof(msg), "Log entry %d", i);
        write_log(logfile, msg);
    }

    // Read back the first line
    char buffer[256];
    if (read_first_line(logfile, buffer, sizeof(buffer)) >= 0) {
        printf("First line: %s\n", buffer);
    }

    // Clean up test file
    unlink(logfile);

    printf("Completed successfully\n");
    return 0;
}
