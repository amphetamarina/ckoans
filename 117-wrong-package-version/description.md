# Wrong Package Version → Detect

## Concept
Version mismatches are a common build failure:
- Code requires library version X
- System has version Y
- Build fails with cryptic errors

Debugging techniques:
1. **Check installed version**: `pkg-config --modversion libname`
2. **Check version requirements**: Look at `Requires` in `.pc` file
3. **List all versions**: `pkg-config --list-all | grep libname`
4. **Check search path**: `pkg-config --variable pc_path pkg-config`
5. **Verbose errors**: `pkg-config --print-errors --errors-to-stdout`

Common scenarios:
- Multiple versions installed (wrong one found first)
- Version in code doesn't match `.pc` file
- Transitive dependency version mismatch

## What's Broken
The build fails because the installed library version doesn't meet the code's requirements. You must diagnose:
1. What version is required?
2. What version is available?
3. How to fix the mismatch?

## Learning Goal
Understand:
- How to diagnose version mismatches
- How to check available package versions
- How to update version requirements
- How PKG_CONFIG_PATH affects version resolution

## Fix It
Detect the version mismatch and fix it by either:
- Updating the `.pc` file version
- Relaxing the version requirement
- Using the correct package name

## Verify
```bash
export PKG_CONFIG_PATH=.
make
./program
diff <(./program) expected.txt
```
