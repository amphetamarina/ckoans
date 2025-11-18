# ABI Break → Fix with Version Script

## Concept
An **ABI (Application Binary Interface) break** occurs when a library changes in a way that's incompatible with existing binaries. **Version scripts** help maintain ABI compatibility.

**Common ABI breaks:**
- Changing function signatures
- Removing public functions
- Changing struct layout
- Changing enum values
- Changing symbol visibility

**Version script solution:**
1. Keep old implementation with old version tag
2. Add new implementation with new version tag
3. Mark new version as default (`@@`)
4. Old binaries use old version (`@VERS_1`)
5. New binaries use new version (`@@VERS_2`)

**Version script syntax:**
```
VERS_1.0 {
    global: old_api;
    local: *;
};
VERS_2.0 {
    global: new_api; old_api;
} VERS_1.0;
```

**Aliasing versions:**
```c
__asm__(".symver old_func,func@VERS_1");
__asm__(".symver new_func,func@@VERS_2");
```

## What's Broken
The library broke ABI by changing a function signature. We'll fix it using symbol versioning.

## Learning Goal
- Understand ABI compatibility
- Learn to use version scripts to maintain compatibility
- See how to evolve APIs without breaking existing binaries
- Use .symver directives

## Task
1. Identify the ABI break
2. Create version script with both versions
3. Use .symver to provide both implementations
4. Compile: `gcc -shared -Wl,--version-script=versions.txt`
5. Verify both versions exist: `nm -D lib.so | grep func`

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
