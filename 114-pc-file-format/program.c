#include <stdio.h>

// Simulating a library function (normally would be in libmylib.a)
int mylib_function(void) {
    return 42;
}

int main(void) {
    printf("Library returned: %d\n", mylib_function());
    return 0;
}
