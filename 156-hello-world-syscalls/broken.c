#include <unistd.h>
#include <sys/syscall.h>

// Minimal hello world using only syscalls
// In true minimal version, we wouldn't include any headers
// and would define syscall numbers ourselves

#define STDOUT_FD 1

// Simulate minimal syscall implementation
// In real nostdlib code:
// static inline long syscall3(long n, long a1, long a2, long a3) {
//     long ret;
//     asm volatile("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3)
//                  : "rcx", "r11", "memory");
//     return ret;
// }

long my_write(int fd, const void *buf, unsigned long count) {
    return syscall(SYS_write, fd, buf, count);
}

void my_exit(int status) {
    syscall(SYS_exit, status);
}

// In minimal version, this would be _start, not main
int main(void) {
    // BUG: Message should be "Hello, World!\n", not "Hello World\n"
    const char msg[] = "Hello World\n";

    // Write to stdout
    // BUG: Should use sizeof(msg) - 1, not sizeof(msg) - 2
    long written = my_write(STDOUT_FD, msg, sizeof(msg) - 2);

    // Check if write succeeded
    if (written < 0) {
        my_exit(1);
    }

    // Exit successfully
    my_exit(0);

    return 0;  // Never reached when using my_exit
}

// For true minimal version without libc, we would need:
// void _start(void) {
//     const char msg[] = "Hello, World!\n";
//     syscall3(SYS_write, 1, (long)msg, sizeof(msg) - 1);
//     syscall1(SYS_exit, 0);
// }
// And compile with: gcc -nostdlib -static program.c
