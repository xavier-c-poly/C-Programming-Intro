#include <stdio.h>

// Function prototypes
/*
    Get the grade
*/
double getGrade(int student_number);

/*
    Return the sum of grades on n students
*/
double sumStudentGrades(int n_students);
double sumStudentGradesSentinel(void);
double sumStudentGradesSentinelMyWay(void);

int main(void) {
    /*
    int student_number;
    printf("Enter the student number whose grade you wish to change: ");
    scanf("%d", &student_number);
    double grade = getGrade(student_number);
    printf("The grade for %d is %.2lf%%.\n", student_number, grade);
    */

    /*
    int n_students = 3;
    double total = sumStudentGrades(n_students);
    printf("The total of all %d students is %.2lf%%.\n", n_students, total);
    */

    double total = sumStudentGradesSentinel();
    printf("The total is %.2lf%%.\n", total);

    return 0;
}

double getGrade(int student_number) {
    double grade;
    printf("Please enter the grade for student %d: ", student_number);
    scanf("%lf", &grade);

    return grade;
}

double sumStudentGrades(int n_students) {
    int current_student = 1;
    double total = 0;

    while (current_student <= n_students) {
        double grade = getGrade(current_student);
        total += grade;  // Adding scanned grade to the total
        current_student++;
    }

    return total;
}

double sumStudentGradesSentinel(void) {
    double total = 0;
    double grade = 0;
    int current_student = 1;

    printf("Enter \"-1\" to exit the loop\n");

    // Sentinel loop
    while (grade != -1) {
        grade = getGrade(current_student);
        if (grade != -1) {
            total += grade;
            current_student++;
        }
    }

    return total;
}

double sumStudentGradesSentinelMyWay(void) {
    int n_students;
    printf("How many students do you want to scan for?: ");
    scanf("%d", &n_students);
    sumStudentGrades(n_students);
}