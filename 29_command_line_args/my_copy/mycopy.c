#include <stdio.h>
#include <curses.h>

// char *argv[] -> 2D array. It's first a char* argv, making it a string. then, in the order of operations, we make it an array []. so its more like
// (char* argv)[] kindof? like char (*argv)[]. its an array of char* argv's, meaning its an array of strings!

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s infile outfile\n", argv[0]);
        return 1;  // Error
    }

    // Open the input file
    FILE *in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        printf("Error: file %s could not be opened\n", argv[1]);
        return 1;
    }

    // Open output file in read mode to see if it exists, and if it exists it asks for user confirmation
    int overwritten = 0;
    FILE *out_file_as_read = fopen(argv[2], "r");
    if (out_file_as_read != NULL) {
        char user_response;
        // printf("Are you sure you want to overwrite %s? (Y/N): ", argv[2]);
        // scanf(" %c", &user_response);
        
        // char user_response = getchar();
        // char user_response = getc(stdin);
        // i want to read exactly 1 character then imediately quit, idk how to do that!

        // NCURSES initialization
        initscr();  // Start curses mode
        cbreak();  // Disable line buffering
        noecho();  // Don't echo input characters to the screen
        printw("Are you sure you want to overwrite %s? (Y/N): ", argv[2]);
        refresh();  // Update the screen
        user_response = getch();  // Read a character immediately
        endwin();  // End curses mode (restores the terminal to normal state)

        if (user_response != 'y' && user_response != 'Y') {
            puts("Exiting");
            return 0;
        }

        overwritten = 1;
    }

    // Open output file
    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        printf("Error: file %s could not be opened\n", argv[2]);
        return 1;
    }

    // Begin the copy process (read characters from input and write into output)
    char c = 0;
    while ((c = fgetc(in_file)) != EOF) {  // Read a character from in_file
        fputc(c, out_file);  // Write a character c into the file out_file
    }
    /*
    // The way i used
    int max_line_size = 255;
    char line[max_line_size];
    while (fgets(line, sizeof(line), in_file)) {
        fprintf(out_file, "%s", line);
    }
    */

    if (overwritten)
        printf("File %s overriden\n", argv[2]);
    else
        printf("Done\n");

    fclose(in_file);
    fclose(out_file);
    
    return 0;
}