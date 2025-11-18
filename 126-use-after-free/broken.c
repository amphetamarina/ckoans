#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void linked_list_bug(void) {
    Node *head = malloc(sizeof(Node));
    head->value = 1;
    head->next = malloc(sizeof(Node));
    head->next->value = 2;
    head->next->next = NULL;

    printf("List before free: %d -> %d\n", head->value, head->next->value);

    free(head->next);
    free(head);

    // BUG: Using freed memory
    printf("List after free: %d -> %d\n", head->value, head->next->value);
}

char* create_string(const char *text) {
    char *str = malloc(strlen(text) + 1);
    strcpy(str, text);
    free(str);  // BUG: Freeing before returning
    return str;  // BUG: Returning freed memory
}

void double_free_bug(void) {
    int *data = malloc(sizeof(int) * 5);
    data[0] = 100;

    printf("Data value: %d\n", data[0]);

    free(data);
    // BUG: Double free
    free(data);
}

int main(void) {
    printf("Use-after-free detection:\n\n");

    // BUG: This uses freed memory
    char *msg = create_string("Test");
    printf("Message: %s\n", msg);  // BUG: msg points to freed memory

    linked_list_bug();

    // double_free_bug();  // Uncomment to test double-free

    return 0;
}
