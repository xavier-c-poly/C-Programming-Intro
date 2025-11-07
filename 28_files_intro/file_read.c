#include <stdio.h>  // FILE structure

int main(void) {
    // A pointer to a FILE structure
    FILE *my_file = fopen("text.txt", "r");  // Open the file for reading

    // Check whether the file was opened
    if (my_file == NULL) {
        puts("The file cannot be opened!");
        return 1;
    }

    // Read from a file
    int i;
    while(!feof(my_file)) {
        fscanf(my_file, "%d", &i);
        printf("%4d", i);
    }

    // Closing the file
    fclose(my_file);


    
    return 0;
}