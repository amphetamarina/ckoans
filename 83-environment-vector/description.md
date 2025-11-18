# Environment Vector

## Concept
Each process has an **environment vector** - an array of strings containing environment variables in the form `NAME=value`. This can be accessed in three ways:

1. **`extern char **environ`**: Global variable pointing to environment array
2. **`getenv(name)`**: Get value of specific variable
3. **`main(int argc, char *argv[], char *envp[])`**: Third parameter to main

Environment variables:
- Inherited from parent process
- Can be modified with `setenv()`, `unsetenv()`, `putenv()`
- Passed to child processes via `fork()`
- Can be explicitly set when using `execve()` or `execle()`

## What's Broken
The program incorrectly accesses and displays environment variables.

## Learning Goal
Understand that:
- Environment is an array of strings with `NAME=value` format
- `getenv()` returns the value portion only
- Environment is inherited across `fork()` but can be customized for `exec()`
- The environ array is NULL-terminated

## Fix It
Correct the environment variable access to properly retrieve and display values.

## Verify
```bash
gcc -o broken broken.c && MY_VAR="test_value" ./broken
diff <(MY_VAR="test_value" ./broken) expected.txt
```
