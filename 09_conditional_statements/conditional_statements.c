/*
    Conditional statements (in order of precedence)

    !  - logical NOT
    && - logical AND
    || - logical OR
*/

#include <stdio.h>

int main(void) {
    int x = 0;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 0 && x < 100 || x % 2 == 0)
        printf("%d is in between 0 and 100, and is even.\n", x);
    else
        printf("Sorry you're not getting in the secret numbers club buddy\n");

    return 0;
}