#include <stdio.h>
#include "api.h"
#include "utils.h"

int main(void) {
    printf("API Version: %s\n", API_VERSION);
    printf("Utils: %d\n", get_value());
    return 0;
}
