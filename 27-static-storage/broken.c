#include <stdio.h>

int call_count(void) {
    // BUG: Missing 'static' keyword - counter resets each call
    int count = 0;
    count++;
    return count;
}

int main(void) {
    printf("Call 1: %d\n", call_count());
    printf("Call 2: %d\n", call_count());
    printf("Call 3: %d\n", call_count());
    printf("Call 4: %d\n", call_count());
    printf("Call 5: %d\n", call_count());
    return 0;
}
