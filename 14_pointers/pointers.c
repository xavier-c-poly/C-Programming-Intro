#include <stdio.h>

int main(void) {
	int luck = 10;
	
	// Access
	printf("Luck is %d\n", luck); // Direct access
	
	// Modify
	luck += 5;
	
    // Print the address of a variable luck
    // & - reference operator
    printf("The address of luck is %p\n", &luck);  // %p - prints pointers, prints the address

    // Create pointer variable (variable that stores an address)
    // <data type>* pointer_name;
    // <data type> *pointer_name;
    // <data type> *pointer_name;
    int* luck_ptr;  // uninitialized pointer (DON'T DO THAT) or else you might modify random important/nonimportant data on your pc!!

    // 1 NULL pointer
    luck_ptr = NULL;
    printf("Null pointer reference: %p\n", luck_ptr);

    // 2 assign with an address
    luck_ptr = &luck;  // When you access data from a variable like this, it's called indirect access
    printf("Luck address from the luck pointer variable: %p\n", luck_ptr);

    // Access the data through the pointer
    // * - dereferencing operator!
    printf("Dereference luck_ptr: %d\n", *luck_ptr);  // Indirect access

    // Create a double variable named score
    // Create a pointer pointing to it
    double score = 13.5;
    double* score_ptr = &score;

    // Modify the score through the pointer
    *score_ptr = 20.9;
    printf("Score: %lf\n", score);

    // int* yPtr = &y; ----------> * is for creating pointers
    // printf("%d\n", *yPtr); ---> * is for dereferencing pointer
    // y *= 12; -----------------> * is for multiplying


    double number1 = 2.25;  // Create double number 1 variable
    double *pF;  // Initialize variable pF pointer
    pF = &number1;  // Create variable pF pointer that points to number1
    printf("%lf\n", *pF);  // Print the value stored at number 1
    double number2 = *pF;  // Create variable number2 that's the same as number1
    *pF *= 2;  // Double the value stored at the memory location pointed to by pF
    printf("%p\n", &number1);  // Print the address of number1
    printf("%p\n", pF);  // Print the address in pF
	
	return 0;
}