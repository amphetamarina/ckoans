#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    printf("Before fork: PID=%d\n", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    // BUG: Logic is reversed - checking child condition for parent
    if (pid == 0) {
        // This is actually the child, not parent
        printf("Parent process: PID=%d, child PID=%d\n", getpid(), pid);
        wait(NULL);
    } else {
        // This is actually the parent, not child
        printf("Child process: PID=%d, parent returned: %d\n", getpid(), pid);
    }

    printf("Process %d exiting\n", getpid());

    return 0;
}
