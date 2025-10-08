#include <stdio.h>

void setToZeroNonWorking(int n);
void setToZero(int *n_ptr);

int main(void) {
    int a = 10;

    printf("Before function: Variable [a=%d]\n", a);
    setToZeroNonWorking(a);
    printf("After function:  Variable [a=%d]\n", a);
    puts("");

    printf("Before new function: Variable [a=%d]\n", a);
    setToZero(&a);  // Get a's reference (memory address)
    printf("After new function:  Variable [a=%d]\n", a);
    puts("");

    return 0;
}

void setToZeroNonWorking(int n) {
    n = 0;
    printf("Inside function: Variable [n=%d]\n", n);
}

void setToZero(int *n_ptr) {
    // Accesses the actual variable that was passed in,
    // since we passed in a pointer to that variable
    *n_ptr = 0;
    printf("Inside new function: Variable [n_ptr=%p] (referencing)\n", n_ptr);
    printf("Inside new function: Variable [n_ptr=%d] (dereferencing)\n", *n_ptr);
}