#include <stdio.h>
#include <string.h>

void flagOutput(char *argv);
void flagRecursive(char *argv);
void flagForce(void);

// char *argv[] -> 2D array. It's first a char* argv, making it a string. then, in the order of operations, we make it an array []. so its more like
// (char* argv)[] kindof? like char (*argv)[]. its an array of char* argv's, meaning its an array of strings!

int main(int argc, char *argv[]) {
    printf("Total arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: '%s'\n", i + 1, argv[i]);
    }

    // look for flags
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && strlen(argv[i]) > 1) {
            for (int c = 1; c < strlen(argv[i]); c++) {
                // if a -.... word (flag) in the string contains an o in it, AND there's an argument after (meaning that it will be passed)
                if (argv[i][c] == 'o' && i + 1 < argc) {
                    // Also make sure that the argument itself that the flag is taking isn't a flag, but
                    // we check it in this nested if statement to make sure that another argument exists (so we don't search out of bounds)
                    if (argv[i + 1][0] != '-')
                        flagOutput(argv[i + 1]);
                }
                else if (argv[i][c] == 'r' && i + 1 < argc) {
                    if (argv[i + 1][0] != '-')
                        flagRecursive(argv[i + 1]);
                }
                // checks if the flag contains f, and if it does, it doesn't matter since it doesn't take any arguments, and just runs the function
                else if (argv[i][c] == 'f') {
                    flagForce();
                }
            }
        }
    }
    
    return 0;
    
}

void flagOutput(char *argv) {
    printf("-o flag was detected! You passed in '%s'!\n", argv);
}
void flagRecursive(char *argv) {
    printf("-r flag was detected! You passed in '%s'!\n", argv);
}
void flagForce(void) {
    printf("-f flag was detected! You passed in nothing because force doesn't take anything, it's just a true/false flag!\n");
}