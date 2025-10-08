#include <stdio.h>

/*
    Split the given 2 digit number into tens and ones
    Return 0 if the number is 2 digit number and 1 otherwise
*/
int splitDigits(int n, int *tens_ptr, int *ones_ptr);
void sumAndAvg(double d1, double d2, double *sum, double *avg);

int main(void) {
    int a = 0, tens = 0, ones = 0;
    do {
        printf("Enter a two digit number [use -1 to exit]: ");
        scanf("%d", &a);
        if (splitDigits(a, &tens, &ones) == 0) {
            printf("Tens is %d, ones is %d\n", tens, ones);
        }
        puts("");
    } while (a != -1);

    double d1 = 0, d2 = 0, sum = 0, avg = 0;
    do {
        printf("Enter number 1 (3 decimal places supported) [use -1 to exit]: ");
        scanf("%lf", &d1);
        if (d1 != -1) {
            printf("Enter number 2 (3 decimal places supported) [use -1 to exit]: ");
            scanf("%lf", &d2);
        }
        if (d1 != -1 && d2 != -1) {
            sumAndAvg(d1, d2, &sum, &avg);
            printf("%.3lf + %.3lf = %.3lf, avg is %.3lf\n", d1, d2, sum, avg);
        }
        puts("");
    } while (d1 != -1 && d2 != -1);

    return 0;
}

int splitDigits(int n, int *tens_ptr, int *ones_ptr) {
    if (n == -1) return 1;

    if (n < 10 || n > 99) {
        puts("Not a 2 digit numbers");
        return 1;
    }

    *tens_ptr = n / 10;
    *ones_ptr = n % 10;

    return 0;  // Success is assured 619
}

void sumAndAvg(double d1, double d2, double *sum, double *avg) {
    *sum = d1 + d2;
    *avg = (d1 + d2) / 2.0;
}