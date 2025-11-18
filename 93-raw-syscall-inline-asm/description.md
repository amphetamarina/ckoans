# Raw Syscall via Inline Assembly

## Concept
You can invoke system calls directly using **inline assembly**, bypassing C library wrappers entirely.

**x86-64 Linux syscall convention**:
- Syscall number in `%rax`
- Arguments in `%rdi`, `%rsi`, `%rdx`, `%r10`, `%r8`, `%r9` (in that order)
- Instruction: `syscall`
- Return value in `%rax`
- Registers `%rcx` and `%r11` are clobbered

**GCC inline assembly syntax**:
```c
asm volatile (
    "syscall"
    : "=a" (result)              // Output: result from %rax
    : "0" (syscall_num),         // Input: syscall_num to %rax (0 means same as output 0)
      "D" (arg1),                // Input: arg1 to %rdi
      "S" (arg2),                // Input: arg2 to %rsi
      "d" (arg3)                 // Input: arg3 to %rdx
    : "rcx", "r11", "memory"     // Clobbered
);
```

**Register constraints**:
- `"a"` = RAX (accumulator)
- `"D"` = RDI (destination)
- `"S"` = RSI (source)
- `"d"` = RDX (data)

**When to use raw syscalls**:
- Writing minimal code without libc (e.g., bootloaders)
- Understanding low-level OS interaction
- Performance-critical code (avoid wrapper overhead)
- Educational purposes

**Most programs should use**:
- C library wrappers (easier, portable)
- `syscall()` function (still simpler than inline asm)

## What's Broken
The inline assembly has incorrect register constraints or argument ordering.

## Learning Goal
Understand that:
- Syscalls can be made directly via assembly
- Must follow calling convention precisely
- Register placement matters
- Inline asm is architecture-specific

## Fix It
Correct the register constraints and argument ordering in the inline assembly.

## Verify
```bash
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
