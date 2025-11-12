#include <stdio.h>

void myFunc1(void);
void myFunc2(void);
void myFunc3(void);

// char *argv[] -> 2D array. It's first a char* argv, making it a string. then, in the order of operations, we make it an array []. so its more like
// (char* argv)[] kindof? like char (*argv)[]. its an array of char* argv's, meaning its an array of strings!

int main(int argc, char *argv[]) {
    printf("Total arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: '%s'\n", i + 1, argv[i]);
    }

    // look for flags
    for (int i = 0; i < argc; i++) {
        if (argv[i] == "-o")
    }
    
    return 0;
    
}

void myFunc1(void) {
    printf("Func 1 was called! This means that the -o flag was detected!\n");
}
void myFunc2(void) {
    printf("Func 2 was called! This means that the -r flag was detected!\n");
}
void myFunc3(void) {
    printf("Func 3 was called! This means that the -f flag was detected!\n");
}