# SSA Form

## Concept
**SSA (Static Single Assignment)** form is an IR property where each variable is assigned exactly once. This simplifies optimization.

**Regular code** (non-SSA):
```c
x = 1;
x = x + 2;
x = x * 3;
```

**SSA form**:
```
x1 = 1
x2 = x1 + 2
x3 = x2 * 3
```

Each assignment creates a new version. SSA enables:
- **Constant propagation**: Track exact values through versions
- **Dead code elimination**: Unused versions can be removed
- **Register allocation**: Each version maps to a register

**Phi functions** merge values from different control flow paths:
```llvm
if.then:
  %x1 = add i32 %a, 1
  br label %merge
if.else:
  %x2 = add i32 %a, 2
  br label %merge
merge:
  %x = phi i32 [ %x1, %if.then ], [ %x2, %if.else ]
```

LLVM IR is in SSA form. View with: `clang -S -emit-llvm -Xclang -disable-O0-optnone`

## What's Broken
The C code has redundant assignments that waste SSA versions. Examine the IR to see the SSA form and optimize the code.

## Learning Goal
Understand:
- What SSA form is
- How LLVM IR uses SSA
- Phi functions for control flow merges
- Why SSA helps optimization

## Task
1. Generate IR: `clang -S -emit-llvm -Xclang -disable-O0-optnone broken.c -o broken.ll`
2. Examine SSA versions (e.g., `%1`, `%2`, `%3`)
3. Identify redundant assignments in C code
4. Optimize the C code to reduce SSA versions

## Verify
```bash
clang -S -emit-llvm broken.c -o broken.ll && grep -E "%(add|mul)" broken.ll
clang -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
