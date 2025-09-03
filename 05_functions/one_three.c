/*
    Practice with void functions.
*/

#include <stdio.h>

// Function prototypes - small description of a function
void two(void);
void one_three(void);

int main(void) {
    printf("starting now:\n");
    one_three();
    printf("done:\n");

    return 0;
}

// Function implementations
void two(void) {
    printf("two\n");
}

void one_three(void) {
    printf("one\n");
    two();
    printf("three\n");
}