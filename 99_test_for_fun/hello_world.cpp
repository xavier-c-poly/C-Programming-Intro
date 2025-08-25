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

int main() {
	// Greeting message
	cout << "Hello, World!" << endl;
	cout << "How old are you?: ";

	// Get input
	string input;
	cin >> input;
	int age = -67;

	if (isNumber(input)) {
		age = stoi(input);

		// Only prints age message if the user entered a number
		if (age < 18)
			cout << "You are the youngest person ever" << endl;
		else
			cout << "You are old" << endl;

	} else {
		// Prints an error message if user did not enter a number
		cout << "Please enter a number next time!" << endl;
	}
	
	// Prints what the user really entered as input
	cout << "You entered: '" << input << "'." << endl;

	return 0;
}
