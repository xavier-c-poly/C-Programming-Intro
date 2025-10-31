#include <stdio.h>
#include <string.h>

#define NAME_SIZE 30

// Create a new type (structures)
struct student {
    // Data members
    char first_name[NAME_SIZE];
    int age;
};

// Function prototype
void printStudentInfo(struct student st);
void printStudentInfoPointer(struct student *st);

int main(void) {
    int a;  // Creates an object of type int called a
    struct student stud;  // Creates an object of type struct student named stud

    // Access and initialize the data members of a structure
    strcpy(stud.first_name, "John");
    stud.age = 21;

    // Print info with a function
    printStudentInfo(stud);

    // Create a pointer to int
    int b = 1;
    int *b_ptr = &b;
    *b_ptr = 2;  // Access b through b_ptr

    // Create a pointer to a structure
    struct student *my_student_ptr = &stud;

    // Create another student
    struct student freshman = {.first_name = "Alice", .age = 20};
    struct student sophomore = {"Dante", 67};
    struct student *freshman_ptr = &freshman;
    printf("First name:\t'%s'\n", freshman_ptr->first_name);
    printf("Age:\t\t'%d'\n", freshman_ptr->age);



    // (*my_student_ptr).age = 41;
    // my_student_ptr->age = 41;
    // (**my_student_ptr).age = 41;
    // (*my_student_ptr)->age = 41;
    // (*my_student_ptr)->age = 41;
    // my_student_ptr-->age = 41;

    return 0;
}

void printStudentInfo(struct student st) {
    puts("-------------------------------");
    printf("First name:\t'%s'\n", st.first_name);
    printf("Age:\t\t'%d'\n", st.age);
    puts("-------------------------------");
}

void printStudentInfoPointer(struct student *st) {
    puts("-------------------------------");
    printf("First name:\t%s\n", (*st).first_name);  // st->first_name
    printf("Age:\t\t%d\n", (*st).age);              // st->age
    puts("-------------------------------");
}