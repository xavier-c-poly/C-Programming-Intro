#include <stdio.h>

int addOne(int n);
int addOneStatic(int n);

int main(void) {
	int i = 0;
	while (i < 10) {
		printf("AddOne returns %d\n", addOne(i));
		i++;
	}
	
	puts("--------------------------");
	i = 0;
	
	while (i < 10) {
		printf("AddOneStatic returns %d\n", addOneStatic(i));
		i++;
	}
	
	return 0;
}

int addOne(int n) {
	int result = 1;
	result += n;
	return result;
}

int addOneStatic(int n) {
	// Static remembers the last value that was inside the variable
	// Static variable is stored through the entire duration of the program, however its scope is still only inside the function
	// This behavior is very useful especially for arrays declared in functions, as they are memory intensive to initialize and delete
	// every single time you run that function.
	static int result = 1;
	result += n;
	return result;
}