# Version Checks

## Concept
pkg-config can check library versions to ensure compatibility:

Version comparison operators:
- `pkg-config --exists "mylib >= 2.0"` - At least version 2.0
- `pkg-config --exists "mylib <= 3.0"` - At most version 3.0
- `pkg-config --exists "mylib = 2.5"` - Exactly version 2.5
- `pkg-config --modversion mylib` - Print version

In Makefiles:
```make
# Check if library exists and meets version requirement
ifeq ($(shell pkg-config --exists "mylib >= 2.0" && echo yes),yes)
    # Use the library
else
    $(error mylib >= 2.0 is required)
endif
```

Or more robustly:
```make
REQUIRED_VERSION = 2.0
$(shell pkg-config --atleast-version=$(REQUIRED_VERSION) mylib || echo "error")
```

## What's Broken
The Makefile has incorrect version checks that either fail when they should succeed or succeed when they should fail.

## Learning Goal
Understand:
- How to check library versions with pkg-config
- Version comparison operators
- How to integrate version checks into Makefiles
- Failing gracefully with informative error messages

## Fix It
Fix the version checks to properly validate library versions.

## Verify
```bash
export PKG_CONFIG_PATH=.
make
./program
diff <(./program) expected.txt
```
