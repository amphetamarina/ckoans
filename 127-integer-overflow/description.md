# Integer Overflow - Detect with UBSan

## Concept
**Integer overflow** occurs when arithmetic operations produce values outside the representable range:
- **Signed overflow**: Undefined behavior in C
- **Unsigned overflow**: Well-defined (wraps around)
- Can lead to incorrect calculations, buffer overflows, security issues

**UndefinedBehaviorSanitizer (UBSan)** detects:
- Signed integer overflow
- Division by zero
- Shift operations with invalid operands
- Other undefined behavior

Compile with: `gcc -fsanitize=undefined -g`

## What's Broken
The program has integer overflow bugs that UBSan will catch.

## Learning Goal
- Understand signed vs unsigned overflow
- Use UBSan to detect integer overflow at runtime
- See how overflow can cause unexpected behavior
- Fix by adding bounds checks or using larger types

## Task
1. Compile with UBSan: `gcc -fsanitize=undefined -g broken.c -o broken`
2. Run and observe UBSan error: `./broken`
3. Read the error report showing overflow location
4. Fix by adding checks or using appropriate types
5. Verify correct output

## Verify
```bash
# Should fail with UBSan
gcc -fsanitize=undefined -g broken.c -o broken
./broken 2>&1 | grep -q "overflow" && echo "UBSan detected overflow (expected)"

# After fixing, should pass
gcc -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
