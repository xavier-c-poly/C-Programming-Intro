/*
    Xavier Cosme 9/5/2025
    Practice with a non-void functions.
*/

#include <stdio.h>

// Function prototypes
// Function takes nothing and returns an integer
int get_five(void);

// Function that converts the given number of kilometers into miles and
// returns the result
double miles_to_kms(int miles);

// Function print weather condition based on the given temperature
void describe_weather(int temperature);

int get_temperature(void);

int main(void) {
    // Call getFive function
    int n = get_five();
    printf("%d\n", n);

    // Convert miles
    double miles = 100.0;
    printf("%.0lf miles is %.2lf kilometer\n", miles, miles_to_kms(miles));

    // Call describe weather function
    int temperature = get_temperature();
    describe_weather(temperature);


    return 0;
}

int get_five(void) {
    return 5;
}

double miles_to_kms(int miles) {
    double kms = miles * 1.609;
    return kms;
}

int get_temperature(void) {
    puts("Enter the temperature");
    int temperature;
    scanf("%d", &temperature);
    return temperature;
}

void describe_weather(int temperature) {
    if (temperature >= 90)
        puts("HOT");
    else if (temperature >= 70)
        puts("MODERATE");
    else if (temperature >= 40)
        puts("CHILLY");
    else
        puts("FREEZING COLD!!!");
}