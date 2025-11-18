#include <stdio.h>
#include <string.h>

// BUG: Returns pointer to local variable (UB!)
char* get_message(void) {
    char msg[50];  // Automatic storage - destroyed on return!
    strcpy(msg, "This is a local message");
    return msg;  // BUG: Returning dangling pointer!
}

// BUG: Returns pointer to local int (UB!)
int* get_number(void) {
    int num = 42;  // Stack variable
    return &num;   // BUG: Address becomes invalid after return
}

// Correct version using static storage
char* get_message_correct(void) {
    // Using 'static' makes it persist
    static char msg[50];
    strcpy(msg, "This is a local message");
    return msg;  // OK: static storage persists
}

int* get_number_correct(void) {
    static int num = 42;
    return &num;  // OK: static storage persists
}

int main(void) {
    // Using the buggy versions (undefined behavior)
    char* msg = get_message();
    int* num = get_number();

    // These might crash, print garbage, or appear to work!
    // Outcome is unpredictable (undefined behavior)
    // printf("Message: %s\n", msg);  // UB!
    // printf("Number: %d\n", *num);   // UB!

    // Use correct versions instead
    char* correct_msg = get_message_correct();
    int* correct_num = get_number_correct();

    printf("Message: %s\n", correct_msg);
    printf("Number: %d\n", *correct_num);

    return 0;
}
