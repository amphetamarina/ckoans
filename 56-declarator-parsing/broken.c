#include <stdio.h>

// BUG: Wrong - this is array of pointers, should be pointer to array
int *array_ptr[5];  // Should be: int (*array_ptr)[5];

// BUG: Wrong - this is function returning pointer, should be pointer to function
int *func_ptr(void);  // Should be: int (*func_ptr)(void);

// Correct definition for comparison
int (*correct_func_ptr)(int);

int sample_function(int x) {
    return x * 2;
}

int main(void) {
    // BUG: Trying to use array_ptr as pointer to array, but it's array of pointers
    int data[5] = {1, 2, 3, 4, 5};
    // This won't work correctly:
    array_ptr = &data;  // Type mismatch
    printf("First element via array_ptr: %d\n", (*array_ptr)[0]);

    // BUG: Trying to assign function to func_ptr won't work - wrong type
    func_ptr = sample_function;  // Type mismatch
    int result = func_ptr(5);
    printf("Function result: %d\n", result);

    // This one works:
    correct_func_ptr = sample_function;
    printf("Correct function result: %d\n", correct_func_ptr(7));

    return 0;
}
