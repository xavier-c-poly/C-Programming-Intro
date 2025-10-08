#include <stdio.h>

// Symbolic constant
#define SIZE 200

int main(void) {
    // Create an array
    int arr[SIZE];

    // Set the first element with 111
    arr[0] = 111;

    // Set the last element with 999
    arr[9] = 999;

    // Print the values of the first and last
    printf("First: %d; Last: %d\n", arr[0], arr[9]);

    // Initialize an array with a loop
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i*i;  // produces squares of each index
        // arr[i] = (i+1)*10;  // produces multiples of ten starting from 1
    }

    // Print the whole array
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
        if (i < sizeof(arr) / sizeof(int) - 1)
            printf("%d ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }

    return 0;
}