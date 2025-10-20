// String functions
#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 1024

// TODO
// copy source into destination
// make sure dest size is not greater than 1024
void my_strcpy(char *dest, char *src);

int my_strlen(const char* str);
char* get_string(const char* prompt);

int my_strlen(const char* str) {
    int i = 0;

    // str[i] != '\0', also adds a string size cap
    while (str[i] && i < STR_SIZE) {
        i++;
    }
    return i;
}

char* get_string(const char* prompt) {
    printf("%s", prompt);
    char *str = (char*)malloc(sizeof(char) * STR_SIZE);

    // Scan the string character by character
    char input;
    int i = 0;
    while (i < STR_SIZE - 1 && (input = getchar() != '\n')) {
        str[i] = input;
        i++;
    }

    // Add null character at the end
    str[i] = '\0';

    return str;
}