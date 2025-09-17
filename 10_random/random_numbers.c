#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void countDown(int n);
void printNRandom(int n);
int returnRandomInclusive(int min, int max);

int main(void) {
    // Call srand function, time 0 calls current time of unix system
    srand(time(0));
    printf("Enter a number to countdown from: ");
    int input;
    scanf("%d", &input);
    countDown(input);

    // printf("\n");

    int randNNumber;
    printf("How many random numbers should I generate: ");
    scanf("%d", &randNNumber);
    printNRandom(randNNumber);

    return 0;
}

void countDown(int n) {
    for (int i = n; i >= 0; i--) {
        printf("%d\n", i);
        // usleep(1000000);  // one second
        usleep(40000);
    }
}

// rand [min, max] = rand() % (max - min + 1) + min
//      scaling factor (range) <--|   |--> shifting value (starting point)
void printNRandom(int n) {
    printf("\n\nFirst generation [3, 17]\n");
    int min, max;
    for (int i = 0; i < n; i++) {
        printf("%d\n", rand() % (17 - 3 + 1) + 3);
    }

    printf("\n\nSecond generation [-5, 5]\n");
    min = -5, max = 5;
    for (int i = 0; i < n; i++) {
        printf("%d\n", rand() % (max - min + 1) + min);
    }

    printf("\n\nThird generation [-7, 8]\n");
    min = -7, max = 8;
    for (int i = 0; i < n; i++) {
        printf("%d\n", returnRandomInclusive(min, max));
    }
}

int returnRandomInclusive(int min, int max) {
    return rand() % (max - min + 1) + min;
}