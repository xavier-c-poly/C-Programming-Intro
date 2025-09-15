#include <stdio.h>

void printHello(void) {
    int i = 1;
    while (i <=10) {
        puts("Hello");
        i = i + 1;
    }

    int p = 3;
    while (p <= 100) {
        printf("%d\n", p);
        p = p * 3;
    }
}