/*
    The program calculates the rootes of quadratic equation.

    ax^2 + bx + c = 0

    Steps:
        1. Print the prompt
        2. Get coefficient
        3. Calculate the discriminant
        4. Print rootes
*/

// NOTE: to compile this program, you must use the -lm flag ([library] [math library])
// So: gcc rootes.c -lm -o rootes.exe

#include <stdio.h>
#include <math.h>  // sqrt - function

// Function prototypes
void printPrompt(char coeff);
int getCoefficient(void);
int calculateDiscriminant(int a, int b, int c);
void printRootes(int a, int b, int c);

int main(void) {
    printPrompt('a');
    int a = getCoefficient();
    printPrompt('b');
    int b = getCoefficient();
    printPrompt('c');
    int c = getCoefficient();
    calculateDiscriminant(a, b, c);
    printRootes(a, b, c);

    return 0;
}

void printPrompt(char coeff) {
    printf("Enter the coefficient %c: ", coeff);
}

int getCoefficient(void) {
    int coeff;
    scanf("%d", &coeff);

    return coeff;
}

int calculateDiscriminant(int a, int b, int c) {
    return (b * b) - (4 * a * c);
}

void printRootes(int a, int b, int c) {
    int discrim = calculateDiscriminant(a, b, c);
    if (discrim < 0) {
        puts("No real rootes");
    }
    else if (discrim == 0) {
        double x = -b / (2 * a);
        printf("x = %f\n", x);
    }
    else if (discrim > 0) {
        double x1 = (-b + sqrt(discrim)) / (2 * a);  // sqrt - square root
        double x2 = (-b - sqrt(discrim)) / (2 * a);
        printf("x1 = %lf; x2 = %lf\n", x1, x2);
    }
}