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
    // WRONG WAY
    // This doesn't work becasue feof doesn't become false until it tries to read the file in the while loop and fails,
    // so it doesn't get updated until after the loop runs for an additional extra time
    /*
    int i;
    while(!feof(my_file)) {
        fscanf(my_file, "%d", &i);
        printf("%4d", i);
        if (i % 10 == 0) printf("\n");
    }
    */
    // RIGHT WAY
    int i;
    while (fscanf(my_file, "%d", &i) == 1) {
        printf("%4d", i);
        if (i % 10 == 0)
            printf("\n");
    }

    // Closing the file
    fclose(my_file);


    
    return 0;
}