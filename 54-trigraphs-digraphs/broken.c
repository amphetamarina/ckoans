#include <stdio.h>

int main(void) {
    // BUG: Using digraphs - harder to read
    // <: and :> are [ and ]
    int array<:10:> = <% 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 %>;

    // BUG: Accidental trigraph in string - ??! becomes |
    printf("What??! This is weird.\n");

    // BUG: Using %: instead of # for preprocessor
    // (This is in a string, so it's just confusing)
    printf("Array size: %d\n", 10);

    // Print array sum
    int sum = 0;
    for (int i = 0; i < 10; i++) <%
        sum += array<:i:>;
    %>

    printf("Sum: %d\n", sum);

    return 0;
}
