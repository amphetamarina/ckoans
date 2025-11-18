# Memory Barriers

## Concept
**Memory barriers** (also called memory fences) ensure that memory operations complete in a specific order. Modern CPUs and compilers can reorder memory operations for optimization, which can break multithreaded code.

**Why reordering happens**:
- **Compiler optimizations**: Reorders instructions for efficiency
- **CPU out-of-order execution**: CPU can execute instructions in different order
- **Store buffers**: Writes may not be immediately visible to other cores
- **Cache coherency**: Takes time to propagate changes between CPU caches

**Types of barriers**:
- **Full barrier**: `__sync_synchronize()` or `__atomic_thread_fence(__ATOMIC_SEQ_CST)`
- **Acquire barrier**: Prevents later loads/stores from moving before it
- **Release barrier**: Prevents earlier loads/stores from moving after it

**GCC atomic built-ins**:
- `__atomic_load_n(&var, order)`
- `__atomic_store_n(&var, val, order)`
- `__atomic_thread_fence(order)`

**Memory orders**:
- `__ATOMIC_SEQ_CST` - Sequential consistency (strongest)
- `__ATOMIC_ACQUIRE` - Acquire semantics
- `__ATOMIC_RELEASE` - Release semantics
- `__ATOMIC_RELAXED` - No ordering (weakest)

## What's Broken
The program uses regular loads/stores where atomic operations with proper memory ordering are needed.

## Learning Goal
Understand that:
- Memory operations can be reordered by compiler and CPU
- Multithreaded code needs memory barriers for correctness
- Atomic operations provide both atomicity and ordering
- Different memory orders provide different guarantees

## Fix It
Replace plain variables with atomic operations and add appropriate memory barriers.

## Verify
```bash
gcc -pthread -o broken broken.c && ./broken
diff <(./broken) expected.txt
```
