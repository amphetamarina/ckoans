#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(void) {
    printf("=== System Call Numbers ===\n\n");

    // Show the syscall number macros
    printf("Syscall numbers on this architecture:\n");
    printf("SYS_getpid  = %ld\n", (long)SYS_getpid);
    printf("SYS_getppid = %ld\n", (long)SYS_getppid);
    printf("SYS_write   = %ld\n", (long)SYS_write);

    // Use syscall() to invoke syscalls directly by number
    printf("\nCalling syscalls by number:\n");

    // BUG: Using wrong syscall number - SYS_getppid instead of SYS_getpid
    long pid = syscall(SYS_getppid);
    printf("My PID (via syscall %ld): %ld\n", (long)SYS_getpid, pid);

    // BUG: Using wrong syscall number - SYS_getpid instead of SYS_getppid
    long ppid = syscall(SYS_getpid);
    printf("Parent PID (via syscall %ld): %ld\n", (long)SYS_getppid, ppid);

    // Correct way for comparison
    printf("\nUsing wrapper functions:\n");
    printf("My PID (via getpid):  %d\n", getpid());
    printf("Parent PID (via getppid): %d\n", getppid());

    printf("\nWrapper functions internally use syscall numbers!\n");

    return 0;
}
