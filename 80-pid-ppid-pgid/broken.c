#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    // BUG: getppid() returns parent PID, not current PID
    printf("Process ID (PID): %d\n", getppid());

    // BUG: getpid() returns current PID, not parent PID
    printf("Parent Process ID (PPID): %d\n", getpid());

    // BUG: getpid() returns PID, not PGID
    printf("Process Group ID (PGID): %d\n", getpid());

    printf("\nProcess hierarchy understood!\n");

    return 0;
}
