# Prologue/Epilogue Patterns

## Concept
Functions have standard entry/exit sequences:
- **Prologue**: Save frame pointer, allocate stack space
  ```asm
  push rbp
  mov rbp, rsp
  sub rsp, N
  ```
- **Epilogue**: Restore frame pointer, return
  ```asm
  leave  ; or: mov rsp, rbp; pop rbp
  ret
  ```

## What's Broken
Examine assembly to understand prologue/epilogue.

## Learning Goal
- Identify prologue/epilogue in assembly
- Understand stack frame setup
- See how optimizations affect these patterns

## Task
Fix the C code and identify prologue/epilogue in assembly.

## Verify
```bash
gcc -O0 -fno-omit-frame-pointer -S broken.c -o broken.s
cat broken.s
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
