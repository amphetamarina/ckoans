#include <stdio.h>

// BUG: Function with local variables - will have prologue
int calculate(int a, int b, int c) {
    // BUG: Many local variables = larger stack frame in prologue
    int temp1 = a + b;
    int temp2 = b + c;
    int temp3 = a + c;
    int result = temp1 + temp2 + temp3;

    // Examine assembly: prologue should allocate space for these

    return result;
}

// BUG: Leaf function with no locals - might skip full prologue
int simple_add(int x, int y) {
    return x + y;
}

int main(void) {
    // BUG: Local variables here too - check main's prologue
    int values[5] = {1, 2, 3, 4, 5};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += values[i];
    }

    printf("Array sum: %d\n", sum);

    int result = calculate(10, 20, 30);
    printf("Calculate: %d\n", result);

    int simple = simple_add(5, 7);
    printf("Simple add: %d\n", simple);

    // Task: Generate assembly and identify:
    // 1. main's prologue (push rbp, mov rsp rbp, sub rsp X)
    // 2. calculate's prologue
    // 3. simple_add's prologue (or lack thereof)

    return 0;
}
