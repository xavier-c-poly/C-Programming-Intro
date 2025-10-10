#include <stdio.h>

#define SIZE 11

int main(void) {
    double d_arr[SIZE] = {0};

    printf("The fourth element is %lf\n", d_arr[3]);
    d_arr[5] = 4.53;
    printf("First element: %.2lf, last element: %.2lf\n", d_arr[0], d_arr[SIZE - 1]);

    for (int i = 0; i < SIZE; i++) {
        printf("%lf ", d_arr[i]);
    }
    puts("");
}