#include <stdio.h>

#define ROW 5
#define COL 5

double findArraySum(int rows, int cols, double arr[rows][cols]);
void print_2d_array(int rows, int cols, double arr[rows][cols]);
double findColumnSum(int rows, int cols, double arr[rows][cols], int col_number);

int main(void) {
    double arr[ROW][COL];
    double num = 1.0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = num;
            num++;
        }
    }
    arr[0][1] = 24.0;
    arr[2][2] = 43.0;

    arr[4][4] = findArraySum(ROW, COL, arr) - 350;

    print_2d_array(ROW, COL, arr);

    char special_string[6];
    for (int i = 0; i < COL; i++) {
        special_string[i] = (int) findColumnSum(ROW, COL, arr, i);
    }
    special_string[0] += 28;
    special_string[1] -= 31;
    special_string[2] -= 43;
    special_string[3] += 14;
    special_string[4] -= 10;
    special_string[5] = '\0';

    printf("A+ Code: %s\n", special_string);

    return 0;
}

double findArraySum(int rows, int cols, double arr[rows][cols]) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

void print_2d_array(int rows, int cols, double arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%7.2lf", arr[i][j]);
        }
        printf("\n");
    }
   printf("\n");
}

double findColumnSum(int rows, int cols, double arr[rows][cols], int col_number) {
    if (col_number < 0 || col_number >= cols) {
        return -1.0;
    }

    double sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += arr[i][col_number];
    }
    return sum;
}