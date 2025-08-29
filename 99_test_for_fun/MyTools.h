#pragma once
#include <iostream>
#include <string>

using namespace std;

bool isNumber(string input) {
	// Loop through each string's characters to determine if the string is a number
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			return false;
		}
	}
	return true;
}

void printSquare(int length) {
    if (length < 3) {
        puts("Invalid input! Length must be at least 3.");
        return;
    }

    cout << "Printing square of length " << length << endl;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (i == 0 || i == length - 1) {
                printf("*");
            } else if (j == 0 || j == length - 1) {
                printf("*");
            }
        }
    }
}