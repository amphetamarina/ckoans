# Symbol Versioning

## Concept
**Symbol versioning** allows multiple versions of a function to coexist in the same library, enabling ABI compatibility.

**Why version symbols:**
- Maintain backward compatibility
- Allow ABI changes without breaking existing binaries
- Multiple versions of same function can coexist
- Clients bind to specific versions

**GNU symbol versioning:**
1. Version script defines symbol→version mapping
2. `@` in symbol name indicates version (e.g., `foo@VERS_1.0`)
3. `@@` indicates default version
4. Old versions can call new implementations

**Example version script:**
```
VERS_1.0 {
    global: foo; bar;
    local: *;
};
VERS_2.0 {
    global: foo; baz;
} VERS_1.0;
```

**Checking versions:**
```bash
readelf -s lib.so | grep @
objdump -T lib.so
nm -D lib.so
```

## What's Broken
The program demonstrates symbol versioning but has incorrect version attributes.

## Learning Goal
- Understand symbol versioning in shared libraries
- Learn version script syntax
- See how multiple symbol versions coexist
- Handle ABI changes gracefully

## Task
1. Create version script defining symbol versions
2. Compile with version script: `gcc -shared -Wl,--version-script=vers.txt -o lib.so`
3. Check versions: `readelf -s lib.so | grep foo`
4. Fix the version annotations

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
