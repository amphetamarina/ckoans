#include <stdio.h>
#include <string.h>

// Slow version: O(n^2) string concatenation
void build_string_slow(char *result, int count) {
    result[0] = '\0';
    for (int i = 0; i < count; i++) {
        // BUG: strlen is called repeatedly, making this O(n^2)
        int len = strlen(result);
        result[len] = 'A' + (i % 26);
        result[len + 1] = '\0';
    }
}

// Fast version: O(n) with position tracking
void build_string_fast(char *result, int count) {
    int pos = 0;
    for (int i = 0; i < count; i++) {
        result[pos++] = 'A' + (i % 26);
    }
    result[pos] = '\0';
}

// Slow version: Bubble sort O(n^2)
void sort_slow(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fast version: Better sorting (insertion sort, still O(n^2) but faster in practice)
void sort_fast(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(void) {
    printf("Callgrind diff comparison:\n\n");

    char result[10001];

#if defined(SLOW)
    printf("Using SLOW version\n");
    build_string_slow(result, 10000);

    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = 1000 - i;
    }
    sort_slow(arr, 1000);

#elif defined(FAST)
    printf("Using FAST version\n");
    build_string_fast(result, 10000);

    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = 1000 - i;
    }
    sort_fast(arr, 1000);

#else
    // BUG: Default is slow version
    printf("Using default (SLOW) version\n");
    build_string_slow(result, 10000);

    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = 1000 - i;
    }
    sort_slow(arr, 1000);
#endif

    printf("String length: %ld\n", strlen(result));
    printf("First 10 chars: %.10s\n", result);
    printf("Sorted array (first 5): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
