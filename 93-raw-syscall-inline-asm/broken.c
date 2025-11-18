#include <sys/syscall.h>
#include <unistd.h>

// Raw write syscall using inline assembly
static long my_write(int fd, const void *buf, size_t count) {
    long ret;

    // BUG: Wrong register for count - should be "d" (RDX) not "S" (RSI)
    // BUG: Wrong register for buf - should be "S" (RSI) not "d" (RDX)
    asm volatile (
        "syscall"
        : "=a" (ret)
        : "0" (__NR_write),  // syscall number in RAX
          "D" (fd),          // arg1 (fd) in RDI - CORRECT
          "d" (buf),         // BUG: arg2 (buf) should use "S" for RSI
          "S" (count)        // BUG: arg3 (count) should use "d" for RDX
        : "rcx", "r11", "memory"
    );

    return ret;
}

// Raw getpid syscall using inline assembly
static long my_getpid(void) {
    long ret;

    // BUG: Missing syscall number initialization - should be __NR_getpid
    asm volatile (
        "syscall"
        : "=a" (ret)
        : "0" (0)  // BUG: Should be __NR_getpid (39), not 0 (__NR_read)
        : "rcx", "r11", "memory"
    );

    return ret;
}

int main(void) {
    const char msg1[] = "=== Raw Syscall via Inline Assembly ===\n\n";
    const char msg2[] = "Hello from raw write syscall!\n";
    const char msg3[] = "PID from raw getpid syscall: ";
    const char msg4[] = "\n\nInline assembly allows direct kernel access!\n";

    // Use raw syscalls
    my_write(1, msg1, sizeof(msg1) - 1);
    my_write(1, msg2, sizeof(msg2) - 1);
    my_write(1, msg3, sizeof(msg3) - 1);

    // Get PID and print it
    long pid = my_getpid();

    // Convert PID to string (simple implementation)
    char pid_str[32];
    int i = 0;
    long temp = pid;
    do {
        pid_str[i++] = '0' + (temp % 10);
        temp /= 10;
    } while (temp > 0);

    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
        char c = pid_str[j];
        pid_str[j] = pid_str[i - 1 - j];
        pid_str[i - 1 - j] = c;
    }
    pid_str[i] = '\n';

    my_write(1, pid_str, i + 1);
    my_write(1, msg4, sizeof(msg4) - 1);

    return 0;
}
