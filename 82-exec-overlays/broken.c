#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    printf("Parent: About to fork and exec\n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child: About to exec /bin/echo\n");

        // BUG: Missing NULL terminator in argument list
        execl("/bin/echo", "echo", "Hello from exec!", (char *)0);

        // BUG: This should only execute if exec fails, but missing error handling
        printf("Child: This line should never print if exec succeeds!\n");
        return 1;
    } else {
        // Parent process
        // BUG: Missing wait - parent might exit before child completes
        printf("Parent: Waiting for child to complete\n");
        // wait(NULL);  // Missing this line
        printf("Parent: Child completed\n");
    }

    return 0;
}
