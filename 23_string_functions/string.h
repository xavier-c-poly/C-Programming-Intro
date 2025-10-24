// String functions
#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 1024

void my_strcpy(char *dest, char *src);
int my_strlen(const char* str);
char* get_string(const char* prompt);
void my_strcat(char *dest, char *src);
int my_strcmp(char *dest, char *src);

int my_strlen(const char* str) {
    int i = 0;

    // str[i] != '\0', also adds a string size cap
    while (str[i] && i < STR_SIZE) {
        i++;
    }
    return i;
}

// Gets string, size of STR_SIZE even if the input itself isn't that big
char* get_string(const char* prompt) {
    printf("%s", prompt);
    char *str = (char*)malloc(sizeof(char) * STR_SIZE);

    // Scan the string character by character
    char input;
    int i = 0;
    while (i < STR_SIZE - 1 && (input = getchar()) != '\n') {
        str[i] = input;
        i++;
    }

    // Add null character at the end
    str[i] = '\0';

    return str;
}


void my_strcpy(char *dest, char *src) {
    // if (my_strlen(src) > my_strlen(dest)) {
        // 
    // }

    int i;
    for (i = 0; i < STR_SIZE - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void my_strcat(char *dest, char *src) {
    int i;
    int len_dest = my_strlen(dest);
    for (i = 0; len_dest < STR_SIZE && src[i] != '\0'; i++) {
        dest[len_dest] = src[i];
        len_dest++;
    }
    dest[len_dest] = '\0';
}

// TODO return negative one, one, or zero
int my_strcmp(char *dest, char *src);