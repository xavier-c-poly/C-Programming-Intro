#include <stdio.h>

#define SIZE 10

void printArray(const int* array, int size);

int main(void) {
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("%p\n", a);

    printArray(a, SIZE);
    printf("%p\n", &a);  // This
    printf("%p\n", a);
    printf("%d\n", *a);

    printf("%d\n", **(&a));  // This one
    printf("%d\n", *a);

    return 0;
}

void printArray(const int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
    puts("");
}