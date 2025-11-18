# Fixed Timestamps

## Concept
**Reproducible builds** require eliminating non-deterministic inputs like timestamps. Fixed timestamps ensure byte-identical builds.

**Sources of timestamps in builds:**
- `__DATE__` and `__TIME__` macros
- File modification times in archives (.a)
- Build timestamps in debug info
- PE/COFF timestamps in Windows binaries

**Making builds reproducible:**
1. Avoid `__DATE__`/`__TIME__` macros
2. Use `SOURCE_DATE_EPOCH` environment variable
3. Pass fixed timestamp to tools: `ar -D` (deterministic mode)
4. Strip timestamps from output

**SOURCE_DATE_EPOCH:**
```bash
export SOURCE_DATE_EPOCH=1234567890
gcc program.c -o program
```

**Checking for embedded timestamps:**
```bash
strings binary | grep -E '[0-9]{4}-[0-9]{2}-[0-9]{2}'
readelf -p .comment binary
```

**Benefits:**
- Verify build integrity
- Detect supply chain attacks
- Enable distributed caching
- Prove binary matches source

## What's Broken
The program embeds timestamps that make builds non-reproducible.

## Learning Goal
- Understand reproducible build principles
- Eliminate timestamp dependencies
- Use SOURCE_DATE_EPOCH
- Verify builds are byte-identical

## Task
1. Remove __DATE__ and __TIME__ usage
2. Use SOURCE_DATE_EPOCH if timestamp needed
3. Verify: Build twice, compare with `sha256sum`
4. Fix timestamp issues

## Verify
```bash
gcc -o broken broken.c
./broken
diff <(./broken) expected.txt
```
