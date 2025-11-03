#include <stdio.h>
#include <string.h>

#define NAME_SIZE 30
#define STREET_NAME 30
#define CITY_NAME 30

// TODO
// Add last name
// Add state for address state[3] (like just normal state like Flordia)

// Address structure
typedef struct {
    char street[STREET_NAME];
    char city[CITY_NAME];
    int zip;
} Address;

// Create a new type (structures)
struct student {
    // Data members
    char first_name[NAME_SIZE];
    int age;
    Address home_address;
};

// Create an alias (alternative name)
typedef struct student Student;

// Function prototypes
void printStudentInfo(struct student st);
void printStudent(struct student *st);
Student createStudent(void);
void printAddress(Address *adr);
Address createAddress(void);

int main(void) {
    Student st1 = createStudent();
    puts("");
    printStudent(&st1);

    puts("\n\n");

    Address adr = {.street = "123_Main", .city = "Lakeland", .zip = 33804};
    printAddress(&adr);

    puts("\n\n");

    Address adr2 = createAddress();
    puts("");
    printAddress(&adr2);
    
    return 0;
}




/*
int old_main(void) {
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
*/




void printStudentInfo(struct student st) {
    puts("-------------------------------");
    printf("First name:\t'%s'\n", st.first_name);
    printf("Age:\t\t'%d'\n", st.age);
    puts("-------------------------------");
}

void printStudent(struct student *st) {
    puts("-------------------------------");
    printf("First name:\t%s\n", (*st).first_name);  // st->first_name
    printf("Age:\t\t%d\n", (*st).age);              // st->age
    printf("Address:\n");
    printAddress(&st->home_address);  // reference & operator is last in precedence. first it dereferences st, then it gets the home address, then it POINTS to that with the & operator, since the funtion itself only accepts a pointer
    puts("-------------------------------");
}

Student createStudent(void) {
    Student st;
    printf("Enter student's name: ");
    scanf("%s", st.first_name);  // Don't need address opoerator since string is already a pointer
    printf("Enter student's age: ");
    scanf("%d", &st.age);
    st.home_address = createAddress();
    return st;
}

void printAddress(Address *adr) {
    puts("-------------------------------");
    printf("Street:\t\t%s\n", adr->street);
    printf("City:\t\t%s\n", adr->city);
    printf("Zip code:\t%d\n", adr->zip);
    puts("-------------------------------");
}

Address createAddress(void) {
    Address adr;

    printf("Enter street address: ");
    scanf("%s", adr.street);  // won't work because its defined as *street not street[NAME_SIZE]
    printf("Enter city of address: ");
    scanf("%s", adr.city);
    printf("Enter address zip code: ");
    scanf("%d", &adr.zip);

    return adr;
}