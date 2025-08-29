/*
    Getting an input from the keyboard
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    int square_side = 1;
    
    // Get the input
    // Print the prompt
    puts("Enter the side of a square:");  // Text only, puts a newline automatically afterwards

    // Get the input
    // & = address operator
    scanf("%d", &square_side);  // scanf("%[format specifier]", &[variable with reference operator])

    // printf("You want %d sides? Okay we will do that\n", square_side);

    // Do the math
    int square_perimeter = square_side * 4;
    int square_area = square_side * square_side;

    printf("The perimeter of a square with a side %d is %d\n", square_side, square_perimeter);
    // printf("The area of a square with a side %d is %d\n", square_side, square_area);

    return 0;
}