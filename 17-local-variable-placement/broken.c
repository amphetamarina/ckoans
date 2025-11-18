#include <stdio.h>

void func(void) {
    int a = 10;
    int b = 20;
    int arr[4] = {1, 2, 3, 4};
    int c = 30;

    printf("Variable addresses (negative offsets from frame base):\n");
    printf("&a   = %p\n", (void*)&a);
    printf("&b   = %p\n", (void*)&b);
    printf("&arr = %p\n", (void*)arr);
    printf("&c   = %p\n", (void*)&c);

    // BUG: Wrong loop bound - should be i < 4
    int sum = 0;
    for (int i = 0; i <= 4; i++) {
        sum += arr[i];  // This accesses out of bounds!
    }

    printf("Sum: %d\n", sum);
}

int main(void) {
    func();
    return 0;
}
