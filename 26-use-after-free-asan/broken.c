#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[32];
} Record;

void process_record(void) {
    Record *rec = malloc(sizeof(Record));
    if (!rec) return;

    rec->id = 42;
    strcpy(rec->name, "Example");

    printf("Processing record: id=%d, name=%s\n", rec->id, rec->name);

    free(rec);

    // BUG: Use-after-free - accessing rec after free
    printf("Record ID after free: %d\n", rec->id);
}

void dangling_pointer_bug(void) {
    int *data = malloc(10 * sizeof(int));
    if (!data) return;

    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }

    printf("Sum before free: ");
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += data[i];
    }
    printf("%d\n", sum);

    free(data);

    // BUG: Use-after-free - calculating sum after free
    printf("Sum after free: ");
    sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += data[i];
    }
    printf("%d\n", sum);
}

int main(void) {
    printf("Use-after-free demonstration:\n\n");
    process_record();
    printf("\n");
    dangling_pointer_bug();
    return 0;
}
