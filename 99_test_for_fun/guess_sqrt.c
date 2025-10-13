#include <stdio.h>
// #include "C:\MinGW\include\stdio.h"
#include <stdbool.h>

double approximate_sqrt(int number);

int main() {
    approximate_sqrt(25);
    approximate_sqrt(35);
    approximate_sqrt(73);

    return 0;
}

double approximate_sqrt(int number) {
    int max_iterations = 100;
    int i = max_iterations;
    double guess = 1.0;
    bool correct = false;

    do {
        if (guess * guess == number) correct = true;
        else guess = ((guess + (number / 10)) / 2);
        i--;
    } while (i > 0 && !correct);

    if (correct) printf("We believe the square root of %d is %lf.\n", number, guess);
    else printf("We tried %d times but idk, the square root of %d might be %lf, lmk if i was close\n", max_iterations, number, guess);
}