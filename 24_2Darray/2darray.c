#include <stdio.h>

#define ROW 4
#define COL 4

// void print_2d_array(int rows, int cols, int **arr);
void print_2d_array(int rows, int cols, int arr[rows][cols]);
void setRow(int rows, int cols, int arr[rows][cols], int row_number, int value);
void setCol(int rows, int cols, int arr[rows][cols], int col_number, int value);

// !! TODO 10/27/2025
void setMainDiagonal(int rows, int cols, int arr[rows][cols], int value);  // negative linear centered at center of array
void setInverseDiagonal(int rows, int cols, int arr[rows][cols], int value);  // positive linear centered at center of array

int main(void) {
    // Create a 2D array
    int arr[ROW][COL] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Access an element
    printf("%d\n", arr[1][0]);
    // printf("%d\n", *(arr + 7));

    // Modify an element of the array
    arr[1][2] = 66;
    printf("%d\n", arr[1][2]);

    /*
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
        printf("\n");
    }
    */

    print_2d_array(ROW, COL, arr);

    /*
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    */

    // Set the second row with 7's
    for (int j = 0; j < COL; j++) {
        arr[1][j] = 7;
    }

    print_2d_array(ROW, COL, arr);

    // Set 3rd column with 5's
    for (int i = 0; i < ROW; i++) {
        arr[i][2] = 5;
    }

    print_2d_array(ROW, COL, arr);



    setRow(ROW, COL, arr, 3, 41);
    setCol(ROW, COL, arr, 1, 67);
    print_2d_array(ROW, COL, arr);

    return 0;
}

// void print_2d_array(int rows, int cols, int **arr) {
void print_2d_array(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
   printf("\n");
}

void setRow(int rows, int cols, int arr[rows][cols], int row_number, int value) {
    if (row_number < 0 || row_number >= rows) {
        return;
    }

    for (int j = 0; j < cols; j++) {
        arr[row_number][j] = value;
    }
}

void setCol(int rows, int cols, int arr[rows][cols], int col_number, int value) {
    for (int i = 0; i < rows; i++) {
        arr[i][col_number] = value;
    }
}

void setMainDiagonal(int rows, int cols, int arr[rows][cols], int value) {  // negative linear centered at center of array
    for (int i = 0; i < rows && i < cols; i++) {
        arr[i][i] = value;
    }
}
void setInverseDiagonal(int rows, int cols, int arr[rows][cols], int value) {
    for (int i = 0; i < rows && i < cols; i++) {
        arr[i][i] = value;
    }
}