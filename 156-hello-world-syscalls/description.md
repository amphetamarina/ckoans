# Write Hello World Using Only Syscalls

## Concept
A **minimal hello world** program using only syscalls, no libc, demonstrating the absolute minimum required for a functional program.

**Minimal hello world (x86-64):**
```c
#define SYS_write 1
#define SYS_exit  60

void _start(void) {
    const char msg[] = "Hello, World!\n";
    syscall3(SYS_write, 1, msg, sizeof(msg) - 1);
    syscall1(SYS_exit, 0);
}
```

**Inline assembly syscall:**
```c
static inline long syscall3(long n, long a1, long a2, long a3) {
    long ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(a1), "S"(a2), "d"(a3)
        : "rcx", "r11", "memory"
    );
    return ret;
}
```

**Building:**
```bash
gcc -nostdlib -static hello.c -o hello
```

**Size comparison:**
- With libc: ~16KB
- Without libc: ~1KB
- Hand-coded assembly: ~500 bytes

**Key points:**
- Must define `_start`, not `main`
- Must call `exit` syscall manually
- No standard library functions available
- Demonstrates true program requirements

## What's Broken
The program attempts minimal hello-world but has syscall implementation bugs.

## Learning Goal
- Write a program without any libc
- Use only syscalls for all I/O
- Implement _start entry point
- Understand absolute minimum program requirements

## Task
1. Implement syscall wrappers with inline assembly
2. Define _start (not main)
3. Use SYS_write to output message
4. Use SYS_exit to terminate
5. Compile with: `gcc -static hello.c -o hello` (using syscall())

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
