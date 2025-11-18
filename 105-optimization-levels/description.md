# Optimization Levels

## Concept
GCC provides multiple optimization levels:
- **`-O0`**: No optimization (default) - best for debugging
- **`-O1`**: Basic optimizations - reduces code size and execution time
- **`-O2`**: Recommended level - enables most optimizations without space/speed tradeoffs
- **`-O3`**: Aggressive optimizations - may increase code size
- **`-Os`**: Optimize for size
- **`-Og`**: Optimize for debugging experience

Higher optimization levels can:
- Expose undefined behavior
- Change timing-sensitive code
- Make debugging harder
- Significantly improve performance

## What's Broken
The code has undefined behavior that only manifests at certain optimization levels.

## Learning Goal
Understand:
- How optimization levels affect code behavior
- Why undefined behavior may work at `-O0` but fail at `-O2`
- The importance of writing well-defined C code

## Fix It
Fix the undefined behavior so the code works correctly at all optimization levels.

## Verify
```bash
gcc -O2 -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
