#include <stdio.h>
// BUG: Using <> for local header - should use ""
#include <myheader.h>

int main(void) {
    printf("Message: %s\n", GREETING);
    printf("Value: %d\n", MAGIC_NUMBER);
    return 0;
}
