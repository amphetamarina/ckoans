# Identify Prologue in GCC Assembly

## Concept
Every function's assembly code has a **prologue** and **epilogue**:

**Prologue** (function entry):
```asm
push   %rbp          # Save old base pointer
mov    %rsp, %rbp    # Set up new base pointer
sub    $N, %rsp      # Allocate N bytes for locals
```

**Epilogue** (function exit):
```asm
mov    %rbp, %rsp    # Restore stack pointer
pop    %rbp          # Restore base pointer
ret                  # Return to caller
```

The prologue:
1. Saves caller's frame pointer (`rbp`)
2. Sets up new frame pointer
3. Allocates stack space for local variables

Variations:
- `-fomit-frame-pointer`: Skip rbp setup (use rsp only)
- Leaf functions: May skip prologue if no locals
- With `-O0`: Full prologue always present

Generate assembly:
```bash
gcc -S -masm=intel source.c   # Intel syntax
gcc -S source.c               # AT&T syntax (default)
```

## What's Broken
The code will compile to assembly with standard prologue/epilogue. Examine the assembly to identify these sections.

## Learning Goal
Understand:
- Function prologue and epilogue structure
- How to read GCC assembly output
- Stack frame setup
- Using `gcc -S` to generate assembly

## Task
1. Generate assembly: `gcc -S broken.c -o broken.s`
2. Open `broken.s` and find the `main` function
3. Identify the prologue (first few instructions)
4. Identify the epilogue (last few instructions before `ret`)
5. Try with `-O2` to see optimized version
6. Try with `-fomit-frame-pointer` to see variation

## Verify
```bash
gcc -S broken.c -o broken.s
grep -A 10 "main:" broken.s    # See prologue
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
