#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    printf("Start");  // BUG: No newline - stays buffered

    printf(" - before fork");  // BUG: No newline - accumulates in buffer
    // BUG: Missing fflush(stdout) here causes buffered content to be duplicated

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child
        printf("\nChild process: PID=%d\n", getpid());
    } else {
        // Parent
        printf("\nParent process: PID=%d, child=%d\n", getpid(), pid);
        wait(NULL);
    }

    printf("Process %d exiting\n", getpid());

    return 0;
}
