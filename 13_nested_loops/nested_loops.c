#include <stdio.h>
#include <unistd.h>

void printTriangleTopLeft(int n);
void printTriangleBottomLeft(int n);

int main(void) {
    int n = 0;

    // Scan a positivev integer
    do {
        printf("Enter a positive integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    // Call a function
    int i = 1;
    while (i < 100) {
        printTriangleTopLeft(n);
        printTriangleBottomLeft(n);
        i++;
    }

    return 0;
}

/*
practice
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5
*/

/*

5
*****
****
***
**
*

*/

void printTriangleTopLeft(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("%c", '*');
        }
        puts(""); // prints new line
        usleep(6000);
    }
}

void printTriangleBottomLeft(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", '*');
        }
        puts("");
        usleep(6000);
    }
}