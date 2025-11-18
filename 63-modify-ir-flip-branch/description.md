# Modify IR to Flip Branch

## Concept
LLVM IR can be manually edited to change program behavior. This demonstrates understanding of:
- IR syntax and semantics
- Control flow in IR (branches, labels)
- How to manipulate IR directly

Branch instructions in LLVM IR:
```llvm
br i1 %cmp, label %if.then, label %if.else  ; Conditional branch
br label %merge                              ; Unconditional branch
```

To flip a branch, swap the target labels:
```llvm
; Original:
br i1 %cmp, label %true_block, label %false_block

; Flipped:
br i1 %cmp, label %false_block, label %true_block
```

Or negate the condition:
```llvm
; Original:
%cmp = icmp sgt i32 %x, 10    ; x > 10
br i1 %cmp, label %greater, label %not_greater

; Flipped:
%cmp = icmp sle i32 %x, 10    ; x <= 10
br i1 %cmp, label %not_greater, label %greater
```

## What's Broken
The code has a logical error in a branch condition. Generate IR, manually modify it to flip the branch, and see how the behavior changes.

## Learning Goal
Understand:
- IR branch instructions (`br`)
- How control flow is represented in IR
- Manually editing IR files
- Compiling modified IR back to executable

## Task
1. Generate IR: `clang -S -emit-llvm broken.c -o broken.ll`
2. Find the branch instruction in `broken.ll`
3. Flip the branch by swapping labels or negating condition
4. Compile modified IR: `clang broken.ll -o broken`
5. Compare original vs modified behavior

## Verify
```bash
clang -S -emit-llvm broken.c -o broken.ll
# Manually edit broken.ll to flip a branch
clang broken.ll -o broken && ./broken
diff <(./broken) expected.txt
```
