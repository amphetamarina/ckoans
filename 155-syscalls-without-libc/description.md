# Syscalls Without libc

## Concept
Programs can make **system calls directly** without using libc wrapper functions, essential for minimal runtime environments.

**Direct syscall invocation (x86-64):**
```c
static inline long syscall1(long n, long a1) {
    long ret;
    asm volatile("syscall"
        : "=a"(ret)
        : "a"(n), "D"(a1)
        : "rcx", "r11", "memory");
    return ret;
}
```

**Register mapping (x86-64):**
- Syscall number: RAX
- Args: RDI, RSI, RDX, R10, R8, R9
- Return: RAX
- Clobbered: RCX, R11

**Common syscalls:**
```c
#define SYS_read  0
#define SYS_write 1
#define SYS_exit  60
```

**Why bypass libc:**
- Minimal binary size
- No libc dependency
- Bootloaders and kernels
- Understanding system interface
- Security-sensitive code

**Example:**
```c
syscall3(SYS_write, 1, "Hello\n", 6);  // write to stdout
syscall1(SYS_exit, 0);                  // exit with 0
```

## What's Broken
The program demonstrates direct syscalls but has incorrect syscall numbers or arguments.

## Learning Goal
- Make syscalls without libc
- Understand syscall ABI
- Learn syscall numbers and arguments
- Write minimal programs

## Task
1. Define syscall wrapper functions
2. Use correct syscall numbers
3. Pass arguments in correct order
4. Compile with -nostdlib if removing all libc

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
