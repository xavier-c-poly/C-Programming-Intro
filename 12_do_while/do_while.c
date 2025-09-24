#include <stdio.h>

int main(void) {
    // Scan an uppercase character
    char input;
    do {
        printf("Enter an uppercase character: ");
        scanf(" %c", &input);
    } while (input < 'A' || input > 'Z');
    printf("You entered the letter '%c'\n", input);

    // Scan a positive integer
    int number;
    do {
        printf("Enter a positive number: ");
        scanf("%d", &number);
    } while (number <= 0);
    printf("You entered the number '%d'\n", number);

    int choice;
    do {
        printf("Choose either 1 or 2: ");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);
    printf("Your choice is %d!\n", choice);

    char inner_choice;
    do {
        printf("Type an in-between character: ");
        scanf("%c", &inner_choice);
    } while (inner_choice < 'A' || inner_choice > 'z');
    printf("Your in-between character is is %d!\n", inner_choice);


    int iterations = 5;
    for (int i = 0; i < 5; i++) {
        if (choice == 1) {
        printf("A");
        printf("%c", inner_choice);
        } else if (choice == 2) {
            printf("A%c\n", inner_choice);
        }
    }
    printf("\n");

    return 0;
}