#include <stdio.h>
#include <string.h>

// BUG: This function has a strict aliasing violation
// At -O2, the optimizer may cache the value of *i
int buggy_function(int* i, float* f) {
    *i = 42;
    // BUG: If f points to same memory as i, this violates strict aliasing
    // Optimizer assumes float* and int* don't alias
    *f = 3.14f;

    // At -O0: will read updated value (3.14 reinterpreted as int)
    // At -O2: may return cached value 42 (optimizer assumes no aliasing)
    return *i;
}

// Correct version using union
union IntFloat {
    int i;
    float f;
};

int correct_function(void) {
    union IntFloat u;
    u.i = 42;
    u.f = 3.14f;
    return u.i;  // Reading after write through different member
}

// Correct version using memcpy
int correct_memcpy_function(void) {
    int result = 42;
    float f = 3.14f;
    memcpy(&result, &f, sizeof(result));
    return result;
}

int main(void) {
    // This would trigger the bug:
    // int x = 0;
    // int result = buggy_function(&x, (float*)&x);  // BUG: Aliasing violation!
    // printf("Buggy result: %d\n", result);

    // Use correct versions instead
    printf("Correct (union): %d\n", correct_function());
    printf("Correct (memcpy): %d\n", correct_memcpy_function());

    // Demonstrate safe usage with separate objects
    int i = 42;
    float f = 3.14f;
    int safe_result = buggy_function(&i, &f);  // OK: no aliasing
    printf("Safe result: %d\n", safe_result);

    return 0;
}
