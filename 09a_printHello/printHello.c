#include <stdio.h>

void printHello(void) {
    int i = 1;
    while (i <= 10) {
        puts("Hello");
        i = i + 1;
    }
}

void printHelloBetter() {
    for (int i = 1; i < 11; i++) {
        puts("Hello");
    }
}

int main(void) {
    printHello();
    printf("\n\n");
    printHelloBetter();
    printf("\n\n");

    return 0;
}