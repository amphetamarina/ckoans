#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// BUG: Allocates many small objects instead of one larger allocation
Node* create_list_slow(int count) {
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < count; i++) {
        // BUG: Many individual malloc calls
        Node *node = malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

// Fixed version using array allocation
// typedef struct {
//     int *data;
//     int size;
// } Array;
//
// Array* create_array_fast(int count) {
//     Array *arr = malloc(sizeof(Array));
//     arr->data = malloc(count * sizeof(int));
//     arr->size = count;
//     for (int i = 0; i < count; i++) {
//         arr->data[i] = i;
//     }
//     return arr;
// }

// BUG: Allocates huge temporary buffers
void process_data_inefficient(int *data, int size) {
    // BUG: Unnecessary large allocation
    int *temp1 = malloc(size * sizeof(int));
    int *temp2 = malloc(size * sizeof(int));
    int *temp3 = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        temp1[i] = data[i] * 2;
        temp2[i] = temp1[i] + 1;
        temp3[i] = temp2[i] * 3;
        data[i] = temp3[i];
    }

    free(temp1);
    free(temp2);
    free(temp3);
}

// Fixed version without temporary allocations
// void process_data_efficient(int *data, int size) {
//     for (int i = 0; i < size; i++) {
//         data[i] = (data[i] * 2 + 1) * 3;
//     }
// }

void free_list(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    printf("Massif heap profiling:\n\n");

    // BUG: Creates many small allocations
    Node *list = create_list_slow(10000);
    printf("Created list with 10000 nodes\n");

    // BUG: Allocates large temporary buffers
    int *data = malloc(50000 * sizeof(int));
    for (int i = 0; i < 50000; i++) {
        data[i] = i;
    }

    process_data_inefficient(data, 50000);
    printf("Processed 50000 elements\n");

    printf("First 5 results: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    free(data);
    free_list(list);

    return 0;
}
