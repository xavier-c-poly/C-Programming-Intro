/*
    Introduction to variables in C.
*/

#include <stdio.h>

int main(void) {
    // Create a variables
    int first_number;
    // Assign a value to a variable
    first_number = 5;

    // Create and initialize
    int second_number = 78;

    // Print the value of a variable
    printf("The first number is %d\n", first_number);  // %d - conversion specifier
    printf("The second number is %d\n", second_number);

    // Calculate the sum
    int sum = first_number + second_number;
    printf("%d + %d = %d\n", first_number, second_number, sum);
    
    return 0;
}