#include <stdio.h>

int main(void) {
    // Print the values from 15 to 45 in steps of 5 (15, 20, 25...)
    for (int i = 15; i <= 45; i += 5) printf("%d\n", i);

    // Print every even number from 100 to 2
    for (int i = 2; i <= 100; i += 2) printf("%d\n", i);

    printf("\n\n");

    int sum1 = 0;
    for (int i = 0; i < 8; ++i) {
        sum1++;
        printf("%d\n", i);
    }
    printf("This loop ran %d times.\n", sum1);

    int sum2 = 0;
    for (int i = 0; i < 8; i++) {
        sum2++;
        printf("%d\n", i);
    }
    printf("This loop ran %d times.\n", sum2);

    int sum3 = 0;
    for (int i = 0; i <= 8; ++i) sum3++;
    printf("This loop ran %d times.\n", sum3);

    int sum4 = 0;
    for (int i = 0; i <= 8; i++) sum4++;
    printf("This loop ran %d times.\n", sum4);

    return 0;
}