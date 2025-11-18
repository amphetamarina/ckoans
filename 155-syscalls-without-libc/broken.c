#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

// Direct syscall wrappers (simplified - using libc for demo)
// In real nostdlib code, we'd use inline assembly

long my_syscall_write(int fd, const void *buf, size_t count) {
    // BUG: Should use syscall(), not write()
    return write(fd, buf, count);
}

long my_syscall_exit(int status) {
    // Using syscall() directly
    syscall(SYS_exit, status);
    return 0;  // Never reached
}

void demonstrate_syscalls(void) {
    printf("Direct Syscalls Without libc\n");
    printf("=============================\n\n");

    printf("Syscall interface (x86-64):\n");
    printf("  Syscall number -> RAX\n");
    printf("  Arg1 -> RDI\n");
    printf("  Arg2 -> RSI\n");
    printf("  Arg3 -> RDX\n");
    printf("  Arg4 -> R10\n");
    printf("  Arg5 -> R8\n");
    printf("  Arg6 -> R9\n");
    printf("  Return value <- RAX\n");
}

void show_common_syscalls(void) {
    printf("\nCommon syscall numbers:\n");
    // BUG: SYS_read should be 0, not 1
    printf("  SYS_read  = 1\n");
    printf("  SYS_write = %ld\n", (long)SYS_write);
    printf("  SYS_exit  = %ld\n", (long)SYS_exit);
    printf("  SYS_open  = %ld\n", (long)SYS_open);
    printf("  SYS_close = %ld\n", (long)SYS_close);
}

void example_direct_write(void) {
    printf("\nDirect syscall example:\n");

    const char msg[] = "  Hello from direct syscall!\n";

    // Using syscall() from libc (which makes the actual syscall)
    long ret = syscall(SYS_write, STDOUT_FILENO, msg, sizeof(msg) - 1);

    if (ret < 0) {
        printf("  Syscall failed\n");
    }
}

int main(void) {
    demonstrate_syscalls();
    show_common_syscalls();
    example_direct_write();

    printf("\nDirect syscalls bypass libc wrappers\n");
    printf("Essential for minimal runtime environments\n");

    return 0;
}
