#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

// Character functions
bool isUpper(char c);
bool isLower(char c);

// TODO
bool isAlpha(char c); // True if the character is a letter (upper or lower)
bool isDigitr(char c);  // True if c is a digit [0; 9]
bool isAlNum(char c);  // True if the character is a letter or a digit

int main(void) {
	// Create a character
	char ch = 'V';
	
	// Create a Boolean variable
	const bool isStudentHappyInCOP2271AfterWeek10 = true;  // false
	
	
	//////////////////////////////////////////////////////////////
	// Create a string
    // '\0' - null character at the end of the string to indicate the end of a string
	char str[SIZE] = "Hello";  // more flexible since we have SIZE in there
	char str2[] = "Hello";  // {'H', 'e', 'l', 'l', 'o', '\0'}
	char str3[SIZE];  // more flexible as we have SIZE "indexes" of characters to add whenever we want to later
    // this will only have a character of size 6 (because '\0' takes up one slot at the end),
    // so we won't be able to add more than 5 letters to this variable if we want to change it in the future.

    // Scan the string
    // dont need & symbol because str is already a pointer to an array of chars
    printf("Enter your string here: ");
    // scanf("%s", str);  // SCANS UNTIL FIRST WHITESPACE!!!
    // We commented out the above scanf because it keeps leaving a newline in the iostream, leading it to be caught by fgets and immediately
    // enters nothing for the str value

    // Get the string with fgets function
    fgets(str, SIZE - 1, stdin);

    // Print the string
    puts("Printing with printf");
    printf("%s\n\n", str);

    puts("Printing with a loop");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n\n");

    

    // Print only lowercase characters from the string
    printf("Lowercase letters only:\n");
    for (int i = 0; str[i] != '\0'; i++) {
        if (isLower(str[i]))
            printf("%c", str[i]);
    }
    puts("\n\n");

    // Print only uppercase characters from the string
    printf("Uppercase letters only:\n");
    for (int i = 0; str[i] != '\0'; i++) {
        if (isUpper(str[i]))
            printf("%c", str[i]);
    }
    puts("\n\n");

    // Print only uppercase characters from the string
    printf("Numbers only:\n");
    for (int i = 0; str[i] != '\0'; i++) {
        if (isNumber(str[i]))
            printf("%c", str[i]);
    }
    puts("\n\n");
	
	
	
	return 0;
}

bool isUpper(char c) {
    // Compares the char's ascii value to the actual ascii values of the uppercase range
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

bool isLower(char c) {
    // Compares the char's ascii value to the actual ascii values of the lowercase range
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

bool isAlpha(char c); // True if the character is a letter (upper or lower)
bool isNumber(char c);  // True if c is a digit [0; 9]
bool isNumber(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
bool isAlNum(char c);  // True if the character is a letter or a digit