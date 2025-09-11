/*
    ! - logical NOT
*/

#include <stdio.h>
#include <stdbool.h>

/*
    Returns true if first is divisible by second AND by (second - 3)
*/

bool is_divisible_both(int first, int second);
bool is_divisible_either(int first, int second); // is divisible by second OR second minus three
bool is_divisible_neither(int first, int second); // is NOT divisible by second and is NOT second minus three
bool is_correct_input(int first, int second);

int main(void) {
    puts("Enter x and y");
    int x = 0;
    printf("x: ");
    scanf("%d", &x);
    int y = 0;
    printf("y: ");
    scanf("%d", &y);
    printf("\n");

    if (!is_correct_input(x, y)) {
        puts("Incorrect input!\n");
    }

    int numbers[] = {12, 6, 12, 5, 15, 5, x, y};

    for (int i = 0; i < sizeof(numbers) / sizeof(int); i += 2) {
        if (is_divisible_both(numbers[i], numbers[i+1])) {
            printf("is_divisible_both(%d, %d) == true\n", numbers[i], numbers[i+1]);
        } else {
            printf("is_divisible_both(%d, %d) == false\n", numbers[i], numbers[i+1]);
        }

        if (is_divisible_either(numbers[i], numbers[i+1])) {
            printf("is_divisible_either(%d, %d) == true\n", numbers[i], numbers[i+1]);
        } else {
            printf("is_divisible_either(%d, %d) == false\n", numbers[i], numbers[i+1]);
        }

        if (is_divisible_neither(numbers[i], numbers[i+1])) {
            printf("is_divisible_neither(%d, %d) == true\n", numbers[i], numbers[i+1]);
        } else {
            printf("is_divisible_neither(%d, %d) == false\n", numbers[i], numbers[i+1]);
        }

        printf("\n");
    }

    /*
    printf("%d\n", is_divisible_both(12, 6));
    printf("%d\n", is_divisible_both(12, 4));
    printf("%d\n", is_divisible_both(15, 5));
    printf("%d\n", is_divisible_both(x, y));
    */

    return 0;
}

bool is_divisible_both(int first, int second) {
    return (is_correct_input(first, second)) && (first % second == 0 && first % (second - 3) == 0);
}

// is divisible by second OR second minus three
bool is_divisible_either(int first, int second) {
    return (is_correct_input(first, second)) && (first % second == 0 || first % (second - 3) == 0);
}

// is NOT divisible by second and is NOT second minus three
bool is_divisible_neither(int first, int second) {
    return (is_correct_input(first, second)) && (first % second != 0 && first % (second - 3) != 0);
}

bool is_correct_input(int first, int second) {
    return second != 0 && second != 3;
    // return !(second == 0 || second == 3);
}