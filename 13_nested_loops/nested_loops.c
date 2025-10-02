#include <stdio.h>
#include <unistd.h>

void printTriangleTopLeft(int n);
void printTriangleBottomLeft(int n);
void printTriangleTopLeftNumbers(int n);
void printTriangleTopLeftNumbers2(int n);
void printTriangleTopLeftNumbers3(int n);
void printTriangleTopRight(int n);
void printTriangleBottomRight(int n);
void printPyramid(int n);
void printPyramidWithDigits(int n);


int main(void) {
    int n = 0;

    // Scan a positivev integer
    do {
        printf("Enter a positive integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    int temp;
    printTriangleTopLeftNumbers(n);
    puts("");
    printTriangleTopRight(n);
    puts("");
    printTriangleBottomRight(n);
    puts("");
    printf("Test:\n");
    printPyramid(n);
    puts("");
    printPyramidWithDigits(n);
    puts("");
    scanf("%d", &temp);

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

void printTriangleTopLeftNumbers(int n) {
    int num = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("%d", num);
            if (j + 1 < i) printf(" ");
            num++;
        }
        puts("");
        num -= i - 1;
    }
}


void printTriangleTopLeftNumbers2(int n) {
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j <=n; j++) {
		    printf("%d", j);
	    }
	    puts("");
    }
}


void printTriangleTopLeftNumbers3(int n) {
    for (int i = 0; i < n; i++) {
	    for (int j = n - i; j > 0; j++) {
		    printf("%d", j);
	    }
	    puts("");
    }
}

void printTriangleTopRight(int n) {
    for (int i = 0; i < n; i++) {
        // Print spaces
        for (int j = 0; j < i; j++) {
            printf("%c", ' ');
        }
        // Print stars
        for (int j = 0; j < n - i; j++) {
            printf("%c", '*');
        }
        puts("");
    }
}

void printTriangleBottomRight(int n) {
    for (int i = 0; i < n; i++) {
        // Print spaces
        for (int j = i; j < n - 1; j++) {
            printf("%c", ' ');
        }
        // Print stars
        for (int j = 0; j <= i; j++) {
            printf("%c", '*');
        }
    }
}

void printPyramid(int n) {
    for (int i = 0; i < n; i++) {
        // Print spaces
        for (int j = i; j < n - 1; j++) {
            printf("%c", ' ');
        }
        // Print stars (first half and a middle)
        for (int j = 0; j <= i; j++) {
            printf("%c", '*');
        }
        // Print the second half of the pyramid
        for (int j = 1; j <= i; j++) {
            printf("%c", '*');
        }
        puts("");
    }
}

/*
    1
   212
  32123
 4321234
543212345
*/
void printPyramidWithDigits(int n) {
    for (int i = 0; i < n; i++) {
        // Print spaces
        for (int j = i; j < n - 1; j++) {
            printf("%c", ' ');
        }
        // Print stars (first half and a middle)
	    for (int j = i + 1; j > 0; j--) {
            printf("%d", j);
        }
        // Print the second half of the pyramid
        for (int j = 2; j <= i + 1; j++) {
            printf("%d", j);
        }
        puts("");
    }
}
