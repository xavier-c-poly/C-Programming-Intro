#include <stdio.h>  // FILE structure

int main(void) {
    // A pointer to a FILE structure
    FILE *my_file = fopen("text.txt", "w");  // Open the file for writing

    // Check whether the file was opened
    if (my_file == NULL) {
        puts("The file cannot be opened!");
        return 1;
    }

    for (int i = 1; i <= 100; i++) {
        fprintf(my_file, "%4d ", i);  // Writing into a file
        if (i % 10 == 0)
            fprintf(my_file, "%c", '\n');
    }

    // Closing the file
    fclose(my_file);


    
    return 0;
}