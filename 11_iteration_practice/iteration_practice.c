#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void countDown(int n);
void printNRandom(int n);

int main(void) {
    srand(2);
    printf("Enter a number: ");
    int input;
    scanf("%d", &input);
    countDown(input);

    printf("\n\n");

    int randNNumber;
    printf("Enter another number: ");
    scanf("%d", &randNNumber);
    printNRandom(randNNumber);

    return 0;
}

void countDown(int n) {
    for (int i = n; i >= 0; i--) {
        printf("%d\n", i);
        // usleep(1000000);
        usleep(40000);
    }
}

void printNRandom(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", rand());
    }
}