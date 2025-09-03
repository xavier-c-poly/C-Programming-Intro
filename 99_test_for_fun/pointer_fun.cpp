#include <iostream>
#include <string>

using namespace std;

void func1(int num) {
    num = 17;
}

void func2(int* num) {
    *num = 17;
}

int main() {
    int myNumber = 3;
    cout << "My number is " << myNumber << endl;
    func1(myNumber);
    cout << "My number is now " << myNumber << endl;
    func2(&myNumber);
    cout << "My number is finally " << myNumber << endl;

    cout << endl;

    int myNewNumber = 8;
    int* myNewNumberPtr = &myNewNumber;
    cout << "My new number is " << myNewNumber << " with pointer " << myNewNumberPtr << endl;
    func1(myNewNumber);
    cout << "My new number is now " << myNewNumber << " with pointer " << myNewNumberPtr << endl;
    func2(myNewNumberPtr);
    cout << "My new number is finally " << myNewNumber << " with pointer " << myNewNumberPtr << endl;
}