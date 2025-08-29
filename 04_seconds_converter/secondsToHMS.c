/*
    Program converts the given number of seconds to HMS

    65 seconds -> 0 hours, 1 minute, 5 seconds
    3690 seconds -> 1 hour, 1 minute, 30 seconds
*/

#include <stdio.h>

int main(void) {
    int raw_seconds = 0;

    // Getting seconds
    puts("Enter the number of seconds: ");
    scanf("%d", &raw_seconds);

    if (raw_seconds < 0) {
        puts("Invalid input. Please enter a number greater than 0.");
        return 0;
    }

    // Calculate the number of minutes
    int seconds = raw_seconds % 60;
    int raw_minutes = raw_seconds / 60;
    int minutes = raw_minutes % 60;
    int hours = raw_minutes / 60;

    /* Selection statement
        <
        >
        <=
        >=
        ==
    */

    printf("Time: %d seconds is %02d hours and %02d minutes and %02d seconds\n", raw_seconds, hours, minutes, seconds);

    // printf("%d seconds is %d minutes and %d seconds\n", raw_seconds, raw_minutes, seconds);
    // printf("Time: %d seconds is %02d:%02d:%02d\n", seconds, hours, remaining_minutes, remaining_seconds);
    // printf("Time: %d seconds is %02d hours and %02d minutes and %02d seconds\n", raw_seconds, hours, minutes, seconds);

    return 0;
}