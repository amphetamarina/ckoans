#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
    int pipefd[2];
    char buffer[128];

    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process - reads from pipe
        // BUG: Should close write end (pipefd[1]) but doesn't

        ssize_t n = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (n > 0) {
            buffer[n] = '\0';
            printf("Child received: %s\n", buffer);
        }

        close(pipefd[0]);
        exit(0);
    } else {
        // Parent process - writes to pipe
        // BUG: Should close read end (pipefd[0]) but doesn't

        const char *message = "Hello from parent";
        write(pipefd[1], message, strlen(message));

        close(pipefd[1]);

        // Wait for child
        wait(NULL);
        printf("Parent done\n");
    }

    return 0;
}
