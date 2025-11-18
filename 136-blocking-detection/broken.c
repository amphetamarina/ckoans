#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int pipefd[2];
    char buffer[64];

    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

    // pipefd[0] is read end, pipefd[1] is write end
    const char *msg = "Blocking test\n";

    // Write some data
    if (write(pipefd[1], msg, strlen(msg)) < 0) {
        perror("write");
        return 1;
    }

    // BUG: Trying to read from write end - this will block forever
    // Should read from pipefd[0], not pipefd[1]
    ssize_t n = read(pipefd[1], buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        close(pipefd[0]);
        close(pipefd[1]);
        return 1;
    }

    buffer[n] = '\0';
    printf("Read from pipe: %s", buffer);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
