

// Character functions
char toLower(char c);
char toUpper(char c);
char toInverse(char c);
bool isUpper(char c);
bool isLower(char c);
bool isAlpha(char c); // True if the character is a letter (upper or lower)
bool isNumber(char c);  // True if c is a digit [0; 9]
bool isAlNum(char c);  // True if the character is a letter or a digit




char toLower(char c) {
    if (isUpper(c))
        return c + 'a' - 'A';  // Returns the lowercase ascii code
    return c;
}

char toUpper(char c) {
    if (isLower(c))
        return c + 'A' - 'a';  // Returns the uppercase ascii code
    return c;
}

char toInverse(char c) {
    if (isLower(c))
        return toUpper(c);
    else if (isUpper(c))
        return toLower(c);
    return c;
}

bool isLower(char c) {
    // Compares the char's ascii value to the actual ascii values of the lowercase range
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

bool isUpper(char c) {
    // Compares the char's ascii value to the actual ascii values of the uppercase range
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

bool isAlpha(char c) {
    return isUpper(c) || isLower(c);
}

bool isNumber(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool isAlNum(char c) {
    return isAlpha(c) || isNumber(c);
}