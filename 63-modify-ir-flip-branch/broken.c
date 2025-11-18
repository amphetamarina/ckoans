#include <stdio.h>

int check_value(int x) {
    // BUG: Branch condition is inverted - should be x >= 10
    if (x < 10) {
        return 1;  // Should mean "large"
    } else {
        return 0;  // Should mean "small"
    }
}

int main(void) {
    int values[] = {5, 10, 15, 20};

    for (int i = 0; i < 4; i++) {
        int result = check_value(values[i]);
        if (result) {
            printf("%d is large\n", values[i]);
        } else {
            printf("%d is small\n", values[i]);
        }
    }

    // BUG: Another branch issue
    int x = 12;
    // Should print "x >= 10" but condition is wrong
    if (x < 10) {
        printf("x >= 10\n");
    } else {
        printf("x < 10\n");
    }

    return 0;
}
