#include<stdio.h>
#include<stdlib.h>

void interchange_row(int **arr, int col, int interchange_1, int interchange_2);

int main() {
    int row, col;
    int interchange_1, interchange_2;
    
    printf("Enter the number of rows and columns of a matrix: ");
    scanf("%d%d", &row, &col);

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Array you entered:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter the numbers of rows to interchange: ");
    scanf("%d%d", &interchange_1, &interchange_2);

    interchange_row(matrix, col, interchange_1, interchange_2);

    printf("Array after interchange:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory for each row
   /* for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }*/
    // Free memory for the matrix itself
    free(matrix);

    return 0;
}

void interchange_row(int **arr, int col, int interchange_1, int interchange_2) {
    for (int i = 0; i < col; i++) {
        int temp = arr[interchange_1][i];
        arr[interchange_1][i] = arr[interchange_2][i];
        arr[interchange_2][i] = temp;
    }
}
