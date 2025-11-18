#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(void) {
    int pipefd[2];
    char buffer[128];

    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

    // Set read end to non-blocking mode
    int flags = fcntl(pipefd[0], F_GETFL);
    fcntl(pipefd[0], F_SETFL, flags | O_NONBLOCK);

    printf("Attempting non-blocking read...\n");

    // Try to read before anything is written
    ssize_t n = read(pipefd[0], buffer, sizeof(buffer));
    if (n < 0) {
        // BUG: Should check for EAGAIN and retry, but instead treats it as fatal error
        perror("read");
        close(pipefd[0]);
        close(pipefd[1]);
        return 1;
    }

    // This code is unreachable due to the bug above
    printf("No data yet (EAGAIN)\n");

    // Now write some data
    const char *message = "Hello non-blocking!";
    write(pipefd[1], message, strlen(message));
    close(pipefd[1]);

    // Try reading again - should succeed now
    n = read(pipefd[0], buffer, sizeof(buffer));
    if (n > 0) {
        buffer[n] = '\0';
        printf("Read: %s\n", buffer);
    }

    close(pipefd[0]);
    return 0;
}
